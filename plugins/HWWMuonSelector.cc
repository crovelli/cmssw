#include <memory>
#include <iostream>
#include "HiggsAnalysis/HiggsToWW2Leptons/plugins/HWWMuonSelector.h"
#include "DataFormats/MuonReco/interface/Muon.h"


HWWMuonSelector::HWWMuonSelector(const edm::ParameterSet& iConfig)
{

 // muonLabel_                 = iConfig.getParameter<edm::InputTag>("MuonLabel");
 muonPtMin_		    = iConfig.getParameter<double>("MuonPtMin");
 muonEtaMax_		    = iConfig.getParameter<double>("MuonEtaMax");

 //register your products
 // produces<reco::MuonCollection>("");
}


HWWMuonSelector::~HWWMuonSelector()
{

}

// ------------ method called to produce the data  ------------
void
HWWMuonSelector::select(edm::Handle<reco::MuonCollection> muons, const edm::Event& iEvent)
{
  using namespace edm;
  using namespace reco;
  selected_.clear();
//	iEvent.getByLabel(muonLabel_,muons);

  //std::auto_ptr<reco::MuonCollection> pOutMuons(new reco::MuonCollection);

  for(unsigned int i=0; i<muons->size();i++)
  {
  	  if((*muons)[i].pt()<=muonPtMin_ || fabs((*muons)[i].eta())>=muonEtaMax_) 
  		  continue;
  	  Ref<MuonCollection> muonRef(muons,i);
  	  selected_.push_back(muonRef);

  //	  pOutMuons->push_back(*iter); 
  }
	
 //   iEvent.put(pOutMuons,"");
}

//define this as a plug-in
//DEFINE_FWK_MODULE(HWWMuonSelector);
