#include "RooRealVar.h"
#include "RooBinning.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooCBShape.h"
#include "RooWorkspace.h"
#include "RooPlot.h"
#include "RooAddPdf.h"
#include "RooBreitWigner.h"
#include "RooFFTConvPdf.h"
#include "RooHistFunc.h"
#include "RooHistPdf.h"
#include "RooFitResult.h"
#include "RooStats/HLFactory.h"

#include "HiggsAnalysis/CombinedLimit/interface/HZZ2L2QRooPdfs.h"

#include "TFile.h"
#include "TF1.h"
#include "TH1.h"
#include "TGraphAsymmErrors.h"
#include "TGraphErrors.h"
#include "TTree.h"
#include "TChain.h"
#include "TMath.h"
#include "TROOT.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TLatex.h"
#include "TPaveText.h"

#include <fstream>

using namespace RooFit;

// ============================================
// to be modified:
static const Int_t NCAT = 4;  
static const Int_t NLOOP = 15;  
Int_t MINmass= 70;
Int_t MAXmass= 110;
// ============================================


// Definition of the variables in the input ntuple
RooArgSet* defineVariables() {

  RooRealVar* zMass     = new RooRealVar("zMass",     "parent supercluster mass", MINmass, MAXmass, "GeV");
  RooRealVar* isEBEB    = new RooRealVar("isEBEB",    "isEBEB",   -0.1, 1.1,   "");
  RooRealVar* isHR9HR9  = new RooRealVar("isHR9HR9",  "isHR9HR9", -0.1, 1.1,   "");
  RooRealVar* iteration = new RooRealVar("iteration", "iteration", 0, 30, "");
  RooRealVar* isOdd     = new RooRealVar("isOdd",     "isOdd",    -0.1, 1.1,   ""); 
  RooArgSet* ntplVars   = new RooArgSet(*zMass, *isEBEB, *isHR9HR9, *iteration, *isOdd);
  
  return ntplVars;
}

// loading signal data and making roodatasets
void AddSigData(RooWorkspace* w) {
  
  Int_t ncat  = NCAT;
  Int_t nloop = NLOOP;
  
  // Variables
  RooArgSet* ntplVars = defineVariables();

  // Dataset
  // TString inDir = "/cmshome/rovelch/calibZee/calibZ_7_2_1_singleX_test2/src/Calibration/EcalCalibAlgos/test/noMiscalib/";
  // TString inDir = "/cmshome/rovelch/calibZee/calibZ_7_2_1_singleX_test2/src/Calibration/EcalCalibAlgos/test/miscalSingleXtal_scala1_smear10/";
  // TString inDir = "/cmshome/rovelch/calibZee/calibZ_7_2_1_singleX_test2/src/Calibration/EcalCalibAlgos/test/miscalSingleXtal_scala1d1_smear10/";
  // TString inDir = "/cmshome/rovelch/calibZee/calibZ_7_2_1_singleX_test2/src/Calibration/EcalCalibAlgos/test/miscalSingleXtal_scala0d9_smear10/";
  TString inDir = "/cmshome/rovelch/calibZee/calibZ_7_2_1_singleX_test2/src/Calibration/EcalCalibAlgos/test/noMiscalib_splitIn2/";
  TChain* sigTree = new TChain();
  cout << "reading file " << inDir+TString("myHistograms_test.root");
  sigTree->Add(inDir+TString("myHistograms_test.root/myTree"));
  sigTree->SetTitle("ZTreeVsLoop");
  sigTree->SetName("ZTreeVsLoop");
  RooDataSet sigWeighted("sigWeighted","dataset",sigTree,*ntplVars,"");   

  // Split in categories and by iteration
  cout << endl;
  cout << "preparing dataset" << endl;

  RooDataSet* signal[NCAT][NLOOP];
  for (int c=0; c<ncat; ++c) {
    for (int iLoop=0; iLoop<nloop; ++iLoop) {
      
      if (c==0) signal[c][iLoop] = (RooDataSet*) sigWeighted.reduce(*w->var("zMass"),TString::Format("isEBEB && isHR9HR9 && !isOdd && iteration==%d",iLoop));
      if (c==1) signal[c][iLoop] = (RooDataSet*) sigWeighted.reduce(*w->var("zMass"),TString::Format("isEBEB && !isHR9HR9 && !isOdd && iteration==%d",iLoop));
      if (c==2) signal[c][iLoop] = (RooDataSet*) sigWeighted.reduce(*w->var("zMass"),TString::Format("!isEBEB && isHR9HR9 && !isOdd && iteration==%d",iLoop));
      if (c==3) signal[c][iLoop] = (RooDataSet*) sigWeighted.reduce(*w->var("zMass"),TString::Format("!isEBEB && !isHR9HR9 && !isOdd && iteration==%d",iLoop));
    
      TString myCut;
      if (c==0)      myCut = "EBHighR9";
      else if (c==1) myCut = "EBLowR9";
      else if (c==2) myCut = "EEHighR9";
      else if (c==3) myCut = "EELowR9";    
      w->import(*signal[c][iLoop],Rename(TString::Format("SigWeight_cat"+myCut+"_iter%d",iLoop)));

      cout << "cat " << myCut << ", iter " << iLoop << " => " << endl;
      signal[c][iLoop]->Print("v");
      cout << endl;
    }
  }
  
  // Create dataset without categorization
  RooDataSet* signalAll[NLOOP];
  for (int iLoop=0; iLoop<nloop; ++iLoop) {
    signalAll[iLoop] = (RooDataSet*) sigWeighted.reduce(*w->var("zMass"), TString::Format("iteration==%d",iLoop));
    w->import(*signalAll[iLoop], Rename(TString::Format("SigWeight_iter%d",iLoop)));
    cout << "now signalAll for iteration " << iLoop << endl;
    signalAll[iLoop]->Print("v");
    cout << endl;
  }
}

