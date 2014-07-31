#ifndef RecoLocalCalo_EcalRecAlgos_EcalUncalibRecHitOutOfTimeSubtractionAlgo_HH
#define RecoLocalCalo_EcalRecAlgos_EcalUncalibRecHitOutOfTimeSubtractionAlgo_HH

/** \class EcalUncalibRecHitOutOfTimeSubtractionAlgo
 *  Template used to compute amplitude, pedestal, time jitter, chi2 of a pulse
 *  using a ratio method
 *
 *  $Id: EcalUncalibRecHitOutOfTimeSubtractionAlgo.h,v 1.50 2012/06/11 21:02:13 wmtan Exp $
 *  $Date: 2012/06/11 21:02:13 $
 *  $Revision: 1.50 $
 *  \author E. Di Marco
 */

#include "Math/SVector.h"
#include "Math/SMatrix.h"
#include "RecoLocalCalo/EcalRecAlgos/interface/EcalUncalibRecHitRecAbsAlgo.h"
#include "CondFormats/EcalObjects/interface/EcalSampleMask.h"
#include <vector>

template < class C > class EcalUncalibRecHitOutOfTimeSubtractionAlgo {
 public:
  struct CalculatedExtraHit {
    double amplitudeMax;
    double timeMax;
    double amplitudeExtapolated;
  };

  virtual ~ EcalUncalibRecHitOutOfTimeSubtractionAlgo < C > () { };
  // function to be able to compute
  // amplitude and time of the OOT pileup
  void init( const C &dataFrame, const EcalPedestals::Item * aped, const EcalMGPAGainRatio * aGain, std::vector<C> neighbors );
  double pulseShapeFunction(double t);
  void computeAmplitudeOOT( std::vector< double > &amplitudeFitParameters, std::vector< double > &subtractionLimits, double time );
  CalculatedExtraHit getCalculatedExtraHit() { return calculatedExtrahit_; };
  
 protected:
  
  DetId          theDetId_;
  std::vector < double > amplitudes_;
  double pedestal_;
  double alpha_, beta_, alphabeta_;

  CalculatedExtraHit calculatedExtrahit_;
};

template<class C> double EcalUncalibRecHitOutOfTimeSubtractionAlgo<C>::pulseShapeFunction(double t){
  if( alphabeta_ <= 0 ) return((double)0.);
  double t0 = calculatedExtrahit_.timeMax;
  //  std::cout << "alphabeta_ = " << alphabeta_ << "   t0 = " << t0 << "   t = " << t << std::endl;
  double dtsbeta,variable,puiss;
  double dt = t-t0 ;
  if(dt > -alphabeta_)  {
    // std::cout << "deltat = " << dt << std::endl;
    dtsbeta=dt/beta_ ;
    variable=1.+dt/alphabeta_ ;
    puiss=pow(variable,alpha_);
    //    std::cout << "the normalization at t0 = " << t0 << " is A_out = " << amplitudes_[calculatedExtrahit_.timeMax] << std::endl;
    int intTime = int(calculatedExtrahit_.timeMax);
    if(intTime<0) intTime = 0;
    if(intTime>9) intTime = 9;
    return amplitudes_[intTime]*puiss*exp(-dtsbeta) ;
  }
  return  0.0 ;
}

