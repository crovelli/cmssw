#include "HiggsAnalysis/HiggsToWW2Leptons/plugins/HWWJetCleaner.h"
#include "DataFormats/EgammaCandidates/interface/PixelMatchGsfElectronFwd.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include <Math/VectorUtil.h>

#include <iostream>
#include <algorithm>


HWWJetCleaner::HWWJetCleaner (const edm::ParameterSet& iConfig) :
    m_GSFInputTag (iConfig.getParameter<edm::InputTag> ("GSFInputTag")) ,
    m_maxDeltaR (iConfig.getParameter<double> ("maxDeltaR")) ,
    m_maxHadronicOverEm (iConfig.getParameter<double> ("maxHadronicOverEm")),
    m_minEleOJetEratio (iConfig.getParameter<double> ("minEleOJetEratio"))
{}


// ----------------------------------------------------------------------------
HWWJetCleaner::~HWWJetCleaner ()
{}

// ----------------------------------------------------------------------------
void
HWWJetCleaner::select (edm::Handle<HWWJetCleaner::collection> jetCollectionHandle,
                       const edm::Event& iEvent)
{
  m_selected.clear () ;

  //PG get the GSF electrons collection
  edm::Handle<reco::PixelMatchGsfElectronCollection> GSFHandle ;
  iEvent.getByLabel (m_GSFInputTag,GSFHandle) ;

  //PG loop over jets
  for (collection::const_iterator jetIt = jetCollectionHandle->begin () ;
       jetIt != jetCollectionHandle->end () ; ++jetIt){
    bool discard = false ;
    //PG loop over electrons
    for (reco::PixelMatchGsfElectronCollection::const_iterator eleIt = GSFHandle->begin () ;
         eleIt != GSFHandle->end () ;++eleIt){
      //PG NB should we use the SC direction, or the electron one?
      double deltaR =
        ROOT::Math::VectorUtil::DeltaR (eleIt->momentum (),jetIt->momentum ()) ;
      if (deltaR < m_maxDeltaR &&
          eleIt->hadronicOverEm() <  m_maxHadronicOverEm &&
          eleIt->superCluster()->energy () /
          jetIt->energy () > m_minEleOJetEratio){
        discard = true ; break ;
      }
    } //PG loop over electrons
    if (!discard) m_selected.push_back (jet (jetCollectionHandle,jetIt - jetCollectionHandle->begin ())) ;
  } //PG loop over jets
}