//-------------------------------------------------------------------------

// Fit to Z mass, CB convoluted with BW
void SigModelFitCBConvBW(RooWorkspace* w) {

  // Dataset
  int plusOne = NCAT+1;
  if (NCAT<4) plusOne = NCAT;
  RooDataSet* sigToFit[plusOne][NLOOP];
  RooRealVar* zMass = w->var("zMass");
  zMass->Print();

  // to save fit results                                                                                                                                                                  
  vector<float> v_iter0, v_mean0, v_sigma0;
  vector<float> v_iter1, v_mean1, v_sigma1;
  vector<float> v_iter2, v_mean2, v_sigma2;
  vector<float> v_iter3, v_mean3, v_sigma3;
  vector<float> v_iterA, v_meanA, v_sigmaA;
  // and errors                                                                                                                                                                           
  vector<float> v_iterE0, v_meanE0, v_sigmaE0;
  vector<float> v_iterE1, v_meanE1, v_sigmaE1;
  vector<float> v_iterE2, v_meanE2, v_sigmaE2;
  vector<float> v_iterE3, v_meanE3, v_sigmaE3;
  vector<float> v_iterEA, v_meanEA, v_sigmaEA;

    
  for (int iLoop=0; iLoop<NLOOP; iLoop++) {   // do everything for each iteration
    
    // Fit to Signal 
    for (int c=0; c<plusOne; ++c) {
      
      TString myCut = "EBHighR9";
      if (c==0)      myCut = "EBHighR9";
      else if (c==1) myCut = "EBLowR9";
      else if (c==2) myCut = "EEHighR9";
      else if (c==3) myCut = "EELowR9";    
      else if (c==4) myCut = "All";    
      cout << "---------- Category = " << c << ", " << myCut << endl;
      
      // dCB
      // RooRealVar CBmean ("CBmean", "CBmean", 0.,-3.,1.);             // scala ok
      // RooRealVar CBmean ("CBmean", "CBmean", 0.,-3.,15.);            // scala +10%
      RooRealVar CBmean ("CBmean", "CBmean", 0.,-20.,1.);               // scala -10%
      // RooRealVar CBsigma("CBsigma","CBsigma", 0.8, 0.01, 3.);        // no miscalib
      RooRealVar CBsigma("CBsigma","CBsigma", 0.8, 0.01, 7.);
      RooRealVar CBalpha1("CBalpha1","CBalpha1",1.,0.,2.);
      RooRealVar CBn1("CBn1","CBn1",1.5,0.,4.);
      RooRealVar CBalpha2("CBalpha2","CBalpha2",1.,0.,3.);
      RooRealVar CBn2("CBn2","CBn2",1.5,0.,5.);
      RooDoubleCB ResCB("ResCB","ResCB", *zMass, CBmean, CBsigma, CBalpha1, CBn1, CBalpha2, CBn2);
      zMass->setBins(5000, "cache");  
      
      // BW 
      RooRealVar meanBW("massBW","massBW",91.1876);
      RooRealVar sigmaBW("widthBW","widthBW",2.4952);
      RooBreitWigner zBW("BW","BW", *zMass, meanBW, sigmaBW);
      
      // Convolution
      RooFFTConvPdf* ConvolutedRes;
      ConvolutedRes = new RooFFTConvPdf("conv","conv", *zMass, zBW, ResCB);
      
      // Fit and Plot
      if (c<4) 
	sigToFit[c][iLoop] = (RooDataSet*) w->data(TString::Format("SigWeight_cat"+myCut+"_iter%d",iLoop));
      else if (c==4)
      	sigToFit[c][iLoop] = (RooDataSet*) w->data(TString::Format("SigWeight_iter%d",iLoop));
      
      float fitMin = MINmass;
      float fitMax = MAXmass;
      RooFitResult* fitresults = (RooFitResult* ) ConvolutedRes->fitTo(*sigToFit[c][iLoop], SumW2Error(kFALSE), Range(fitMin,fitMax), RooFit::Save(kTRUE));
      fitresults->Print("V");

      // Saving the fit outcome
      if (c==0) {
	v_iter0.push_back(iLoop);
	v_iterE0.push_back(0);
	v_mean0.push_back(CBmean.getVal()+91.1876);
	v_meanE0.push_back(CBmean.getError());
	v_sigma0.push_back(CBsigma.getVal());
	v_sigmaE0.push_back(CBsigma.getError());
      } else if (c==1) {
	v_iter1.push_back(iLoop);
	v_iterE1.push_back(0);
	v_mean1.push_back(CBmean.getVal()+91.1876);
	v_meanE1.push_back(CBmean.getError());
	v_sigma1.push_back(CBsigma.getVal());
	v_sigmaE1.push_back(CBsigma.getError());
      } else if (c==2) {
	v_iter2.push_back(iLoop);
	v_iterE2.push_back(0);
	v_mean2.push_back(CBmean.getVal()+91.1876);
	v_meanE2.push_back(CBmean.getError());
	v_sigma2.push_back(CBsigma.getVal());
	v_sigmaE2.push_back(CBsigma.getError());
      } else if (c==3) {
	v_iter3.push_back(iLoop);
	v_iterE3.push_back(0);
	v_mean3.push_back(CBmean.getVal()+91.1876);
	v_meanE3.push_back(CBmean.getError());
	v_sigma3.push_back(CBsigma.getVal());
	v_sigmaE3.push_back(CBsigma.getError());
      } else if (c==4) {
	v_iterA.push_back(iLoop);
	v_iterEA.push_back(0);
	v_meanA.push_back(CBmean.getVal()+91.1876);
	v_meanEA.push_back(CBmean.getError());
	v_sigmaA.push_back(CBsigma.getVal());
	v_sigmaEA.push_back(CBsigma.getError());
      }
      
      // CB for the plot
      float CBmeanV   = CBmean.getVal() + 91.1876;
      float CBsigmaV  = CBsigma.getVal();
      float CBalpha1V = CBalpha1.getVal();
      float CBalpha2V = CBalpha2.getVal();
      float CBn1V     = CBn1.getVal();
      float CBn2V     = CBn2.getVal();
      RooRealVar CBmeanP("CBmeanP", "CBmeanP", CBmeanV);
      RooRealVar CBsigmaP("CBsigmaP","CBsigmaP", CBsigmaV);
      RooRealVar CBalpha1P("CBalpha1P","CBalpha1P", CBalpha1V);
      RooRealVar CBalpha2P("CBalpha2P","CBalpha2P", CBalpha2V);
      RooRealVar CBn1P("CBn1P","CBn1P",CBn1V);
      RooRealVar CBn2P("CBn2P","CBn2P",CBn2V);
      RooDoubleCB ResCBP("ResCBP","ResCBP", *zMass, CBmeanP, CBsigmaP, CBalpha1P, CBn1P, CBalpha2P, CBn2P);
      
      RooPlot* plotOnlyResPdf = w->var("zMass")->frame(Range(fitMin,fitMax),Bins(100));
      sigToFit[c][iLoop]->plotOn(plotOnlyResPdf, LineColor(kRed), LineStyle(kDashed));
      double max = plotOnlyResPdf->GetMaximum();
      
      RooPlot* plotAll = w->var("zMass")->frame(Range(fitMin,fitMax),Bins(100));
      plotAll->GetXaxis()->SetTitle("m(ee)");
      plotAll->SetTitle(TString::Format("DoubleCB conv BW, cat "+myCut+", loop %d",iLoop));
      sigToFit[c][iLoop]->plotOn(plotAll);
      zBW.plotOn(plotAll, LineColor(kGreen), LineStyle(kDashed));
      ResCBP.plotOn(plotAll, LineColor(kRed), LineStyle(kDashed));
      ConvolutedRes->plotOn(plotAll, LineColor(kBlue));
      
      TCanvas* c1 = new TCanvas("c1","Z mass",0,0,800,800);
      c1->cd(1);
      plotAll->Draw();  
      plotAll->GetYaxis()->SetRangeUser(0.01, max*1.2);
      plotAll->GetXaxis()->SetRangeUser(210, 290);
      
      TLegend *legmc = new TLegend(0.55, 0.6, 0.87, 0.88, "");
      legmc->AddEntry(plotAll->getObject(0),"Simulation","LPE");
      legmc->AddEntry(plotAll->getObject(1),"BW","L");
      legmc->AddEntry(plotAll->getObject(2),"CB","L");
      legmc->AddEntry(plotAll->getObject(3),"BW #otimes CB","L");
      legmc->SetTextSize(0.0206044);
      legmc->SetTextFont(42);
      legmc->SetBorderSize(0);
      legmc->SetFillStyle(0);
      legmc->Draw();
      
      c1->SetLogy();
      plotAll->GetXaxis()->SetTitle("m(ee)[GeV]");
      
      c1->SetLogy(0);
      c1->SaveAs("CBconvBW"+TString::Format(("_cat%d_loop%d.png"),c,iLoop));
      
      c1->SetLogy();
      plotAll->GetYaxis()->SetRangeUser(0.01,max*10. );
      plotAll->GetXaxis()->SetRangeUser(210, 290);
      c1->SaveAs("CBconvBW"+TString::Format(("_cat%d_loop%d_LOG.png"),c,iLoop));

      delete legmc;
      delete c1;
      delete ConvolutedRes;
    } // loop over cats
  }   // loop over iters

  // graphs with trend                                                                                                                                                                    
  TGraphErrors *gMean_cat0   = new TGraphErrors(NLOOP, &v_iter0[0], &v_mean0[0],   &v_iterE0[0], &v_meanE0[0]);
  TGraphErrors *gSigma_cat0  = new TGraphErrors(NLOOP, &v_iter0[0], &v_sigma0[0],  &v_iterE0[0], &v_sigmaE0[0]);
  TGraphErrors *gMean_cat1   = new TGraphErrors(NLOOP, &v_iter1[0], &v_mean1[0],   &v_iterE1[0], &v_meanE1[0]);
  TGraphErrors *gSigma_cat1  = new TGraphErrors(NLOOP, &v_iter1[0], &v_sigma1[0],  &v_iterE1[0], &v_sigmaE1[0]);
  TGraphErrors *gMean_cat2   = new TGraphErrors(NLOOP, &v_iter2[0], &v_mean2[0],   &v_iterE2[0], &v_meanE2[0]);
  TGraphErrors *gSigma_cat2  = new TGraphErrors(NLOOP, &v_iter2[0], &v_sigma2[0],  &v_iterE2[0], &v_sigmaE2[0]);
  TGraphErrors *gMean_cat3   = new TGraphErrors(NLOOP, &v_iter3[0], &v_mean3[0],   &v_iterE3[0], &v_meanE3[0]);
  TGraphErrors *gSigma_cat3  = new TGraphErrors(NLOOP, &v_iter3[0], &v_sigma3[0],  &v_iterE3[0], &v_sigmaE3[0]);
  TGraphErrors *gMean_catA   = new TGraphErrors(NLOOP, &v_iterA[0], &v_meanA[0],   &v_iterEA[0], &v_meanEA[0]);
  TGraphErrors *gSigma_catA  = new TGraphErrors(NLOOP, &v_iterA[0], &v_sigmaA[0],  &v_iterEA[0], &v_sigmaEA[0]);
  TFile fileOut("outTrends.root","RECREATE");
  gMean_cat0->Write("gMean_cat0");
  gSigma_cat0->Write("gSigma_cat0");
  gMean_cat1->Write("gMean_cat1");
  gSigma_cat1->Write("gSigma_cat1");
  gMean_cat2->Write("gMean_cat2");
  gSigma_cat2->Write("gSigma_cat2");
  gMean_cat3->Write("gMean_cat3");
  gSigma_cat3->Write("gSigma_cat3");
  gMean_catA->Write("gMean_all");
  gSigma_catA->Write("gSigma_all");
  fileOut.Close();
}

void runfits() {

  RooWorkspace* w = new RooWorkspace("w");
  
  RooRealVar* zMass = new RooRealVar("zMass", "parent supercluster mass", MINmass, MAXmass, "GeV");
  w->import(*zMass);

  cout << endl; 
  cout << "Now add data" << endl;
  AddSigData(w);   

  cout << endl; 
  cout << "Now mass fit" << endl; 
  SigModelFitCBConvBW(w);

  return;
}

