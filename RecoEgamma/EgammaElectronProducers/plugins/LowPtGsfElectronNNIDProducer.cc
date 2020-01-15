#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "RecoEgamma/EgammaElectronProducers/plugins/LowPtGsfElectronNNIDProducer.h"

////////////////////////////////////////////////////////////////////////////////
LowPtGsfElectronNNIDProducer::LowPtGsfElectronNNIDProducer( const edm::ParameterSet& conf ) :

  gsfElectrons_(consumes< edm::View<reco::GsfElectron> >(conf.getParameter<edm::InputTag>("electrons"))),
  rho_(consumes<double>(conf.getParameter<edm::InputTag>("rho"))),
  packedCands_(consumes< edm::View<pat::PackedCandidate> >(conf.getParameter<edm::InputTag>("packedCands"))),
  lostTracks_(consumes< edm::View<pat::PackedCandidate> >(conf.getParameter<edm::InputTag>("lostTracks"))),
  unbiased_(consumes< edm::ValueMap<float> >(conf.getParameter<edm::InputTag>("unbiased"))),
  // 
  names_(conf.getParameter<std::string>("ModelName")),
  weights_(conf.getParameter<std::string>("ModelWeights")),
  minPtThreshold_(conf.getParameter<double>("MinPtThreshold")),
  maxPtThreshold_(conf.getParameter<double>("MaxPtThreshold")),
  maxEtaThreshold_(conf.getParameter<double>("MaxEtaThreshold"))        
{
  produces< edm::ValueMap<float> >(names_);
}

////////////////////////////////////////////////////////////////////////////////
LowPtGsfElectronNNIDProducer::~LowPtGsfElectronNNIDProducer() {}

