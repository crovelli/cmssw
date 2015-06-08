#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "FWCore/Framework/interface/TriggerNamesService.h"

#include "CondFormats/EcalObjects/interface/EcalIntercalibConstants.h"
#include "CondFormats/DataRecord/interface/EcalIntercalibConstantsRcd.h"

#include "Calibration/Tools/interface/calibXMLwriter.h"
#include "Calibration/Tools/interface/CalibrationCluster.h"
#include "Calibration/Tools/interface/HouseholderDecomposition.h"
#include "Calibration/Tools/interface/MinL3Algorithm.h"
#include "Calibration/Tools/interface/EcalRingCalibrationTools.h"
#include "Calibration/Tools/interface/EcalIndexingTools.h"
#include "Calibration/EcalCalibAlgos/interface/ZeeCalibration.h"
#include "Calibration/EcalCalibAlgos/interface/ZeeKinematicTools.h"

#include "CalibCalorimetry/CaloMiscalibTools/interface/MiscalibReaderFromXMLEcalBarrel.h"
#include "CalibCalorimetry/CaloMiscalibTools/interface/MiscalibReaderFromXMLEcalEndcap.h"
#include "CalibCalorimetry/CaloMiscalibTools/interface/CaloMiscalibMapEcal.h"

#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"

#include "DataFormats/Common/interface/ValueMap.h"

#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHit.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include "DataFormats/EgammaCandidates/interface/Electron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectronFwd.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/TrackReco/interface/HitPattern.h"
#include "DataFormats/EgammaCandidates/interface/ConversionFwd.h"
#include "DataFormats/EgammaCandidates/interface/Conversion.h"
#include "RecoEgamma/EgammaTools/interface/ConversionTools.h"
#include "DataFormats/CaloRecHit/interface/CaloRecHit.h"
#include "DataFormats/Common/interface/TriggerResults.h"

#include "DataFormats/Math/interface/deltaR.h"

#include "HLTrigger/HLTanalyzers/interface/HLTrigReport.h"

#include "CLHEP/Vector/LorentzVector.h"

#include "TTree.h"
#include "TBranch.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TProfile.h"
#include "TH1.h"
#include "TH2.h"
#include "TGraphErrors.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <utility>
#include <map>
#include <fstream>
#include <cmath>

#define MZ 91.1876

// #define DEBUG
// #define DEBUG_HLT
// #define DEBUG_MC 
// #define DEBUG_COLL 
// #define DEBUG_EWK

using namespace std;

ZeeCalibration::ZeeCalibration(const edm::ParameterSet& iConfig) {

#ifdef DEBUG
  std::cout<<"[ZeeCalibration] Starting the ctor"<<std::endl;
#endif
  
  // algo parameters and options
  theMaxLoops = iConfig.getUntrackedParameter<unsigned int>("maxLoops",0);
  wantEtaCorrection_ = iConfig.getUntrackedParameter<bool>("wantEtaCorrection",false);   
  requireOppositeCharge_ = iConfig.getUntrackedParameter<bool>("requireOppositeCharge",false);   

  minInvMassCut_ = iConfig.getUntrackedParameter<double>("minInvMassCut", 70.);   
  maxInvMassCut_ = iConfig.getUntrackedParameter<double>("maxInvMassCut", 110.);   
  electronSelection_ = iConfig.getUntrackedParameter<int> ("electronSelection",-1);
  
  histoFileName_ = iConfig.getParameter<std::string>("histoFile");
  zeeFileName_   = iConfig.getParameter<std::string>("zeeFile");
  
  barrelfile_ = iConfig.getUntrackedParameter<std::string> ("initialMiscalibrationBarrel","");
  endcapfile_ = iConfig.getUntrackedParameter<std::string> ("initialMiscalibrationEndcap","");

  etaBins_ = iConfig.getUntrackedParameter<unsigned int>("etaBins", 10);   
  etBins_  = iConfig.getUntrackedParameter<unsigned int>("etBins", 10);   
  etaMin_  = iConfig.getUntrackedParameter<double>("etaMin", 0.);   
  etMin_   = iConfig.getUntrackedParameter<double>("etMin", 0.);   
  etaMax_  = iConfig.getUntrackedParameter<double>("etaMax", 3.);   
  etMax_   = iConfig.getUntrackedParameter<double>("etMax", 100.);   

  calibMode_ = iConfig.getUntrackedParameter<std::string>("ZCalib_CalibType");
 
  // collections
  rechitProducer_    = iConfig.getParameter<std::string>("rechitProducer");
  rechitCollection_  = iConfig.getParameter<std::string>("rechitCollection");     
  erechitProducer_   = iConfig.getParameter<std::string>("erechitProducer");     
  erechitCollection_ = iConfig.getParameter<std::string>("erechitCollection");    

  ebSuperclusters_ = iConfig.getParameter<edm::InputTag> ("ebSuperclusters");  
  eeSuperclusters_ = iConfig.getParameter<edm::InputTag> ("eeSuperclusters");  

  electrons_   = iConfig.getParameter<edm::InputTag> ("electrons");      
  
  vertices_ = iConfig.getParameter<edm::InputTag> ("vertices");
  conversions_ = iConfig.getParameter<edm::InputTag> ("conversions");
  beamspot_ = iConfig.getParameter<edm::InputTag> ("beamspot");
  // full5x5sieie_ = iConfig.getParameter<edm::InputTag> ("full5x5sieie");

  mcProducer_ = iConfig.getUntrackedParameter<std::string>("mcProducer");

  hlTriggerResults_ = iConfig.getParameter<edm::InputTag> ("HLTriggerResults");


  // outputs
  myZeePlots_ = new ZeePlots( zeeFileName_.c_str() );   
  outputFile_ = TFile::Open(histoFileName_.c_str(),"RECREATE"); 
  outputFile_->cd();

  bookHistograms();
#ifdef DEBUG
  std::cout<<"[ZeeCalibration::ctor] Histograms booked "<<std::endl;
#endif

  myTree = new TTree("myTree","myTree");
  myTree->Branch("iteration",&loopFlag_,"iteration/I");
  myTree->Branch("isEBEB",&isEBEB,"isEBEB/I");
  myTree->Branch("zMass",&mass4tree,"mass/F");
  myTree->Branch("zMassDiff",&massDiff4tree,"massDiff/F");
  
  theParameterSet=iConfig;
  EcalIndexingTools* myIndexTool=0;
  myIndexTool = EcalIndexingTools::getInstance();  
  myIndexTool->setBinRange( etaBins_, etaMin_, etaMax_, etBins_, etMin_, etMax_ );
  
  // creating the algorithm
  theAlgorithm_ = new ZIterativeAlgorithmWithFit(iConfig);
  
  // Tell the framework what data is being produced
  setWhatProduced (this, &ZeeCalibration::produceEcalIntercalibConstants ) ;
  findingRecord<EcalIntercalibConstantsRcd> () ;

  for(int i = 0; i<50; i++){
    coefficientDistanceAtIteration[i] = -1.;
    loopArray[i] = -1.;
    sigmaArray[i] = -1.;
    sigmaErrorArray[i] = -1.;
  }

#ifdef DEBUG
  std::cout<<"[ZeeCalibration] Done with the ctor"<<std::endl;
#endif
}

ZeeCalibration::~ZeeCalibration() { }

// Produce EcalIntercalibConstants
boost::shared_ptr<EcalIntercalibConstants>
ZeeCalibration::produceEcalIntercalibConstants( const EcalIntercalibConstantsRcd& iRecord ) {

  std::cout << "@SUB=ZeeCalibration::produceEcalIntercalibConstants" << std::endl;
  return ical;
}

// Geometry and set of initial miscalibration (if requested)
void ZeeCalibration::beginOfJob(edm::EventSetup const& iSetup) {

#ifdef DEBUG
  std::cout<<"[ZeeCalibration] starting beginOfJob"<<std::endl;
#endif
  
  isfirstcall_=true;

  if (isfirstcall_){

    // loading ecal geometry
    edm::ESHandle<CaloGeometry> pG;
    iSetup.get<CaloGeometryRecord>().get(pG);     
    EcalRingCalibrationTools::setCaloGeometry(&(*pG));  
    
    loopFlag_ = 0;

    // Read miscalibration map if requested
    CaloMiscalibMapEcal* miscalibMap=0;
    if (!barrelfile_.empty() || !endcapfile_.empty()) {
      miscalibMap=new CaloMiscalibMapEcal();
      miscalibMap->prefillMap();
    }
    
    if(!barrelfile_.empty()) {
      MiscalibReaderFromXMLEcalBarrel barrelreader_(*miscalibMap);
      barrelreader_.parseXMLMiscalibFile(barrelfile_);
#ifdef DEBUG
      std::cout<<"[ZeeCalibration::beginOfJob] Parsed EB miscal file"<<std::endl;
#endif
    }
    
    if(!endcapfile_.empty()) {
      MiscalibReaderFromXMLEcalEndcap endcapreader_(*miscalibMap);
      endcapreader_.parseXMLMiscalibFile(endcapfile_);
#ifdef DEBUG
      std::cout<<"[ZeeCalibration::beginOfJob] Parsed EE miscal file"<<std::endl;
#endif
    }
    
#ifdef DEBUG
    std::cout << "TheAlgorithm_->getNumberOfChannels() " << theAlgorithm_->getNumberOfChannels() << std::endl;
#endif

    for(int k = 0; k < theAlgorithm_->getNumberOfChannels(); k++) {
      
      calibCoeff[k]=1.;
      calibCoeffError[k]=0.;
      
      std::vector<DetId> ringIds;
      if(calibMode_ == "RING")   ringIds = EcalRingCalibrationTools::getDetIdsInRing(k);
      if(calibMode_ == "MODULE") ringIds = EcalRingCalibrationTools::getDetIdsInModule(k);
      if(calibMode_ == "ABS_SCALE" || calibMode_ == "ETA_ET_MODE" ) ringIds = EcalRingCalibrationTools::getDetIdsInECAL();
      
      // set miscalibration
      if (miscalibMap) {
	initCalibCoeff[k]=0.;	      
	for (unsigned int iid=0; iid<ringIds.size();++iid) {
	  float miscalib=* (miscalibMap->get().getMap().find(ringIds[iid])  );
	  initCalibCoeff[k]+=miscalib;
	}
	initCalibCoeff[k]/=(float)ringIds.size();

#ifdef DEBUG
	std::cout << k << " " << initCalibCoeff[k] << " " << ringIds.size() << std::endl;
#endif
      }
      else {
	initCalibCoeff[k]=1.;
      }
    }
    
    ical = boost::shared_ptr<EcalIntercalibConstants>( new EcalIntercalibConstants() );
    
    for(int k = 0; k < theAlgorithm_->getNumberOfChannels(); k++) {
      
      std::vector<DetId> ringIds;
      if(calibMode_ == "RING")   ringIds = EcalRingCalibrationTools::getDetIdsInRing(k);
      if(calibMode_ == "MODULE") ringIds = EcalRingCalibrationTools::getDetIdsInModule(k);
      if(calibMode_ == "ABS_SCALE" || calibMode_ == "ETA_ET_MODE") ringIds = EcalRingCalibrationTools::getDetIdsInECAL();
      
      for (unsigned int iid=0; iid<ringIds.size();++iid) {
	
	if (miscalibMap) {  
	  if(ringIds[iid].subdetId() == EcalBarrel){
	    EBDetId myEBDetId(ringIds[iid]);  
	    h2_xtalMiscalibCoeffBarrel_->SetBinContent( myEBDetId.ieta() + 86, myEBDetId.iphi(), * (miscalibMap->get().getMap().find(ringIds[iid]) ) );
	  }
	  if(ringIds[iid].subdetId() == EcalEndcap){
	    EEDetId myEEDetId(ringIds[iid]);
	    if(myEEDetId.zside() < 0)
	      h2_xtalMiscalibCoeffEndcapMinus_->SetBinContent( myEEDetId.ix(), myEEDetId.iy(), * ( miscalibMap->get().getMap().find(ringIds[iid]) ) );
	    if(myEEDetId.zside() > 0)
	      h2_xtalMiscalibCoeffEndcapPlus_->SetBinContent( myEEDetId.ix(), myEEDetId.iy(), * (miscalibMap->get().getMap().find(ringIds[iid]) ) );
	  }
	  ical->setValue( ringIds[iid], *(miscalibMap->get().getMap().find(ringIds[iid])  ) );
	} else {
	  ical->setValue( ringIds[iid], 1. );
	}
      }
    }
    
    read_events = 0;
    init_ = false;
    isfirstcall_=false;

  }  // if isfirstcall  
  
#ifdef DEBUG
  std::cout<<"[ZeeCalibration] beginOfJob done"<<std::endl;
#endif
}

