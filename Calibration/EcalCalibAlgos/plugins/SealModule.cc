#include "FWCore/Framework/interface/MakerMacros.h"
#include "Calibration/EcalCalibAlgos/interface/EcalEleCalibLooper.h"
#include "Calibration/EcalCalibAlgos/interface/InvRingCalib.h"
#include "Calibration/EcalCalibAlgos/interface/miscalibExample.h"
#include "Calibration/EcalCalibAlgos/interface/ZeeCalibration.h"
#include "Calibration/EcalCalibAlgos/interface/ZeeScSelection.h"
#include "Calibration/EcalCalibAlgos/interface/ZeeCalibSkim.h"
//#include "Calibration/EcalCalibAlgos/interface/GEDElectronRecalibSuperClusterAssociator.h"
#include "Calibration/EcalCalibAlgos/interface/PhiSymmetryCalibration.h"
#include "Calibration/EcalCalibAlgos/interface/Pi0FixedMassWindowCalibration.h"

DEFINE_FWK_MODULE(miscalibExample);
DEFINE_FWK_MODULE(ZeeScSelection);
//DEFINE_FWK_MODULE(GEDElectronRecalibSuperClusterAssociator);
DEFINE_FWK_MODULE(PhiSymmetryCalibration);
DEFINE_FWK_MODULE(ZeeCalibSkim);
DEFINE_FWK_LOOPER(Pi0FixedMassWindowCalibration);
DEFINE_FWK_LOOPER(ZeeCalibration);
DEFINE_FWK_LOOPER(EcalEleCalibLooper);
DEFINE_FWK_LOOPER(InvRingCalib);

