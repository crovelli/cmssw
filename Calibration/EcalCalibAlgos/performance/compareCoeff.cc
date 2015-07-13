#include "TStyle.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TH1.h"
#include "TH2.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <unistd.h>
#include <fstream>

using namespace std;

void compareCoeff() {

  // 
  TH1F *H_check1    = new TH1F("H_check1","",100, -2, 2);
  TH1F *H_check2    = new TH1F("H_check2","",100, 0.5, 1.5);
  TH1F *H_check3    = new TH1F("H_check3","",100, 0.5, 1.5);
  TH2F *H_NewVsOld  = new TH2F("H_NewVsOld","",100, 0.5,1.5,100,0.9,1.1);
  TH2F *H_NewVsOldz = new TH2F("H_NewVsOldz","",100, 0.9,1.1,100,0.9,1.1);
  TH2F *H_vsEta     = new TH2F("H_vsEta","",170, -85,85,100,-0.5,2);
  TH2F *H_vsPhi     = new TH2F("H_vsPhi","",360, 0,360,100,-0.5,2);

  // my coeff
  char buffer1[5000];
  int IFC1 = 0;
  int eta1[80000];
  int phi1[80000];
  int z1[80000];
  float ic1[80000];
  
  // EcalIntercalibConstants
  char buffer2[5000];
  int IFC2 = 0;
  int eta2[80000];
  int phi2[80000];
  int z2[80000];
  float ic2[80000];
  float extra2[80000];

  // EcalIntercalibConstantsMC
  char buffer3[5000];
  int IFC3 = 0;
  int eta3[80000];
  int phi3[80000];
  int z3[80000];
  float ic3[80000];
  float extra3[80000];

  ifstream *inFile1 = new ifstream("noMiscalibMio__ordered.txt");
  while( !(inFile1->eof()) ){
    inFile1->getline(buffer1,800);
    if (!strstr(buffer1,"#") && !(strspn(buffer1," ") == strlen(buffer1))){
      sscanf(buffer1,"%d %d %d %f", &eta1[IFC1], &phi1[IFC1], &z1[IFC1], &ic1[IFC1]);
      IFC1++;
    }
  }
  inFile1->close();
  delete inFile1;

  ifstream *inFile2 = new ifstream("dump_EcalIntercalibConstants__EcalIntercalib_2011_V3_Bon_mc_subModCor_smeared_1fb___ordered.dat");
  while( !(inFile2->eof()) ){
    inFile2->getline(buffer2,800);
    if (!strstr(buffer2,"#") && !(strspn(buffer2," ") == strlen(buffer2))){
      sscanf(buffer2,"%d %d %d %f %f", &eta2[IFC2], &phi2[IFC2], &z2[IFC2], &ic2[IFC2], &extra2[IFC2]);
      IFC2++;
    }
  }
  inFile2->close();
  delete inFile2;

  ifstream *inFile3 = new ifstream("dump_EcalIntercalibConstantsMC__digi_2011_V3_Bon_mc___ordered.dat");
  while( !(inFile3->eof()) ){
    inFile3->getline(buffer3,800);
    if (!strstr(buffer3,"#") && !(strspn(buffer3," ") == strlen(buffer3))){
      sscanf(buffer3,"%d %d %d %f %f", &eta3[IFC3], &phi3[IFC3], &z3[IFC3], &ic3[IFC3], &extra3[IFC3]);
      IFC3++;
    }
  }
  inFile3->close();
  delete inFile3;

  if (IFC1 != IFC2 || IFC1 !=IFC3) cout << "big problem!" << endl;

  for (int ii=0; ii<IFC1; ii++) {

    if (eta1[ii] != eta2[ii] || eta1[ii] != eta3[ii]) cout << "ii " << ii << ": eta is different" << endl; 
    if (phi1[ii] != phi2[ii] || phi1[ii] != phi3[ii]) cout << "ii " << ii << ": phi is different" << endl; 
    if (z1[ii] != z2[ii] || z1[ii] != z3[ii])         cout << "ii " << ii << ": z is different" << endl; 

    if (z1[ii]!=0) continue;

    float smearing = ic2[ii]/ic3[ii];
    
    float forFill  = ic1[ii] - (1./smearing);

    H_check1->Fill(forFill);
    H_check2->Fill(smearing);
    H_check3->Fill(ic1[ii]);
    H_NewVsOld->Fill(ic1[ii], smearing); 
    H_NewVsOldz->Fill(ic1[ii], smearing); 
    H_vsEta->Fill(eta1[ii],forFill);
    H_vsPhi->Fill(phi1[ii],forFill);

    if (forFill>0.6) cout << eta1[ii] << endl;
  }

  gStyle->SetOptStat(1); 

  TCanvas c1m("c1m","",1);
  H_check1->SetTitle("");
  H_check1->GetXaxis()->SetTitle("newIC - 1./smearing");  
  H_check1 -> Draw();
  c1m.SaveAs("testPrecision.png");
  c1m.SaveAs("testPrecision.root");

  TCanvas c1ml("c1ml","",1);
  c1ml.SetLogy();
  H_check1->SetTitle("");
  H_check1->GetXaxis()->SetTitle("newIC - 1./smearing");  
  H_check1 -> Draw();
  c1ml.SaveAs("testPrecisionLog.png");
  c1ml.SaveAs("testPrecisionLog.root");

  TCanvas c2m("c2m","",1);
  H_check2->SetTitle("");
  H_check2->GetXaxis()->SetTitle("ICreco/ICmc");  
  H_check2 -> Draw();
  c2m.SaveAs("testPrecision2.png");
  c2m.SaveAs("testPrecision2.root");

  TCanvas c3m("c3m","",1);
  H_check3->SetTitle("");
  H_check3->GetXaxis()->SetTitle("newIC");  
  H_check3 -> Draw();
  c3m.SaveAs("testPrecision3.png");
  c3m.SaveAs("testPrecision3.root");

  gStyle->SetOptStat(0);

  TCanvas c4m("c4m","",1);
  H_NewVsOld->SetTitle("");
  H_NewVsOld->GetXaxis()->SetTitle("newIC");
  H_NewVsOld->GetYaxis()->SetTitle("ICreco/ICmc");
  H_NewVsOld -> Draw("colz");
  c4m.SaveAs("testPrecision_corr.png");
  c4m.SaveAs("testPrecision_corr.root");

  TCanvas c5m("c5m","",1);
  H_NewVsOldz->SetTitle("");
  H_NewVsOldz->GetXaxis()->SetTitle("newIC");
  H_NewVsOldz->GetYaxis()->SetTitle("ICreco/ICmc");
  H_NewVsOldz -> Draw("colz");
  c5m.SaveAs("testPrecision_corrZoom.png");
  c5m.SaveAs("testPrecision_corrZoom.root");

  TCanvas c6m("c6m","",1);
  H_vsEta->SetTitle("");
  H_vsEta->GetXaxis()->SetTitle("iEta");
  H_vsEta->GetYaxis()->SetTitle("newIC - 1./smearing");
  H_vsEta -> Draw("colz");
  c6m.SaveAs("testPrecision_vsEta.png");
  c6m.SaveAs("testPrecision_vsEta.root");

  TCanvas c7m("c7m","",1);
  H_vsPhi->SetTitle("");
  H_vsPhi->GetXaxis()->SetTitle("iPhi");
  H_vsPhi->GetYaxis()->SetTitle("newIC - 1./smearing");
  H_vsPhi -> Draw("colz");
  c7m.SaveAs("testPrecision_vsPhi.png");
  c7m.SaveAs("testPrecision_vsPhi.root");
}