// dump of coefficients, and summary plots
void ZeeCalibration::endOfJob() {

#ifdef DEBUG
  std::cout<<"[ZeeCalibration] starting endOfJob"<<std::endl;
#endif

  printStatistics();
  
  if(calibMode_ != "ETA_ET_MODE") {

    // Writing out calibration coefficients
    calibXMLwriter* barrelWriter = new calibXMLwriter(EcalBarrel);
    for(int ieta=-EBDetId::MAX_IETA; ieta<=EBDetId::MAX_IETA ;++ieta) {
      if(ieta==0) continue;
      for(int iphi=EBDetId::MIN_IPHI; iphi<=EBDetId::MAX_IPHI; ++iphi) {
	if (EBDetId::validDetId(ieta,iphi)) {
	  EBDetId ebid(ieta,iphi);
	  barrelWriter->writeLine(ebid,* (ical->getMap().find(ebid.rawId()) ));
	}
      }
    }
    
    calibXMLwriter* endcapWriter = new calibXMLwriter(EcalEndcap);
    for(int iX=EEDetId::IX_MIN; iX<=EEDetId::IX_MAX ;++iX) {
      for(int iY=EEDetId::IY_MIN; iY<=EEDetId::IY_MAX; ++iY) {
	if (EEDetId::validDetId(iX,iY,1)) {
	  EEDetId eeid(iX,iY,1);
	  endcapWriter->writeLine(eeid,*(ical->getMap().find(eeid.rawId())  ) );
	}
	if (EEDetId::validDetId(iX,iY,-1)) {
	  EEDetId eeid(iX,iY,-1);
	  endcapWriter->writeLine(eeid, *(ical->getMap().find(eeid.rawId())) );
	}
      }
    }
    
  } ///if not ETA_ET MODE - end

#ifdef DEBUG  
  std::cout<<"Writing  histos..."<<std::endl;
#endif

  outputFile_->cd();

  h1_Selection_ ->Write();   

  h1_massBeforeCut_->Write();
  h1_massAfterCut_->Write();

  // h1_eventsBeforeBorderSelection_ ->Write();
  // h1_eventsAfterBorderSelection_  ->Write();
  // h1_borderElectronClassification_->Write();
 
  h2_xtalMiscalibCoeffBarrel_      ->Write();
  h2_xtalMiscalibCoeffEndcapMinus_ ->Write();
  h2_xtalMiscalibCoeffEndcapPlus_  ->Write();

  // h1_electronCosTheta_SC_->Write();
  // h1_electronCosTheta_TK_->Write();
  // h1_electronCosTheta_SC_TK_->Write();

  // h1_zMassResol_ ->Write();
  // h1_zEtaResol_  ->Write();
  // h1_zPhiResol_  ->Write();
  // h1_eleEtaResol_->Write();
  // h1_elePhiResol_->Write();
  // h1_seedOverSC_ ->Write();
  // h1_preshowerOverSC_->Write();

  for(unsigned int i =0; i<25; i++){
    if( i < theMaxLoops ) {
      // h_ESCEtrueVsEta_[i]->Write();
      // h_ESCEtrue_[i]->Write();
      h2_chi2_[i]->Write();
      h2_iterations_[i]->Write();
      h1_zMassBarrel_[i]->Write();
      h2_coeffVsEta_loop[i]->Write();   
    }
  }

  for(unsigned int i =0; i<25; i++){
    if( i < theMaxLoops ) {
      char histoNameEta[300];
      sprintf(histoNameEta,"Prof_coeffVsEta_loop%d",i);    
      TProfile *px = h2_coeffVsEta_loop[i]->ProfileX(histoNameEta);
      px->SetXTitle("Eta channel");
      px->SetYTitle("recalibCoeff");
      px->Write();
    }    
  }

  h1_eleClasses_->Write();

  // h_eleEffEta_[0]->Write();
  // h_eleEffPhi_[0]->Write();
  // h_eleEffPt_[0]->Write();
  
  // h_eleEffEta_[1]->Write();
  // h_eleEffPhi_[1]->Write();
  // h_eleEffPt_[1]->Write();

  // h1_deltaEta -> Write();
  // h1_deltaPhi -> Write();
  // h1_sIeIe    -> Write();
  // h1_hoe      -> Write();
  // h1_eop      -> Write();
  // h1_do       -> Write();
  // h1_dz       -> Write();
  // h1_pfIso    -> Write();
  // h1_mhits    -> Write();

  // h1_afterEWK_deltaEta -> Write();
  // h1_afterEWK_deltaPhi -> Write();
  // h1_afterEWK_sIeIe    -> Write();
  // h1_afterEWK_hoe      -> Write();
  // h1_afterEWK_eop      -> Write();
  // h1_afterEWK_do       -> Write();
  // h1_afterEWK_dz       -> Write();
  // h1_afterEWK_pfIso    -> Write();
  // h1_afterEWK_mhits    -> Write();

  int j = 0;
  int flag=0;
  
  Double_t mean[25] = {0.};
  Double_t num[25]  = {0.};
  Double_t meanErr[25] = {0.};
  Float_t rms[25] = {0.};
  Float_t tempRms[10][25];
  
  for(int ia = 0; ia<10; ia++){
    for(int ib = 0; ib<25; ib++){
      tempRms[ia][ib] = 0.;
    }
  }
    
  int aa = 0;

  for( int k = 0; k<theAlgorithm_->getNumberOfChannels(); k++ ) {
      
    // grouped
    bool isNearCrack = false;    
    if( calibMode_ == "RING"){
      isNearCrack = ( abs( ringNumberCorrector(k) ) == 1 || abs( ringNumberCorrector(k) ) == 25 ||
		      abs( ringNumberCorrector(k) ) == 26 || abs( ringNumberCorrector(k) ) == 45 ||
		      abs( ringNumberCorrector(k) ) == 46 || abs( ringNumberCorrector(k) ) == 65 ||
		      abs( ringNumberCorrector(k) ) == 66 || abs( ringNumberCorrector(k) ) == 85 ||
		      abs( ringNumberCorrector(k) ) == 86 || abs( ringNumberCorrector(k) ) == 124 );
    }
    
    if(k<85) {
      
      if((k+1)%5!=0) {
	
	if(!isNearCrack){
	  mean[j]+=calibCoeff[k];
	  mean[j]+=calibCoeff[169 - k];
	  
	  num[j] += 2.;
	  
	  meanErr[j]+= 1./ pow ( calibCoeffError[k], 2 );
	  meanErr[j]+= 1./ pow ( calibCoeffError[169 - k], 2);
	  
	  tempRms[aa][j]+=calibCoeff[k];
	  aa++;
	  tempRms[aa][j]+=calibCoeff[169 - k];
	  aa++;
	}

      } else {
	
	if(!isNearCrack){
	  mean[j]+=calibCoeff[k];
	  mean[j]+=calibCoeff[169 - k];
	      
	  num[j] += 2.;
	      
	  meanErr[j]+= 1./ pow ( calibCoeffError[k], 2 );
	  meanErr[j]+= 1./ pow ( calibCoeffError[169 - k], 2);
	  
	  tempRms[aa][j]+=calibCoeff[k];
	  aa++;
	  tempRms[aa][j]+=calibCoeff[169 - k];
	  aa++;
	}
	
	j++;
	aa = 0;
      }
    }
    
    // EE begin
    if(k>=170 && k<=204){
	
      if(flag<4){
	//make groups of 5 Xtals in #eta
	mean[j]+=calibCoeff[k]/10.;
	mean[j]+=calibCoeff[k+39]/10.;
	
	meanErr[j]+= calibCoeffError[k]/30.;
	meanErr[j]+= calibCoeffError[k + 39]/30.;

	tempRms[aa][j]+=calibCoeff[k];
	aa++;
	tempRms[aa][j]+=calibCoeff[k + 39];
	aa++;
	
	flag++;

      } else if(flag==4){
      
	//make groups of 5 Xtals in #eta
	mean[j]+=calibCoeff[k]/10.;
	mean[j]+=calibCoeff[k+39]/10.;

	meanErr[j]+= calibCoeffError[k]/30.;
	meanErr[j]+= calibCoeffError[k + 39]/30.;
	  
	tempRms[aa][j]+=calibCoeff[k];
	aa++;
	tempRms[aa][j]+=calibCoeff[k + 39];
	aa++;
	  
	flag=0;
	j++;
	aa = 0;
      }	
    } 
    
    if(k>=205 && k<=208) {

      mean[j]+=calibCoeff[k]/8.;
      mean[j]+=calibCoeff[k+39]/8.;
      
      meanErr[j]+= calibCoeffError[k]/30.;
      meanErr[j]+= calibCoeffError[k + 39]/30.;
      
      tempRms[aa][j]+=calibCoeff[k];
      aa++;
      tempRms[aa][j]+=calibCoeff[k + 39];
      aa++;
    }
    // EE end
  
    if(!isNearCrack){
      h2_coeffVsEta_->Fill( ringNumberCorrector(k), calibCoeff[k] );
      h2_miscalRecal_->Fill( initCalibCoeff[k], 1./calibCoeff[k] );
      h1_mc_->Fill( initCalibCoeff[k]*calibCoeff[k] -1. );
	
      if(k<170){
	h2_miscalRecalEB_->Fill( initCalibCoeff[k], 1./calibCoeff[k] );
	h1_mcEB_->Fill( initCalibCoeff[k]*calibCoeff[k] -1. );
      }
	
      if(k>=170){
	h2_miscalRecalEE_->Fill( initCalibCoeff[k], 1./calibCoeff[k] );
	h1_mcEE_->Fill( initCalibCoeff[k]*calibCoeff[k] -1. );
      }    
    }
  }   // end loop over channels
  

  for(int ic = 0; ic< 17; ic++){
    mean[ic] = mean[ic] / num[ic];      //find mean of recalib coeff on group of rings
    //meanErr[ic] = meanErr[ic] / ( sqrt( num[ic] ) * num[ic] ); //find mean of recalib coeff on group of rings
    meanErr[ic] = 1. / sqrt(meanErr[ic]); //find mean of recalib coeff on group of rings
  }

  // build array of RMS
  for(int ic = 0; ic< 25; ic++){
    for(int id = 0; id< 10; id++){
      
      if(tempRms[id][ic] > 0.){
	rms[ic] += (tempRms[id][ic] - mean[j])*(tempRms[id][ic] - mean[j]);
      }
    }
    rms[ic]/= 10.;//this is approximate
    rms[ic] = sqrt(rms[ic]);
  }
  
  Double_t xtalEta[25] = { 1.4425, 1.3567, 1.2711, 1.1855,
			   1.10, 1.01, 0.92, 0.83,
			   0.7468, 0.6612, 0.5756, 0.4897, 0.3985, 0.3117, 0.2250, 0.1384, 0.0487,
			   1.546, 1.651, 1.771, 1.908, 2.071, 2.267, 2.516, 2.8};
  
  Double_t zero[25] = {0.026};  //interval/sqrt(12)

  for(int j = 0; j <25; j++)
    h2_coeffVsEtaGrouped_->Fill( xtalEta[j],mean[j]);
  

  TProfile *px = h2_coeffVsEta_->ProfileX("coeffVsEtaProfile");
  px->SetXTitle("Eta channel");
  px->SetYTitle("recalibCoeff");
  px->Write();

  h2_coeffVsEta_->Write();
  h2_coeffVsEtaGrouped_->Write();
  h2_zMassVsLoop_->Write();
  h2_zMassDiffVsLoop_->Write();
  h2_zMassDiffAbsVsLoop_->Write();
  h2_zWidthVsLoop_->Write();
  h2_coeffVsLoop_->Write();
  h2_miscalRecal_->Write();
  h1_mc_->Write();
  h2_miscalRecalEB_->Write();
  h1_mcEB_->Write();
  h2_miscalRecalEE_->Write();
  h1_mcEE_->Write();

  h2_residualSigma_->Write();
  

  
  const ZIterativeAlgorithmWithFit::ZIterativeAlgorithmWithFitPlots* algoHistos=theAlgorithm_->getHistos();

  double weightSumMeanBarrel = 0.;
  double weightSumMeanEndcap = 0.;

  for (int iIteration=0;iIteration<theAlgorithm_->getNumberOfIterations();iIteration++) 

    for (int iChannel=0;iChannel<theAlgorithm_->getNumberOfChannels();iChannel++) {

      if( iIteration==(theAlgorithm_->getNumberOfIterations()-1) ){
	
	if(iChannel < 170)
	  weightSumMeanBarrel += algoHistos->weightedRescaleFactor[iIteration][iChannel]->Integral()/170.; 
	
	if(iChannel >= 170)
	  weightSumMeanEndcap += algoHistos->weightedRescaleFactor[iIteration][iChannel]->Integral()/78.; 
	
	h1_occupancyVsEta_->Fill((Double_t)ringNumberCorrector(iChannel), algoHistos->weightedRescaleFactor[iIteration][iChannel]->Integral() );
	
	h1_occupancy_->Fill( algoHistos->weightedRescaleFactor[iIteration][iChannel]->Integral() );
	
	if(iChannel < 170)
	  h1_occupancyBarrel_->Fill( algoHistos->weightedRescaleFactor[iIteration][iChannel]->Integral() );
	
	if(iChannel >= 170)
	  h1_occupancyEndcap_->Fill( algoHistos->weightedRescaleFactor[iIteration][iChannel]->Integral() );
	
#ifdef DEBUG
	std::cout<<"Writing weighted integral for channel "<<ringNumberCorrector(iChannel)<<" ,value "<<algoHistos->weightedRescaleFactor[iIteration][iChannel]->Integral()<<std::endl;
#endif
	
      }
    }
  
  h1_weightSumMeanBarrel_ ->Fill(weightSumMeanBarrel);
  h1_weightSumMeanEndcap_ ->Fill(weightSumMeanEndcap);

#ifdef DEBUG  
  std::cout<<"Weight sum mean on channels in Barrel is :"<<weightSumMeanBarrel<<std::endl;
  std::cout<<"Weight sum mean on channels in Endcap is :"<<weightSumMeanEndcap<<std::endl;
#endif
  
  h1_weightSumMeanBarrel_ ->Write();
  h1_weightSumMeanEndcap_ ->Write();
  
  h1_occupancyVsEta_->Write();
  h1_occupancy_->Write();
  h1_occupancyBarrel_->Write();
  h1_occupancyEndcap_->Write();

  myTree->Write();

  TGraphErrors* graph = new TGraphErrors(25,xtalEta,mean,zero,meanErr);
  graph->Draw("APL");
  graph->Write();

  double zero50[50] = { 0. };

  TGraphErrors* residualSigmaGraph = new TGraphErrors(50,loopArray,sigmaArray,zero50,sigmaErrorArray);
  residualSigmaGraph->SetName("residualSigmaGraph");
  residualSigmaGraph->Draw("APL");
  residualSigmaGraph->Write();

  TGraphErrors* coefficientDistanceAtIterationGraph = new TGraphErrors(50,loopArray,coefficientDistanceAtIteration,zero50,zero50);
  coefficientDistanceAtIterationGraph->SetName("coefficientDistanceAtIterationGraph");
  coefficientDistanceAtIterationGraph->Draw("APL");
  coefficientDistanceAtIterationGraph->Write();
  
  Float_t noError[250] = {0.};
  
  Float_t ringInd[250];
  for(int i =0; i<250; i++)
    ringInd[i]=ringNumberCorrector(i);

  TGraphErrors* graphCoeff = new TGraphErrors(theAlgorithm_->getNumberOfChannels(),ringInd,calibCoeff,noError,calibCoeffError);
  graphCoeff->SetName("graphCoeff");
  graphCoeff->Draw("APL");
  graphCoeff->Write();
  
  h1_ZCandMult_->Write();
  h1_reco_ZMass_->Write();
  h2_reco_ZMassVsIter_->Write();
  
  h1_reco_ZMassCorr_->Write();
  h1_reco_ZMassCorrBB_->Write();
  h1_reco_ZMassCorrEE_->Write();

  outputFile_->Close();
  
  // myZeePlots_ ->writeEleHistograms();
  // myZeePlots_ ->writeMCEleHistograms();
  // myZeePlots_ ->writeZHistograms();
  // myZeePlots_ ->writeMCZHistograms();
    
  myZeeRescaleFactorPlots_ = new ZeeRescaleFactorPlots("zeeRescaleFactorPlots.root");
  myZeeRescaleFactorPlots_->writeHistograms( theAlgorithm_ );
  //  delete myZeeRescaleFactorPlots_;         // chiara: sicuri che non va acceso?

#ifdef DEBUG
  std::cout<<"[ZeeCalibration] endOfJob done"<<std::endl;
#endif
}


