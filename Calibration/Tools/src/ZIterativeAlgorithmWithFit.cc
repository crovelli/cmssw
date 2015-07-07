/* ******************************************
 * ZIterativeAlgorithmWithFit.cc
 *
 * 
 * Paolo Meridiani 06/07/2005
 * Rewritten for CMSSW 04/06/2007
 ********************************************/

#include "Calibration/Tools/interface/ZIterativeAlgorithmWithFit.h"
#include "Calibration/Tools/interface/EcalRingCalibrationTools.h"
#include "Calibration/Tools/interface/EcalIndexingTools.h"

#include "DataFormats/EgammaCandidates/interface/Electron.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/TrackReco/interface/Track.h"

#include <TMath.h>
#include <TCanvas.h> 
#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TH1F.h"
#include "TMinuit.h"
#include "TGraphErrors.h"
#include "THStack.h"
#include "TLegend.h"

#include <fstream>
#include <iostream>
#include <vector>

//Scale and Bins for calibration factor histograms
#define MIN_RESCALE -0.5
#define MAX_RESCALE 0.5
#define NBINS_LOWETA 100
#define NBINS_HIGHETA 50

const double ZIterativeAlgorithmWithFit::M_Z_=91.187;

//  #if !defined(__CINT__)
//  ClassImp(Electron)
//  #endif

// not used / not updated
ZIterativeAlgorithmWithFit::ZIterativeAlgorithmWithFit() {

  numberOfIterations_=10;
  nCrystalCut_=-1;
  channels_=1;
  totalEvents_=0;
  currentEvent_=0;
  currentIteration_=0;
  optimizedCoefficients_.resize(channels_);
  optimizedCoefficientsError_.resize(channels_);
  optimizedChiSquare_.resize(channels_);
  optimizedIterations_.resize(channels_);
  calib_fac_.resize(channels_);
  weight_sum_.resize(channels_);
  electrons_.resize(1);
  massReco_.resize(1);
}

// initializations 
ZIterativeAlgorithmWithFit::ZIterativeAlgorithmWithFit(const edm::ParameterSet&  ps) {

  numberOfIterations_=ps.getUntrackedParameter<unsigned int>("maxLoops",0);
  massMethod = ps.getUntrackedParameter<std::string>("ZCalib_InvMass","SCMass");
  calibType_= ps.getUntrackedParameter<std::string>("ZCalib_CalibType","RING"); 
  nCrystalCut_=ps.getUntrackedParameter<int>("ZCalib_nCrystalCut",-1); 

  if (calibType_ == "RING")
    channels_ = EcalRingCalibrationTools::N_RING_TOTAL;
  else if (calibType_ == "MODULE")
    channels_ = EcalRingCalibrationTools::N_MODULES_BARREL;  
  else if (calibType_ == "ABS_SCALE")
    channels_ = 1;  
  else if(calibType_ == "ETA_ET_MODE")
    channels_ = EcalIndexingTools::getInstance()->getNumberOfChannels();
  else if(calibType_ == "SINGLEXTAL")    
    channels_ = EcalRingCalibrationTools::N_XTAL_TOTAL;  
  
  std::cout << "[ZIterativeAlgorithmWithFit::ZIterativeAlgorithmWithFit] channels_ = " << channels_ << std::endl;
  
  // Resetting currentEvent & iteration
  currentEvent_=0;
  currentIteration_=0;
  totalEvents_=0;

  optimizedCoefficients_.resize(channels_);
  optimizedCoefficientsError_.resize(channels_);
  optimizedChiSquare_.resize(channels_);
  optimizedIterations_.resize(channels_);
  calib_fac_.resize(channels_);
  weight_sum_.resize(channels_);

  // Creating and booking histograms
  thePlots_ = new ZIterativeAlgorithmWithFitPlots; 
  bookHistograms(); 

  // Setting up rescaling if needed
  UseStatWeights_=ps.getUntrackedParameter<bool>("ZCalib_UseStatWeights",false);
  if (UseStatWeights_) {
    WeightFileName_="weights.txt";
    StatWeights_.resize(channels_);
    getStatWeights(WeightFileName_);
    //    Event_Weight_.resize(events);
  }

  // chiara: trovare un modo furbo per metterlo qui e chiamarlo una sola volta
  // if(calibType_ == "SINGLEXTAL" )
  // HashedToRingIndexMap = EcalRingCalibrationTools::HashedToRingIndex();
}

