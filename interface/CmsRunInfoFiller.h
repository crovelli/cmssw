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

  int *run, *lumisection, *event, *bx, *orbit;
  
public:
  void initialise();
};

class CmsRunInfoFiller {

public:
  
  CmsRunInfoFiller(CmsTree *tree);
  virtual ~CmsRunInfoFiller();

  void writeRunInfoToTree(const edm::Event&, const edm::EventSetup&, 
                          bool dumpData=false);

protected:

  void treeRunInfo();

  CmsRunInfoFillerData *privateData_;
  
  CmsTree *cmstree;

};

#endif // CmsRunInfoFiller_h