//_____________________________________________________________________________
// Called at each event
edm::EDLooper::Status
ZeeCalibration::duringLoop( const edm::Event& iEvent, const edm::EventSetup& iSetup ) {

  using namespace edm;
  using namespace reco;
  using namespace std;


#ifdef DEBUG
  std::cout<<"[ZeeCalibration] Entering duringLoop"<<std::endl;
#endif

  h1_Selection_->Fill(0.);

  // Get EBRecHits
  Handle<EBRecHitCollection> phits;
  try {
    iEvent.getByLabel( rechitProducer_, rechitCollection_, phits);
  } catch (std::exception& ex) {
    std::cerr << "Error! can't get the product EBRecHitCollection " << std::endl;
  }
  const EBRecHitCollection* hits = phits.product();     

  // Get EERecHits
  Handle<EERecHitCollection> ephits;
  try {
    iEvent.getByLabel( erechitProducer_, erechitCollection_, ephits);
  } catch (std::exception& ex) {
    std::cerr << "Error! can't get the product EERecHitCollection " << std::endl;
  }
  const EERecHitCollection* ehits = ephits.product();   

  if ( !hits && !ehits){
    std::cout << "!hits" << std::endl;   
    return kContinue;
  }
  if (hits->size() == 0 && ehits->size() == 0){
    std::cout << "hits->size() == 0" << std::endl;   
    return kContinue;
  }  

  // Get SuperClusters in EB
  Handle<reco::SuperClusterCollection> pSuperClustersEB;
  try {
    iEvent.getByLabel(ebSuperclusters_, pSuperClustersEB);
  } catch (std::exception& ex) {
    std::cerr << "Error! can't get the product pSuperClustersEB " << std::endl;
  }
  const reco::SuperClusterCollection* ebScCollection = pSuperClustersEB.product();

  // Get SuperClusters in EE      
  Handle<reco::SuperClusterCollection> pSuperClustersEE;
  try {
    iEvent.getByLabel(eeSuperclusters_, pSuperClustersEE);
  } catch (std::exception& ex) {
    std::cerr << "Error! can't get the product pSuperClustersEE " << std::endl;
  }
  const reco::SuperClusterCollection* eeScCollection = pSuperClustersEE.product();

  if ( !ebScCollection && !eeScCollection ){
    std::cout << "!SC" << std::endl;   
    return kContinue;
  }

#ifdef DEBUG_COLL
  cout << "taken: " 
       << ebScCollection->size() << " sc in EB, " 
       << eeScCollection->size() << " sc in EE, "
       << hits->size()           << " rechits in EB, "
       << ehits->size()          << " rechits in EE, " << endl;
#endif
  
#ifdef DEBUG_COLL
  std::cout<<"EB: ebScCollection->size() = " << ebScCollection->size() << std::endl;
  for(reco::SuperClusterCollection::const_iterator scIt = ebScCollection->begin(); scIt != ebScCollection->end(); scIt++) {
    std::cout << scIt->energy() << " " << scIt->eta() << " " << scIt->phi() << std::endl;
  }
  std::cout<<"EE: eeScCollection->size() = " << eeScCollection->size() << std::endl;
  for(reco::SuperClusterCollection::const_iterator scIt = eeScCollection->begin(); scIt != eeScCollection->end(); scIt++) {
    std::cout << scIt->energy() << " " << scIt->eta() << " " << scIt->phi() << std::endl;
  }
  std::cout << std::endl;
#endif
  
  // at least 2 superclusters must be present
  if(  ( ebScCollection->size()+eeScCollection->size() ) < 2) return kContinue;
  h1_Selection_->Fill(1.);
  
  

  // Get Electrons
  Handle<reco::GsfElectronCollection> pElectrons;
  try {
    iEvent.getByLabel(electrons_, pElectrons);
  } catch (std::exception& ex) {
    std::cerr << "Error! can't get the product pElectrons " << std::endl;
  }
  const reco::GsfElectronCollection* electronCollection = pElectrons.product();
  
  if (!electronCollection){
    std::cout << "!electronCollection" << std::endl;
    return kContinue;
  }
  
#ifdef DEBUG_COLL
  std::cout<<"electronCollection->size() = " << electronCollection->size() << std::endl;
  for(reco::GsfElectronCollection::const_iterator eleIt = electronCollection->begin(); eleIt != electronCollection->end(); eleIt++) {
    std::cout << eleIt->energy() << " " << eleIt->eta() << " " << eleIt->phi() << std::endl;
  }
  std::cout << std::endl;
#endif

  if(electronCollection->size() < 2) return kContinue; 
  h1_Selection_->Fill(2.);    
  

  ///////////////////////////////////////////////////////////////////////////////////////
  ///                          START HERE....
  ///////////////////////////////////////////////////////////////////////////////////////
  
  read_events++;
  
#ifdef DEBUG
  std::cout <<" Starting with myZeePlots_->fillEleInfo(electronCollection); " << std::endl; 
#endif
  
  // if (loopFlag_ == 0)
  //   myZeePlots_->fillEleInfo(electronCollection);
  
#ifdef DEBUG
  std::cout <<" Done with myZeePlots_->fillEleInfo(electronCollection); " << std::endl; 
#endif

  // Filling new ElectronCollection with new SC ref and calibElectron container
  std::vector<calib::CalibElectron> calibElectrons;

  // Geometrical match between superclusters and electrons
  for(reco::GsfElectronCollection::const_iterator eleIt = electronCollection->begin(); eleIt != electronCollection->end(); eleIt++) {

    if (!(eleIt->parentSuperCluster()))
      continue;

    // only electrons in the acceptance and with pT above threshold
    float etaFromSc   = eleIt->parentSuperCluster()->eta();
    float thetaFromSc = eleIt->parentSuperCluster()->position().theta();
    float ptFromSc    = (eleIt->parentSuperCluster()->energy())*fabs(sin(thetaFromSc));
    if (ptFromSc<20) continue;                // chiara: hardcoded!
    if (fabs(etaFromSc)>2.5) continue;

    float DeltaRMineleSCbarrel(0.15);
    float DeltaRMineleSCendcap(0.15);

    const reco::SuperCluster* sc=0;

    // loop on EB superClusters   
    if(eleIt->isEB()) 
      {   // chiara: gap EB/EE excluded
	for(reco::SuperClusterCollection::const_iterator scEbIt = ebScCollection->begin(); scEbIt != ebScCollection->end(); scEbIt++) 
	  {
	    double DeltaReleSC = deltaR(eleIt->parentSuperCluster()->eta(),eleIt->parentSuperCluster()->phi(),scEbIt->eta(),scEbIt->phi());
	      if(DeltaReleSC<DeltaRMineleSCbarrel) 
		{
		  DeltaRMineleSCbarrel = DeltaReleSC;
		  sc=&(*scEbIt);
		} 
	  }
      } 
    else if(eleIt->isEE()) 
      {   // chiara: gap EB/EE excluded
	for(reco::SuperClusterCollection::const_iterator scEeIt = eeScCollection->begin(); scEeIt != eeScCollection->end(); scEeIt++){
	  double DeltaReleSC = deltaR(eleIt->parentSuperCluster()->eta(),eleIt->parentSuperCluster()->phi(),scEeIt->eta(),scEeIt->phi());
	  if(DeltaReleSC<DeltaRMineleSCendcap) {
	    DeltaRMineleSCendcap = DeltaReleSC;
	    sc = &(*scEeIt);
	  }
	}
      }
    
    if(!sc) continue;

    calibElectrons.push_back(calib::CalibElectron(&(*eleIt),sc,hits,ehits));

#ifdef DEBUG
    std::cout << "calibElectrons.back().getParentSuperCluster()->energy() = " 
	      << calibElectrons.back().getParentSuperCluster()->energy() 
	      << ", calibElectrons.back().getRecoElectron()->energy() = " 
	      << calibElectrons.back().getRecoElectron()->energy() << std::endl;
#endif
  }
  
#ifdef DEBUG
  std::cout << "calibElectrons.size() = " << calibElectrons.size() << endl; 
#endif
  
#ifdef DEBUG
  std::cout << "Filled histos" << std::endl;
#endif  

  // COMBINATORY FOR Z MASS - begin 
  if (calibElectrons.size() < 2) return kContinue;
  h1_Selection_->Fill(3.);

#ifdef DEBUG
  std::cout << "building zeeCandidates" << std::endl;
#endif  

  std::vector<std::pair<calib::CalibElectron*,calib::CalibElectron*> > zeeCandidates;
  int  myBestZ=-1;
  mass = -1.;
  double DeltaMinvMin(5000.);

  for(unsigned int e_it = 0 ; e_it != calibElectrons.size() - 1 ; e_it++) {
    for(unsigned int p_it = e_it + 1 ; p_it != calibElectrons.size() ; p_it++) {
      
#ifdef DEBUG
      std::cout << e_it << " " << calibElectrons[e_it].getRecoElectron()->charge() << " " 
		<< p_it << " " << calibElectrons[p_it].getRecoElectron()->charge() << std::endl;
#endif		
      
      // opposite charge
      if ( requireOppositeCharge_ && (calibElectrons[e_it].getRecoElectron()->charge() * calibElectrons[p_it].getRecoElectron()->charge() != -1) ) continue;
      
      // when selecting the same SC for the two electrons I drop the event 
      if (calibElectrons[e_it].getParentSuperCluster() == calibElectrons[p_it].getParentSuperCluster()) continue;

      // chiara: bisogna capire in 72x che correzioni sono applicate a ele->sc->energy
      mass = ZeeKinematicTools::calculateZMass_withTK(std::pair<calib::CalibElectron*,calib::CalibElectron*>(&(calibElectrons[e_it]),&(calibElectrons[p_it])));

      if (mass<0) continue;
      
#ifdef DEBUG
      std::cout << "####################### mass = " << mass << std::endl;
#endif
      zeeCandidates.push_back(std::pair<calib::CalibElectron*,calib::CalibElectron*>(&(calibElectrons[e_it]),&(calibElectrons[p_it])));

      double DeltaMinv = fabs(mass - MZ); 
      if( DeltaMinv < DeltaMinvMin) {
	DeltaMinvMin = DeltaMinv;
	myBestZ=zeeCandidates.size()-1;
      }
    }
  }      
  
  h1_ZCandMult_->Fill(zeeCandidates.size());

  if(zeeCandidates.size()==0 || myBestZ==-1 ) return kContinue;
  h1_Selection_->Fill(4.);

  // if (loopFlag_ == 0)
  //   myZeePlots_->fillZInfo( zeeCandidates[myBestZ] );
  
#ifdef DEBUG  
  std::cout << "Found ZCandidates: " << myBestZ << std::endl;
#endif  

  // -----------------------------------  DUMP ELECTRON CLASS
  // Classification:
  // enum Classification { UNKNOWN=-1, GOLDEN=0, BIGBREM=1, BADTRACK=2, SHOWERING=3, GAP=4 } 
  // in DataFormats/EgammaCandidates/interface/GsfElecron.h

  int class1 = zeeCandidates[myBestZ].first->getRecoElectron()->classification();
  int class2 = zeeCandidates[myBestZ].second->getRecoElectron()->classification();
  h1_eleClasses_->Fill(zeeCandidates[myBestZ].first->getRecoElectron()->classification());
  h1_eleClasses_->Fill(zeeCandidates[myBestZ].second->getRecoElectron()->classification());

  float eta1 = zeeCandidates[myBestZ].first->getParentSuperCluster()->eta();
  float eta2 = zeeCandidates[myBestZ].second->getParentSuperCluster()->eta();

  if(fabs(eta1)<1.5) TOTAL_ELECTRONS_IN_BARREL++;
  else TOTAL_ELECTRONS_IN_ENDCAP++;
  if(fabs(eta2)<1.5) TOTAL_ELECTRONS_IN_BARREL++;
  else TOTAL_ELECTRONS_IN_ENDCAP++;
    
  if( class1==0 && fabs(eta1)<1.5) GOLDEN_ELECTRONS_IN_BARREL++;
  if( class1==0 && fabs(eta1)>1.5) GOLDEN_ELECTRONS_IN_ENDCAP++;
  if( class2==0 && fabs(eta2)<1.5) GOLDEN_ELECTRONS_IN_BARREL++;
  if( class2==0 && fabs(eta2)>1.5) GOLDEN_ELECTRONS_IN_ENDCAP++;
    
  // ----------------------------------  EXCLUDE ELECTRONS HAVING HOTTEST XTAL WHICH IS A BORDER XTAL
  // chiara: questo paolo lo aveva commentato, begin
  /*
  DetId firstElehottestDetId  = getHottestDetId( zeeCandidates[myBestZ].first->getParentSuperCluster()->seed()->hitsAndFractions(), hits, ehits ).first;   
  DetId secondElehottestDetId = getHottestDetId( zeeCandidates[myBestZ].second->getParentSuperCluster()->seed()->hitsAndFractions(), hits, ehits ).first;
  
  bool firstElectronIsOnModuleBorder(false);
  bool secondElectronIsOnModuleBorder(false);
  
  h1_eventsBeforeBorderSelection_->Fill(1);
  
  if(fabs(eta1)<1.5){
    if( firstElehottestDetId.subdetId() == EcalBarrel) {
      BARREL_ELECTRONS_BEFORE_BORDER_CUT++;
      firstElectronIsOnModuleBorder = xtalIsOnModuleBorder( firstElehottestDetId ); 
      if ( !firstElectronIsOnModuleBorder ) BARREL_ELECTRONS_AFTER_BORDER_CUT++;
    }
  }
  
  if(fabs(eta2)<1.5){
    if( secondElehottestDetId.subdetId() == EcalBarrel) {
      BARREL_ELECTRONS_BEFORE_BORDER_CUT++;
      secondElectronIsOnModuleBorder = xtalIsOnModuleBorder( secondElehottestDetId );
      if( !secondElectronIsOnModuleBorder ) BARREL_ELECTRONS_AFTER_BORDER_CUT++;
    }
  }
  
  if (fabs(eta1)<1.5) {
    if ( firstElehottestDetId.subdetId()==EcalBarrel && firstElectronIsOnModuleBorder ){
      h1_borderElectronClassification_ -> Fill( zeeCandidates[myBestZ].first->getRecoElectron()->classification() );
      return kContinue;
    }  
  }
  
  if(fabs(eta2)<1.5){
    if ( secondElehottestDetId.subdetId()==EcalBarrel && secondElectronIsOnModuleBorder ){ 
      h1_borderElectronClassification_ -> Fill( zeeCandidates[myBestZ].second->getRecoElectron()->classification() );
      return kContinue;
    }
  }

  h1_eventsAfterBorderSelection_->Fill(1);
  // chiara: questo paolo lo aveva commentato, end
  // ------------------------------------------------------------------------


  // counting EB/EB - EE/EE - golden etc combinations after border selection
  if( fabs(eta1)<1.5 && fabs(eta2)<1.5 ){
    BBZN++;
    if(class1==0 && class2==0) BBZN_gg++;
  }

  if( fabs(eta1)>1.5 && fabs(eta2)>1.5 ){
    EEZN++;
    if(class1==0 && class2==0) EEZN_gg++;
  }
  
  if( (fabs(eta1)<1.5 && fabs(eta2)>1.5) || (fabs(eta2)<1.5 && fabs(eta1)>1.5)){
    EBZN++;
    if(class1==0 && class2==0) EBZN_gg++;
  }
  */
  ///////////////////////////ELECTRON SELECTION///////////////////////////////
  if(myBestZ == -1) return kContinue;
  h1_Selection_->Fill(5.);

  h1_massBeforeCut_->Fill(mass);
  bool invMassBool = ( (mass > minInvMassCut_) && (mass < maxInvMassCut_) );
  if (!invMassBool) return kContinue;
  h1_massAfterCut_->Fill(mass);

  h1_Selection_->Fill(6.);


  // Variables implementation from
  // https://github.com/lgray/cmssw/blob/common_isolation_selection_70X/TestElectronID/ElectronIDAnalyzer/plugins/ElectronIDAnalyzer.cc
  bool selectionBool = false;  

  h1_Selection_->Fill(7.);
  
  // ----------------------------------------------------------------------
  // extra selections (on top of ID + mass window) based on EB/EE and class
  // not to apply them => electronSelection_ = -1
  if(electronSelection_==-1) selectionBool=( myBestZ != -1 );

  // 0 = all electrons but not gap
  if(electronSelection_==0) selectionBool=( myBestZ != -1 && 
					    zeeCandidates[myBestZ].first->getRecoElectron()->classification()!= 4 && 
					    zeeCandidates[myBestZ].second->getRecoElectron()->classification()!= 4 );
  
  // 1 = all electrons are Golden
  if(electronSelection_==1) selectionBool=( myBestZ != -1 &&
					    zeeCandidates[myBestZ].first->getRecoElectron()->classification()==0 &&
					    zeeCandidates[myBestZ].second->getRecoElectron()->classification()==0 );

  
  // 2 = all Endcap electrons (but no crack)
  if(electronSelection_==2) selectionBool=( myBestZ != -1 && 
					    fabs(eta1)>1.5 && zeeCandidates[myBestZ].first->getRecoElectron()->classification()!=4 &&
					    fabs(eta2)>1.5 && zeeCandidates[myBestZ].second->getRecoElectron()->classification()!= 4
					    );


  // 3 = all Barrel electrons (but no crack)
  if(electronSelection_==3) selectionBool=( myBestZ != -1 && 
					    fabs(eta1)<1.5 && zeeCandidates[myBestZ].first->getRecoElectron()->classification()!=4 &&
					    fabs(eta2)<1.5 && zeeCandidates[myBestZ].second->getRecoElectron()->classification()!= 4
					    );

  // 4 = this eliminates the events which have 1 ele in the Barrel and 1 in the Endcap
  if(electronSelection_==4) selectionBool=( myBestZ != -1 && 
					    ( (fabs(eta1)<1.5 && fabs(eta2)<1.5) || (fabs(eta1)>1.5 && fabs(eta2)>1.5) )
					    );

  if (!selectionBool) return kContinue;
  // ----------------------------------------------------------------------

  // chiara: ora queste correzioni sono state sostituite dalla regression. Commento tutto
  float ele1EnergyCorrection(1.);
  float ele2EnergyCorrection(1.);
  // if(invMassBool && selectionBool && wantEtaCorrection_) {
  //  ele1EnergyCorrection=getEtaCorrection(zeeCandidates[myBestZ].first->getRecoElectron());
  //  ele2EnergyCorrection=getEtaCorrection(zeeCandidates[myBestZ].second->getRecoElectron());
  //}
  if (invMassBool && selectionBool) { 

    // SC energies without f(eta) corrections
    // h1_electronCosTheta_SC_    -> Fill( ZeeKinematicTools::cosThetaElectrons_SC(zeeCandidates[myBestZ])  );
    // h1_electronCosTheta_TK_    -> Fill( ZeeKinematicTools::cosThetaElectrons_TK(zeeCandidates[myBestZ])  );
    // h1_electronCosTheta_SC_TK_ -> Fill( ZeeKinematicTools::cosThetaElectrons_SC(zeeCandidates[myBestZ])/ZeeKinematicTools::cosThetaElectrons_TK(zeeCandidates[myBestZ]) - 1. );

    mass4tree = ZeeKinematicTools::calculateZMassWithCorrectedElectrons_withTK(zeeCandidates[myBestZ],ele1EnergyCorrection,ele2EnergyCorrection);
    
    h1_reco_ZMass_->Fill(mass4tree);
    h2_reco_ZMassVsIter_->Fill(loopFlag_,mass4tree);

    // PUT f(eta) IN OUR Zee ALGORITHM 
    theAlgorithm_->addEvent(zeeCandidates[myBestZ].first, zeeCandidates[myBestZ].second,MZ*sqrt(ele1EnergyCorrection*ele2EnergyCorrection) );
    // SC energies after f(eta) corrections - fuffa, perche' ora le correzioni sono vuote
    h1_reco_ZMassCorr_->Fill(mass4tree);
    isEBEB=0;
    if (fabs(eta1)<1.5 && fabs(eta2)<1.5 )  
      {     
	h1_zMassBarrel_[loopFlag_]->Fill(mass4tree);
	h1_reco_ZMassCorrBB_->Fill(mass4tree);
	isEBEB=1;
      }
    if (fabs(eta1)>1.5 && fabs(eta2)>1.5 )       
      h1_reco_ZMassCorrEE_->Fill(mass4tree);


    //    massDiff4tree = ZeeKinematicTools::calculateZMassWithCorrectedElectrons_withTK(zeeCandidates[myBestZ],ele1EnergyCorrection,ele2EnergyCorrection) - myGenZMass;
    myTree->Fill();
  }

#ifdef DEBUG
  std::cout << "Added event to algorithm" << std::endl;  
#endif

  return kContinue;
}

