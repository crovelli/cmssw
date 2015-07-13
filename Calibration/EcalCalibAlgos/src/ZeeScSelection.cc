#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "DataFormats/Common/interface/Handle.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h" 
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h" 

#include "../interface/ZeeScSelection.h"

#include "TTree.h"
#include "TBranch.h"
#include "TFile.h"

#include <iostream>
#include "TLorentzVector.h"

#define MZ 91.1876

ZeeScSelection::ZeeScSelection(const edm::ParameterSet& iConfig) {

  // collections
  // ebSuperclusters_ = iConfig.getParameter<edm::InputTag> ("ebSuperclusters");  
  // eeSuperclusters_ = iConfig.getParameter<edm::InputTag> ("eeSuperclusters");  
  
  electrons_   = iConfig.getParameter<edm::InputTag> ("electrons");   
}

ZeeScSelection::~ZeeScSelection() { }

void ZeeScSelection::beginJob() { 
  
  myTree = fs_->make<TTree>("Ztree","Ztree");
  
  myTree->Branch("mass",   &(tree_.mass),   "mass/F");         // mass from ele
  myTree->Branch("massSc", &(tree_.massSc), "massSc/F");       // mass from SC
  myTree->Branch("massPsc",&(tree_.massPsc),"massPsc/F");      // mass from parent SC
  myTree->Branch("eta1",&(tree_.eta1),"eta1/F");
  myTree->Branch("eta2",&(tree_.eta2),"eta2/F");
  myTree->Branch("phi1",&(tree_.phi1),"phi1/F");
  myTree->Branch("phi2",&(tree_.phi2),"phi2/F");
  myTree->Branch("ene1",&(tree_.ene1),"ene1/F");
  myTree->Branch("ene2",&(tree_.ene2),"ene2/F");
  myTree->Branch("et1",&(tree_.et1),"et1/F");
  myTree->Branch("et2",&(tree_.et2),"et2/F");
  myTree->Branch("r91",&(tree_.r91),"r91/F");
  myTree->Branch("r92",&(tree_.r92),"r92/F");
}

void ZeeScSelection::endJob() { }

