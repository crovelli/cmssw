#ifndef EcalRingCalibrationTools_h
#define EcalRingCalibrationTools_h

/****************************************
 *
 *   25/09/2007 P. Meridiani (CERN)
 *   Description:
 *   Tools to ease the hanling of indices  
 *   for ECAL ring intercalibration
 *
 ***************************************/

#include <vector>
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/EcalDetId/interface/EEDetId.h"
#include <map>


class DetId;
class CaloGeometry;

class EcalRingCalibrationTools 
{
 public:
  EcalRingCalibrationTools() {};
  ~EcalRingCalibrationTools() {};
  
  /// Retrieve the phi-ring index corresponding to a DetId 
  static short getRingIndex(DetId aDetId); 

  static short getModuleIndex(DetId aDetId); 

  static int getHashedIndex(DetId aDetId);  

  /// Map to associate hashed index and ring index 
  static std::map<int,short> HashedToRingIndex();
  static std::map<int,short> HashedToRingIndexEE();
  
  /// Retrieve the DetIds in a phi-ring 
  static std::vector<DetId> getDetIdsInRing(short aRingIndex);
  static std::vector<DetId> getDetIdsInModule(short int);  
  static std::vector<DetId> getDetIdsInECAL();  
  static std::vector<DetId> getOrderedDetIdsInECAL();  

  static const short N_RING_TOTAL = 248;
  static const short N_RING_BARREL = 170 ;
  static const short N_RING_ENDCAP = 78;

  static const short N_MODULES_BARREL = 144;

  static const int N_XTAL_TOTAL = 75848;
  static const int N_XTAL_BARREL = 61200;
  static const int N_XTAL_ENDCAP = 14648;

  static void setCaloGeometry(const CaloGeometry* geometry) { caloGeometry_ = geometry; };

 private:

  static void initializeFromGeometry(); //needed only for the endcap
  
  static bool isInitializedFromGeometry_;
  static short endcapRingIndex_[EEDetId::IX_MAX][EEDetId::IY_MAX]; //array needed only for the endcaps 
  static const CaloGeometry* caloGeometry_;

};
#endif
