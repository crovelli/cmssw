// -*- C++ -*-
//-----------------------------------------------------------------------
//
// Package:    
//      HiggsAnalysis/HiggsToWW2e
// Description:
//      Class CmsRunInfoFiller
//      Simple class for dumping RECO (or AOD) contents to a ROOT tree
//      
// Original Author:  Emanuele Di Marco
//         Created:  Mon Nov  14 11:15:34 CEST 2008
//
//-----------------------------------------------------------------------

#ifndef CmsRunInfoFiller_h
#define CmsRunInfoFiller_h

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "HiggsAnalysis/HiggsToWW2e/interface/CmsTree.h"

struct CmsRunInfoFillerData {

  int *nl1Global, *nl1Technical;
  vector<int> *l1Global, *l1Technical;
  int *run, *lumisection, *bx, *orbit;
  uint64_t *event;
  // pileup info
  int *nBX;
  vector<int> *nInteractions, *bxPU;

  //beamspot
  double *beamSpotX,*beamSpotY, *beamSpotZ;

  int isMC_;

public:
  void initialise();
  void clearVectors();
  void setMC(bool what) { isMC_ = what; }
};

class CmsRunInfoFiller {

public:
  
  CmsRunInfoFiller(CmsTree *tree, bool isMC, bool is8TeV);
  virtual ~CmsRunInfoFiller();

  void dumpL1Trigger(bool what) { dumpL1_ = what; }
  void dumpLogErrorFlags(bool what) { dumpLogErrorFlags_ = what; }
  void writeRunInfoToTree(const edm::Event&, const edm::EventSetup&, 
                          bool dumpData=false);
  void is8TeV(bool what) { is8TeV_ = what; }

protected:

  void treeRunInfo();

  CmsRunInfoFillerData *privateData_;
  
  CmsTree *cmstree;
  bool isMC_;
  bool is8TeV_;
  bool dumpL1_;
  bool dumpLogErrorFlags_;

};

#endif // CmsRunInfoFiller_h
