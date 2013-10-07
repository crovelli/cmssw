// -*- C++ -*-
//
// Package:    EcalAnomalousEventFilter
// Class:      EcalAnomalousEventFilter
//
/**\class EcalAnomalousEventFilter EcalAnomalousEventFilter.cc PhysicsTools/EcalAnomalousEventFilter/src/EcalAnomalousEventFilter.cc

 Description: <one line class summary>
 Event filtering for anomalous ECAL events where the energy measured by ECAL is significantly biased due to energy depositions
 in passive or problematic detector regions. The filter will handle ECAL flags and will compute the boundary energy in the channels
 surrounding the problematic regions such as dead channels and gaps.

 // Filter Algos :
 // a)  "TuningMode" keep all events and save event info in a ROOT TTree for tuning/algo development
 // b)  "FilterMode" returns false for all events passing the AnomalousEcalVariables.isDeadEcalCluster() function (--->rejects events affected by energy deposits in Dead Cells)

 Implementation:
 <Notes on implementation>
 */
//
// Original Author:  Konstantinos Theofilatos, Ulla Gebbert and Christian Sander
//         Created:  Sat Nov 14 18:43:21 CET 2009
// $Id: EcalAnomalousEventFilter.cc,v 1.11 2011/05/23 18:42:16 csander Exp $
//
//


// system include files
#include <memory>
#include <fstream>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDFilter.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/EcalRecHit/interface/EcalRecHit.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"

#include "CondFormats/EcalObjects/interface/EcalChannelStatus.h"
#include "CondFormats/DataRecord/interface/EcalChannelStatusRcd.h"

#include "Geometry/CaloEventSetup/interface/CaloTopologyRecord.h"
#include "Geometry/Records/interface/IdealGeometryRecord.h"
#include "Geometry/CaloTopology/interface/CaloTopology.h"
#include "Geometry/CaloTopology/interface/CaloSubdetectorTopology.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"

#include "PhysicsTools/EcalAnomalousEventFilter/interface/EcalBoundaryInfoCalculator.h"
#include "DataFormats/METReco/interface/AnomalousECALVariables.h"

class EcalAnomalousEventFilter: public edm::EDFilter {
   public:
      explicit EcalAnomalousEventFilter(const edm::ParameterSet&);
      ~EcalAnomalousEventFilter();

   private:
      virtual void beginJob();
      virtual bool filter(edm::Event&, const edm::EventSetup&);
      virtual void endJob();

      // ----------member data ---------------------------
      edm::InputTag EBRecHitsLabel_;
      edm::InputTag EERecHitsLabel_;

      std::string FilterAlgo_;

      const int kMAX;
      int i_EBDead, i_EEDead, i_EBGap, i_EEGap;
      float * enNeighboursGap_EB;
      float * enNeighboursGap_EE;

      vector<BoundaryInformation> v_enNeighboursGap_EB;
      vector<BoundaryInformation> v_enNeighboursGap_EE;

      vector<BoundaryInformation> v_boundaryInfoDeadCells_EB;
      vector<BoundaryInformation> v_boundaryInfoDeadCells_EE;

      double cutBoundEnergyGapEE;
      double cutBoundEnergyGapEB;
      double cutBoundEnergyDeadCellsEB;
      double cutBoundEnergyDeadCellsEE;

      EcalBoundaryInfoCalculator<EBDetId> ebBoundaryCalc;
      EcalBoundaryInfoCalculator<EEDetId> eeBoundaryCalc;

      bool debug_;

      bool skimGap_;
      bool skimDead_;

      double maxBoundaryEnergy_;

      bool limitFilterToEB_, limitFilterToEE_;
      vector<int> limitDeadCellToChannelStatusEB_;
      vector<int> limitDeadCellToChannelStatusEE_;

      bool enableGap_;
      ofstream *outFile;

};

//
// static data member definitions
//