// histo booking
void ZIterativeAlgorithmWithFit::bookHistograms() {
  
  if (!thePlots_) return;
  
  for (unsigned int i2 = 0; i2 < numberOfIterations_; i2++) {
    for (unsigned int i1 = 0; i1 < channels_; i1++) {
      char histoName[200];
      char histoTitle[200];
      
      // WeightedRescaling factor (rescale distribution weighted with the fraction of energy in the region)
      // ==> to get the optimized coefficients
      sprintf(histoName,  "WeightedRescaleFactor_channel_%d_Iteration_%d",i1, i2);
      sprintf(histoTitle, "WeightedRescaleFactor Channel_%d Iteration %d",i1, i2);
      if(calibType_ != "SINGLEXTAL" ) { 
	if (i1>15 && i1<155)  
	  thePlots_->weightedRescaleFactor[i2][i1] = new TH1F(histoName, histoTitle, NBINS_LOWETA, MIN_RESCALE, MAX_RESCALE);
	else
	  thePlots_->weightedRescaleFactor[i2][i1] = new TH1F(histoName, histoTitle, NBINS_HIGHETA, MIN_RESCALE, MAX_RESCALE);
      } else {
	thePlots_->weightedRescaleFactor[i2][i1] = new TH1F(histoName, histoTitle, NBINS_LOWETA, MIN_RESCALE, MAX_RESCALE);    // qui: controlla che questo binning sia ragionevole
      }
      thePlots_->weightedRescaleFactor[i2][i1]->GetXaxis()->SetTitle("Rescale factor");
      thePlots_->weightedRescaleFactor[i2][i1]->GetYaxis()->SetTitle("a.u.");

      // UnweightedRescaling factor (rescale distribution without weight)
      sprintf(histoName,  "UnweightedRescaleFactor_channel_%d_Iteration_%d",i1, i2);
      sprintf(histoTitle, "UnweightedRescaleFactor Channel_%d Iteration %d",i1, i2);
      if(calibType_ != "SINGLEXTAL" ) {
	if (i1>15 && i1<155)    
	  thePlots_->unweightedRescaleFactor[i2][i1] = new TH1F(histoName, histoTitle, NBINS_LOWETA, MIN_RESCALE, MAX_RESCALE);
	else
	  thePlots_->unweightedRescaleFactor[i2][i1] = new TH1F(histoName, histoTitle, NBINS_HIGHETA, MIN_RESCALE, MAX_RESCALE);      
      } else {
	thePlots_->unweightedRescaleFactor[i2][i1] = new TH1F(histoName, histoTitle, NBINS_LOWETA, MIN_RESCALE, MAX_RESCALE);   // qui: controlla che questo binning sia ragionevole
      }
      thePlots_->unweightedRescaleFactor[i2][i1] = new TH1F(histoName, histoTitle, NBINS_LOWETA, MIN_RESCALE, MAX_RESCALE); 
      thePlots_->unweightedRescaleFactor[i2][i1]->GetXaxis()->SetTitle("Rescale factor");
      thePlots_->unweightedRescaleFactor[i2][i1]->GetYaxis()->SetTitle("a.u.");

      // Weights - energy fraction in the region
      sprintf(histoName, "Weight_channel_%d_Iteration_%d",i1, i2);
      sprintf(histoTitle, "Weight Channel_%d Iteration %d",i1, i2);
      thePlots_->weight[i2][i1] = new TH1F(histoName, histoTitle, 100, 0., 1.);
      thePlots_->weight[i2][i1]->GetXaxis()->SetTitle("Weight");
      thePlots_->weight[i2][i1]->GetYaxis()->SetTitle("a.u.");
    }

    char histoNameZ[200];
    char histoTitleZ[200];
    sprintf(histoNameZ,  "WeightedZmassVsChannel_Iteration_%d",i2);
    sprintf(histoTitleZ, "WeightedZmassVsChannel Iteration %d",i2);
    thePlots_->weightedZmassVsChannel[i2] = new TH2F(histoNameZ, histoTitleZ, channels_, 0., channels_, 100, 40., 140.);
    thePlots_->weightedZmassVsChannel[i2]->GetXaxis()->SetTitle("module");
    thePlots_->weightedZmassVsChannel[i2]->GetYaxis()->SetTitle("Zmass");      
  }
}

