import FWCore.ParameterSet.Config as cms

isMC = True
HLTProcessName = 'HLT'

processName='ZEECALIB'
process = cms.Process(processName)

# import of standard configurations 
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_PostLS1_cff')  
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')

process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

#relvals
process.source = cms.Source("PoolSource", 
                            fileNames=cms.untracked.vstring(    
        "/store/relval/CMSSW_7_4_2/RelValZEE_13/GEN-SIM-RECO/MCRUN2_74_V9_multiThTechTest3-v1/00000/3A4313B7-C2FF-E411-8A37-0025905B85F6.root"    
        )     
                            )    

if (not isMC):
    process.source.lumisToProcess = goodLumis                            

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag
if (not isMC):
    process.GlobalTag.globaltag = 'GR_P_V55' 
else:
    process.GlobalTag = GlobalTag(process.GlobalTag, 'DESRUN2_74_V4', '') 

# recalibrator
process.load('RecoLocalCalo.EcalRecAlgos.EcalSeverityLevelESProducer_cfi')
process.load("RecoLocalCalo.EcalRecProducers.ecalRecalibRecHit_cfi")
process.ecalRecHit.doEnergyScale = cms.bool(False)                # chiara: in questo modo usa 1 come adcToGeV
process.ecalRecHit.doIntercalib = cms.bool(True)
process.ecalRecHit.doLaserCorrection = cms.bool(False)
process.ecalRecHit.EBRecHitCollection = "reducedEcalRecHitsEB"          
process.ecalRecHit.EERecHitCollection = "reducedEcalRecHitsEE"          
process.ecalRecHit.EBRecalibRecHitCollection = "EcalRecHitsEB"          # chiara: e' la collezione di output
                                                                        # si chiamano EcalRecHitsEB ma sono reduced. Da capire 
process.ecalRecHit.EERecalibRecHitCollection = "EcalRecHitsEE"          # quale formato ci sara'. Inoltre, considera che il PF dopo
                                                                        # avrebbe bisogno i non reduced! che sono usati in
                                                                        # RecoParticleFlow/PFClusterProducer/interface/PFEcalRecHitCreator.h
# chiara:
# non so come cambiare il nome alla collezione di rechits reduced che deve diventare EcalRecHitsES invece di reducedEcalRecHitsES         
# giro questo modulo dummy che si limita a cambiare il nome.                                                                      
# non servira' quando girero' sui raw => NB: a me servono i rechits tutti, ma negli AOD ci sono solo i reducedEcalRecHitsES            
process.load("RecoLocalCalo.EcalRecProducers.esDummyRecHit_cfi")
process.ecalPreshowerRecHit.ESRecHitCollection = "reducedEcalRecHitsES"

# PF rechits
process.load('RecoParticleFlow.PFClusterProducer.particleFlowRecHitECAL_cfi')
process.load('RecoParticleFlow.PFClusterProducer.particleFlowRecHitPS_cfi') 

# PF clustering       
process.load('RecoParticleFlow.PFClusterProducer.particleFlowClusterECALUncorrected_cfi')
process.load('RecoParticleFlow.PFClusterProducer.particleFlowClusterECAL_cfi')
process.load('RecoParticleFlow.PFClusterProducer.particleFlowClusterPS_cfi') 
process.load("RecoEcal.EgammaClusterProducers.particleFlowSuperClusterECAL_cfi")

# PF superclustering
# chiara: la regression e' accesa
process.particleFlowSuperClusterECAL.PFBasicClusterCollectionBarrel = cms.string('recalibParticleFlowBasicClusterECALBarrel')
process.particleFlowSuperClusterECAL.PFSuperClusterCollectionBarrel = cms.string('recalibParticleFlowSuperClusterECALBarrel')
process.particleFlowSuperClusterECAL.PFBasicClusterCollectionEndcap = cms.string('recalibParticleFlowBasicClusterECALEndcap')
process.particleFlowSuperClusterECAL.PFSuperClusterCollectionEndcap = cms.string('recalibParticleFlowSuperClusterECALEndcap')
process.particleFlowSuperClusterECAL.PFBasicClusterCollectionPreshower = cms.string('recalibParticleFlowBasicClusterECALPreshower')
process.particleFlowSuperClusterECAL.PFSuperClusterCollectionEndcapWithPreshower = cms.string('recalibParticleFlowSuperClusterECALEndcapWithPreshower')

# calibration algo
process.load("Calibration.EcalCalibAlgos.zeeCalibration_cff")
process.looper.maxLoops = cms.untracked.uint32(8)              
process.looper.electronSelection = cms.untracked.int32(-1)     # 0-1-2-3-4; -1 to do nothing
process.looper.histoFile = cms.string('myHistograms_test.root')
process.looper.zeeFile = cms.string('myZeePlots_test.root')
#process.looper.initialMiscalibrationBarrel = cms.untracked.string('miscalib_ring_1.00_0.10.xml')
process.looper.initialMiscalibrationBarrel = cms.untracked.string('')
process.looper.initialMiscalibrationEndcap = cms.untracked.string('')
process.looper.ZCalib_CalibType = cms.untracked.string('RING')
process.looper.ZCalib_InvMass = cms.untracked.string('SCTRMass')
# not to be changed
process.looper.rechitProducer   = cms.string('ecalRecHit')                          
process.looper.rechitCollection = cms.string('EcalRecHitsEB') 
process.looper.erechitProducer  = cms.string('ecalRecHit')                          
process.looper.erechitCollection = cms.string('EcalRecHitsEE')
process.looper.ebSuperclusters = cms.InputTag("particleFlowSuperClusterECAL","recalibParticleFlowSuperClusterECALBarrel",processName)
process.looper.eeSuperclusters = cms.InputTag("particleFlowSuperClusterECAL","recalibParticleFlowSuperClusterECALEndcapWithPreshower",processName)
process.looper.electrons = cms.InputTag("gedGsfElectrons","","RECO")
process.looper.HLTriggerResults = cms.InputTag("TriggerResults","",HLTProcessName)    

process.zFilterPath = cms.Path( 
    process.ecalRecHit * process.ecalPreshowerRecHit * 
    process.particleFlowRecHitPS * process.particleFlowClusterPS *    
    process.particleFlowRecHitECAL * process.particleFlowClusterECALUncorrected * process.particleFlowClusterECAL *
    process.particleFlowSuperClusterECAL 
    )

#process.out = cms.OutputModule("PoolOutputModule",
#                               fileName = cms.untracked.string("testOut.root")
#                               )
#process.outpath = cms.EndPath(process.out)


process.end_step = cms.EndPath(process.endOfProcess)
process.Schedule = cms.Schedule(process.zFilterPath,process.end_step)