// Called at beginning of loop (re-inizialization of everything)
void ZeeCalibration::startingNewLoop ( unsigned int iLoop ) {

#ifdef DEBUG
  std::cout<< "[ZeeCalibration] Starting loop number " << iLoop<<std::endl;
#endif
  
  theAlgorithm_->resetIteration();
  
  resetVariables();
  
  resetHistograms(); 
}
 
// Called at end of loop
// control plots; computation of new coefficients + residual miscalib; comparison new/old coeff
 edm::EDLooper::Status 
   ZeeCalibration::endOfLoop(const edm::EventSetup& iSetup, unsigned int iLoop) {
   
#ifdef DEBUG
  std::cout<<"[ZeeCalibration] starting endOfLoop"<<std::endl;
#endif

  double par[3];
  double errpar[3];
  double zChi2;
  int zIters;
  
  ZIterativeAlgorithmWithFit::gausfit(h1_reco_ZMass_,par,errpar,2.,2., &zChi2, &zIters );
  h2_zMassVsLoop_     -> Fill(loopFlag_,  par[1] );
  h2_zMassDiffVsLoop_ -> Fill(loopFlag_,  (par[1]-MZ)/MZ );
  h2_zMassDiffAbsVsLoop_ -> Fill(loopFlag_,  par[1]-MZ );
  h2_zWidthVsLoop_    -> Fill(loopFlag_, par[2] );


  // RUN the algorithm - real computation of coefficients for this loop (with a fit to the histos which are filled in addEvent)
  theAlgorithm_->iterate();

  const std::vector<float>& optimizedCoefficients      = theAlgorithm_->getOptimizedCoefficients();
  const std::vector<float>& optimizedCoefficientsError = theAlgorithm_->getOptimizedCoefficientsError();
  const std::vector<float>& optimizedChi2              = theAlgorithm_->getOptimizedChiSquare();
  const std::vector<int>& optimizedIterations          = theAlgorithm_->getOptimizedIterations();

#ifdef DEBUG
  std::cout<< "Optimized coefficients " << optimizedCoefficients.size() <<std::endl;
#endif

  // define NewCalibCoeff
  for (unsigned int ieta=0;ieta<optimizedCoefficients.size();ieta++) {
    
    NewCalibCoeff[ieta] = calibCoeff[ieta] * optimizedCoefficients[ieta];
    
    h2_chi2_[loopFlag_]->Fill( ringNumberCorrector( ieta ), optimizedChi2[ieta] );
    h2_iterations_[loopFlag_]->Fill( ringNumberCorrector( ieta ), optimizedIterations[ieta] );
  }

  // comparison between new and old coefficients
  coefficientDistanceAtIteration[loopFlag_]= computeCoefficientDistanceAtIteration(calibCoeff, NewCalibCoeff, optimizedCoefficients.size() );
#ifdef DEBUG
  std::cout<<"Iteration # : "<< loopFlag_ << " CoefficientDistanceAtIteration "<< coefficientDistanceAtIteration[loopFlag_] <<std::endl;
#endif

  // computing the new coefficients
  for (unsigned int ieta=0;ieta<optimizedCoefficients.size();ieta++) {
    
    calibCoeff[ieta] *= optimizedCoefficients[ieta];
    calibCoeffError[ieta] = calibCoeff[ieta] * sqrt ( pow( optimizedCoefficientsError[ieta]/optimizedCoefficients[ieta], 2 ) + pow( calibCoeffError[ieta]/calibCoeff[ieta] , 2 )  );
    
#ifdef DEBUG
    std::cout<< ieta << " " << optimizedCoefficients[ieta] <<std::endl;  
#endif
    
    
    std::vector<DetId> ringIds;
    
    if(calibMode_ == "RING")
      ringIds = EcalRingCalibrationTools::getDetIdsInRing(ieta);

    if(calibMode_ == "MODULE")
      ringIds = EcalRingCalibrationTools::getDetIdsInModule(ieta);

    if(calibMode_ == "ABS_SCALE" || calibMode_ == "ETA_ET_MODE" )
      ringIds = EcalRingCalibrationTools::getDetIdsInECAL();

  
    for (unsigned int iid=0; iid<ringIds.size();++iid){
	
      if(ringIds[iid].subdetId() == EcalBarrel){
	EBDetId myEBDetId(ringIds[iid]);  
	h2_xtalRecalibCoeffBarrel_[loopFlag_]->SetBinContent( myEBDetId.ieta() + 86, myEBDetId.iphi(), 100 * (calibCoeff[ieta]*initCalibCoeff[ieta] - 1.) );

	// filling extra histos to debug - barrel only 
	h1_calibCoeffBeforeBarrel_[loopFlag_]->Fill(calibCoeff[ieta]/optimizedCoefficients[ieta]);
	h1_calibCoeffAfterBarrel_[loopFlag_]->Fill(calibCoeff[ieta]);
	h1_initCalibCoeffBarrel_[loopFlag_]->Fill(initCalibCoeff[ieta]);
	h2_calibCoeffVsInitCalibCoeffBarrel_[loopFlag_]->Fill(initCalibCoeff[ieta],calibCoeff[ieta]);
      }

      if(ringIds[iid].subdetId() == EcalEndcap){
	EEDetId myEEDetId(ringIds[iid]);
	if(myEEDetId.zside() < 0)
	  h2_xtalRecalibCoeffEndcapMinus_[loopFlag_]->SetBinContent( myEEDetId.ix(), myEEDetId.iy(), 100 * (calibCoeff[ieta]*initCalibCoeff[ieta] - 1.) );

	if(myEEDetId.zside() > 0)
	  h2_xtalRecalibCoeffEndcapPlus_[loopFlag_]->SetBinContent( myEEDetId.ix(), myEEDetId.iy(), 100 * (calibCoeff[ieta]*initCalibCoeff[ieta] - 1.) );
      }

      ical->setValue( ringIds[iid], *(ical->getMap().find(ringIds[iid])  ) * optimizedCoefficients[ieta] );
    }    
  }
  
  for( int kkk = 0; kkk<theAlgorithm_->getNumberOfChannels(); kkk++ ) {  
    h2_coeffVsEta_loop[loopFlag_]->Fill( ringNumberCorrector(kkk), calibCoeff[kkk] );
  }

  // dump residual miscalibration at each loop 
  for ( int k = 0; k<theAlgorithm_->getNumberOfChannels(); k++ ) {
    bool isNearCrack = ( abs( ringNumberCorrector(k) ) == 1 || abs( ringNumberCorrector(k) ) == 25 ||
			 abs( ringNumberCorrector(k) ) == 26 || abs( ringNumberCorrector(k) ) == 45 ||
			 abs( ringNumberCorrector(k) ) == 46 || abs( ringNumberCorrector(k) ) == 65 ||
			 abs( ringNumberCorrector(k) ) == 66 || abs( ringNumberCorrector(k) ) == 85 ||
			 abs( ringNumberCorrector(k) ) == 86 || abs( ringNumberCorrector(k) ) == 124 );
    
    if(!isNearCrack){

      h1_mcParz_[iLoop]->Fill( initCalibCoeff[k]*calibCoeff[k] -1. );
	
      if(k<170)
	h1_mcEBParz_[iLoop]->Fill( initCalibCoeff[k]*calibCoeff[k] -1. );
	
      if(k>=170)
	h1_mcEEParz_[iLoop]->Fill( initCalibCoeff[k]*calibCoeff[k] -1. );
    }
  }
  
  // ----------------------------------
  double parResidual[3];
  double errparResidual[3];
  double zResChi2;
  int zResIters;
  
  ZIterativeAlgorithmWithFit::gausfit(h1_mcParz_[iLoop],parResidual,errparResidual,3.,3., &zResChi2, &zResIters);
  
  h2_residualSigma_ -> Fill(loopFlag_ + 1,  parResidual[2]);
  loopArray[loopFlag_] = loopFlag_ + 1;
  sigmaArray[loopFlag_] = parResidual[2];
  sigmaErrorArray[loopFlag_] = errparResidual[2];

#ifdef DEBUG  
  std::cout<<"Fit on residuals, sigma is " << parResidual[2] << " +/- " << errparResidual[2] << std::endl;
#endif
  
  outputFile_->cd();

  // histos
  h1_mcParz_[iLoop]->Write();
  h1_mcEBParz_[iLoop]->Write();
  h1_mcEEParz_[iLoop]->Write();
  h2_xtalRecalibCoeffBarrel_[loopFlag_] -> Write();
  h2_xtalRecalibCoeffEndcapPlus_[loopFlag_] -> Write();
  h2_xtalRecalibCoeffEndcapMinus_[loopFlag_] -> Write();

  h1_calibCoeffBeforeBarrel_[iLoop]->Write();
  h1_calibCoeffAfterBarrel_[iLoop]->Write();
  h1_initCalibCoeffBarrel_[iLoop]->Write();
  h2_calibCoeffVsInitCalibCoeffBarrel_[iLoop]->Write();
  
  loopFlag_++;
  
#ifdef DEBUG  
  std::cout<<" loopFlag_ is "<<loopFlag_<<std::endl;
#endif  
 
  if ( iLoop == theMaxLoops-1 || iLoop >= theMaxLoops ) return kStop;
  else return kContinue;
}