////////////////////////////////////////////////////////////////////////////////
void LowPtGsfElectronNNIDProducer::beginRun(edm::Run const&, edm::EventSetup const&)   {

  // std::cout<<"Init the NN ..."<<std::endl; 

  // Build a fake Tree
  TTree *faketree ;
  faketree = new TTree("faketree", "Fake tree for NN training");

  float gsf_dr, gsf_bdtout1, gsf_mode_p, trk_dr, core_shFracHits, eid_rho, eid_ele_pt , eid_sc_eta; 
  float eid_shape_full5x5_sigmaIetaIeta, eid_shape_full5x5_sigmaIphiIphi, eid_shape_full5x5_circularity; 
  float eid_shape_full5x5_r9, eid_sc_etaWidth, eid_sc_phiWidth, eid_shape_full5x5_HoverE;
  float eid_trk_nhits, eid_trk_chi2red, eid_gsf_chi2red, eid_brem_frac, eid_gsf_nhits;
  float eid_match_SC_EoverP, eid_match_eclu_EoverP, eid_match_SC_dEta, eid_match_SC_dPhi, eid_match_seed_dEta; 
  float eid_sc_E, eid_trk_p, sc_clus1_E, sc_clus1_E_ov_p, sc_clus1_dphi, sc_clus1_deta, sc_clus2_E, sc_clus2_E_ov_p;
  float sc_clus2_dphi, sc_clus2_deta, sc_clus3_E, sc_clus3_E_ov_p, sc_clus3_dphi, sc_clus3_deta, weight;
  int sc_clus1_nxtal, sc_clus1_ntrk_deta01, sc_clus2_nxtal, sc_clus2_ntrk_deta01, sc_clus3_nxtal, sc_clus3_ntrk_deta01;
  int sc_goodSeed,sc_Nclus, type;  

  faketree->Branch("gsf_dr", &gsf_dr, "gsf_dr/f");
  faketree->Branch("gsf_bdtout1", &gsf_bdtout1, "gsf_bdtout1/f");
  faketree->Branch("gsf_mode_p", &gsf_mode_p, "gsf_mode_p/f");
  faketree->Branch("trk_dr", &trk_dr, "trk_dr/f");
  faketree->Branch("core_shFracHits",&core_shFracHits,"core_shFracHits/f");
  faketree->Branch("eid_rho", &eid_rho, "eid_rho/f");
  faketree->Branch("eid_ele_pt", &eid_ele_pt, "eid_ele_pt/f");
  faketree->Branch("eid_sc_eta", &eid_sc_eta, "eid_sc_eta/f");
  faketree->Branch("eid_shape_full5x5_sigmaIetaIeta", &eid_shape_full5x5_sigmaIetaIeta, "eid_shape_full5x5_sigmaIetaIeta/f");
  faketree->Branch("eid_shape_full5x5_sigmaIphiIphi", &eid_shape_full5x5_sigmaIphiIphi, "eid_shape_full5x5_sigmaIphiIphi/f");
  faketree->Branch("eid_shape_full5x5_circularity", &eid_shape_full5x5_circularity, "eid_shape_full5x5_circularity/f");
  faketree->Branch("eid_shape_full5x5_r9", &eid_shape_full5x5_r9, "eid_shape_full5x5_r9/f");
  faketree->Branch("eid_sc_etaWidth", &eid_sc_etaWidth, "eid_sc_etaWidth/f");
  faketree->Branch("eid_sc_phiWidth", &eid_sc_phiWidth, "eid_sc_phiWidth/f");
  faketree->Branch("eid_shape_full5x5_HoverE", &eid_shape_full5x5_HoverE, "eid_shape_full5x5_HoverE/f");
  faketree->Branch("eid_trk_nhits", &eid_trk_nhits, "eid_trk_nhits/f");
  faketree->Branch("eid_trk_chi2red", &eid_trk_chi2red, "eid_trk_chi2red/f");
  faketree->Branch("eid_gsf_chi2red", &eid_gsf_chi2red, "eid_gsf_chi2red/f");
  faketree->Branch("eid_brem_frac", &eid_brem_frac, "eid_brem_frac/f");
  faketree->Branch("eid_gsf_nhits", &eid_gsf_nhits, "eid_gsf_nhits/f");
  faketree->Branch("eid_match_SC_EoverP", &eid_match_SC_EoverP, "eid_match_SC_EoverP/f");
  faketree->Branch("eid_match_eclu_EoverP", &eid_match_eclu_EoverP, "eid_match_eclu_EoverP/f");
  faketree->Branch("eid_match_SC_dEta", &eid_match_SC_dEta, "eid_match_SC_dEta/f");
  faketree->Branch("eid_match_SC_dPhi", &eid_match_SC_dPhi, "eid_match_SC_dPhi/f");
  faketree->Branch("eid_match_seed_dEta", &eid_match_seed_dEta, "eid_match_seed_dEta/f");
  faketree->Branch("eid_sc_E", &eid_sc_E,   "eid_sc_E/f");
  faketree->Branch("eid_trk_p", &eid_trk_p, "eid_trk_p/f");
  faketree->Branch("sc_goodSeed",&sc_goodSeed,"sc_goodSeed/O");
  faketree->Branch("sc_Nclus",&sc_Nclus,"sc_Nclus/I");
  faketree->Branch("sc_clus1_E",     &sc_clus1_E,     "sc_clus1_E/F");
  faketree->Branch("sc_clus1_E_ov_p",     &sc_clus1_E_ov_p,     "sc_clus1_E_ov_p/F");
  faketree->Branch("sc_clus1_nxtal", &sc_clus1_nxtal, "sc_clus1_nxtal/I");
  faketree->Branch("sc_clus1_dphi",  &sc_clus1_dphi,  "sc_clus1_dphi/F");
  faketree->Branch("sc_clus1_deta",  &sc_clus1_deta,  "sc_clus1_deta/F");
  faketree->Branch("sc_clus1_ntrk_deta01",  &sc_clus1_ntrk_deta01,  "sc_clus1_ntrk_deta01/I");
  faketree->Branch("sc_clus2_E",     &sc_clus2_E,    "sc_clus2_E/F");
  faketree->Branch("sc_clus2_E_ov_p",     &sc_clus2_E_ov_p,     "sc_clus2_E_ov_p/F");
  faketree->Branch("sc_clus2_nxtal", &sc_clus2_nxtal, "sc_clus2_nxtal/I");
  faketree->Branch("sc_clus2_dphi",  &sc_clus2_dphi,  "sc_clus2_dphi/F");
  faketree->Branch("sc_clus2_deta",  &sc_clus2_deta,  "sc_clus2_deta/F");
  faketree->Branch("sc_clus2_ntrk_deta01",  &sc_clus2_ntrk_deta01,  "sc_clus2_ntrk_deta01/I");
  faketree->Branch("sc_clus3_E",     &sc_clus3_E,    "sc_clus3_E/F");
  faketree->Branch("sc_clus3_E_ov_p",     &sc_clus3_E_ov_p,     "sc_clus3_E_ov_p/F");
  faketree->Branch("sc_clus3_nxtal", &sc_clus3_nxtal, "sc_clus3_nxtal/I");
  faketree->Branch("sc_clus3_dphi",  &sc_clus3_dphi,  "sc_clus3_dphi/F");
  faketree->Branch("sc_clus3_deta",  &sc_clus3_deta,  "sc_clus3_deta/F");
  faketree->Branch("sc_clus3_ntrk_deta01",  &sc_clus3_ntrk_deta01,  "sc_clus3_ntrk_deta01/I");
  faketree->Branch("type",   &type,   "type/I");
  faketree->Branch("weight", &weight, "weight/f");
  
  // Build the NN
  mlp = new TMultiLayerPerceptron("@gsf_mode_p,@eid_rho,@eid_ele_pt,@eid_sc_eta,@eid_shape_full5x5_sigmaIetaIeta,@eid_shape_full5x5_sigmaIphiIphi,@eid_shape_full5x5_circularity,@eid_shape_full5x5_r9,@eid_sc_etaWidth,@eid_sc_phiWidth,@eid_shape_full5x5_HoverE,@eid_trk_nhits,@eid_trk_chi2red,@eid_gsf_chi2red,@eid_brem_frac,@eid_gsf_nhits,@eid_match_SC_EoverP,@eid_match_eclu_EoverP,@eid_match_SC_dEta,@eid_match_SC_dPhi,@eid_match_seed_dEta,@eid_sc_E,@eid_trk_p,@gsf_bdtout1,@sc_goodSeed,@core_shFracHits,@gsf_dr,@trk_dr,@sc_Nclus,@sc_clus1_nxtal,@sc_clus2_nxtal,@sc_clus3_nxtal,@sc_clus1_dphi,@sc_clus2_dphi,@sc_clus3_dphi,@sc_clus1_deta,@sc_clus2_deta,@sc_clus3_deta,@sc_clus1_E,@sc_clus2_E,@sc_clus3_E,@sc_clus1_ntrk_deta01,@sc_clus2_ntrk_deta01,@sc_clus3_ntrk_deta01,@sc_clus1_E_ov_p,@sc_clus2_E_ov_p,@sc_clus3_E_ov_p:23:12:type","weight",faketree,"Entry$%2","(Entry$+1)%2");

  // std::cout<<"Loading the NN weights"<<std::endl; 
  mlp->LoadWeights(weights_.c_str());
  // std::cout << "Done loading the NN weights: " << weights_ << std::endl; 
  
  TMLPAnalyzer ana(mlp);

  // Initialisation
  ana.GatherInformations();
  ana.CheckNetwork();
    
  // std::cout<<"Init the NN ... done"<<std::endl; 
}