// chiara: letto se il parametro UseStatWeights_ e' acceso, ma poi non mi paiono comunque essere usati
void ZIterativeAlgorithmWithFit::getStatWeights(const std::string &file) {
  std::ifstream statfile;
  statfile.open(file.c_str());
  if (!statfile) {
    std::cout << "ZIterativeAlgorithmWithFit::FATAL: stat weight  file " << file << " not found" << std::endl;
    exit(-1);
  }
  for(unsigned int i=0;i<channels_;i++) {    // qui. Secondo me non e' usato, altrimenti il file va aggiornato
    int imod;
    statfile >> imod >> StatWeights_[i];
    //std::cout << "Read Stat Weight for module " << imod << ": " <<  StatWeights_[i] << std::endl;
  }
}

// re-initializations
bool ZIterativeAlgorithmWithFit::resetIteration() {
  
  totalEvents_=0;
  currentEvent_=0;
  
  // Reset correction
  massReco_.clear();
  for (unsigned int i=0;i<channels_;i++) calib_fac_[i]=0.;
  for (unsigned int i=0;i<channels_;i++) weight_sum_[i]=0.;
  
  return kTRUE;
}    

// computation of the optimizedCoefficients_ at this loop
// with an iterative gaussian fit to the weightedRescaleFactors histos

bool ZIterativeAlgorithmWithFit::iterate() {

  // chiara: trovare un modo furbo per metterlo nel costruttore o simili e chiamarlo una sola volta
  // if(calibType_ == "SINGLEXTAL" )
  // HashedToRingIndexMap = EcalRingCalibrationTools::HashedToRingIndex();

  // Found optimized coefficients
  for (int i=0;i<(int)channels_;i++) { 

    // with nCrystalCut_==1 this is excluding:
    // ieta = -85, -66, -46, -26, -1, +25, 45, 65, 85
    int newIdx = i;

    // Chiara: To speed-up: for the moment, we comment the possibility to exclude border channels for single xtals   
    // if (calibType_ == "SINGLEXTAL") newIdx = (HashedToRingIndexMap.find(i))->second;
    bool toBeConsidered = false;
    if(calibType_ == "SINGLEXTAL" )              
      toBeConsidered = true;   
    else {
      if( (nCrystalCut_ == -1) || ((!(newIdx <=  nCrystalCut_ -1 )) &&
				   !((newIdx > (19-nCrystalCut_)) && (newIdx <= (19+nCrystalCut_))) &&
				   !((newIdx > (39-nCrystalCut_)) && (newIdx <= (39+nCrystalCut_))) &&
				   !((newIdx > (59-nCrystalCut_)) && (newIdx <= (59+nCrystalCut_))) &&
				   !((newIdx > (84-nCrystalCut_)) && (newIdx <= (84+nCrystalCut_))) &&
				   !((newIdx > (109-nCrystalCut_)) && (newIdx <= (109+nCrystalCut_))) &&
				   !((newIdx > (129-nCrystalCut_)) && (newIdx <= (129+nCrystalCut_))) &&
				   !((newIdx > (149-nCrystalCut_)) && (newIdx <= (149+nCrystalCut_))) &&
				   !(newIdx > (169-nCrystalCut_))) )
	toBeConsidered = true;
    }
    
    if (toBeConsidered) 
      {
	if (weight_sum_[i]!=0.) {
	  
	  double gausFitParameters[3], gausFitParameterErrors[3], gausFitChi2;
	  int gausFitIterations;
	  
	  gausfit( (TH1F*)thePlots_->weightedRescaleFactor[currentIteration_][i], gausFitParameters, gausFitParameterErrors, 2.5, 2.5, &gausFitChi2, &gausFitIterations );

	  float peak=gausFitParameters[1];
	  float peakError=gausFitParameterErrors[1];
	  float chi2 = gausFitChi2;
	  
	  int iters = gausFitIterations;
	  
	  optimizedCoefficientsError_[i] = peakError;
	  optimizedChiSquare_[i] = chi2;
	  optimizedIterations_[i] = iters;

	  if (peak >=MIN_RESCALE && peak <= MAX_RESCALE)
	    optimizedCoefficients_[i] = 1 / (1 + peak);
	  else
	    optimizedCoefficients_[i] = 1 / (1 + calib_fac_[i]/weight_sum_[i]);
	  
	} else {
	  optimizedCoefficients_[i]=1.;
	  optimizedCoefficientsError_[i] = 0.;
	  optimizedChiSquare_[i] = -1.;
	  optimizedIterations_[i] = 0;
	}
	
      }
    else {
      optimizedCoefficientsError_[i] = 0.;
      optimizedCoefficients_[i]=1.;
      optimizedChiSquare_[i] = -1.;
      optimizedIterations_[i] = 0;
      // 	  EcalCalibMap::getMap()->setRingCalib(i, optimizedCoefficients_[i]);
      // 	  //	  initialCoefficients_[i] *= optimizedCoefficients_[i];
    }
    
    std::cout << "ZIterativeAlgorithmWithFit::run():Energy Rescaling Coefficient for region " 
	      << i << " is "  << optimizedCoefficients_[i] << ", with error "<<optimizedCoefficientsError_[i]<<" - number of events: " << weight_sum_[i] << std::endl;
  }
  
  currentIteration_++;
  return kTRUE;
}    

