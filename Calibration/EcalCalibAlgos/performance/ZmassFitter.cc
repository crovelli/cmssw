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
Int_t MINmass= 60;
Int_t MAXmass= 120;
// ============================================


// Definition of the variables in the input ntuple
RooArgSet* defineVariables() {

  RooRealVar* massPsc = new RooRealVar("massPsc", "parent supercluster mass", MINmass, MAXmass, "GeV");
  RooRealVar* eta1    = new RooRealVar("eta1", "eta1", -2.5, 2.5,   "");
  RooRealVar* eta2    = new RooRealVar("eta2", "eta2", -2.5, 2.5,   "");
  RooRealVar* r91     = new RooRealVar("r91",  "r91",  0., 1.,   "");
  RooRealVar* r92     = new RooRealVar("r92",  "r92",  0., 1.,   "");
  RooArgSet* ntplVars = new RooArgSet(*massPsc, *eta1, *eta2, *r91, *r92);
  
  return ntplVars;
}

// loading signal data and making roodatasets
void AddSigData(RooWorkspace* w) {
  
  Int_t ncat = NCAT;
  
  // Variables
  RooArgSet* ntplVars = defineVariables();

  // Dataset
  TString inDir = "/cmshome/rovelch/calibZee/calibZ_7_2_1_singleX_test1/src/Calibration/EcalCalibAlgos/test/standalone/";  
  TChain* sigTree = new TChain();
  cout << "reading file " << inDir+TString("zee.root");
  sigTree->Add(inDir+TString("zee.root/zeeScSel/Ztree"));
  sigTree->SetTitle("ZTree");
  sigTree->SetName("ZTree");
  RooDataSet sigWeighted("sigWeighted","dataset",sigTree,*ntplVars,"");   

  // Split in categories
  cout << endl;
  cout << "preparing dataset" << endl;
  RooDataSet* signal[NCAT];
  for (int c=0; c<ncat; ++c) {
    if (c==0) signal[c] = (RooDataSet*) sigWeighted.reduce(*w->var("massPsc"),"abs(eta1)<1.5 && abs(eta2)<1.5 && r91>0.94 && r92>0.94");
    if (c==1) signal[c] = (RooDataSet*) sigWeighted.reduce(*w->var("massPsc"),"abs(eta1)<1.5 && abs(eta2)<1.5 && (r91<0.94 || r92<0.94)");
    if (c==2) signal[c] = (RooDataSet*) sigWeighted.reduce(*w->var("massPsc"),"(abs(eta1)>1.5 || abs(eta2)>1.5) && r91>0.94 && r92>0.94");
    if (c==3) signal[c] = (RooDataSet*) sigWeighted.reduce(*w->var("massPsc"),"(abs(eta1)>1.5 || abs(eta2)>1.5) && (r91<0.94 || r92<0.94)");

    TString myCut;
    if (c==0)      myCut = "EBHighR9";
    else if (c==1) myCut = "EBLowR9";
    else if (c==2) myCut = "EEHighR9";
    else if (c==3) myCut = "EELowR9";    
    w->import(*signal[c],Rename("SigWeight_cat"+myCut));

    cout << "cat " << myCut << ", signal: " << endl;
    signal[c]->Print("v");
    cout << "---- for category " << c << ", nX for signal[c]:  " << signal[c]->sumEntries() << endl; 
    cout << endl;
  }

  // Create dataset without categorization
  RooDataSet* signalAll = (RooDataSet*) sigWeighted.reduce(*w->var("massPsc"),"1");
  w->import(*signalAll, Rename("SigWeight"));
  cout << "now signalAll" << endl;
  signalAll->Print("v");
  cout << "---- nX for signalAll:  " << signalAll->sumEntries() << endl; 
  cout << endl;
}

//-------------------------------------------------------------------------