//
// constructors and destructor
//
EcalAnomalousEventFilter::EcalAnomalousEventFilter(const edm::ParameterSet& iConfig) :
   kMAX(50) {
   cout << "Constructor EcalAnomalousEvent" << endl;

   //now do what ever initialization is needed
   EBRecHitsLabel_ = iConfig.getParameter<edm::InputTag> ("recHitsEB");
   EERecHitsLabel_ = iConfig.getParameter<edm::InputTag> ("recHitsEE");

   FilterAlgo_ = iConfig.getUntrackedParameter<std::string> ("FilterAlgo", "TuningMode");
   skimGap_ = iConfig.getUntrackedParameter<bool> ("skimGap", false);
   skimDead_ = iConfig.getUntrackedParameter<bool> ("skimDead", false);
   if (skimGap_)
      cout << "Skim Gap!" << endl;
   if (skimDead_)
      cout << "Skim Dead!" << endl;

   cutBoundEnergyGapEB = iConfig.getUntrackedParameter<double> ("cutBoundEnergyGapEB");
   cutBoundEnergyGapEE = iConfig.getUntrackedParameter<double> ("cutBoundEnergyGapEE");
   cutBoundEnergyDeadCellsEB = iConfig.getUntrackedParameter<double> ("cutBoundEnergyDeadCellsEB");
   cutBoundEnergyDeadCellsEE = iConfig.getUntrackedParameter<double> ("cutBoundEnergyDeadCellsEE");

   maxBoundaryEnergy_ = cutBoundEnergyDeadCellsEB;

   limitFilterToEB_ = iConfig.getUntrackedParameter<bool> ("limitFilterToEB", false);
   limitFilterToEE_ = iConfig.getUntrackedParameter<bool> ("limitFilterToEE", false);
   limitDeadCellToChannelStatusEB_ = iConfig.getParameter<vector<int> > ("limitDeadCellToChannelStatusEB");
   limitDeadCellToChannelStatusEE_ = iConfig.getParameter<vector<int> > ("limitDeadCellToChannelStatusEE");

   enableGap_ = iConfig.getUntrackedParameter<bool> ("enableGap", false);

   i_EBDead = 0;
   i_EEDead = 0;
   i_EBGap = 0;
   i_EEGap = 0;

   v_enNeighboursGap_EB.clear();
   v_enNeighboursGap_EE.clear();
   v_enNeighboursGap_EB.reserve(50);
   v_enNeighboursGap_EE.reserve(50);

   v_boundaryInfoDeadCells_EB.reserve(50);
   v_boundaryInfoDeadCells_EE.reserve(50);
   v_boundaryInfoDeadCells_EB.clear();
   v_boundaryInfoDeadCells_EE.clear();

   debug_ = false;

   if (FilterAlgo_ == "TuningMode") {
      produces<AnomalousECALVariables> ("anomalousECALVariables");
   }
}

EcalAnomalousEventFilter::~EcalAnomalousEventFilter() {
   //cout << "destructor Filter" << endl;
}