// Control histograms
void ZeeCalibration::bookHistograms() {

  h1_Selection_ = new TH1F("h1_Selection","h1_Selection",10,-0.5,9.5);

  h1_massBeforeCut_ = new TH1F("h1_massBeforeCut_","h1_massBeforeCut_",150,0.,150.); 
  h1_massAfterCut_  = new TH1F("h1_massAfterCut_", "h1_massAfterCut_", 150,0.,150.); 

  // h1_eventsBeforeBorderSelection_ = new TH1F("h1_eventsBeforeBorderSelection", "h1_eventsBeforeBorderSelection", 5,0,5); 
  // h1_eventsAfterBorderSelection_  = new TH1F("h1_eventsAfterBorderSelection", "h1_eventsAfterBorderSelection", 5,0,5);
  // h1_borderElectronClassification_ = new TH1F("h1_borderElectronClassification", "h1_borderElectronClassification", 6, -1, 5);

  // h1_seedOverSC_ = new TH1F("h1_seedOverSC", "h1_seedOverSC", 400, 0., 2.);
  // h1_preshowerOverSC_= new TH1F("h1_preshowerOverSC", "h1_preshowerOverSC", 400, 0., 1.);

  /*
  for (int i=0;i<2;i++) {

    char histoName[50];

    sprintf(histoName,"h_eleEffEta_%d",i);
    h_eleEffEta_[i] = new TH1F(histoName,histoName, 150, 0., 2.7);
    h_eleEffEta_[i]->SetXTitle("|#eta|");
    
    sprintf(histoName,"h_eleEffPhi_%d",i);
    h_eleEffPhi_[i] = new TH1F(histoName,histoName, 400, -4., 4.);
    h_eleEffPhi_[i]->SetXTitle("Phi");
    
    sprintf(histoName,"h_eleEffPt_%d",i);
    h_eleEffPt_[i] = new TH1F(histoName,histoName, 200, 0., 200.);
    h_eleEffPt_[i]->SetXTitle("p_{T}(GeV/c)");
  }
  */

  h2_xtalMiscalibCoeffBarrel_ = new TH2F("h2_xtalMiscalibCoeffBarrel","h2_xtalMiscalibCoeffBarrel", 171, -85, 85, 360, 0, 360);
  h2_xtalMiscalibCoeffEndcapMinus_ = new TH2F("h2_xtalMiscalibCoeffEndcapMinus", "h2_xtalMiscalibCoeffEndcapMinus", 100, 0,100, 100, 0, 100);
  h2_xtalMiscalibCoeffEndcapPlus_ = new TH2F("h2_xtalMiscalibCoeffEndcapPlus", "h2_xtalMiscalibCoeffEndcapPlus", 100, 0,100, 100, 0, 100);
  
  h2_xtalMiscalibCoeffBarrel_ ->SetXTitle("ieta");
  h2_xtalMiscalibCoeffBarrel_ ->SetYTitle("iphi");
  
  h2_xtalMiscalibCoeffEndcapMinus_->SetXTitle("ix");
  h2_xtalMiscalibCoeffEndcapMinus_->SetYTitle("iy");

  for (int i=0;i<25;i++) {
      
    char histoName[50];

    // sprintf(histoName,"h_ESCEtrueVsEta_%d",i);
    // h_ESCEtrueVsEta_[i] = new TH2F(histoName,histoName, 150, 0., 2.7, 300,0.,1.5);
    // h_ESCEtrueVsEta_[i]->SetXTitle("|#eta|");
    // h_ESCEtrueVsEta_[i]->SetYTitle("E_{SC,raw}/E_{MC}");
    
    // sprintf(histoName,"h_ESCEtrue_%d",i);
    // h_ESCEtrue_[i] = new TH1F(histoName,histoName, 300,0.,1.5);

    sprintf(histoName,"h1_zMassBarrel_%d",i);
    h1_zMassBarrel_[i] = new TH1F(histoName,histoName, 120,30.,150.);

    sprintf(histoName,"h2_chi2_%d",i);
    h2_chi2_[i] = new TH2F(histoName,histoName, 1000,-150,150, 1000, -1, 5);
    
    sprintf(histoName,"h2_iterations_%d",i);
    h2_iterations_[i] = new TH2F(histoName,histoName, 1000,-150,150, 1000, -1, 15);
    
    sprintf(histoName,"h2_xtalRecalibCoeffBarrel_%d",i);
    h2_xtalRecalibCoeffBarrel_[i] = new TH2F(histoName,histoName, 171, -85, 85, 360, 0, 360);
    
    h2_xtalRecalibCoeffBarrel_[i]->SetXTitle("ieta");
    h2_xtalRecalibCoeffBarrel_[i]->SetYTitle("iphi");

    sprintf(histoName,"h2_xtalRecalibCoeffEndcapMinus_%d",i);
    h2_xtalRecalibCoeffEndcapMinus_[i] = new TH2F(histoName,histoName, 100, 0,100, 100, 0, 100);
    h2_xtalRecalibCoeffEndcapMinus_[i]->SetXTitle("ix");
    h2_xtalRecalibCoeffEndcapMinus_[i]->SetYTitle("iy");
    
    sprintf(histoName,"h2_xtalRecalibCoeffEndcapPlus_%d",i);
    h2_xtalRecalibCoeffEndcapPlus_[i] = new TH2F(histoName,histoName, 100, 0,100, 100, 0, 100);
    h2_xtalRecalibCoeffEndcapPlus_[i]->SetXTitle("ix");
    h2_xtalRecalibCoeffEndcapPlus_[i]->SetYTitle("iy");

    sprintf(histoName,"h2_calibCoeffVsEta_loop%d",i);
    h2_coeffVsEta_loop[i]= new TH2F(histoName,histoName,249,-124,125, 200, 0., 2.);
    h2_coeffVsEta_loop[i]->SetXTitle("Eta channel");
    h2_coeffVsEta_loop[i]->SetYTitle("recalibCoeff");
  }                         

  // h1_zMassResol_ = new TH1F("zMassResol", "zMassResol", 200, -50., 50.);
  // h1_zMassResol_->SetXTitle("M_{Z, reco} - M_{Z, MC}");
  // h1_zMassResol_->SetYTitle("events");

  // h1_eleEtaResol_ = new TH1F("eleEtaResol", "eleEtaResol", 100, -0.01, 0.01);
  // h1_eleEtaResol_->SetXTitle("#eta_{reco} - #eta_{MC}");
  // h1_eleEtaResol_->SetYTitle("events");

  // h1_electronCosTheta_TK_ = new TH1F("electronCosTheta_TK", "electronCosTheta_TK", 100, -1, 1);
  // h1_electronCosTheta_TK_->SetXTitle("cos #theta_{12}");
  // h1_electronCosTheta_TK_->SetYTitle("events");

  // h1_electronCosTheta_SC_ = new TH1F("electronCosTheta_SC", "electronCosTheta_SC", 100, -1, 1);
  // h1_electronCosTheta_SC_->SetXTitle("cos #theta_{12}");
  // h1_electronCosTheta_SC_->SetYTitle("events");

  // h1_electronCosTheta_SC_TK_ = new TH1F("electronCosTheta_SC_TK", "electronCosTheta_SC_TK", 200, -0.1, 0.1);
  // h1_electronCosTheta_SC_TK_->SetXTitle("cos #theta_{12}^{SC}/ cos #theta_{12}^{TK} - 1");
  // h1_electronCosTheta_SC_TK_->SetYTitle("events");
  
  // h1_elePhiResol_ = new TH1F("elePhiResol", "elePhiResol", 100, -0.01, 0.01);
  // h1_elePhiResol_->SetXTitle("#phi_{reco} - #phi_{MC}");
  // h1_elePhiResol_->SetYTitle("events");

  // h1_zEtaResol_ = new TH1F("zEtaResol", "zEtaResol", 200, -1., 1.);
  // h1_zEtaResol_->SetXTitle("#eta_{Z, reco} - #eta_{Z, MC}");
  // h1_zEtaResol_->SetYTitle("events");
  
  // h1_zPhiResol_ = new TH1F("zPhiResol", "zPhiResol", 200, -1., 1.);
  // h1_zPhiResol_->SetXTitle("#phi_{Z, reco} - #phi_{Z, MC}");
  // h1_zPhiResol_->SetYTitle("events");

  // h1_nEleReco_ = new TH1F("nEleReco","Number of reco electrons",10,-0.5,10.5);
  // h1_nEleReco_->SetXTitle("nEleReco");
  // h1_nEleReco_->SetYTitle("events");
  
  h1_occupancyVsEta_ = new TH1F("occupancyVsEta","occupancyVsEta",249, -124, 124);
  h1_occupancyVsEta_->SetYTitle("Weighted electron statistics");
  h1_occupancyVsEta_->SetXTitle("Eta channel");

  h1_weightSumMeanBarrel_= new TH1F("weightSumMeanBarrel","weightSumMeanBarrel",10000, 0, 10000);
  h1_weightSumMeanEndcap_= new TH1F("weightSumMeanEndcap","weightSumMeanEndcap",10000, 0, 10000);
  
  h1_occupancy_ = new TH1F("occupancy","occupancy",1000,0,10000);
  h1_occupancy_->SetXTitle("Weighted electron statistics");

  h1_occupancyBarrel_ = new TH1F("occupancyBarrel","occupancyBarrel",1000,0,10000);
  h1_occupancyBarrel_->SetXTitle("Weighted electron statistics");

  h1_occupancyEndcap_ = new TH1F("occupancyEndcap","occupancyEndcap",1000,0,10000);
  h1_occupancyEndcap_->SetXTitle("Weighted electron statistics");
  
  h1_eleClasses_= new TH1F("eleClasses","eleClasses",6,-1,5);
  h1_eleClasses_->SetXTitle("classCode");
  h1_eleClasses_->SetYTitle("#");

  // myZeePlots_ -> bookHLTHistograms();
  // myZeePlots_ -> bookZMCHistograms();
  // myZeePlots_ -> bookZHistograms();
  // myZeePlots_ -> bookEleMCHistograms();	
  // myZeePlots_ -> bookEleHistograms();		
  
  h1_ZCandMult_ =new TH1F("ZCandMult","Multiplicity of Z candidates in one event",10,-0.5,10.5);
  h1_ZCandMult_ ->SetXTitle("ZCandMult");
  
  h1_reco_ZMass_ = new TH1F("reco_ZMass","Inv. mass of 2 reco Electrons",200,0.,150.);
  h1_reco_ZMass_->SetXTitle("reco_ZMass (GeV)");
  h1_reco_ZMass_->SetYTitle("events");

  h2_reco_ZMassVsIter_ = new TH2F("reco_ZMassVsIter","Inv. mass of 2 reco Electrons",20,-0.5,19.5,200,0.,150.);
  h2_reco_ZMassVsIter_->SetXTitle("#iteration");
  h2_reco_ZMassVsIter_->SetYTitle("reco_ZMass (GeV)");
  h2_reco_ZMassVsIter_->SetZTitle("events");

  h1_reco_ZMassCorr_ = new TH1F("reco_ZMassCorr","Inv. mass of 2 corrected reco Electrons",200,0.,150.);
  h1_reco_ZMassCorr_->SetXTitle("reco_ZMass (GeV)");
  h1_reco_ZMassCorr_->SetYTitle("events");

  h1_reco_ZMassCorrBB_ = new TH1F("reco_ZMassCorrBB","Inv. mass of 2 corrected reco Electrons",200,0.,150.);
  h1_reco_ZMassCorrBB_->SetXTitle("reco_ZMass (GeV)");
  h1_reco_ZMassCorrBB_->SetYTitle("events");
  
  h1_reco_ZMassCorrEE_ = new TH1F("reco_ZMassCorrEE","Inv. mass of 2 corrected reco Electrons",200,0.,150.);
  h1_reco_ZMassCorrEE_->SetXTitle("reco_ZMass (GeV)");
  h1_reco_ZMassCorrEE_->SetYTitle("events");
  
  h2_coeffVsEta_= new TH2F("h2_calibCoeffVsEta","h2_calibCoeffVsEta",249,-124,125, 200, 0., 2.);
  h2_coeffVsEta_->SetXTitle("Eta channel");
  h2_coeffVsEta_->SetYTitle("recalibCoeff");

  h2_coeffVsEtaGrouped_= new TH2F("h2_calibCoeffVsEtaGrouped","h2_calibCoeffVsEtaGrouped", 200, 0., 3., 200, 0.6, 1.4);
  h2_coeffVsEtaGrouped_->SetXTitle("|#eta|");
  h2_coeffVsEtaGrouped_->SetYTitle("recalibCoeff");

  h2_zMassVsLoop_= new TH2F("h2_zMassVsLoop","h2_zMassVsLoop",1000,0,40,200,90.,120.);

  h2_zMassDiffVsLoop_= new TH2F("h2_zMassDiffVsLoop","h2_zMassDiffVsLoop",1000,0,40, 100, -1., 1.);
  h2_zMassDiffVsLoop_->SetXTitle("Iteration");
  h2_zMassDiffVsLoop_->SetYTitle("(M_{Z, reco peak} - M_{Z, true})/M_{Z, true}");

  h2_zMassDiffAbsVsLoop_= new TH2F("h2_zMassDiffAbsVsLoop","h2_zMassDiffAbsVsLoop",1000,0,40, 100, -10., 10.);
  h2_zMassDiffAbsVsLoop_->SetXTitle("Iteration");
  h2_zMassDiffAbsVsLoop_->SetYTitle("M_{Z, reco peak} - M_{Z, true}");
  
  h2_zWidthVsLoop_= new TH2F("h2_zWidthVsLoop","h2_zWidthVsLoop",1000,0,40, 100, 0.,10.);

  h2_coeffVsLoop_= new TH2F("h2_coeffVsLoop","h2_coeffVsLoop",1000,0,40, 100, 0., 2.);

  h2_residualSigma_= new TH2F("h2_residualSigma","h2_residualSigma",1000, 0, 40, 100, 0., .5);

  h2_miscalRecal_ = new TH2F("h2_miscalRecal","h2_miscalRecal", 500, 0., 2., 500, 0., 2.);
  h2_miscalRecal_->SetXTitle("initCalibCoeff");
  h2_miscalRecal_->SetYTitle("1/RecalibCoeff");
 
  h2_miscalRecalEB_ = new TH2F("h2_miscalRecalEB","h2_miscalRecalEB", 500, 0., 2., 500, 0., 2.);
  h2_miscalRecalEB_->SetXTitle("initCalibCoeff");
  h2_miscalRecalEB_->SetYTitle("1/RecalibCoeff");

  h2_miscalRecalEE_ = new TH2F("h2_miscalRecalEE","h2_miscalRecalEE", 500, 0., 2., 500, 0., 2.);
  h2_miscalRecalEE_->SetXTitle("initCalibCoeff");
  h2_miscalRecalEE_->SetYTitle("1/RecalibCoeff");

  h1_mc_ = new TH1F("h1_residualMiscalib","h1_residualMiscalib", 200, -0.2, 0.2);
  h1_mcEB_ = new TH1F("h1_residualMiscalibEB","h1_residualMiscalibEB", 200, -0.2, 0.2);
  h1_mcEE_ = new TH1F("h1_residualMiscalibEE","h1_residualMiscalibEE", 200, -0.2, 0.2);
 
  for (int i=0;i<25;i++) {
    char histoName[500];
    sprintf(histoName,"h1_residualMiscalibParz_%d",i);
    h1_mcParz_[i] = new TH1F(histoName,histoName, 200, -0.2, 0.2);
    sprintf(histoName,"h1_residualMiscalibEBParz_%d",i);
    h1_mcEBParz_[i] = new TH1F(histoName,histoName, 200, -0.2, 0.2);
    sprintf(histoName,"h1_residualMiscalibEEParz_%d",i);
    h1_mcEEParz_[i] = new TH1F(histoName,histoName, 200, -0.2, 0.2);

    // chiara
    sprintf(histoName,"calibCoeffBeforeBarrelParz_%d",i);
    h1_calibCoeffBeforeBarrel_[i] = new TH1F(histoName,histoName, 200, 0., 2.);
    sprintf(histoName,"calibCoeffAfterBarrelParz_%d",i);
    h1_calibCoeffAfterBarrel_[i] = new TH1F(histoName,histoName, 200, 0., 2.);
    sprintf(histoName,"initCalibCoeffBarrelParz_%d",i);
    h1_initCalibCoeffBarrel_[i] = new TH1F(histoName,histoName, 200, 0., 2.);
    sprintf(histoName,"h2_calibCoeffVsInitCalibCoeffBarrel_%d",i);
    h2_calibCoeffVsInitCalibCoeffBarrel_[i] = new TH2F(histoName,histoName,100, 0.5, 1.5,200, 0., 2.);
  }


  // h1_deltaEta = new TH1F("h1_deltaEta","h1_deltaEta",50,-0.01,0.01);
  // h1_deltaPhi = new TH1F("h1_deltaPhi","h1_deltaPhi",50,-0.07,0.07);
  // h1_sIeIe    = new TH1F("h1_sIeIe",   "h1_sIeIe",   50,0.005,0.020);
  // h1_hoe      = new TH1F("h1_hoe",     "h1_hoe",     50,-0.15,0.15);
  // h1_eop      = new TH1F("h1_eop",     "h1_eop",     50,-0.03,0.02);
  // h1_do       = new TH1F("h1_do",      "h1_do",      50,-0.04,0.04);
  // h1_dz       = new TH1F("h1_dz",      "h1_dz",      50,-0.04,0.04);
  // h1_pfIso    = new TH1F("h1_pfIso",   "h1_pfIso",   50,0.00,2.00);
  // h1_mhits    = new TH1F("h1_mhits",   "h1_mhits",   5,-0.5,4.5);
  //
  // h1_afterEWK_deltaEta = new TH1F("h1_afterEWK_deltaEta","h1_afterEWK_deltaEta",50,-0.01,0.01);
  // h1_afterEWK_deltaPhi = new TH1F("h1_afterEWK_deltaPhi","h1_afterEWK_deltaPhi",50,-0.07,0.07);
  // h1_afterEWK_sIeIe    = new TH1F("h1_afterEWK_sIeIe",   "h1_afterEWK_sIeIe",   50,0.005,0.020);
  // h1_afterEWK_hoe      = new TH1F("h1_afterEWK_hoe",     "h1_afterEWK_hoe",     50,-0.15,0.15);
  // h1_afterEWK_eop      = new TH1F("h1_afterEWK_eop",     "h1_afterEWK_eop",     50,-0.03,0.02);
  // h1_afterEWK_do       = new TH1F("h1_afterEWK_do",      "h1_afterEWK_do",      50,-0.04,0.04);
  // h1_afterEWK_dz       = new TH1F("h1_afterEWK_dz",      "h1_afterEWK_dz",      50,-0.04,0.04);
  // h1_afterEWK_pfIso    = new TH1F("h1_afterEWK_pfIso",   "h1_afterEWK_pfIso",   50,0.00,2.00);
  // h1_afterEWK_mhits    = new TH1F("h1_afterEWK_mhits",   "h1_afterEWK_mhits",   5,-0.5,4.5);
}