// computation of massReco_ (without corrections) and call to getWeight, 
// where the fraction of SC energy which is in the region of interest is computed
// and where the histos used in iterate are filled
bool ZIterativeAlgorithmWithFit::addEvent(calib::CalibElectron* ele1, calib::CalibElectron* ele2, float invMassRescFactor) {

  totalEvents_++;
  std::pair<calib::CalibElectron*, calib::CalibElectron*> Electrons(ele1, ele2);

#ifdef DEBUG
  std::cout  << "In addEvent " ;
  std::cout << ele1->getRecoElectron()->parentSuperCluster()->rawEnergy() << " " ;
  std::cout << ele1->getRecoElectron()->parentSuperCluster()->position().eta() << " " ;
  std::cout << ele2->getRecoElectron()->parentSuperCluster()->rawEnergy() << " " ;
  std::cout << ele2->getRecoElectron()->parentSuperCluster()->position().eta() << " " ;
  std::cout << std::endl;
#endif

  if (massMethod == "SCTRMass" ) {
    massReco_.push_back(invMassCalc(ele1->getParentSuperCluster()->energy(), ele1->getRecoElectron()->eta(), ele1->getRecoElectron()->phi(), ele2->getParentSuperCluster()->energy(), ele2->getRecoElectron()->eta(), ele2->getRecoElectron()->phi()));
  }
  else if (massMethod == "SCMass" ) {
    massReco_.push_back(invMassCalc(ele1->getParentSuperCluster()->energy(), ele1->getParentSuperCluster()->position().eta(), ele1->getParentSuperCluster()->position().phi(), ele2->getParentSuperCluster()->energy(), ele2->getParentSuperCluster()->position().eta(), ele2->getParentSuperCluster()->position().phi()));
  }  
  
#ifdef DEBUG
  std::cout << "Mass calculated " << massReco_[currentEvent_] << std::endl;
#endif
  
  if((ele2->getParentSuperCluster()->position().eta() > -10.) && (ele2->getParentSuperCluster()->position().eta() < 10.) && 
     (ele2->getParentSuperCluster()->position().phi() > -10.) && (ele2->getParentSuperCluster()->position().phi() < 10.)) {
    getWeight(currentEvent_, Electrons, invMassRescFactor);
  }
  currentEvent_++;
  return kTRUE;
}

