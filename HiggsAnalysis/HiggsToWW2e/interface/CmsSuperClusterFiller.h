// -*- C++ -*-
//-----------------------------------------------------------------------
//
// Package:    
//      HiggsAnalysis/HiggsToWW2e
// Description:
//      Class CmsSuperClusterFiller
//      Simple class for dumping RECO (or AOD) contents to a ROOT tree
//      
// Original Author:  Emanuele Di Marco
//         Created:  Fri Apr  6 18:05:34 CEST 2007
//
//-----------------------------------------------------------------------

#ifndef CmsSuperClusterFiller_h
#define CmsSuperClusterFiller_h

#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/CaloRecHit/interface/CaloCluster.h"
#include "DataFormats/EgammaReco/interface/BasicCluster.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"

#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/CaloTopology/interface/CaloTopology.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "Geometry/CaloEventSetup/interface/CaloTopologyRecord.h"

#include "HiggsAnalysis/HiggsToWW2e/interface/CmsTree.h"

#include "RecoEcal/EgammaCoreTools/interface/EcalClusterFunctionFactory.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterFunctionBaseClass.h"
#include "CondFormats/EcalObjects/interface/EcalFunctionParameters.h" 

#include "RecoEcal/EgammaCoreTools/interface/PositionCalc.h"

#include <TTree.h>

struct CmsSuperClusterFillerData {
  // All the vectors that will store the stuff
  // going into the tree.
  vector<int>  *nBC, *nCrystals;
  vector<float> *rawEnergy, *energy, *esEnergy, *seedClusterEnergy, *phiWidth, *etaWidth, *eta, *theta, *phi;
  vector<float> *seedEnergy, *seedX, *seedY,*xPos,*yPos,*zPos;
  vector<float> *e3x3, * e5x5, *eMax, *e2x2, *e2nd, *covIEtaIEta, *covIEtaIPhi, *covIPhiIPhi,
    *e1x5, *e2x5Max, *e4SwissCross,*e3x1,*e1x3,*e4x4;
  vector<float> *e2x5Left, *e2x5Right, *e2x5Top, *e2x5Bottom, *eLeft, *eRight, *eTop, *eBottom;
  vector<float> *esEffsIxIx, *esEffsIyIy, *esL1Energy, *esL2Energy;
  vector<int> *esL1Strips, *esL2Strips;
//   vector<float> *etaC,*etaS,*etaM,*phiC,*phiS,*phiM;
//   vector<float> *xZ,*xC,*xS,*xM,*yZ,*yC,*yS,*yM;

  vector<float> *hOverE;
  int *nSC;

public:
  void initialiseCandidate();
  void clear();
};


class CmsSuperClusterFiller {

public:

  // Constructors

  // Dump everything
  CmsSuperClusterFiller(CmsTree *, int maxSC=500);


  // Destructor
  virtual ~CmsSuperClusterFiller();

  // Operators

  // run number and all of that --- to implement

  virtual void writeCollectionToTree(edm::InputTag collectionTag,
				     const edm::Event&, const edm::EventSetup&,
				     const std::string &columnPrefix, const std::string &columnSuffix,
				     bool dumpData=false);

  //! set the calotowers collection (to calculate H/E)
  void setCalotowers( edm::InputTag Calotowers ) { Calotowers_ = Calotowers; }
  //! set the rechits for ECAL barrel (needed for cluster shapes)
  void setEcalBarrelRecHits( edm::InputTag EcalBarrelRecHits ) { EcalBarrelRecHits_ = EcalBarrelRecHits; }
  //! set the rechits for ECAL endcap (needed for cluster shapes)
  void setEcalEndcapRecHits( edm::InputTag EcalEndcapRecHits ) { EcalEndcapRecHits_ = EcalEndcapRecHits; }
  //! set the rechits for preshower (needed for cluster shapes)
  void setESRecHits( edm::InputTag ESRecHits ) { ESRecHits_ = ESRecHits; }

protected:
  virtual void writeSCInfo(const reco::SuperCluster *cand, 
			   const edm::Event&, const edm::EventSetup&,
                           const EcalRecHitCollection *EBRecHits, const EcalRecHitCollection *EERecHits,
                           const EcalRecHitCollection *ESRecHits);

  virtual void treeSCInfo(const std::string colPrefix, const std::string colSuffix);
  
  // Friends

  CmsSuperClusterFillerData *privateData_;

  CmsTree *cmstree;

  edm::InputTag EcalBarrelRecHits_;
  edm::InputTag EcalEndcapRecHits_;
  edm::InputTag ESRecHits_;
  edm::InputTag Calotowers_;

  edm::Handle<CaloTowerCollection> calotowers_;

  enum tracktype { track, gsftrack };

  int maxSC_;
  std::string *trkIndexName_;

  std::map<DetId, EcalRecHit> es_rechits_map_;
};

#endif // CmsSuperClusterFiller_h
