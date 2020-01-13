#ifndef RecoEgamma_EgammaElectronProducers_LowPtGsfElectronNNIDProducer_h
#define RecoEgamma_EgammaElectronProducers_LowPtGsfElectronNNIDProducer_h

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/stream/EDProducer.h"
#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ParameterSet/interface/ParameterSetDescription.h"   
#include "FWCore/Utilities/interface/EDGetToken.h"

#include "DataFormats/Common/interface/View.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/Common/interface/Association.h"
#include "DataFormats/Common/interface/View.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "FastSimulation/BaseParticlePropagator/interface/BaseParticlePropagator.h"

#include <TROOT.h>
#include "TVector3.h"
#include <TTree.h>
#include <TBranch.h>
#include <string>
#include <vector>

#include <TMultiLayerPerceptron.h>
#include <TMLPAnalyzer.h>
#include <TNeuron.h>
#include <TSynapse.h>

namespace reco { typedef edm::Ptr<Track> TrackPtr; }
namespace reco { typedef edm::Ref< edm::View<GsfElectron> > LowPtGsfElectronRef; }

class LowPtGsfElectronNNIDProducer : public edm::stream::EDProducer<> { 

 public:
  explicit LowPtGsfElectronNNIDProducer( const edm::ParameterSet& );

  void beginRun( edm::Run const&, edm::EventSetup const & );
  void endRun( edm::Run const&, edm::EventSetup const & );
  
  ~LowPtGsfElectronNNIDProducer();

  void produce( edm::Event&, const edm::EventSetup& );

  static void fillDescriptions( edm::ConfigurationDescriptions& );

 private:
  
  // the NN        
  TMultiLayerPerceptron *mlp ; 

  const edm::EDGetTokenT< edm::View<reco::GsfElectron> > gsfElectrons_;
  const edm::EDGetTokenT<double> rho_;
  const edm::EDGetTokenT< edm::View<pat::PackedCandidate> > packedCands_; 
  const edm::EDGetTokenT< edm::View<pat::PackedCandidate> > lostTracks_; 

  const edm::EDGetTokenT< edm::ValueMap<float> > unbiased_;

  const std::string names_;
  std::string weights_;
  const double minPtThreshold_;
  const double maxPtThreshold_;
  const double maxEtaThreshold_;

  // more functions
  template <typename T> bool validPtr( edm::Ptr<T>& ptr );     
  bool extrapolate_to_ECAL(reco::TrackPtr kfTrackRef, float& eta_ECAL, float& phi_ECAL);

};

#endif // RecoEgamma_EgammaElectronProducers_LowPtGsfElectronNNIDProducer_h

