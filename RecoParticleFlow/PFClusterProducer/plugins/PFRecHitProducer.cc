#include "RecoParticleFlow/PFClusterProducer/plugins/PFRecHitProducer.h"
#include "FWCore/Utilities/interface/RunningAverage.h"

#include <iostream>

namespace {
  bool sortByDetId(const reco::PFRecHit& a,
		   const reco::PFRecHit& b) {
    return a.detId() < b.detId();
  }

 edm::RunningAverage localRA1;
 edm::RunningAverage localRA2;
}

 PFRecHitProducer:: PFRecHitProducer(const edm::ParameterSet& iConfig)
{
  //std::cout << "chiara: costruttore di PFRecHitProducer" << std::endl;

  produces<reco::PFRecHitCollection>();
  produces<reco::PFRecHitCollection>("Cleaned");

  edm::ConsumesCollector iC = consumesCollector();

  std::vector<edm::ParameterSet> creators = iConfig.getParameter<std::vector<edm::ParameterSet> >("producers");
  for (auto & creator : creators) {
      std::string name = creator.getParameter<std::string>("name");
      creators_.emplace_back(PFRecHitFactory::get()->create(name,creator,iC));
      //std::cout << "chiara: dentro creators -> name = " << name << std::endl;
  }
  //std::cout << "chiara: creators_.size = " << creators_.size() << std::endl;


  edm::ParameterSet navSet = iConfig.getParameter<edm::ParameterSet>("navigator");

  navigator_.reset(PFRecHitNavigationFactory::get()->create(navSet.getParameter<std::string>("name"),navSet));
    
}


 PFRecHitProducer::~ PFRecHitProducer() = default;


//
// member functions
//

void
 PFRecHitProducer::beginLuminosityBlock(edm::LuminosityBlock const& iLumi, const edm::EventSetup& iSetup) {
  //std::cout << "chiara: dentro beginLuminosityBlock" << std::endl;
  for( const auto& creator : creators_ ) {
    creator->init(iSetup);
  }
  //std::cout << "chiara: esco da beginLuminosityBlock" << std::endl;
}

void
 PFRecHitProducer::endLuminosityBlock(edm::LuminosityBlock const& iLumi, const edm::EventSetup&) { }

// ------------ method called to produce the data  ------------
void
 PFRecHitProducer::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  //std::cout << "chiara: dentro PFRecHitProducer::produce" << std::endl;

   using namespace edm;
   auto out = std::make_unique<reco::PFRecHitCollection>();
   auto cleaned = std::make_unique<reco::PFRecHitCollection>();

   //std::cout << "chiara: dentro PFRecHitProducer::produce1" << std::endl;
   navigator_->beginEvent(iSetup);
   //std::cout << "chiara: dentro PFRecHitProducer::produce2" << std::endl;

   out->reserve(localRA1.upper());
   //std::cout << "chiara: dentro PFRecHitProducer::produce3" << std::endl;
   cleaned->reserve(localRA2.upper());
   //std::cout << "chiara: dentro PFRecHitProducer::produce4" << std::endl;

   for( const auto& creator : creators_ ) {
     //std::cout << "chiara: dentro PFRecHitProducer::produce => importRecHits" << std::endl;
     creator->importRecHits(out,cleaned,iEvent,iSetup);
     //std::cout << "chiara: dentro PFRecHitProducer::produce => fatto importRecHits" << std::endl;
   }

   //std::cout << "chiara, dentro PFRecHitProducer::produce5a = " << out->size() << std::endl;
   if (out->capacity()>2*out->size()) out->shrink_to_fit();
   if (cleaned->capacity()>2*cleaned->size()) cleaned->shrink_to_fit();
   localRA1.update(out->size());
   localRA2.update(cleaned->size());
   std::sort(out->begin(),out->end(),sortByDetId);
   //std::cout << "chiara, dentro PFRecHitProducer::produce5b = " << out->size() << std::endl;
 
   //create a refprod here
   edm::RefProd<reco::PFRecHitCollection> refProd = 
     iEvent.getRefBeforePut<reco::PFRecHitCollection>();

   for( auto& pfrechit : *out ) {
     navigator_->associateNeighbours(pfrechit,out,refProd);
   }

   iEvent.put(std::move(out),"");
   iEvent.put(std::move(cleaned),"Cleaned");

}

void
 PFRecHitProducer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

