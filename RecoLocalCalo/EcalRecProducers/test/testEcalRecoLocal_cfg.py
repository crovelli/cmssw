import FWCore.ParameterSet.Config as cms
process = cms.Process("testEcalRecoLocal")

process.load("Configuration.StandardSequences.GeometryRecoDB_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")
process.load("RecoEgamma.EgammaElectronProducers.gsfElectronSequence_cff")
process.load("Configuration.StandardSequences.DigiToRaw_cff")
process.load("Configuration.StandardSequences.RawToDigi_cff")
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.load("EventFilter.EcalRawToDigi.EcalUnpackerMapping_cfi")
process.load("EventFilter.EcalRawToDigi.EcalUnpackerData_cfi")

#### CONFIGURE IT HERE
isMC = True
# methods: Weights, AlphaBetaFit, AnalyticFit
AmplitudeRecoMethod = "Weights"
#####################

if isMC:
    process.ecalEBunpacker.InputLabel = cms.InputTag('rawDataCollector')
else:
    process.ecalEBunpacker.InputLabel = cms.InputTag('source')

# get timing service up for profiling
process.TimerService = cms.Service("TimerService")
process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True)
)

# get uncalibrechits with weights method
import RecoLocalCalo.EcalRecProducers.ecalWeightUncalibRecHit_cfi
process.ecalUncalibHitWeights = RecoLocalCalo.EcalRecProducers.ecalWeightUncalibRecHit_cfi.ecalWeightUncalibRecHit.clone()
process.ecalUncalibHitWeights.EBdigiCollection = 'ecalEBunpacker:ebDigis'
process.ecalUncalibHitWeights.EEdigiCollection = 'ecalEBunpacker:eeDigis'

# get uncalibrechits with fit method
import RecoLocalCalo.EcalRecProducers.ecalFixedAlphaBetaFitUncalibRecHit_cfi
process.ecalUncalibHitFixedAlphaBetaFit = RecoLocalCalo.EcalRecProducers.ecalFixedAlphaBetaFitUncalibRecHit_cfi.ecalFixedAlphaBetaFitUncalibRecHit.clone()
process.ecalUncalibHitFixedAlphaBetaFit.EBdigiCollection = 'ecalEBunpacker:ebDigis'
process.ecalUncalibHitFixedAlphaBetaFit.EEdigiCollection = 'ecalEBunpacker:eeDigis'

# get uncalibrechits with analytic fit method  
import RecoLocalCalo.EcalRecProducers.ecalAnalFitUncalibRecHit_cfi
process.ecalUncalibHitAnalFit = RecoLocalCalo.EcalRecProducers.ecalAnalFitUncalibRecHit_cfi.ecalAnalFitUncalibRecHit.clone()
process.ecalUncalibHitAnalFit.EBdigiCollection = 'ecalEBunpacker:ebDigis'
process.ecalUncalibHitAnalFit.EEdigiCollection = 'ecalEBunpacker:eeDigis'

# get uncalibrechits with ratio method (does not run in 5_3_12)
#import RecoLocalCalo.EcalRecProducers.ecalRatioUncalibRecHit_cfi
#process.ecalUncalibHitRatio = RecoLocalCalo.EcalRecProducers.ecalRatioUncalibRecHit_cfi.ecalRatioUncalibRecHit.clone()
#process.ecalUncalibHitRatio.EBdigiCollection = 'ecalEBunpacker:ebDigis'
#process.ecalUncalibHitRatio.EEdigiCollection = 'ecalEBunpacker:eeDigis'


# get uncalibrechits with ratio method
import RecoLocalCalo.EcalRecProducers.ecalGlobalUncalibRecHit_cfi
process.ecalUncalibHitGlobal = RecoLocalCalo.EcalRecProducers.ecalGlobalUncalibRecHit_cfi.ecalGlobalUncalibRecHit.clone()
process.ecalUncalibHitGlobal.EBdigiCollection = 'ecalEBunpacker:ebDigis'
process.ecalUncalibHitGlobal.EEdigiCollection = 'ecalEBunpacker:eeDigis'


