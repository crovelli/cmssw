import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils

isMC = True

process = cms.Process("ZeeScSelection")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32( 1000 )

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
from Configuration.AlCa.GlobalTag import GlobalTag
if (isMC):
    process.GlobalTag.globaltag = 'MCRUN2_74_V9A'        # 50ns
    #process.GlobalTag.globaltag = 'MCRUN2_74_V9'        # 25ns
else:
    process.GlobalTag.globaltag = 'GR_P_V56'             # prompt reco 


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( 20000 ) )

#from Calibration.EcalCalibAlgos.data2015B_cff import *
from Calibration.EcalCalibAlgos.DYJetsToLLSpring15_50ns_OfficialSkimZee_cff import *
process.source = cms.Source("PoolSource",
                            fileNames = readFilesRM,                                                             
                            )                       
if (isMC):
    process.TFileService = cms.Service("TFileService",fileName = cms.string("zeeMC.root"))
else: 
    process.TFileService = cms.Service("TFileService",fileName = cms.string("zeeData.root"))

process.zeeScSel = cms.EDAnalyzer('ZeeScSelection',
                                  electrons = cms.InputTag("gedGsfElectrons")
                                  )

process.p = cms.Path(process.zeeScSel)