// ------------ method called on each new Event  ------------
bool EcalAnomalousEventFilter::filter(edm::Event& iEvent, const edm::EventSetup& iSetup) {
   using namespace edm;

   //int eventno = (int) iEvent.eventAuxiliary().event();

   v_enNeighboursGap_EB.clear();
   v_enNeighboursGap_EE.clear();

   v_boundaryInfoDeadCells_EB.clear();
   v_boundaryInfoDeadCells_EE.clear();

   // Get the Ecal RecHits
   Handle<EcalRecHitCollection> EBRecHits;
   iEvent.getByLabel(EBRecHitsLabel_, EBRecHits);
   Handle<EcalRecHitCollection> EERecHits;
   iEvent.getByLabel(EERecHitsLabel_, EERecHits);

   edm::ESHandle<CaloTopology> theCaloTopology;
   iSetup.get<CaloTopologyRecord> ().get(theCaloTopology);

   edm::ESHandle<EcalChannelStatus> ecalStatus;
   iSetup.get<EcalChannelStatusRcd> ().get(ecalStatus);

   edm::ESHandle<CaloGeometry> geometry;
   iSetup.get<CaloGeometryRecord> ().get(geometry);

   i_EBDead = 0;
   i_EEDead = 0;
   i_EBGap = 0;
   i_EEGap = 0;

   vector<DetId> sameFlagDetIds;

   if (!limitFilterToEE_) {

      if (debug_)
         cout << "process EB" << endl;

      for (EcalRecHitCollection::const_iterator hit = EBRecHits->begin(); hit != EBRecHits->end(); ++hit) {

         bool detIdAlreadyChecked = false;
         DetId currDetId = (DetId) hit->id();
         //add limitation to channel stati
         EcalChannelStatus::const_iterator chit = ecalStatus->find(currDetId);
         int status = (chit != ecalStatus->end()) ? chit->getStatusCode() & 0x1F : -1;
         if (status != 0)
            continue;
         bool passChannelLimitation = false;

         // check if hit has a dead neighbour
         vector<int> deadNeighbourStati;
         ebBoundaryCalc.checkRecHitHasDeadNeighbour(*hit, ecalStatus, deadNeighbourStati);

         for (int cs = 0; cs < (int) limitDeadCellToChannelStatusEB_.size(); ++cs) {
            int channelAllowed = limitDeadCellToChannelStatusEB_[cs];

            for (vector<int>::iterator sit = deadNeighbourStati.begin(); sit != deadNeighbourStati.end(); ++sit) {
               //cout << "Neighbouring dead channel with status: " << *sit << endl;
               if (channelAllowed == *sit || (channelAllowed < 0 && abs(channelAllowed) <= *sit)) {
                  passChannelLimitation = true;
                  break;
               }
            }
         }

         for (vector<DetId>::iterator it = sameFlagDetIds.begin(); it != sameFlagDetIds.end(); it++) {
            if (currDetId == *it)
               detIdAlreadyChecked = true;
         }

         // RecHit is at EB boundary and should be processed
         if (!detIdAlreadyChecked && deadNeighbourStati.size() == 0 && ebBoundaryCalc.checkRecHitHasInvalidNeighbour(
               *hit, ecalStatus)) {

            if (debug_)
               ebBoundaryCalc.setDebugMode();
            BoundaryInformation gapinfo = ebBoundaryCalc.gapRecHits(
                  (const edm::Handle<EcalRecHitCollection>&) EBRecHits, (const EcalRecHit *) &(*hit), theCaloTopology,
                  ecalStatus, geometry);

            // get rechits along gap cluster
            for (vector<DetId>::iterator it = gapinfo.detIds.begin(); it != gapinfo.detIds.end(); it++) {
               sameFlagDetIds.push_back(*it);
            }

            if (gapinfo.boundaryEnergy > cutBoundEnergyGapEB) {

               i_EBGap++;
               v_enNeighboursGap_EB.push_back(gapinfo);

               if (debug_)
                  cout << "EB: gap cluster energy: " << gapinfo.boundaryEnergy << " deadCells: "
                        << gapinfo.detIds.size() << endl;
            }
         }

         // RecHit is member of boundary and should be processed
         if (!detIdAlreadyChecked && (passChannelLimitation || (limitDeadCellToChannelStatusEB_.size() == 0
               && deadNeighbourStati.size() > 0))) {

            if (debug_)
               ebBoundaryCalc.setDebugMode();
            BoundaryInformation boundinfo = ebBoundaryCalc.boundaryRecHits(
                  (const edm::Handle<EcalRecHitCollection>&) EBRecHits, (const EcalRecHit *) &(*hit), theCaloTopology,
                  ecalStatus, geometry);

            // get boundary of !kDead rechits arround the dead cluster
            for (vector<DetId>::iterator it = boundinfo.detIds.begin(); it != boundinfo.detIds.end(); it++) {
               sameFlagDetIds.push_back(*it);
            }

            if (boundinfo.boundaryEnergy > cutBoundEnergyDeadCellsEB) {

               i_EBDead++;
               v_boundaryInfoDeadCells_EB.push_back(boundinfo);

               if (debug_)
                  cout << "EB: boundary Energy dead RecHit: " << boundinfo.boundaryEnergy << " ET: "
                        << boundinfo.boundaryET << " deadCells: " << boundinfo.detIds.size() << endl;
            }

         }
      }

   } //// End of EB

   sameFlagDetIds.clear();

   if (!limitFilterToEB_) {

      if (debug_)
         cout << "process EE" << endl;

      for (EcalRecHitCollection::const_iterator hit = EERecHits->begin(); hit != EERecHits->end(); ++hit) {

         bool detIdAlreadyChecked = false;
         DetId currDetId = (DetId) hit->id();
         //add limitation to channel stati
         EcalChannelStatus::const_iterator chit = ecalStatus->find(currDetId);
         int status = (chit != ecalStatus->end()) ? chit->getStatusCode() & 0x1F : -1;
         if (status != 0)
            continue;
         bool passChannelLimitation = false;

         // check if hit has a dead neighbour
         vector<int> deadNeighbourStati;
         eeBoundaryCalc.checkRecHitHasDeadNeighbour(*hit, ecalStatus, deadNeighbourStati);

         for (int cs = 0; cs < (int) limitDeadCellToChannelStatusEE_.size(); ++cs) {
            int channelAllowed = limitDeadCellToChannelStatusEE_[cs];

            for (vector<int>::iterator sit = deadNeighbourStati.begin(); sit != deadNeighbourStati.end(); ++sit) {
               //cout << "Neighbouring dead channel with status: " << *sit << endl;
               if (channelAllowed == *sit || (channelAllowed < 0 && abs(channelAllowed) <= *sit)) {
                  passChannelLimitation = true;
                  break;
               }
            }
         }

         for (vector<DetId>::iterator it = sameFlagDetIds.begin(); it != sameFlagDetIds.end(); it++) {
            if (currDetId == *it)
               detIdAlreadyChecked = true;
         }

         // RecHit is at EE boundary and should be processed
         const CaloSubdetectorGeometry* subGeom = geometry->getSubdetectorGeometry(currDetId);
         const CaloCellGeometry* cellGeom = subGeom->getGeometry(currDetId);
         double eta = cellGeom->getPosition().eta();

         if (!detIdAlreadyChecked && deadNeighbourStati.size() == 0 && eeBoundaryCalc.checkRecHitHasInvalidNeighbour(
               *hit, ecalStatus) && abs(eta) < 1.6) {

            if (debug_)
               eeBoundaryCalc.setDebugMode();
            BoundaryInformation gapinfo = eeBoundaryCalc.gapRecHits(
                  (const edm::Handle<EcalRecHitCollection>&) EERecHits, (const EcalRecHit *) &(*hit), theCaloTopology,
                  ecalStatus, geometry);

            // get rechits along gap cluster
            for (vector<DetId>::iterator it = gapinfo.detIds.begin(); it != gapinfo.detIds.end(); it++) {
               sameFlagDetIds.push_back(*it);
            }

            if (gapinfo.boundaryEnergy > cutBoundEnergyGapEE) {

               i_EEGap++;
               v_enNeighboursGap_EE.push_back(gapinfo);

               if (debug_)
                  cout << "EE: gap cluster energy: " << gapinfo.boundaryEnergy << " deadCells: "
                        << gapinfo.detIds.size() << endl;
            }
         }

         // RecHit is member of boundary and should be processed
         if (!detIdAlreadyChecked && (passChannelLimitation || (limitDeadCellToChannelStatusEE_.size() == 0
               && deadNeighbourStati.size() > 0))) {

            if (debug_)
               eeBoundaryCalc.setDebugMode();
            BoundaryInformation boundinfo = eeBoundaryCalc.boundaryRecHits(
                  (const edm::Handle<EcalRecHitCollection>&) EERecHits, (const EcalRecHit *) &(*hit), theCaloTopology,
                  ecalStatus, geometry);

            // get boundary of !kDead rechits arround the dead cluster
            for (vector<DetId>::iterator it = boundinfo.detIds.begin(); it != boundinfo.detIds.end(); it++) {
               sameFlagDetIds.push_back(*it);
            }

            if (boundinfo.boundaryEnergy > cutBoundEnergyDeadCellsEE) {

               i_EEDead++;
               v_boundaryInfoDeadCells_EE.push_back(boundinfo);

               if (debug_)
                  cout << "EE: boundary Energy dead RecHit: " << boundinfo.boundaryEnergy << " ET: "
                        << boundinfo.boundaryET << " deadCells: " << boundinfo.detIds.size() << endl;

               //               for (vector<DetId>::iterator it = boundinfo.detIds.begin(); it != boundinfo.detIds.end(); it++) {
               //                  cout << (EEDetId) * it << endl;
               //               }

            }

         }
      }

   } //// End of EE

   sameFlagDetIds.clear();

   if (FilterAlgo_ == "TuningMode") {
      std::auto_ptr<AnomalousECALVariables> pAnomalousECALVariables(new AnomalousECALVariables(v_enNeighboursGap_EB,
            v_enNeighboursGap_EE, v_boundaryInfoDeadCells_EB, v_boundaryInfoDeadCells_EE));
      iEvent.put(pAnomalousECALVariables, "anomalousECALVariables");

      if (skimDead_ && (i_EBDead >= 1 || i_EEDead >= 1)) {
         return true;
      } else if (skimGap_ && (i_EBGap >= 1 || i_EEGap >= 1)) {
         return true;
      } else if (!skimDead_ && !skimGap_)
         return true;
      else {
         return false;
      }
   }

   if (FilterAlgo_ == "FilterMode") {
      std::auto_ptr<AnomalousECALVariables> pAnomalousECALVariables(new AnomalousECALVariables(v_enNeighboursGap_EB,
            v_enNeighboursGap_EE, v_boundaryInfoDeadCells_EB, v_boundaryInfoDeadCells_EE));

      bool isGap = pAnomalousECALVariables->isGapEcalCluster(cutBoundEnergyGapEB, cutBoundEnergyGapEE);
      bool isBoundary = pAnomalousECALVariables->isDeadEcalCluster(maxBoundaryEnergy_, limitDeadCellToChannelStatusEB_,
            limitDeadCellToChannelStatusEE_);

      bool result = (!isBoundary && ((!isGap && enableGap_) || !enableGap_));
      if (!result) {
         (*outFile) << iEvent.id().run() << ":" << iEvent.id().luminosityBlock() << ":" << iEvent.id().event() << std::endl;
      }
      return result;
   }

   return true;
}

// ------------ method called once each job just before starting event loop  ------------
void EcalAnomalousEventFilter::beginJob() {
   outFile = new ofstream("./filteredEventsBE.txt");
}

// ------------ method called once each job just after ending the event loop  ------------
void EcalAnomalousEventFilter::endJob() {
   outFile->close();
}

//define this as a plug-in
DEFINE_FWK_MODULE( EcalAnomalousEventFilter);