////////////////////////////////////////////////////////////////////////////////
void LowPtGsfElectronNNIDProducer::endRun(edm::Run const&, edm::EventSetup const&) {

  // std::cout<<"ending the NN ..."<<std::endl; 

  delete mlp;

  // std::cout<<"ending the NN ... done"<<std::endl; 
}

////////////////////////////////////////////////////////////////////////////////
template <typename T>
bool LowPtGsfElectronNNIDProducer::validPtr (edm::Ptr<T>& ptr) {
  return ( ptr.isNonnull() && ptr.isAvailable() );
}


////////////////////////////////////////////////////////////////////////////////
bool LowPtGsfElectronNNIDProducer::extrapolate_to_ECAL(reco::TrackPtr kfTrackRef, float& eta_ECAL, float& phi_ECAL) {
  
  // Propagate 'electron' to ECAL surface
  double massR_=0.000511*0.000511; // ele mass 
  bool result=false;
  if (! validPtr(kfTrackRef) ) return result; 

  float p2R=pow( kfTrackRef->p() ,2 );
  float energyR = sqrt(massR_ + p2R);
  XYZTLorentzVector momR = XYZTLorentzVector(kfTrackRef->px(), kfTrackRef->py(), kfTrackRef->pz(), energyR);
  XYZTLorentzVector posR = XYZTLorentzVector(kfTrackRef->vx(), kfTrackRef->vy(), kfTrackRef->vz(), 0.);

  float field_zR=3.8;
  BaseParticlePropagator mypartR(RawParticle(momR,posR), 0, 0, field_zR);
  mypartR.setCharge(kfTrackRef->charge());
  mypartR.propagateToEcalEntrance(true);      // true only first half loop , false more than one loop
  bool reach_ECALR=mypartR.getSuccess();      // 0 does not reach ECAL, 1 yes barrel, 2 yes endcaps 

  return reach_ECALR; 
}