// Fit to Z mass, CB convoluted with BW
void SigModelFitCBConvBW(RooWorkspace* w) {

  // Dataset
  int plusOne = NCAT+1;
  RooDataSet* sigToFit[plusOne];
  RooRealVar* massPsc = w->var("massPsc");
  massPsc->Print();
  
  // Fit to Signal 
  for (int c=0; c<plusOne; ++c) {
    cout << "---------- Category = " << c << endl;
    
    TString myCut = "EBHighR9";
    if (c==0)      myCut = "EBHighR9";
    else if (c==1) myCut = "EBLowR9";
    else if (c==2) myCut = "EEHighR9";
    else if (c==3) myCut = "EELowR9";    
    else if (c==4) myCut = "All";    

    // dCB
    RooRealVar CBmean ("CBmean", "CBmean", 0.,-2.,1.);
    RooRealVar CBsigma("CBsigma","CBsigma", 0.8, 0.1, 3.);
    RooRealVar CBalpha1("CBalpha1","CBalpha1",1.,0.,2.);
    RooRealVar CBn1("CBn1","CBn1",1.5,0.,4.);
    RooRealVar CBalpha2("CBalpha2","CBalpha2",1.,0.,2.);
    RooRealVar CBn2("CBn2","CBn2",1.5,0.,4.);
    RooDoubleCB ResCB("ResCB","ResCB", *massPsc, CBmean, CBsigma, CBalpha1, CBn1, CBalpha2, CBn2);
    massPsc->setBins(5000, "cache");  

    // BW 
    RooRealVar meanBW("massBW","massBW",91.1876);
    RooRealVar sigmaBW("widthBW","widthBW",2.4952);
    RooBreitWigner zBW("BW","BW", *massPsc, meanBW, sigmaBW);

    // Convolution
    RooFFTConvPdf* ConvolutedRes;
    ConvolutedRes = new RooFFTConvPdf("conv","conv", *massPsc, zBW, ResCB);

    // Fit and Plot
    if (c<4) 
      sigToFit[c] = (RooDataSet*) w->data("SigWeight_cat"+myCut);
    else if (c==4)
      sigToFit[c] = (RooDataSet*) w->data("SigWeight");
    float fitMin = MINmass;
    float fitMax = MAXmass;
    RooFitResult* fitresults = (RooFitResult* ) ConvolutedRes->fitTo(*sigToFit[c], SumW2Error(kFALSE), Range(fitMin,fitMax), RooFit::Save(kTRUE));
    fitresults->Print("V");
    
    // dCB for the plot
    float CBmeanV  = CBmean.getVal() + 91.1876;
    float CBsigmaV = CBsigma.getVal();
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
    RooDoubleCB ResCBP("ResCBP","ResCBP", *massPsc, CBmeanP, CBsigmaP, CBalpha1P, CBn1P, CBalpha2P, CBn2P);

    RooPlot* plotOnlyResPdf = w->var("massPsc")->frame(Range(fitMin,fitMax),Bins(100));
    sigToFit[c]->plotOn(plotOnlyResPdf, LineColor(kRed), LineStyle(kDashed));
    double max = plotOnlyResPdf->GetMaximum();
    
    RooPlot* plotAll = w->var("massPsc")->frame(Range(fitMin,fitMax),Bins(100));
    plotAll->GetXaxis()->SetTitle("m(ee)");
    plotAll->SetTitle("CB conv BW, cat"+myCut);
    sigToFit[c]->plotOn(plotAll);
    zBW.plotOn(plotAll, LineColor(kGreen), LineStyle(kDashed));
    ResCBP.plotOn(plotAll, LineColor(kRed), LineStyle(kDashed));
    ConvolutedRes->plotOn(plotAll, LineColor(kBlue));
    
    TCanvas* c1 = new TCanvas("c1","Z mass",0,0,800,800);
    c1->cd(1);
    plotAll->Draw();  
    plotAll->GetYaxis()->SetRangeUser(0.01, max*1.2);
    plotAll->GetXaxis()->SetRangeUser(210, 290);
    
    TLatex *lat  = new TLatex(0.55,0.9,TString::Format("Cat: %d", c));  
    lat->SetTextSize(0.038);
    lat->SetTextAlign(11);
    lat->SetTextFont(42); 
    lat->SetNDC();
    
    TLegend *legmc = new TLegend(0.55, 0.6, 0.87, 0.88, "");
    legmc->AddEntry(plotAll->getObject(0),"Simulation","LPE");
    legmc->AddEntry(plotAll->getObject(1),"BW","L");
    legmc->AddEntry(plotAll->getObject(2),"dCB","L");
    legmc->AddEntry(plotAll->getObject(3),"BW #otimes dCB","L");
    legmc->SetTextSize(0.0206044);
    legmc->SetTextFont(42);
    legmc->SetBorderSize(0);
    legmc->SetFillStyle(0);
    legmc->Draw();
    lat->Draw("same");
    
    c1->SetLogy();
    plotAll->GetXaxis()->SetTitle("m(ee)[GeV]");
    
    c1->SetLogy(0);
    c1->SaveAs("standaloneCBconvBW"+TString::Format(("_cat%d.png"),c));
    
    c1->SetLogy();
    plotAll->GetYaxis()->SetRangeUser(0.01,max*10. );
    plotAll->GetXaxis()->SetRangeUser(210, 290);
    c1->SaveAs("standaloneCBconvBW"+TString::Format(("_cat%d_LOG.png"),c));
    
    w->Print("V");
  }
}

void runfits() {

  RooWorkspace* w = new RooWorkspace("w");
  
  RooRealVar* massPsc = new RooRealVar("massPsc", "parent supercluster mass", MINmass, MAXmass, "GeV");
  w->import(*massPsc);

  cout << endl; 
  cout << "Now add data" << endl;
  AddSigData(w);   

  cout << endl; 
  cout << "Now mass fit" << endl; 
  SigModelFitCBConvBW(w);

  return;
}