/*
double ZeeCalibration::fEtaBarrelBad(double scEta) const{
  
  float p0 = 1.00153e+00;
  float p1 = 3.29331e-02;
  float p2 = 1.21187e-03;
  
  double x  = (double) fabs(scEta);

  return 1. / ( p0 + p1*x*x + p2*x*x*x*x );  
}

double ZeeCalibration::fEtaEndcapGood(double scEta) const{

  // f(eta) for the first 3 classes (100, 110 and 120) 
  // Ivica's new corrections 01/06
  float p0 = 1.06819e+00;
  float p1 = -1.53189e-02;
  float p2 = 4.01707e-04 ;
  
  double x  = (double) fabs(scEta);
  
  return 1. / ( p0 + p1*x*x + p2*x*x*x*x );  
}

double ZeeCalibration::fEtaEndcapBad(double scEta) const{
  
  float p0 = 1.17382e+00;
  float p1 = -6.52319e-02; 
  float p2 = 6.26108e-03;

  double x  = (double) fabs(scEta);

  return 1. / ( p0 + p1*x*x + p2*x*x*x*x );  
}

double ZeeCalibration::fEtaBarrelGood(double scEta) const{
  
  float p0 = 9.99782e-01 ;
  float p1 = 1.26983e-02;
  float p2 = 2.16344e-03;
  
  double x  = (double) fabs(scEta);
  
  return 1. / ( p0 + p1*x*x + p2*x*x*x*x );  
}
*/