void ZeeScSelection::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup){

  /*
  // Get SuperClusters in EB
  Handle<SuperClusterCollection> pSuperClustersEB;
  try {
    iEvent.getByLabel(ebSuperclusters_, pSuperClustersEB);
  } catch (std::exception& ex) {
    std::cerr << "Error! can't get the product pSuperClustersEB " << std::endl;
  }
  const SuperClusterCollection* ebScCollection = pSuperClustersEB.product();

  // Get SuperClusters in EE      
  Handle<SuperClusterCollection> pSuperClustersEE;
  try {
    iEvent.getByLabel(eeSuperclusters_, pSuperClustersEE);
  } catch (std::exception& ex) {
    std::cerr << "Error! can't get the product pSuperClustersEE " << std::endl;
  }
  const SuperClusterCollection* eeScCollection = pSuperClustersEE.product();
  */

  // Get Electrons
  Handle<reco::GsfElectronCollection> pElectrons;   
  try {    
    iEvent.getByLabel(electrons_, pElectrons);   
  } catch (std::exception& ex) {    
    std::cerr << "Error! can't get the product pElectrons " << std::endl;  
  }
  const reco::GsfElectronCollection* eleCollection = pElectrons.product();  
  

  // Checks
  /*
  cout << "taken: " 
       << ebScCollection->size() << " sc in EB, " 
       << eeScCollection->size() << " sc in EE, " 
       << eleCollection->size()  << " electrons" << endl;
    
    std::cout<<"EB: ebScCollection->size() = " << ebScCollection->size() << std::endl;
    for(SuperClusterCollection::const_iterator scIt = ebScCollection->begin(); scIt != ebScCollection->end(); scIt++) {
      std::cout << scIt->energy() << " " << scIt->eta() << " " << scIt->phi() << std::endl;
    }
    std::cout<<"EE: eeScCollection->size() = " << eeScCollection->size() << std::endl;
    for(SuperClusterCollection::const_iterator scIt = eeScCollection->begin(); scIt != eeScCollection->end(); scIt++) {
      std::cout << scIt->energy() << " " << scIt->eta() << " " << scIt->phi() << std::endl;
    }
    std::cout <<"eleCollection->size() = " << eleCollection->size() << std::endl;
    for(GsfElectronCollection::const_iterator eleIt = eleCollection->begin(); eleIt !=eleCollection->end(); eleIt++) {
      std::cout << eleIt->energy() << " " << eleIt->eta() << " " << eleIt->phi() << std::endl; 
    }
    std::cout << std::endl;
  */


  /*
  if (ebScCollection || eeScCollection) {

    // at least 2 superclusters must be present
    if(  ( ebScCollection->size()+eeScCollection->size() ) >= 2) {


      // tree variables
      float mass;
      float eta1, eta2;
      float phi1, phi2;
      float ene1, ene2;
      initTreeStructure();

      // best pair
      const SuperCluster* sc1eb=0;
      const SuperCluster* sc2eb=0;
      const SuperCluster* sc1ee=0;
      const SuperCluster* sc2ee=0;
      const SuperCluster* sc1=0;
      const SuperCluster* sc2=0;
      
      // EB-EB
      float dMminEb = 9999;
      for(SuperClusterCollection::const_iterator scEbIt1 = ebScCollection->begin(); scEbIt1 != ebScCollection->end(); scEbIt1++) {
	for(SuperClusterCollection::const_iterator scEbIt2 = ebScCollection->begin(); scEbIt2 != ebScCollection->end(); scEbIt2++) {
	  if (scEbIt1==scEbIt2) continue;
      
	  float eta1 = scEbIt1->eta();
	  float phi1 = scEbIt1->phi();
	  float ene1 = scEbIt1->energy();
	  float eta2 = scEbIt2->eta();
	  float phi2 = scEbIt2->phi();
	  float ene2 = scEbIt2->energy();
	  float et1  = ene1*fabs(sin(scEbIt1->position().theta()));
	  float et2  = ene2*fabs(sin(scEbIt2->position().theta()));

	  // minimal selection
	  if (fabs(eta1)>2.5 || fabs(eta2)>2.5) continue;
	  if (et1<20 || et2<20) continue;
	  
	  float massT = invMassCalc(ene1,eta1,phi1,ene2,eta2,phi2);
	  if (massT<60 || massT>120) continue;
	  
	  if (fabs(massT-MZ)<dMminEb) {
	    dMminEb = fabs(massT-MZ);
	    sc1eb = &(*scEbIt1);
	    sc2eb = &(*scEbIt2);
	  }
	}
      }

      // EE-EE
      float dMminEe = 9999;
      for(SuperClusterCollection::const_iterator scEeIt1 = eeScCollection->begin(); scEeIt1 != eeScCollection->end(); scEeIt1++) {
	for(SuperClusterCollection::const_iterator scEeIt2 = eeScCollection->begin(); scEeIt2 != eeScCollection->end(); scEeIt2++) {
	  if (scEeIt1==scEeIt2) continue;
	  
	  float eta1 = scEeIt1->eta();
	  float phi1 = scEeIt1->phi();
	  float ene1 = scEeIt1->energy();
	  float eta2 = scEeIt2->eta();
	  float phi2 = scEeIt2->phi();
	  float ene2 = scEeIt2->energy();

	  // hardcoded
	  if (fabs(eta1)>2.5 || fabs(eta2)>2.5) continue;
	  if (ene1<20 || ene2<20) continue;

	  float massT = invMassCalc(ene1,eta1,phi1,ene2,eta2,phi2);
	  if (massT<60 || massT>120) continue;
  
	  if (fabs(massT-MZ)<dMminEe) {
	    dMminEe = fabs(massT-MZ);
	    sc1ee = &(*scEeIt1);
	    sc2ee = &(*scEeIt2);
	  }
	}
      }

      // at least one Z candidate found
      if (dMminEb<100 || dMminEe<100) {  
      
	// selected SCs
	if (dMminEb<dMminEe) {
	  sc1 = sc1eb;
	  sc2 = sc2eb;
	} else {
	  sc1 = sc1ee;
	  sc2 = sc2ee;
	}
	
	// Filling the tree
	eta1 = sc1->eta();
	eta2 = sc2->eta();
	phi1 = sc1->phi();
	phi2 = sc2->phi();
	ene1 = sc1->energy();
	ene2 = sc2->energy();
	mass = invMassCalc(ene1,eta1,phi1,ene2,eta2,phi2);  
	
	tree_.mass = mass;
	tree_.eta1 = eta1;
	tree_.eta2 = eta2;
	tree_.phi1 = phi1;
	tree_.phi2 = phi2;
	tree_.ene1 = ene1;
	tree_.ene2 = ene2;
	myTree->Fill();

	// cout << "dM: " << dMminEb << " " << dMminEe << " " << mass << endl;

      } // Z found     

    }   // ok superclusters
  }     // ok superclusters
  */

  if (eleCollection) {

    // at least 1 electron must be present
    if( eleCollection->size()>= 1 ) {

      // tree variables
      float mass;
      float massSc;
      float massPsc;
      float eta1, eta2;
      float phi1, phi2;
      float ene1, ene2;
      float et1, et2;
      float r91, r92;
      initTreeStructure();

      // best pair
      const GsfElectron* ele1=0;
      const GsfElectron* ele2=0;
      
      float dMmin = 9999;
      for(GsfElectronCollection::const_iterator eleIt1 = eleCollection->begin(); eleIt1 != eleCollection->end(); eleIt1++) {
	for(GsfElectronCollection::const_iterator eleIt2 = eleCollection->begin(); eleIt2 != eleCollection->end(); eleIt2++) {

	  if (eleIt1==eleIt2) continue;

	  if (!eleIt1->superCluster()) continue;
	  if (!eleIt2->superCluster()) continue;
	  if (!eleIt1->parentSuperCluster()) continue;
	  if (!eleIt2->parentSuperCluster()) continue;
      
	  float leta1 = eleIt1->eta();
	  float lphi1 = eleIt1->phi();
	  float let1  = eleIt1->et();
	  float lene1 = eleIt1->energy();
	  float leta2 = eleIt2->eta();
	  float lphi2 = eleIt2->phi();
	  float let2  = eleIt2->et();
	  float lene2 = eleIt2->energy();

	  // minimal selection
	  if (fabs(leta1)>2.5 || fabs(leta2)>2.5) continue;
	  if (let1<20 || let2<20) continue;
	  
	  float massT = invMassCalc(lene1,leta1,lphi1,lene2,leta2,lphi2);
	  if (massT<60 || massT>120) continue;
	  
	  if (fabs(massT-MZ)<dMmin) {
	    dMmin = fabs(massT-MZ);
	    ele1 = &(*eleIt1);
	    ele2 = &(*eleIt2);
	  }
	}
      }
    
      // at least one Z candidate found
      if (dMmin<100) {  
      
	// Filling the tree
	eta1    = ele1->eta();
	eta2    = ele2->eta();
	phi1    = ele1->phi();
	phi2    = ele2->phi();
	ene1    = ele1->energy();
	ene2    = ele2->energy();
	et1     = ele1->et();
	et2     = ele2->et();
	r91     = ele1->r9();
	r92     = ele2->r9();
	float eneSc1  = ele1->superCluster()->energy();
	float enePsc1 = ele1->parentSuperCluster()->energy();
	float eneSc2  = ele2->superCluster()->energy();
	float enePsc2 = ele2->parentSuperCluster()->energy();
	mass    = invMassCalc(ene1,eta1,phi1,ene2,eta2,phi2);  
	massSc  = invMassCalc(eneSc1,eta1,phi1,eneSc2,eta2,phi2);  
	massPsc = invMassCalc(enePsc1,eta1,phi1,enePsc2,eta2,phi2);  
	
	tree_.mass    = mass;
	tree_.massSc  = massSc;
	tree_.massPsc = massPsc;
	tree_.eta1 = eta1;
	tree_.eta2 = eta2;
	tree_.phi1 = phi1;
	tree_.phi2 = phi2;
	tree_.ene1 = ene1;
	tree_.ene2 = ene2;
	tree_.et1  = et1;
	tree_.et2  = et2;
	tree_.r91  = r91;
	tree_.r92  = r92;
	myTree->Fill();

	// cout << "dM: " << dMminEb << " " << dMminEe << " " << mass << endl;

      } // Z found     

    }   // ok superclusters
  }     // ok superclusters

}

void ZeeScSelection::initTreeStructure() {

  tree_.mass    = -500.;
  tree_.massSc  = -500.;
  tree_.massPsc = -500.;
  tree_.eta1 = -500.;
  tree_.eta2 = -500.;
  tree_.phi1 = -500.;
  tree_.phi2 = -500.;
  tree_.ene1 = -500.;
  tree_.ene2 = -500.;
  tree_.et1 = -500.;
  tree_.et2 = -500.;
  tree_.r91 = -500.;
  tree_.r92 = -500.;
}

float ZeeScSelection::invMassCalc(float Energy1, float Eta1, float Phi1, float Energy2, float Eta2, float Phi2) {
  return (sqrt(2 * Energy1 * Energy2 * (1 - cosTheta12(Eta1, Phi1, Eta2, Phi2))));
}

float ZeeScSelection::cosTheta12(float Eta1, float Phi1, float Eta2, float Phi2) {
  return ((cos(Phi1 - Phi2) + sinh(Eta1) * sinh(Eta2)) / (cosh(Eta1) * cosh(Eta2)));
}

