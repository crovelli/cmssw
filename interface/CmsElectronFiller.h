// -*- C++ -*-
//-----------------------------------------------------------------------
//
// Package:    
//      HiggsAnalysis/HiggsToWW2e
// Description:
//      Class CmsElectronFiller
//      Simple class for dumping RECO (or AOD) contents to a ROOT tree
//      
// Original Author:  Emanuele Di Marco
//         Created:  Fri Apr  6 18:05:34 CEST 2007
//
//-----------------------------------------------------------------------

#ifndef CmsElectronFiller_h
#define CmsElectronFiller_h

#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"

#include "HiggsAnalysis/HiggsToWW2e/interface/CmsTree.h"
#include "HiggsAnalysis/HiggsToWW2e/interface/CmsCandidateFiller.h"
#include <TTree.h>

struct CmsElectronFillerData : public CmsCandidateFillerData {

  // All the vectors that will store the stuff
  // going into the tree.

  vector<float> *pxAtInner, *pyAtInner, *pzAtInner, *xAtInner, *yAtInner, *zAtInner;
  vector<float> *pxAtOuter, *pyAtOuter, *pzAtOuter, *xAtOuter, *yAtOuter, *zAtOuter;
  vector<float> *eleTrackNormalizedChi2;
  vector<float> *eleTrackDxy, *eleTrackD0, *eleTrackDsz, *eleTrackDz;
  vector<float> *eleTrackDxyError, *eleTrackD0Error, *eleTrackDszError, *eleTrackDzError;
  vector<float> *eleTrackValidHits, *eleTrackLostHits;
  vector<float> *eleTrackVx, *eleTrackVy, *eleTrackVz; 

  vector<int> *fiducialFlags;
  vector<int> *recoFlags;

  vector<float> *ecal, *eraw, *esEnergy, *caloEta, *caloPhi;
  vector<int> *energyCorrections;

  vector<int> *nClu, *nCry;
  vector<float> *e2x2, *e3x3, *e5x5;
  vector<float> *eMax, *e2nd;
  vector<float> *s1s9, *s9s25;
  vector<float> *covEtaEta, *covEtaPhi, *covPhiPhi;
  vector<float> *covIEtaIEta, *covIEtaIPhi, *covIPhiIPhi;
  vector<float> *lat, *phiLat, *etaLat, *a20, *a42;
  
public:
  void initialise();
  void clearTrkVectors();


};

class CmsElectronFiller : public CmsCandidateFiller {

 public:

  //! Dump everything
  CmsElectronFiller(CmsTree *, int maxTracks=500,
		int maxMCTracks=2000, bool noOutputIfLimitsReached=false );

  //! Dump  everything if fatTree is true and less informations otherwise
  CmsElectronFiller(CmsTree *, bool fatTree, int maxTracks=500,
		int maxMCTracks=2000, bool noOutputIfLimitsReached=false );


  //! Destructor
  virtual ~CmsElectronFiller();

  //! dump tracking related variables
  void saveTrk(bool );
  //! dump ECAL related variables
  void saveEcal(bool );
  //! dump more tracking related variables
  void saveFatTrk(bool );
  //! dump more ECAL related variables
  void saveFatEcal(bool );
  //! dump electron ID variables
  void saveEleID(bool );

  //! write the electron related informations for the given collection
  void writeCollectionToTree(edm::InputTag collectionTag,
			     const edm::Event&, const edm::EventSetup&,
			     const std::string &columnPrefix, const std::string &columnSuffix,
			     bool dumpData=false);

  //! set the rechits for ECAL barrel (needed for cluster shapes)
  void setEcalBarrelRecHits( edm::InputTag EcalBarrelRecHits ) { EcalBarrelRecHits_ = EcalBarrelRecHits; }
  //! set the rechits for ECAL endcap (needed for cluster shapes)
  void setEcalEndcapRecHits( edm::InputTag EcalEndcapRecHits ) { EcalEndcapRecHits_ = EcalEndcapRecHits; }
  //! set the tracker isolation producer
  void setTkIsolationProducer( edm::InputTag tkIsolationProducer ) { tkIsolationProducer_ = tkIsolationProducer; }
  //! set the HCAL isolation producer with calo towers
  void setTowerIsolationProducer( edm::InputTag towerIsolationProducer ) { towerIsolationProducer_ = towerIsolationProducer; }
  //! set the track producer for tracker isolation
  void setTracksProducer( edm::InputTag tracksProducer ) { tracksProducer_ = tracksProducer; }
  //! set the calotower producer for calorimetric isolation
  void setCalotowersProducer( edm::InputTag calotowersProducer ) { calotowersProducer_ = calotowersProducer; }


 private:
  
  void writeTrkInfo(const reco::GsfElectronRef, const edm::Event&, const edm::EventSetup&, reco::GsfTrackRef trkRef);
  void treeTrkInfo(const std::string &colPrefix, const std::string &colSuffix);

  void writeEcalInfo(const reco::GsfElectronRef, const edm::Event&, const edm::EventSetup&, reco::SuperClusterRef sclusRef,
		     const EcalRecHitCollection *EBRecHits, const EcalRecHitCollection *EERecHits);
  void treeEcalInfo(const std::string &colPrefix, const std::string &colSuffix);


  bool saveTrk_;
  bool saveEcal_;
  bool saveFatTrk_;
  bool saveFatEcal_;
  bool saveEleID_;

  bool hitLimitsMeansNoOutput_;
  int maxTracks_;
  int maxMCTracks_;

  std::string *trkIndexName_;

  CmsElectronFillerData *privateData_;
  edm::InputTag matchMap_;

  edm::InputTag EcalBarrelRecHits_;
  edm::InputTag EcalEndcapRecHits_;

  edm::InputTag electronIdCutsLabel_;
  edm::InputTag electronIdLikelihoodLabel_;
  edm::InputTag tkIsolationProducer_;
  edm::InputTag towerIsolationProducer_;

  edm::InputTag tracksProducer_;
  edm::InputTag calotowersProducer_;

  CmsTree *cmstree;


};

#endif // CmsElectronFiller_h