void ZIterativeAlgorithmWithFit::getWeight(unsigned int event_id, std::pair<calib::CalibElectron*,calib::CalibElectron*> elepair, float invMassRescFactor) 
{
  getWeight(event_id, elepair.first, invMassRescFactor);
  getWeight(event_id, elepair.second, invMassRescFactor);
}

float ZIterativeAlgorithmWithFit::getEventWeight(unsigned int event_id) {

  return 1.;
}

// computation of:
// rescale = [( mreco(for this event, no correction) / mZ(from PDG, with corrections) )^2 -1] / 2
// weight2 = rawEne of SC / sum of raw energies of the SC hits in each module
//
// The calibration factor are extractedfrom the distribution of rescale weighted with weight2
// which is fit in iterate. If the fit is bad, they are obtained from the values of 
// calib_fac_ and weight_sum_ (for each region) which are computed here
void ZIterativeAlgorithmWithFit::getWeight(unsigned int event_id, calib::CalibElectron* ele, float evweight) {

  // sum of the energies of the rechits corresponding to the electron SC
  // and division by ring, module etc according to calibType_
  // first = ring etc; second = energy sum

  // To speed-up: for the moment, we comment the possibility to exclude border channels
  // qui chiara: trovare un modo furbo per metterlo nel costruttore o simili e chiamarlo una sola volta
  // if(calibType_ == "SINGLEXTAL" )
  // HashedToRingIndexMap = EcalRingCalibrationTools::HashedToRingIndex();

  std::vector< std::pair<int,float> > modules=(*ele).getCalibModulesWeights(calibType_);   
  
  for (int imod=0; imod< (int) modules.size(); imod++) {
    
    int mod = (int) modules[imod].first;
    if (mod< (int) channels_ && mod>=0) {

      if (modules[imod].second >= 0.12 && modules[imod].second < 10000.) { 

	// Chiara: to speed-up we comment the possibility to exclude border xtals from calib, for the moment
	int newIdx = imod;
	// if (calibType_ == "SINGLEXTAL") newIdx = (HashedToRingIndexMap.find(imod))->second;

	bool toBeConsidered = false;
	if(calibType_ == "SINGLEXTAL" )              
	  toBeConsidered = true;   
	else {
	  if( (nCrystalCut_ == -1) || ((!(newIdx <=  nCrystalCut_ -1 )) &&
				       !((newIdx > (19-nCrystalCut_)) && (newIdx <= (19+nCrystalCut_))) &&
				       !((newIdx > (39-nCrystalCut_)) && (newIdx <= (39+nCrystalCut_))) &&
				       !((newIdx > (59-nCrystalCut_)) && (newIdx <= (59+nCrystalCut_))) &&
				       !((newIdx > (84-nCrystalCut_)) && (newIdx <= (84+nCrystalCut_))) &&
				       !((newIdx > (109-nCrystalCut_)) && (newIdx <= (109+nCrystalCut_))) &&
				       !((newIdx > (129-nCrystalCut_)) && (newIdx <= (129+nCrystalCut_))) &&
				       !((newIdx > (149-nCrystalCut_)) && (newIdx <= (149+nCrystalCut_))) &&
				       !(newIdx > (169-nCrystalCut_)))) 
	    toBeConsidered = true;
	}

	if (toBeConsidered)
	  {
	    // SC rawEne / sum of raw energies of the SC hits in imod
	    // fraction of raw energy of the electron in the module
	    float weight2 = modules[imod].second / ele->getParentSuperCluster()->rawEnergy();
#ifdef DEBUG
	    std::cout << "w2 " << weight2 << std::endl;
#endif
	    if (weight2>=0. && weight2<=1.) {
	      
	      // e' [( mreco(this event) / mZ(pdg, with corrections) )^2 -1] / 2 
	      float rescale = (TMath::Power((massReco_[event_id] / evweight), 2.) - 1) / 2.;
#ifdef DEBUG
	      std::cout << "rescale " << rescale << std::endl;		  
#endif
	      if (rescale>= MIN_RESCALE && rescale<=MAX_RESCALE) {

		calib_fac_[mod] += weight2 * rescale;
		weight_sum_[mod]+= weight2;

		thePlots_->weightedRescaleFactor[currentIteration_][mod]->Fill(rescale,weight2);
		thePlots_->unweightedRescaleFactor[currentIteration_][mod]->Fill(rescale,1.);
		thePlots_->weight[currentIteration_][mod]->Fill(weight2,1.);
		thePlots_->weightedZmassVsChannel[currentIteration_]->Fill(mod,massReco_[event_id],weight2);  
	      }
	      else {
		std::cout     << "[ZIterativeAlgorithmWithFit]::[getWeight]::rescale out " << rescale << std::endl;
	      }
	    }
	  }
      }
    }
    else 
      {
	std::cout << "ZIterativeAlgorithmWithFit::FATAL:found a wrong module_id " << mod << " channels " << channels_ << std::endl;
      }
  }
}