template <class C>
void EcalUncalibRecHitOutOfTimeSubtractionAlgo<C>::init( const C &dataFrame, const EcalPedestals::Item * aped, const EcalMGPAGainRatio * aGain,
                                                         std::vector<C> neighbors ) {
    
  theDetId_ = DetId(dataFrame.id().rawId());  
  calculatedExtrahit_.timeMax = 5;
  calculatedExtrahit_.amplitudeMax = 0;
  calculatedExtrahit_.amplitudeExtapolated = 0;
  amplitudes_.clear();
  amplitudes_.reserve(C::MAXSAMPLES);
	
  // obtain the max sample in the 3x3 matrix. 
  // pedestal is super-simple: 200 ADC (we are interested only in the time of the max here)
  int max5x5Ampli=-100;
  int max5x5Sample=5;
  for(typename std::vector<C>::const_iterator itn=neighbors.begin(); itn!=neighbors.end(); ++itn) {
    for(int iSample = 0; iSample < C::MAXSAMPLES; iSample++) {
      int gainId = itn->sample(iSample).gainId(); 

      int  sampleAdc = 0;
      if ( gainId == 1 ) sampleAdc = itn->sample(iSample).adc() - 200;
      else if ( gainId == 2 ) sampleAdc = (itn->sample(iSample).adc() - 200) * 2 ;
      else sampleAdc = (dataFrame.sample(iSample).adc() - 200) * 12 ;

      if( sampleAdc > max5x5Ampli ) {
        max5x5Ampli  = sampleAdc;
        max5x5Sample = iSample;
      }
    }// loop on samples
  } // loop over neighbors
  
  if(neighbors.size()>0) {
    calculatedExtrahit_.amplitudeMax = max5x5Ampli;
    calculatedExtrahit_.timeMax = max5x5Sample;
  } else calculatedExtrahit_.amplitudeMax = -100.;

  // now compute the samples for the reconstructed rechit 
  // with pedestal subtraction scheme that is consistent with the local reco 
  for (int iSample = 0; iSample < C::MAXSAMPLES; iSample++) {
    
    const EcalMGPASample &sample = dataFrame.sample(iSample);

    double amplitude = 0.;
    int gainId = sample.gainId();

    double pedestal = 0.;
    double gainratio = 1.;
    
    if (gainId==0 || gainId==3) {
      pedestal = aped->mean_x1;
      gainratio = aGain->gain6Over1()*aGain->gain12Over6();
    }
    else if (gainId==1) {
      pedestal = aped->mean_x12;
      gainratio = 1.;
    }
    else if (gainId==2) {
      pedestal = aped->mean_x6;
      gainratio = aGain->gain12Over6();
    }

    amplitude = double(((double)(sample.adc()) - pedestal) * gainratio);
    
    if (gainId == 0)  amplitude = double((4095. - pedestal) * gainratio);

    amplitudes_.push_back(amplitude);
  }

}

template<class C>
void EcalUncalibRecHitOutOfTimeSubtractionAlgo<C>::computeAmplitudeOOT( std::vector< double > &amplitudeFitParameters, std::vector< double > &subtractionLimits, double time )
{

  // these are the parameters of the pulse shape function
  alphabeta_ = amplitudeFitParameters[0]*amplitudeFitParameters[1];
  alpha_ = amplitudeFitParameters[0];
  beta_ = amplitudeFitParameters[1];

  // these are the limits of the subtraction algorithm
  float minAmplitudeOutOfTime = subtractionLimits[1];

  // if the max sample of the max of the neighbors is 
  // in the pre-samples, and the amplitude is above noise, 
  // --> there is a hope to fit for the out-of-time contributions
  // -> not, return 0
  double amplitudeExtapolated_= -1.0;
  if (calculatedExtrahit_.amplitudeMax == -100) amplitudeExtapolated_ = 0.0;
  else if (fabs(calculatedExtrahit_.timeMax - 5) < subtractionLimits[0]) amplitudeExtapolated_ = 0.0;
  else if (calculatedExtrahit_.amplitudeMax < minAmplitudeOutOfTime) amplitudeExtapolated_ = 0.0;
  else {

    /*
    std::cout << "===> timeMax = " << calculatedExtrahit_.timeMax << "\tcalculatedExtrahit_.amplitudeMax = " << calculatedExtrahit_.amplitudeMax << std::endl;
    std::cout << "listing the samples ... " << std::endl;
    for (int iSample = 0; iSample < C::MAXSAMPLES; iSample++) {
      std::cout << "\tisample " << iSample << " has amplitudes_[iSample] = " << amplitudes_[iSample] << std::endl;
    }
    std::cout << "Done listing samples " << std::endl;
    */

    amplitudeExtapolated_ = pulseShapeFunction(time);

    //    std::cout << "==> AMPLITUDE EXTRAP = " << amplitudeExtapolated_ << std::endl;
  }

  calculatedExtrahit_.amplitudeExtapolated = amplitudeExtapolated_;
}


#endif
