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
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( -1 ) )

# Input source
process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring('/store/relval/CMSSW_7_4_2/DoubleElectron/RAW/GR_R_74_V12_19May_RelVal_zEl2012D-v1/00000/04174426-54FE-E411-859E-0025905B855C.root'
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
                                         fileName = cms.untracked.string("OUTPUT"),
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


