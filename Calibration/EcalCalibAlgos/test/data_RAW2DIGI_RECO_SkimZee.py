# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: reco --data --no_exec -s RAW2DIGI,RECO --filein /store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/04174426-54FE-E411-859E-0025905B855C.root --fileout anOutputFileName.root --conditions GR_R_74_V12
import FWCore.ParameterSet.Config as cms

#electron cuts 
ELECTRON_ET_CUT_MIN = 20.0
ELECTRON_CUTS = "(abs(superCluster.eta)<2.5) && (ecalEnergy*sin(superClusterPosition.theta)>" + str(ELECTRON_ET_CUT_MIN) + ")"

MASS_CUT_MIN = 60.

process = cms.Process('RECOSKIM')

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_AutoFromDBCurrent_cff')
process.load('Configuration.StandardSequences.RawToDigi_Data_cff')
process.load('Configuration.StandardSequences.Reconstruction_Data_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')

process.MessageLogger.cerr.FwkReport.reportEvery = 1

# conditions
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'GR_R_74_V12', '')

# events
process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

# Input source
process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/04174426-54FE-E411-859E-0025905B855C.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/2213532A-54FE-E411-8DAD-0025905A6104.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/26D7CD37-54FE-E411-855A-00261894386E.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/2A6E3229-54FE-E411-809A-0025905A60D0.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/3664632D-54FE-E411-AD8D-00261894390A.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/3EBE0B2D-54FE-E411-B556-0025905A608C.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/506DEF32-54FE-E411-952D-0026189438E8.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/52B62930-54FE-E411-8BD5-0025905B8598.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/643EE039-54FE-E411-9636-0025905A60E0.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/68366243-54FE-E411-AA1F-0025905AA9CC.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/6A068F30-54FE-E411-ABFF-0025905A60AA.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/70FD0229-54FE-E411-B606-00261894382A.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/9CFE7344-54FE-E411-9B55-0025905964BE.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/A6965435-54FE-E411-BD2D-0025905A60B2.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/CA015B3B-54FE-E411-915A-0025905964B6.root',
        '/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/FED86D36-54FE-E411-82F0-0025905B8592.root')
                            )

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True)
    )

# Electron id section
#useAOD = True
#from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
#if useAOD == True :
#    dataFormat = DataFormat.AOD
#else :
#    dataFormat = DataFormat.MiniAOD

#switchOnVIDElectronIdProducer(process, dataFormat)

#my_id_modules = ['RecoEgamma.ElectronIdentification.Identification.cutBasedElectronID_PHYS14_PU20bx25_V2_cff']

#for idmod in my_id_modules:
#    setupAllVIDIdsInModule(process,idmod,setupVIDElectronSelection)

#process.zeeCalibSkimSeq = cms.Sequence()
#process.tagElectrons = cms.EDFilter("GsfElectronSelector",
#                                    src = cms.InputTag("gedGsfElectrons"),
#                                    cut = cms.string(ELECTRON_CUTS),
#                                    filter = cms.bool(True)
#                                    )
#process.zeeCalibSkimSeq *= ( process.tagElectrons )
#process.filter = cms.EDFilter("ZeeCalibSkim",
#                              electrons = cms.InputTag("tagElectrons"),
#                              electronIdMap = cms.InputTag("egmGsfElectronIDs:cutBasedElectronID-PHYS14-PU20bx25-V2-standalone-loose"),
#                              mass_cut_low = cms.untracked.double(60.),
#                              requireOppositeCharge = cms.untracked.bool(False)
#                              )
#process.zeeCalibSkimSeq *= ( process.egmGsfElectronIDSequence * process.filter)
#process.zFilterPath = cms.Path( process.zeeCalibSkimSeq )

# event content
process.RECOSIMEventContent.outputCommands.extend( [
        "drop *_*_*_*",
        "keep *_*gedGsfElectron*_*_*",
        "keep *_*reducedEcalRecHits*_*_*",
        "keep *_*TriggerResults*_*_HLT",
        "keep *_offlinePrimaryVertices_*_*",    # we do not save the collection with BS for the moment
        "keep *_*conversions*_*_*",
        "keep *_*offlineBeamSpot*_*_*",
        "keep *_*particleFlowEGamma*_*_*",
        "keep *_*particleFlowSuperClusterECAL*_*_*",
        "keep *_*electronGsfTracks*_*_*",
        "keep *recoGenParticles_*genParticles*_*_*"
        ] )

# Output definition
process.RECOSIMoutput = cms.OutputModule("PoolOutputModule",
                                         dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string(''),
        filterName = cms.untracked.string('')
        ),
###                                         SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring('zFilterPath')),
                                         eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
                                         fileName = cms.untracked.string('anOutputFileName.root'),
                                         outputCommands = process.RECOSIMEventContent.outputCommands,
                                         splitLevel = cms.untracked.int32(0)
                                         )

# Path and EndPath definitions
process.raw2digi_step = cms.Path(process.RawToDigi)
process.reconstruction_step = cms.Path(process.reconstruction)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RECOSIMoutput_step = cms.EndPath(process.RECOSIMoutput)

# Schedule definition
#process.schedule = cms.Schedule(process.raw2digi_step,process.reconstruction_step,process.endjob_step,process.zFilterPath,process.RECOSIMoutput_step)
process.schedule = cms.Schedule(process.raw2digi_step,process.reconstruction_step,process.endjob_step,process.RECOSIMoutput_step)