////////////////////////////////////////////////////////////////////////////////
void LowPtGsfElectronNNIDProducer::produce( edm::Event& event, const edm::EventSetup& setup ) {

  // Pileup
  edm::Handle<double> rhoH;
  event.getByToken(rho_,rhoH);
  if ( !rhoH.isValid() ) { edm::LogError("Problem with rho handle"); }
  float rho=(float)*rhoH;    

  // Retrieve Collections from Event
  edm::Handle< edm::View<reco::GsfElectron> > gsfElectrons;
  event.getByToken(gsfElectrons_,gsfElectrons);
  if ( !gsfElectrons.isValid() ) { edm::LogError("Problem with lowPtGsfElectrons handle"); }

  edm::Handle< edm::View<pat::PackedCandidate> > packedCands;
  event.getByToken(packedCands_,packedCands);
  if ( !packedCands.isValid() ) { edm::LogError("Problem with packedCands handle"); }   

  edm::Handle< edm::View<pat::PackedCandidate> > lostTracks;
  event.getByToken(lostTracks_,lostTracks);
  if ( !lostTracks.isValid() ) { edm::LogError("Problem with lostTracks handle"); }   

  // ElectronSeed unbiased BDT
  edm::Handle< edm::ValueMap<float> > unbiasedH;
  event.getByToken(unbiased_,unbiasedH);
  if ( !unbiasedH.isValid() ) { edm::LogError("Problem with unbiased handle"); }

  // ID values vector
  std::vector<float> output;
  for ( unsigned int iele = 0; iele < gsfElectrons->size(); iele++ ) {
    output.push_back( -999. );
  }

  // Iterate through Electrons, evaluate BDT, and store result      
  for ( unsigned int iele = 0; iele < gsfElectrons->size(); iele++ ) {
    reco::LowPtGsfElectronRef ele(gsfElectrons,iele);

    if ( ele->core().isNull() ) continue; 

    reco::GsfTrackRef gsf = ele->core()->gsfTrack();
    if ( gsf.isNull() ) continue; 
    float unbiased = (*unbiasedH)[gsf];

    reco::TrackRef trk = ele->closestCtfTrackRef();  
    // if ( !trk.isNonnull() )  continue;
    if ( trk.isNull() )  continue;

    if ( ele->superCluster().isNull() ) continue; 
    const reco::SuperClusterRef& sc = ele->superCluster();

    // ------------------------------------------------
    // calculate all needed input variables 
    double params[47];

    params[0] = gsf->pMode();    
    params[1] = (rho);  
    params[2] = ele->pt();    
    params[3] = sc->eta();
    params[4] = ele->full5x5_sigmaIetaIeta();
    params[5] = ele->full5x5_sigmaIphiIphi();
    params[6] = 1. - ele->full5x5_e1x5() / ele->full5x5_e5x5();
    params[7] = ele->full5x5_r9();
    params[8] = sc->etaWidth();
    params[9] = sc->phiWidth();
    params[10] = ele->full5x5_hcalOverEcal();
    params[11] = float(trk->found());
    params[12] = float(trk->normalizedChi2());
    params[13] = gsf->normalizedChi2();
    params[14] = ele->fbrem();
    params[15] = gsf->found();
    params[16] = ele->eSuperClusterOverP();
    params[17] = (1./ele->ecalEnergy()) - (1./ele->p());
    params[18] = ele->deltaEtaSuperClusterTrackAtVtx();
    params[19] = ele->deltaPhiSuperClusterTrackAtVtx();
    params[20] = ele->deltaEtaSeedClusterTrackAtCalo();
    params[21] = sc->energy();
    params[22] = float(trk->p());
    params[23] = unbiased;        // seed unbiased BDT output
    params[25] = ele->shFracInnerHits();

    TVector3 eleTV3(0,0,0);
    eleTV3.SetPtEtaPhi(ele->pt(), ele->eta(), ele->phi());
    TVector3 gsfTV3(0,0,0);
    gsfTV3.SetPtEtaPhi(gsf->ptMode(), gsf->etaMode(), gsf->phiMode());
    params[26] = eleTV3.DeltaR(gsfTV3);     

    // Propagate electron track to ECAL surface 
    double mass_ = 0.000511*0.000511; 
    float p2=pow( gsf->p() ,2 );
    float energy = sqrt(mass_ + p2);
    XYZTLorentzVector mom = XYZTLorentzVector(gsf->px(), gsf->py(), gsf->pz(), energy);
    XYZTLorentzVector pos = XYZTLorentzVector(gsf->vx(), gsf->vy(), gsf->vz(), 0.);
    float field_z=3.8;
    BaseParticlePropagator mypart(RawParticle(mom,pos), 0, 0, field_z);
    mypart.setCharge(gsf->charge());
    mypart.propagateToEcalEntrance(true);    // true only first half loop , false more than one loop 
    bool reach_ECAL = mypart.getSuccess();   // 0 does not reach ECAL, 1 yes barrel, 2 yes endcaps                                            
    GlobalPoint ecal_pos(mypart.x(), mypart.y(), mypart.z());    // ECAL entry point for track  

    // Iterate through ECAL clusters and sort in energy
    int clusNum=0;
    float maxEne1=-1;
    float maxEne2=-1;
    float maxEne3=-1;
    int i1=-1;
    int i2=-1;
    int i3=-1;
    try{
      if(sc->clustersSize()>0 && sc->clustersBegin()!=sc->clustersEnd()){
	for(auto& cluster : sc->clusters()) {
	  if (cluster->energy() > maxEne1){
	    maxEne1=cluster->energy();
	    i1=clusNum;
	  }
	  clusNum++;
	}
	if(sc->clustersSize()>1){
	  clusNum=0;
	  for(auto& cluster : sc->clusters()) {
	    if (clusNum!=i1) {
	      if (cluster->energy() > maxEne2){
		maxEne2=cluster->energy();
		i2=clusNum;
	      }
	    }
	    clusNum++;
	  }
	}
	if(sc->clustersSize()>2){
	  clusNum=0;
	  for(auto& cluster : sc->clusters()) {
	    if (clusNum!=i1 && clusNum!=i2) {
	      if (cluster->energy() > maxEne3){
		maxEne3=cluster->energy();
		i3=clusNum;
	      }
	    }
	    clusNum++;
	  }
	}
      }
    } catch(...) {
      std::cout<<"exception caught clusNum="<<clusNum<<" clus size"<<sc->clustersSize()<<" energy="<< sc->energy()<<std::endl;
    }

    // EGM-like seed or not
    bool sc_goodSeed=false;
    float seedEne=sc->seed()->energy();
    if(fabs(seedEne-maxEne1)<0.001) sc_goodSeed=true;
    params[24] = sc_goodSeed;

    // Initializations
    float sc_clus1_E_       = -999.;
    float sc_clus2_E_       = -999.;
    float sc_clus3_E_       = -999.;
    float sc_clus1_eta_     = -999.;
    float sc_clus2_eta_     = -999.;
    float sc_clus3_eta_     = -999.;
    float sc_clus1_phi_     = -999.;
    float sc_clus2_phi_     = -999.;
    float sc_clus3_phi_     = -999.;
    float sc_clus1_E_ov_p_  = -999.;
    float sc_clus2_E_ov_p_  = -999.;
    float sc_clus3_E_ov_p_  = -999.;
    int sc_clus1_nxtal_     = -999;
    int sc_clus2_nxtal_     = -999;
    int sc_clus3_nxtal_     = -999;
    float sc_clus1_deta_    = -999.;
    float sc_clus2_deta_    = -999.;
    float sc_clus3_deta_    = -999.;
    float sc_clus1_dphi_    = -999.;
    float sc_clus2_dphi_    = -999.;
    float sc_clus3_dphi_    = -999.;

    // track-clusters match
    clusNum=0;
    try { 
      if(sc->clustersSize()>0&& sc->clustersBegin()!=sc->clustersEnd()){
	for(auto& cluster : sc->clusters()) {
	  double pi_=3.1415926535;
	  float deta = std::fabs(ecal_pos.eta()-cluster->eta()) ;
	  float dphi = std::fabs(ecal_pos.phi()-cluster->phi());
	  if (dphi > pi_)  dphi -= 2 * pi_;
	  if (ecal_pos.phi()-cluster->phi()<0) dphi=-dphi;
	  if (ecal_pos.eta()-cluster->eta()<0) deta=-deta;

	  if (clusNum==i1) {
	    sc_clus1_E_    = cluster->energy();
	    sc_clus1_eta_  = cluster->eta();
	    sc_clus1_phi_  = cluster->phi();
	    if(gsf->pMode()>0) sc_clus1_E_ov_p_ = cluster->energy()/gsf->pMode();
	    sc_clus1_nxtal_ = (int)cluster->size();
	    if (reach_ECAL>0){
	      sc_clus1_deta_ = deta;
	      sc_clus1_dphi_ = dphi;
	    } 
	  } else if (clusNum==i2) {   
	    sc_clus2_E_    = cluster->energy();
	    sc_clus2_eta_  = cluster->eta();
	    sc_clus2_phi_  = cluster->phi();
	    if(gsf->pMode()>0) sc_clus2_E_ov_p_ = cluster->energy()/gsf->pMode();
	    sc_clus2_nxtal_ = (int)cluster->size();
	    if (reach_ECAL>0){
	      sc_clus2_deta_ = deta;
	      sc_clus2_dphi_ = dphi;
	    } 
	  } else if(clusNum==i3) {   
	    sc_clus3_E_   = cluster->energy();
	    sc_clus3_eta_ = cluster->eta();
	    sc_clus3_phi_ = cluster->phi();
	    if(gsf->pMode()>0) sc_clus3_E_ov_p_ = cluster->energy()/gsf->pMode();
	    sc_clus3_nxtal_ = (int)cluster->size();
	    if (reach_ECAL>0){
	      sc_clus3_deta_ = deta;
	      sc_clus3_dphi_ = dphi;
	    }
	  }
	  clusNum++;
	}
      }
    } catch(...) {
      std::cout<<"caught an exception"<<std::endl;                                                                                  
    }
  
    // KTF track linked to electron   
    float trk_dr=-999.;
    TVector3 trkTV3(0,0,0);
    trkTV3.SetPtEtaPhi(trk->pt(), trk->eta(), trk->phi());  
    trk_dr = eleTV3.DeltaR(trkTV3);  
    params[27] = trk_dr;

    // How many tracks there around first second and third cluster within dR<0.1  
    int sc_clus1_ntrk_deta01_ = 0;
    int sc_clus2_ntrk_deta01_ = 0;
    int sc_clus3_ntrk_deta01_ = 0;
    if(sc_clus1_E_>0){
      size_t iptr=0;
      for ( auto& ptr : *packedCands) {
	if(ptr.bestTrack() == nullptr) { continue;}
	reco::TrackPtr trkx(ptr.bestTrack(), iptr);
	float eta_EC=0;
	float phi_EC=0;
	float dRcur1=100;
	float dRcur2=100;
	float dRcur3=100;
	if (extrapolate_to_ECAL(trkx,eta_EC, phi_EC)) {
	  if(sc_clus1_E_>0) dRcur1=deltaR(eta_EC,phi_EC,sc_clus1_eta_,sc_clus1_phi_);
	  if(sc_clus2_E_>0) dRcur2=deltaR(eta_EC,phi_EC,sc_clus2_eta_,sc_clus2_phi_);
	  if(sc_clus3_E_>0) dRcur3=deltaR(eta_EC,phi_EC,sc_clus3_eta_,sc_clus3_phi_);
	  if(dRcur1<0.1) sc_clus1_ntrk_deta01_=sc_clus1_ntrk_deta01_+1;
	  if(dRcur2<0.1) sc_clus2_ntrk_deta01_=sc_clus2_ntrk_deta01_+1;
	  if(dRcur3<0.1) sc_clus3_ntrk_deta01_=sc_clus3_ntrk_deta01_+1;
	}
	++iptr;
      }
      for ( auto& ptr : *lostTracks) {
	if(ptr.bestTrack() == nullptr) { continue;}
	reco::TrackPtr trkx(ptr.bestTrack(), iptr);
	float eta_EC=0;
	float phi_EC=0;
	float dRcur1=100;
	float dRcur2=100;
	float dRcur3=100;
	if(extrapolate_to_ECAL(trkx,eta_EC, phi_EC)){
	  if(sc_clus1_E_>0) dRcur1=deltaR(eta_EC, phi_EC, sc_clus1_eta_, sc_clus1_phi_);
	  if(sc_clus2_E_>0) dRcur2=deltaR(eta_EC, phi_EC, sc_clus2_eta_, sc_clus2_phi_);
	  if(sc_clus3_E_>0) dRcur3=deltaR(eta_EC, phi_EC, sc_clus3_eta_, sc_clus3_phi_);
	  if(dRcur1<0.1) sc_clus1_ntrk_deta01_=sc_clus1_ntrk_deta01_+1;
	  if(dRcur2<0.1) sc_clus2_ntrk_deta01_=sc_clus2_ntrk_deta01_+1;
	  if(dRcur3<0.1) sc_clus3_ntrk_deta01_=sc_clus3_ntrk_deta01_+1;
	}
	++iptr;
      }
    }

    // Cluster-related variables
    params[28] = sc->clustersSize();
    params[29] = sc_clus1_nxtal_;
    params[30] = sc_clus2_nxtal_;
    params[31] = sc_clus3_nxtal_;
    params[32] = sc_clus1_dphi_;
    params[33] = sc_clus2_dphi_;
    params[34] = sc_clus3_dphi_;
    params[35] = sc_clus1_deta_;
    params[36] = sc_clus2_deta_;
    params[37] = sc_clus3_deta_;
    params[38] = sc_clus1_E_;
    params[39] = sc_clus2_E_;
    params[40] = sc_clus3_E_;
    params[41] = sc_clus1_ntrk_deta01_;
    params[42] = sc_clus2_ntrk_deta01_;
    params[43] = sc_clus3_ntrk_deta01_;
    params[44] = sc_clus1_E_ov_p_;
    params[45] = sc_clus2_E_ov_p_;
    params[46] = sc_clus3_E_ov_p_;
    
    //std::cout << "" << std::endl;
    //std::cout << "Inputs ===> " << std::endl;
    //for (int ii=0; ii<47; ii++) std::cout << "ii = " << ii << ", params = " << params[ii] << std::endl;
    //std::cout << "" << std::endl;
    //std::cout << "Output ===> " << mlp->Evaluate(0,params) << std::endl;

    output[iele] = mlp->Evaluate(0,params); 

  } // loop over electrons


  // Create and put ValueMap in Event
  auto ptr = std::make_unique< edm::ValueMap<float> >( edm::ValueMap<float>() );
  edm::ValueMap<float>::Filler filler(*ptr);
  filler.insert(gsfElectrons, output.begin(), output.end());
  filler.fill();
  reco::LowPtGsfElectronRef ele(gsfElectrons,0);
  event.put(std::move(ptr),names_);
  
}

