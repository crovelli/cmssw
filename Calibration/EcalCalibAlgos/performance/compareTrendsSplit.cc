#include "TStyle.h"
#include "TFile.h"
#include <TGraphErrors.h>
#include "TCanvas.h"
#include "TLegend.h"
#include "TH2F.h"
#include <iostream>

using namespace std;

void compareTrendsSplit() {

  // taking inputs                                                                                                                           
  TFile *infile[2];
  infile[0] = new TFile("/cmshome/rovelch/calibZee/calibZ_7_2_1_singleX_test2/src/Calibration/EcalCalibAlgos/test/trends/outTrends_noMiscalibSplitIn2_isOdd.root");
  infile[1] = new TFile("/cmshome/rovelch/calibZee/calibZ_7_2_1_singleX_test2/src/Calibration/EcalCalibAlgos/test/trends/outTrends_noMiscalibSplitIn2_isNotOdd.root");
  for (int ii=0; ii<2; ii++) {
    if (!infile[ii]) cout << "File " << infile[ii] << " not existing" << endl;
  }
  
  TGraphErrors *Gmean[2][4], *Gsigma[2][4];    // [file][cat]
  for (int ii=0; ii<2; ii++) {      // file
    for (int jj=0; jj<4; jj++) {    // cat
      Gmean[ii][jj]  = (TGraphErrors*)infile[ii]->Get(TString::Format("gMean_cat%d",jj));
      Gsigma[ii][jj] = (TGraphErrors*)infile[ii]->Get(TString::Format("gSigma_cat%d",jj));
      Gmean[ii][jj]  -> SetMarkerStyle(20);    
      Gsigma[ii][jj] -> SetMarkerStyle(20);
      Gmean[ii][jj]  -> SetMarkerColor(ii+1);    
      Gsigma[ii][jj] -> SetMarkerColor(ii+1);
    }
  }
  

  // ---------------------------------------------------------------------
  TLegend* leg = new TLegend(0.45, 0.60, 0.90, 0.85); 
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(Gmean[0][0], "odd event", "p");  
  leg->AddEntry(Gmean[1][0], "even event", "p");  

  gStyle->SetOptStat(0); 

  TH2F *myH_mean = new TH2F("myH_mean","",100,0.,16.,100,87.,100.);
  myH_mean->SetTitle("");
  myH_mean->GetXaxis()->SetTitle("iteration");
  myH_mean->GetYaxis()->SetTitle("CB mean");

  TCanvas c1m("c1m","cat0",1);
  myH_mean -> Draw();
  for (int ii=0; ii<2; ii++) Gmean[ii][0] ->Draw("Psame");
  leg->Draw();  
  c1m.SaveAs("mass_cat0.png");
  
  TCanvas c2m("c2m","cat1",1);
  myH_mean -> Draw();
  for (int ii=0; ii<2; ii++) Gmean[ii][1] ->Draw("Psame");
  leg->Draw();  
  c2m.SaveAs("mass_cat1.png");

  TCanvas c3m("c3m","cat2",1);
  myH_mean -> Draw();
  for (int ii=0; ii<2; ii++) Gmean[ii][2] ->Draw("Psame");
  leg->Draw();  
  c3m.SaveAs("mass_cat2.png");

  TCanvas c4m("c4m","cat3",1);
  myH_mean -> Draw();
  for (int ii=0; ii<2; ii++) Gmean[ii][3] ->Draw("Psame");
  leg->Draw();  
  c4m.SaveAs("mass_cat3.png");


  // ---------------------------------------------------------------------
  TH2F *myH_sigma = new TH2F("myH_sigma","myH_sigma",100,0.,16.,100,-0.5,6.5);
  myH_sigma->SetTitle("");
  myH_sigma->GetXaxis()->SetTitle("iteration");
  myH_sigma->GetYaxis()->SetTitle("CB sigma");

  TCanvas c1s("c1s","cat0",1);
  myH_sigma -> Draw();
  for (int ii=0; ii<2; ii++) Gsigma[ii][0] ->Draw("Psame");    
  leg->Draw();  
  c1s.SaveAs("sigma_cat0.png");
  
  TCanvas c2s("c2s","cat1",1);
  myH_sigma -> Draw();
  for (int ii=0; ii<2; ii++) Gsigma[ii][1] ->Draw("Psame");
  leg->Draw();  
  c2s.SaveAs("sigma_cat1.png");

  TCanvas c3s("c3s","cat2",1);
  myH_sigma -> Draw();
  for (int ii=0; ii<2; ii++) Gsigma[ii][2] ->Draw("Psame");
  leg->Draw();  
  c3s.SaveAs("sigma_cat2.png");

  TCanvas c4s("c4s","cat3",1);
  myH_sigma -> Draw();
  for (int ii=0; ii<2; ii++) Gsigma[ii][3] ->Draw("Psame");
  leg->Draw();  
  c4s.SaveAs("sigma_cat3.png");
}
