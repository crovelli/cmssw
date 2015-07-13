#include "TStyle.h"
#include "TFile.h"
#include <TGraphErrors.h>
#include "TCanvas.h"
#include "TLegend.h"
#include "TH2F.h"
#include <iostream>

using namespace std;

void compareTrends() {

  // taking inputs                                                                                                                           
  TFile *infile[4];
  infile[0] = new TFile("/cmshome/rovelch/calibZee/calibZ_7_2_1_singleX_test2/src/Calibration/EcalCalibAlgos/fits/files/outTrends_noMiscalib.root");
  infile[1] = new TFile("/cmshome/rovelch/calibZee/calibZ_7_2_1_singleX_test2/src/Calibration/EcalCalibAlgos/fits/files/outTrends_scala1_smear10.root");
  infile[2] = new TFile("/cmshome/rovelch/calibZee/calibZ_7_2_1_singleX_test2/src/Calibration/EcalCalibAlgos/fits/files/outTrends_scala1d1_smear10.root");
  for (int ii=0; ii<3; ii++) {
    if (!infile[ii]) cout << "File " << infile[ii] << " not existing" << endl;
  }
  
  TGraphErrors *Gmean[3][4], *Gsigma[3][4];    // [file][cat]
  TGraphErrors *GmeanAll[3], *GsigmaAll[3];    // [file]
  for (int ii=0; ii<3; ii++) {      // file
    for (int jj=0; jj<4; jj++) {    // cat
      Gmean[ii][jj]  = (TGraphErrors*)infile[ii]->Get(TString::Format("gMean_cat%d",jj));
      Gsigma[ii][jj] = (TGraphErrors*)infile[ii]->Get(TString::Format("gSigma_cat%d",jj));
      Gmean[ii][jj]  -> SetMarkerStyle(20);    
      Gsigma[ii][jj] -> SetMarkerStyle(20);
      Gmean[ii][jj]  -> SetMarkerColor(ii+1);    
      Gsigma[ii][jj] -> SetMarkerColor(ii+1);
    }
    GmeanAll[ii]  = (TGraphErrors*)infile[ii]->Get("gMean_all");
    GsigmaAll[ii] = (TGraphErrors*)infile[ii]->Get("gSigma_all");
    GmeanAll[ii]  -> SetMarkerStyle(20);
    GsigmaAll[ii] -> SetMarkerStyle(20);
    GmeanAll[ii]  -> SetMarkerColor(ii+1);
    GsigmaAll[ii] -> SetMarkerColor(ii+1);
  }
  

  // ---------------------------------------------------------------------
  TLegend* leg = new TLegend(0.45, 0.60, 0.90, 0.85); 
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->AddEntry(Gmean[0][0], "no miscalib, scale 1", "p");  
  leg->AddEntry(Gmean[1][0], "miscalib 10% in EB, scale 1", "p");  
  leg->AddEntry(Gmean[2][0], "miscalib 10%, scale +10% in EB", "p");  

  gStyle->SetOptStat(0); 

  TH2F *myH_mean = new TH2F("myH_mean","",100,0.,16.,100,87.,100.);
  myH_mean->SetTitle("");
  myH_mean->GetXaxis()->SetTitle("iteration");
  myH_mean->GetYaxis()->SetTitle("CB mean");

  TCanvas c1m("c1m","cat0",1);
  myH_mean -> Draw();
  for (int ii=0; ii<3; ii++) Gmean[ii][0] ->Draw("Psame");
  leg->Draw();  
  c1m.SaveAs("mass_cat0.png");
  
  TCanvas c2m("c2m","cat1",1);
  myH_mean -> Draw();
  for (int ii=0; ii<3; ii++) Gmean[ii][1] ->Draw("Psame");
  leg->Draw();  
  c2m.SaveAs("mass_cat1.png");

  TCanvas c3m("c3m","cat2",1);
  myH_mean -> Draw();
  for (int ii=0; ii<3; ii++) Gmean[ii][2] ->Draw("Psame");
  leg->Draw();  
  c3m.SaveAs("mass_cat2.png");

  TCanvas c4m("c4m","cat3",1);
  myH_mean -> Draw();
  for (int ii=0; ii<3; ii++) Gmean[ii][3] ->Draw("Psame");
  leg->Draw();  
  c4m.SaveAs("mass_cat3.png");

  TCanvas c5m("c5m","all",1);
  myH_mean -> Draw();
  for (int ii=0; ii<3; ii++) GmeanAll[ii] ->Draw("Psame");
  leg->Draw();  
  c5m.SaveAs("mass_allCats.png");


  // ---------------------------------------------------------------------
  TH2F *myH_sigma = new TH2F("myH_sigma","myH_sigma",100,0.,16.,100,-0.5,6.5);
  myH_sigma->SetTitle("");
  myH_sigma->GetXaxis()->SetTitle("iteration");
  myH_sigma->GetYaxis()->SetTitle("CB sigma");

  TCanvas c1s("c1s","cat0",1);
  myH_sigma -> Draw();
  for (int ii=0; ii<3; ii++) Gsigma[ii][0] ->Draw("Psame");    
  leg->Draw();  
  c1s.SaveAs("sigma_cat0.png");
  
  TCanvas c2s("c2s","cat1",1);
  myH_sigma -> Draw();
  for (int ii=0; ii<3; ii++) Gsigma[ii][1] ->Draw("Psame");
  leg->Draw();  
  c2s.SaveAs("sigma_cat1.png");

  TCanvas c3s("c3s","cat2",1);
  myH_sigma -> Draw();
  for (int ii=0; ii<3; ii++) Gsigma[ii][2] ->Draw("Psame");
  leg->Draw();  
  c3s.SaveAs("sigma_cat2.png");

  TCanvas c4s("c4s","cat3",1);
  myH_sigma -> Draw();
  for (int ii=0; ii<3; ii++) Gsigma[ii][3] ->Draw("Psame");
  leg->Draw();  
  c4s.SaveAs("sigma_cat3.png");

  TCanvas c5s("c5s","all",1);
  myH_sigma -> Draw();
  for (int ii=0; ii<3; ii++) GsigmaAll[ii] ->Draw("Psame");
  leg->Draw();  
  c5s.SaveAs("sigma_allCats.png");

}
