import FWCore.ParameterSet.Config as cms

# To Be Changed
isMC = False

#electron cuts
ELECTRON_CUT=("pt > 10 && abs(eta)<2.5")
DIELECTRON_CUT=("mass > 40 && mass < 140 && daughter(0).pt>20 && daughter(1).pt()>10")

process = cms.Process("ZEESKIM")

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
process.load('Configuration.EventContent.EventContent_cff')

process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)

readFiles = cms.untracked.vstring()
readFiles.extend( [
        "/store/mc/RunIISpring15DR74/DYJetsToLL_M-50_TuneCUETP8M1_13TeV-amcatnloFXFX-pythia8/AODSIM/Asympt25ns_MCRUN2_74_V9-v3/10000/96EF1A5F-8115-E511-AF17-02163E0125CE.root"
] )

process.source = cms.Source("PoolSource",
                            fileNames = readFiles
)

process.options = cms.untracked.PSet(
    wantSummary = cms.untracked.bool(True)
    )

# Other statements
from Configuration.AlCa.GlobalTag import GlobalTag                        
if (not isMC):
    process.GlobalTag = GlobalTag(process.GlobalTag, 'GR_P_V56', '')     
else:
    process.GlobalTag = GlobalTag(process.GlobalTag, 'MCRUN2_74_V9A', '')     

# to save sum of mc weights
process.sumMcWeights = cms.EDAnalyzer('sumMcWeights') 

# single lepton selectors
process.goodZeeElectrons = cms.EDFilter("GsfElectronRefSelector",
                                        src = cms.InputTag("gedGsfElectrons"),
                                        cut = cms.string(ELECTRON_CUT)
                                        )

# electron ID (sync with the AlCaReco: https://raw.githubusercontent.com/cms-sw/cmssw/CMSSW_7_5_X/Calibration/EcalAlCaRecoProducers/python/WZElectronSkims_cff.py)
process.identifiedElectrons = process.goodZeeElectrons.clone(cut = cms.string(process.goodZeeElectrons.cut.value() +
                                                                              " && (gsfTrack.hitPattern().numberOfHits(\'MISSING_INNER_HITS\')<=2)"
                                                                              " && ((isEB"
                                                                              " && ( ((pfIsolationVariables().sumChargedHadronPt + max(0.0,pfIsolationVariables().sumNeutralHadronEt + pfIsolationVariables().sumPhotonEt - 0.5 * pfIsolationVariables().sumPUPt))/p4.pt)<0.164369)"
                                                                              " && (full5x5_sigmaIetaIeta<0.011100)"
                                                                              " && ( - 0.252044<deltaPhiSuperClusterTrackAtVtx< 0.252044 )"
                                                                              " && ( -0.016315<deltaEtaSuperClusterTrackAtVtx<0.016315 )"
                                                                              " && (hadronicOverEm<0.345843)"
                                                                              ")"
                                                                              " || (isEE"
                                                                              " && (gsfTrack.hitPattern().numberOfHits(\'MISSING_INNER_HITS\')<=3)"
                                                                              " && ( ((pfIsolationVariables().sumChargedHadronPt + max(0.0,pfIsolationVariables().sumNeutralHadronEt + pfIsolationVariables().sumPhotonEt - 0.5 * pfIsolationVariables().sumPUPt))/p4.pt)<0.212604 )"
                                                                              " && (full5x5_sigmaIetaIeta<0.033987)"
                                                                              " && ( -0.245263<deltaPhiSuperClusterTrackAtVtx<0.245263 )"
                                                                              " && ( -0.010671<deltaEtaSuperClusterTrackAtVtx<0.010671 )"
                                                                              " && (hadronicOverEm<0.134691) "
                                                                              "))"
                                                                              )
                                                             )

# dilepton selectors
process.diZeeElectrons = cms.EDProducer("CandViewShallowCloneCombiner",
                                        decay       = cms.string("identifiedElectrons identifiedElectrons"),
                                        checkCharge = cms.bool(False),
                                        cut         = cms.string(DIELECTRON_CUT)
                                        )

# dilepton counters
process.diZeeElectronsFilter = cms.EDFilter("CandViewCountFilter",
                                            src = cms.InputTag("diZeeElectrons"),
                                            minNumber = cms.uint32(1)
                                            )

#sequences
if (not isMC):
    process.zdiElectronSequence = cms.Sequence( process.goodZeeElectrons * process.identifiedElectrons * process.diZeeElectrons * process.diZeeElectronsFilter )
else:
    process.zdiElectronSequence = cms.Sequence( process.sumMcWeights * process.goodZeeElectrons * process.identifiedElectrons * process.diZeeElectrons * process.diZeeElectronsFilter )

process.zFilterPath = cms.Path( process.zdiElectronSequence )

process.AODEventContent.outputCommands.extend( [
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
        "keep *recoGenParticles_*genParticles*_*_*",
        "keep *GenEventInfoProduct_generator_*_*",
        "keep *_addPileupInfo_bunchSpacing_*"
        ] )

process.ZeeSkimOutput = cms.OutputModule("PoolOutputModule",
                                         splitLevel = cms.untracked.int32(0),
                                         outputCommands = process.AODEventContent.outputCommands,
                                         fileName = cms.untracked.string('zeeCalibSkim.root'),
                                         SelectEvents = cms.untracked.PSet(SelectEvents = cms.vstring('zFilterPath')),
                                         dataset = cms.untracked.PSet(
        filterName = cms.untracked.string(''),
        dataTier = cms.untracked.string('ALCARECO')
        )
                                          )                                          
process.ZeeSkimOutput_step = cms.EndPath(process.ZeeSkimOutput)

process.schedule = cms.Schedule(process.zFilterPath,process.ZeeSkimOutput_step)
