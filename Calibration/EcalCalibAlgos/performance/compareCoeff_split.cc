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

void compareCoeff_split() {

  // 
  TH1F *H_check  = new TH1F("H_check", "",100, -2, 2);
  TH1F *H_checkz = new TH1F("H_checkz","",100, -0.02, 0.02);

  // my coeff odd
  char buffer1[5000];
  int IFC1 = 0;
  int eta1[80000];
  int phi1[80000];
  float ic1[80000];
  
  // my coeff even
  char buffer2[5000];
  int IFC2 = 0;
  int eta2[80000];
  int phi2[80000];
  float ic2[80000];

  ifstream *inFile1 = new ifstream("../test/debug_even_ring/barrel_formatted.txt");
  while( !(inFile1->eof()) ){
    inFile1->getline(buffer1,800);
    if (!strstr(buffer1,"#") && !(strspn(buffer1," ") == strlen(buffer1))){
      sscanf(buffer1,"%d %d %f", &eta1[IFC1], &phi1[IFC1], &ic1[IFC1]);
      IFC1++;
    }
  }
  inFile1->close();
  delete inFile1;
  std::cout << "ok file1" << std::endl;

  ifstream *inFile2 = new ifstream("../test/debug_odd_ring/barrel_formatted.txt");
  while( !(inFile2->eof()) ){
    inFile2->getline(buffer2,800);
    if (!strstr(buffer2,"#") && !(strspn(buffer2," ") == strlen(buffer2))){
      sscanf(buffer2,"%d %d %f", &eta2[IFC2], &phi2[IFC2], &ic2[IFC2]);
      IFC2++;
    }
  }
  inFile2->close();
  delete inFile2;
  std::cout << "ok file2" << std::endl;

  if (IFC1 != IFC2) cout << "big problem!" << endl;

  for (int ii=0; ii<IFC1; ii++) {

    if (eta1[ii] != eta2[ii]) cout << "ii " << ii << ": eta is different" << endl; 
    if (phi1[ii] != phi2[ii]) cout << "ii " << ii << ": phi is different" << endl; 

    if (eta1[ii]==85 && phi1[ii]==360) cout << ic1[ii] << " " << ic2[ii] << endl;
    float diff = ic1[ii] - ic2[ii];
    H_check->Fill(diff);
    H_checkz->Fill(diff);
  }

  gStyle->SetOptStat(111111); 

  TCanvas c1m("c1m","",1);
  H_check->SetTitle("");
  H_check->GetXaxis()->SetTitle("ICodd - ICeven");  
  H_check -> Draw();
  c1m.SetLogy();
  c1m.SaveAs("testPrecisionSplitLog.png");

  TCanvas c2m("c2m","",1);
  H_checkz->SetTitle("");
  H_checkz->GetXaxis()->SetTitle("ICodd - ICeven");  
  H_checkz -> Draw();
  c2m.SaveAs("testPrecisionSplitZoom.png");
}