# get the recovered digis
process.ecalDetIdToBeRecovered.ebSrFlagCollection = 'simEcalDigis:ebSrFlags'
process.ecalDetIdToBeRecovered.eeSrFlagCollection = 'simEcalDigis:eeSrFlags'
process.ecalDetIdToBeRecovered.ebIntegrityGainErrors = 'ecalEBunpacker:EcalIntegrityGainErrors'
process.ecalDetIdToBeRecovered.ebIntegrityGainSwitchErrors = 'ecalEBunpacker:EcalIntegrityGainSwitchErrors'
process.ecalDetIdToBeRecovered.ebIntegrityChIdErrors = 'ecalEBunpacker:EcalIntegrityChIdErrors'
process.ecalDetIdToBeRecovered.eeIntegrityGainErrors = 'ecalEBunpacker:EcalIntegrityGainErrors'
process.ecalDetIdToBeRecovered.eeIntegrityGainSwitchErrors = 'ecalEBunpacker:EcalIntegrityGainSwitchErrors'
process.ecalDetIdToBeRecovered.eeIntegrityChIdErrors = 'ecalEBunpacker:EcalIntegrityChIdErrors'
process.ecalDetIdToBeRecovered.integrityTTIdErrors = 'ecalEBunpacker:EcalIntegrityTTIdErrors'
process.ecalDetIdToBeRecovered.integrityBlockSizeErrors = 'ecalEBunpacker:EcalIntegrityBlockSizeErrors'


wrongAlgoMessage = "The AmplitudeRecoMethod: "+AmplitudeRecoMethod+" that you chose is not foreseen. Check the customization of the cfg "

# get rechits e.g. from the weights
process.load("CalibCalorimetry.EcalLaserCorrection.ecalLaserCorrectionService_cfi")
process.load("RecoLocalCalo.EcalRecProducers.ecalRecHit_cfi")
process.ecalRecHit.triggerPrimitiveDigiCollection = 'ecalEBunpacker:EcalTriggerPrimitives'
if AmplitudeRecoMethod == "Weights":
    print "==> Using Weights as amplitude reconstruction"
    process.ecalRecHit.EBuncalibRecHitCollection = 'ecalUncalibHitWeights:EcalUncalibRecHitsEB'
    process.ecalRecHit.EEuncalibRecHitCollection = 'ecalUncalibHitWeights:EcalUncalibRecHitsEE'
elif AmplitudeRecoMethod == "AlphaBetaFit":
    print "==> Using AlphaBetaFit as amplitude reconstruction" 
    process.ecalRecHit.EBuncalibRecHitCollection = 'ecalUncalibHitFixedAlphaBetaFit:EcalUncalibRecHitsEB'
    process.ecalRecHit.EEuncalibRecHitCollection = 'ecalUncalibHitFixedAlphaBetaFit:EcalUncalibRecHitsEE'    
elif AmplitudeRecoMethod == "AnalyticFit":
    print "==> Using AlphaBetaFit as amplitude reconstruction" 
    process.ecalRecHit.EBuncalibRecHitCollection = 'ecalUncalibHitAnalFit:EcalUncalibRecHitsEB'
    process.ecalRecHit.EEuncalibRecHitCollection = 'ecalUncalibHitAnalFit:EcalUncalibRecHitsEE'        
else: print wrongAlgoMessage

process.maxEvents = cms.untracked.PSet(  input = cms.untracked.int32(10) )
process.source = cms.Source("PoolSource",
            fileNames = cms.untracked.vstring('file:/cmsrm/pc23_2/emanuele/data/Pool/DYToEE_M_20_TuneZ2star_8TeV_pythia6_GEN-SIM-RAW+PU25bx25_START53_V19D-v1.root')
                )


process.out = cms.OutputModule("PoolOutputModule",
                               outputCommands = cms.untracked.vstring('drop *',
                                                                      'keep *_ecalUncalibHit*_*_*',
                                                                      'keep *_ecalRecHit_*_*'
                                                                      ),
                               fileName = cms.untracked.string('testEcalLocalRecoA.root')
                               )



if AmplitudeRecoMethod == "Weights":        process.ecalAmplitudeReco = cms.Sequence(process.ecalUncalibHitWeights)
elif AmplitudeRecoMethod == "AlphaBetaFit": process.ecalAmplitudeReco = cms.Sequence(process.ecalUncalibHitFixedAlphaBetaFit)
elif AmplitudeRecoMethod == "AnalyticFit":  process.ecalAmplitudeReco = cms.Sequence(process.ecalUncalibHitAnalFit)
else: print wrongAlgoMessage

process.ecalTestRecoLocal = cms.Sequence(process.ecalEBunpacker
                                         *process.ecalAmplitudeReco
                                         *process.ecalUncalibHitGlobal
                                         *process.ecalDetIdToBeRecovered
                                         *process.ecalRecHit
                                        )

process.p = cms.Path(process.ecalTestRecoLocal)
process.outpath = cms.EndPath(process.out)
process.GlobalTag.globaltag = 'START53_V19D::All'