ZIterativeAlgorithmWithFit::~ZIterativeAlgorithmWithFit() { }

// iterative gaussian fit to get the coefficients
void ZIterativeAlgorithmWithFit::gausfit(TH1F * histoou, double* par, double* errpar, float nsigmalow, float nsigmaup, double* myChi2, int* iterations) {

  std::unique_ptr<TF1> gausa{ new TF1("gausa","gaus",histoou->GetMean()-3*histoou->GetRMS(),histoou->GetMean()+3*histoou->GetRMS()) };
  gausa->SetParameters(histoou->GetMaximum(),histoou->GetMean(),histoou->GetRMS());
  
  histoou->Fit(gausa.get(),"qR0N");
  
  double p1    = gausa->GetParameter(1);
  double sigma = gausa->GetParameter(2);
  double nor   = gausa->GetParameter(0);
    
  double xmi=p1-5*sigma;
  double xma=p1+5*sigma;
  double chi2=100;
  
  double xmin_fit=p1-nsigmalow*sigma;
  double xmax_fit=p1+nsigmaup*sigma;
  
  int iter=0;

  while ((chi2>1. && iter<5) || iter<2 ) {

    xmin_fit=p1-nsigmalow*sigma;
    xmax_fit=p1+nsigmaup*sigma;
    xmi=p1-5*sigma;
    xma=p1+5*sigma;
    
    char suffix[20];
    sprintf (suffix,"_iter_%d",iter); 
    std::unique_ptr<TF1> fitFunc{ new TF1("FitFunc"+TString(suffix),"gaus",xmin_fit,xmax_fit) };
    fitFunc->SetParameters(nor,p1,sigma);
    fitFunc->SetLineColor((int)(iter+1));
    fitFunc->SetLineWidth(1);
    //histoou->Fit("FitFunc","lR+","");
    histoou->Fit(fitFunc.get(),"qR0+","");
    
    histoou->GetXaxis()->SetRangeUser(xmi,xma);
    histoou->GetXaxis()->SetLabelSize(0.055);
    
    par[0]=(fitFunc->GetParameters())[0];
    par[1]=(fitFunc->GetParameters())[1];
    par[2]=(fitFunc->GetParameters())[2];
    errpar[0]=(fitFunc->GetParErrors())[0];
    errpar[1]=(fitFunc->GetParErrors())[1];
    errpar[2]=(fitFunc->GetParErrors())[2];

    if (fitFunc->GetNDF()!=0) {
      chi2=fitFunc->GetChisquare()/(fitFunc->GetNDF());
      *myChi2 = chi2;
    }
    else
      {
	chi2=100.;
	std::cout << "WARNING: Not enough NDF" << std::endl;
      }

    nor=par[0];
    p1=par[1];
    sigma=par[2];
    iter++;
    *iterations = iter;
  }
  return;
}


