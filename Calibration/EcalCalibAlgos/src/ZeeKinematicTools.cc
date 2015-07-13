
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "CondFormats/EcalObjects/interface/EcalIntercalibConstants.h"
#include "CondFormats/DataRecord/interface/EcalIntercalibConstantsRcd.h"
#include "Calibration/Tools/interface/calibXMLwriter.h"
#include "Calibration/Tools/interface/CalibrationCluster.h"
#include "Calibration/Tools/interface/HouseholderDecomposition.h"
#include "Calibration/Tools/interface/MinL3Algorithm.h"
#include "Calibration/EcalCalibAlgos/interface/ZeeKinematicTools.h"
#include "Calibration/Tools/interface/ZIterativeAlgorithmWithFit.h"
#include "DataFormats/EgammaCandidates/interface/Electron.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/TrackExtraFwd.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TRandom.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"

ZeeKinematicTools::ZeeKinematicTools(){}

ZeeKinematicTools::~ZeeKinematicTools(){}


//--------------------------------------------

 float ZeeKinematicTools::calculateZMassWithCorrectedElectrons_noTK(const std::pair<calib::CalibElectron*,calib::CalibElectron*>& aZCandidate, float ele1EnergyCorrection, float ele2EnergyCorrection)
{
  return ZIterativeAlgorithmWithFit::invMassCalc(aZCandidate.first->getParentSuperCluster()->energy() / ele1EnergyCorrection, aZCandidate.first->getParentSuperCluster()->eta(), aZCandidate.first->getParentSuperCluster()->phi(), aZCandidate.second->getParentSuperCluster()->energy() / ele2EnergyCorrection, aZCandidate.second->getParentSuperCluster()->eta(), aZCandidate.second->getParentSuperCluster()->phi());

}

//--------------------------------------------

 float ZeeKinematicTools::calculateZMassWithCorrectedElectrons_withTK(const std::pair<calib::CalibElectron*,calib::CalibElectron*>& aZCandidate, float ele1EnergyCorrection, float ele2EnergyCorrection)
{
  return ZIterativeAlgorithmWithFit::invMassCalc(aZCandidate.first->getParentSuperCluster()->energy() / ele1EnergyCorrection, aZCandidate.first->getRecoElectron()->eta(), aZCandidate.first->getRecoElectron()->phi(), aZCandidate.second->getParentSuperCluster()->energy() / ele2EnergyCorrection, aZCandidate.second->getRecoElectron()->eta(), aZCandidate.second->getRecoElectron()->phi());

}

//--------------------------------------------

 float ZeeKinematicTools::calculateZMass_noTK(const std::pair<calib::CalibElectron*,calib::CalibElectron*>& aZCandidate)
{

  return  ZIterativeAlgorithmWithFit::invMassCalc(aZCandidate.first->getParentSuperCluster()->energy(), aZCandidate.first->getParentSuperCluster()->eta(), aZCandidate.first->getParentSuperCluster()->phi(), aZCandidate.second->getParentSuperCluster()->energy(), aZCandidate.second->getParentSuperCluster()->eta(), aZCandidate.second->getParentSuperCluster()->phi());  

}

//--------------------------------------------

float ZeeKinematicTools::calculateZMass_withTK(const std::pair<calib::CalibElectron*,calib::CalibElectron*>& aZCandidate)
{
  return  ZIterativeAlgorithmWithFit::invMassCalc(aZCandidate.first->getParentSuperCluster()->energy(), aZCandidate.first->getRecoElectron()->eta(), aZCandidate.first->getRecoElectron()->phi(), aZCandidate.second->getParentSuperCluster()->energy(), aZCandidate.second->getRecoElectron()->eta(), aZCandidate.second->getRecoElectron()->phi());  

}

//--------------------------------------------

 float ZeeKinematicTools::calculateZRapidity(const std::pair<calib::CalibElectron*,calib::CalibElectron*>& aZCandidate)
{

  TLorentzVector ele1LV( aZCandidate.first->getRecoElectron()->px(), aZCandidate.first->getRecoElectron()->py(), aZCandidate.first->getRecoElectron()->pz(), aZCandidate.first->getParentSuperCluster()->energy());

  TLorentzVector ele2LV( aZCandidate.second->getRecoElectron()->px(), aZCandidate.second->getRecoElectron()->py(), aZCandidate.second->getRecoElectron()->pz(), aZCandidate.second->getParentSuperCluster()->energy());
  

  return  (ele1LV + ele2LV).Rapidity();

}

//--------------------------------------------

 float ZeeKinematicTools::calculateZEta(const std::pair<calib::CalibElectron*,calib::CalibElectron*>& aZCandidate)
{

  TLorentzVector ele1LV( aZCandidate.first->getRecoElectron()->px(), aZCandidate.first->getRecoElectron()->py(), aZCandidate.first->getRecoElectron()->pz(), aZCandidate.first->getParentSuperCluster()->energy());

  TLorentzVector ele2LV( aZCandidate.second->getRecoElectron()->px(), aZCandidate.second->getRecoElectron()->py(), aZCandidate.second->getRecoElectron()->pz(), aZCandidate.second->getParentSuperCluster()->energy());
  
  return  (ele1LV + ele2LV).Eta();
  
}

//--------------------------------------------

 float ZeeKinematicTools::calculateZTheta(const std::pair<calib::CalibElectron*,calib::CalibElectron*>& aZCandidate)
{

  TLorentzVector ele1LV( aZCandidate.first->getRecoElectron()->px(), aZCandidate.first->getRecoElectron()->py(), aZCandidate.first->getRecoElectron()->pz(), aZCandidate.first->getParentSuperCluster()->energy());

  TLorentzVector ele2LV( aZCandidate.second->getRecoElectron()->px(), aZCandidate.second->getRecoElectron()->py(), aZCandidate.second->getRecoElectron()->pz(), aZCandidate.second->getParentSuperCluster()->energy());
  
  return  (ele1LV + ele2LV).Theta();
  
}

//--------------------------------------------

 float ZeeKinematicTools::calculateZPhi(const std::pair<calib::CalibElectron*,calib::CalibElectron*>& aZCandidate)
{

  TLorentzVector ele1LV( aZCandidate.first->getRecoElectron()->px(), aZCandidate.first->getRecoElectron()->py(), aZCandidate.first->getRecoElectron()->pz(), aZCandidate.first->getParentSuperCluster()->energy());

  TLorentzVector ele2LV( aZCandidate.second->getRecoElectron()->px(), aZCandidate.second->getRecoElectron()->py(), aZCandidate.second->getRecoElectron()->pz(), aZCandidate.second->getParentSuperCluster()->energy());
  
  return  (ele1LV + ele2LV).Phi();

}

//--------------------------------------------

 float ZeeKinematicTools::calculateZPt(const std::pair<calib::CalibElectron*,calib::CalibElectron*>& aZCandidate)
{

  TLorentzVector ele1LV( aZCandidate.first->getRecoElectron()->px(), aZCandidate.first->getRecoElectron()->py(), aZCandidate.first->getRecoElectron()->pz(), aZCandidate.first->getParentSuperCluster()->energy());

  TLorentzVector ele2LV( aZCandidate.second->getRecoElectron()->px(), aZCandidate.second->getRecoElectron()->py(), aZCandidate.second->getRecoElectron()->pz(), aZCandidate.second->getParentSuperCluster()->energy());
  
  return  (ele1LV + ele2LV).Pt();

}