int ZeeCalibration::ringNumberCorrector(int k) {

  int index=-999;
  
  if( calibMode_ == "RING"){
    if(k>=0 && k<=84)    index = k - 85;
    if(k>=85 && k<=169)  index = k - 84;
    if(k>=170 && k<=208) index = - k + 84;
    if(k>=209 && k<=247) index = k - 123;
  }
  
  else if( calibMode_ == "MODULE"){
    if(k>=0 && k<=71)   index = k - 72;
    if(k>=72 && k<=143) index = k - 71;
  }

  return index;
}

/*
double ZeeCalibration::getEtaCorrection(const reco::GsfElectron* ele){

  double correction(1.);

  if(ele->classification() ==0 ||
     ele->classification() ==10 ||
     ele->classification() ==20)
    correction = fEtaBarrelGood(ele->superCluster()->eta());
                                                                                                                                               
  if(ele->classification() ==100 ||
     ele->classification() ==110 ||
     ele->classification() ==120)
    correction = fEtaEndcapGood(ele->superCluster()->eta());
                                                                                                                                               
  if(ele->classification() ==30 ||
     ele->classification() ==31 ||
     ele->classification() ==32 ||
     ele->classification() ==33 ||
     ele->classification() ==34)
    correction = fEtaBarrelBad(ele->superCluster()->eta());

  if(ele->classification() ==130 ||
     ele->classification() ==131 ||
     ele->classification() ==132 ||
     ele->classification() ==133 ||
     ele->classification() ==134)
    correction = fEtaEndcapBad(ele->superCluster()->eta());
 
  return correction;                                         
}
*/