//////////////////////////////////////////////////////////////////////////////////////////
void LowPtGsfElectronNNIDProducer::fillDescriptions( edm::ConfigurationDescriptions& descriptions )
{
  edm::ParameterSetDescription desc;
  desc.add<edm::InputTag>("electrons",edm::InputTag("slimmedLowPtElectrons")); 
  desc.add<edm::InputTag>("rho",edm::InputTag("fixedGridRhoFastjetAll"));      
  desc.add<edm::InputTag>("packedCands",edm::InputTag("packedPFCandidates")); 
  desc.add<edm::InputTag>("lostTracks",edm::InputTag("lostTracks")); 
  desc.add<edm::InputTag>("unbiased",edm::InputTag("lowPtGsfElectronSeedValueMaps:unbiased"));

  desc.add<std::string>("ModelName","unbiasNN");
  desc.add<std::string>("ModelWeights","weights.txt");
  desc.add<double>("ModelThresholds",-50);
  desc.add<double>("MinPtThreshold",0.5);
  desc.add<double>("MaxPtThreshold",15.);
  desc.add<double>("MaxEtaThreshold",2.4); 
  descriptions.add("defaultLowPtGsfElectronNNID",desc);
}

//////////////////////////////////////////////////////////////////////////////////////////
#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(LowPtGsfElectronNNIDProducer);
