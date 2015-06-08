import FWCore.ParameterSet.Config as cms
import FWCore.Utilities.FileUtils as FileUtils

isMC = False

process = cms.Process("ZeeScSelection")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = cms.untracked.int32( 1000 )

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
from Configuration.AlCa.GlobalTag import GlobalTag
if (isMC):
    process.GlobalTag.globaltag = 'DESRUN2_74_V4' 
else:
    process.GlobalTag.globaltag = 'GR_P_V55' 


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( 10 ) )

from Calibration.EcalCalibAlgos.Run246081_cff import * 
process.source = cms.Source("PoolSource",                                                          
                            fileNames = readFiles,
)
#process.source = cms.Source("PoolSource",
#                            fileNames=cms.untracked.vstring(
#        "/store/relval/CMSSW_7_4_2/RelValZEE_13/GEN-SIM-RECO/MCRUN2_74_V9_multiThTechTest3-v1/00000/3A4313B7-C2FF-E411-8A37-0025905B85F6.root"
#        )
#                            )

process.TFileService = cms.Service("TFileService",fileName = cms.string("zee.root"))

process.zeeScSel = cms.EDAnalyzer('ZeeScSelection',
                                  ebSuperclusters = cms.InputTag("particleFlowSuperClusterECAL","particleFlowSuperClusterECALBarrel"),
                                  eeSuperclusters = cms.InputTag("particleFlowSuperClusterECAL","particleFlowSuperClusterECALEndcapWithPreshower"),
                                  electrons = cms.InputTag("gedGsfElectrons")
                                  )

process.p = cms.Path(process.zeeScSel)