std::pair<DetId, double> ZeeCalibration::getHottestDetId(const std::vector<std::pair< DetId,float > >& mySCRecHits, const EBRecHitCollection* ebhits, const EERecHitCollection* eehits){
  
  double maxEnergy = -9999.;
  const EcalRecHit* hottestRecHit=0;
  
  std::pair<DetId, double> myPair (DetId(0), -9999.);

  for(   std::vector<std::pair<DetId,float> >::const_iterator idIt=mySCRecHits.begin(); idIt != mySCRecHits.end(); idIt++){
   
    if (idIt->first.subdetId() == EcalBarrel ) {
      hottestRecHit  = & (* ( ebhits->find((*idIt).first) ) );
      if( hottestRecHit == & (*( ebhits->end())) ) {
	std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@ NO RECHIT FOUND SHOULD NEVER HAPPEN"<<std::endl;
	continue;
      }
    }
    else if (idIt->first.subdetId() == EcalEndcap ) {
      hottestRecHit  = & (* ( eehits->find((*idIt).first) ) );
      if( hottestRecHit == & (*( eehits->end())) ) {
	std::cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@ NO RECHIT FOUND SHOULD NEVER HAPPEN"<<std::endl;
	continue;
      }
    }    
    
    if(hottestRecHit && hottestRecHit->energy() > maxEnergy){
      maxEnergy = hottestRecHit->energy();
      myPair.first  = hottestRecHit ->id();
      myPair.second = maxEnergy;
    }
    
  } //end loop to find hottest RecHit    
  
  return myPair;
}

bool ZeeCalibration::xtalIsOnModuleBorder( EBDetId myEBDetId ){
  
  bool myBool(false); 
  
  short ieta = myEBDetId.ieta();
  short iphi = myEBDetId.iphi();
  
  myBool = ( abs( ieta )  == 1 || abs( ieta ) == 25
	     || abs( ieta ) == 26 || abs( ieta ) == 45
	     || abs( ieta ) == 46 || abs( ieta ) == 65
	     || abs( ieta ) == 66 || abs( ieta ) == 85 );
  
  for(int i = 0; i < 19; i++){
    if(iphi == ( 20*i + 1 ) || iphi == 20*i )
      myBool = true;
  }
  
  return myBool;
}

float ZeeCalibration::computeCoefficientDistanceAtIteration( float v1[250], float v2[250], int size ){

  float dist(0.);
  
  for(int i =0; i < size; i++) {

    bool isNearCrack = false;

    if( calibMode_ == "RING"){ // exclude non-calibrated rings from computation
      isNearCrack = ( abs( ringNumberCorrector(i) ) == 1 || abs( ringNumberCorrector(i) ) == 25 ||
		      abs( ringNumberCorrector(i) ) == 26 || abs( ringNumberCorrector(i) ) == 45 ||
		      abs( ringNumberCorrector(i) ) == 46 || abs( ringNumberCorrector(i) ) == 65 ||
		      abs( ringNumberCorrector(i) ) == 66 || abs( ringNumberCorrector(i) ) == 85 ||
		      abs( ringNumberCorrector(i) ) == 86 || abs( ringNumberCorrector(i) ) == 124 );
    }
    
    if(!isNearCrack)
      dist += pow( v1[i]-v2[i], 2 );
  }
  
  dist = sqrt(dist) / size;
  
  return dist;
}


void ZeeCalibration::resetVariables(){

 BBZN=0;
 EBZN=0;
 EEZN=0;
 BBZN_gg=0;
 EBZN_gg=0;
 EEZN_gg=0;

 TOTAL_ELECTRONS_IN_BARREL=0;
 TOTAL_ELECTRONS_IN_ENDCAP=0;

 GOLDEN_ELECTRONS_IN_BARREL=0;
 GOLDEN_ELECTRONS_IN_ENDCAP=0;

 BARREL_ELECTRONS_BEFORE_BORDER_CUT = 0;
 BARREL_ELECTRONS_AFTER_BORDER_CUT = 0;

 return;
}

void ZeeCalibration::resetHistograms(){

  h1_Selection_->Reset();

  h1_massBeforeCut_->Reset();
  h1_massAfterCut_->Reset();
  
  // h1_eventsBeforeBorderSelection_ ->Reset();
  // h1_eventsAfterBorderSelection_  ->Reset();

  // for (int i=0;i<2;i++) {
  // h_eleEffEta_[i] ->Reset();
  // h_eleEffPhi_[i] ->Reset(); 
  // h_eleEffPt_[i]  ->Reset();
  // }

  // h1_seedOverSC_ ->Reset();
  // h1_preshowerOverSC_ ->Reset();
  
  // h1_eleEtaResol_->Reset();
  // h1_elePhiResol_->Reset();
  
  // h1_zMassResol_->Reset(); 

  // h1_electronCosTheta_TK_->Reset();
  // h1_electronCosTheta_SC_->Reset();
  // h1_electronCosTheta_SC_TK_->Reset();
  
  h1_eleClasses_->Reset();
  
  h1_ZCandMult_-> Reset();
  h1_reco_ZMass_-> Reset();

  h1_reco_ZMassCorr_-> Reset();
  h1_reco_ZMassCorrBB_-> Reset();
  h1_reco_ZMassCorrEE_-> Reset();
  h1_occupancyVsEta_-> Reset();
  h1_occupancy_-> Reset();
  h1_occupancyBarrel_-> Reset();
  h1_occupancyEndcap_-> Reset();

  // h1_deltaEta -> Reset();
  // h1_deltaPhi -> Reset();
  // h1_sIeIe    -> Reset();
  // h1_hoe      -> Reset();
  // h1_eop      -> Reset();
  // h1_do       -> Reset();
  // h1_dz       -> Reset();
  // h1_pfIso    -> Reset();
  // h1_mhits    -> Reset();

  // h1_afterEWK_deltaEta -> Reset();
  // h1_afterEWK_deltaPhi -> Reset();
  // h1_afterEWK_sIeIe    -> Reset();
  // h1_afterEWK_hoe      -> Reset();
  // h1_afterEWK_eop      -> Reset();
  // h1_afterEWK_do       -> Reset();
  // h1_afterEWK_dz       -> Reset();
  // h1_afterEWK_pfIso    -> Reset();
  // h1_afterEWK_mhits    -> Reset();

  return;
}

void ZeeCalibration::printStatistics(){

  std::cout<< "[ CHECK ON BARREL ELECTRON NUMBER ]"
	   <<" first "<<BARREL_ELECTRONS_BEFORE_BORDER_CUT<<" second "<<TOTAL_ELECTRONS_IN_BARREL << std::endl;
  
  std::cout<< "[ EFFICIENCY OF THE BORDER SELECTION ]" 
	   << (float)BARREL_ELECTRONS_AFTER_BORDER_CUT / (float) BARREL_ELECTRONS_BEFORE_BORDER_CUT << std::endl;
  
  std::cout<< "[ EFFICIENCY OF THE GOLDEN SELECTION ] BARREL: " 
	   << (float)GOLDEN_ELECTRONS_IN_BARREL / (float) TOTAL_ELECTRONS_IN_BARREL << " ENDCAP: "
	   << (float)GOLDEN_ELECTRONS_IN_ENDCAP / (float) TOTAL_ELECTRONS_IN_ENDCAP << std::endl;
  
  std::ofstream fout("ZeeStatistics.txt");
  
  if(!fout) {
    std::cout << "Cannot open output file.\n";
  }

  fout<<"ZeeStatistics"<<std::endl;

  fout<<"##########################RECO#########################"<<std::endl;
  fout<<"##################Zee with Barrel-Barrel electrons: "<<BBZN<<std::endl;
  fout<<"Golden-Golden fraction: "<<(float)BBZN_gg/BBZN<<std::endl;
  fout<<"##################Zee with Barrel-Endcap electrons: "<<EBZN<<std::endl;
  fout<<"Golden-Golden fraction: "<<(float)EBZN_gg/EBZN<<std::endl;
  fout<<"##################Zee with Endcap-Endcap electrons: "<<EEZN<<std::endl;
  fout<<"Golden-Golden fraction: "<<(float)EEZN_gg/EEZN<<std::endl;

  fout<<"\n"<<std::endl;

  fout<<"##########################GEN#########################"<<std::endl;
  fout<<"##################Zee with Barrel-Barrel electrons: "<<(float)MCZBB/NEVT<<std::endl;
  fout<<"##################Zee with Barrel-Endcap electrons: "<<(float)MCZEB/NEVT<<std::endl;
  fout<<"##################Zee with Endcap-Endcap electrons: "<<(float)MCZEE/NEVT<<std::endl;

  fout.close();
}
