import FWCore.ParameterSet.Config as cms

treeDumper = cms.EDFilter("HWWTreeDumper",
                          TriggerResultsTag = cms.InputTag("TriggerResults::HLT"),
                          electronCollection = cms.InputTag("ambiguityResolvedElectrons"),
                          pflowElectronCollection = cms.InputTag("particleFlow","electrons"),
                          muonCollection = cms.InputTag("muons"),
                          ecalSCCollection = cms.InputTag("mergedSuperClusters"),
                          ecalBarrelSCCollection = cms.InputTag("correctedHybridSuperClusters"),
                          ecalEndcapSCCollection = cms.InputTag("multi5x5SuperClusters","multi5x5EndcapSuperClusters"),
                          ecalPFClusterCollection = cms.InputTag("pfElectronTranslator","pf"),
                          ecalBCCollection = cms.InputTag("mergedBasicClusters"),
                          ecalBarrelRecHits = cms.InputTag("ecalRecHit","EcalRecHitsEB"),
                          ecalEndcapRecHits = cms.InputTag("ecalRecHit","EcalRecHitsEE"),
                          calotowersForIsolationProducer = cms.InputTag("towerMaker"),
                          trackCollection = cms.InputTag("generalTracks"),
                          gsfTrackCollection = cms.InputTag("electronGsfTracks"),
                          globalMuonTrackCollection = cms.InputTag("globalMuons"),
                          standAloneMuonTrackCollection = cms.InputTag("standAloneMuons"),
#                          refittedForDeDxTrackCollection = cms.InputTag("RefitterForDeDx"),
                          refittedForDeDxTrackCollection = cms.InputTag("generalTracks"),
                          vertexCollection = cms.InputTag("offlinePrimaryVertices"),
                          K0sCollection = cms.InputTag("generalV0Candidates","Kshort"),
                          genJetCollection = cms.InputTag("antikt5GenJets"),
                          jetCollection1 = cms.InputTag("L2L3CorJetAK5Calo"),
                          jetVertexAlphaCollection1 = cms.InputTag("jetVertexAlpha1","Var"),
                          jetCollection2 = cms.InputTag("antikt5CaloJets"),
                          jetVertexAlphaCollection2 = cms.InputTag("jetVertexAlpha2","Var"),
                          PFjetCollection1 = cms.InputTag("L2L3CorJetAK5PF"),
                          PFjetCollection2 = cms.InputTag("antikt5PFJets"),
                          metCollection = cms.InputTag("met"), # preselection
                          TCmetCollection = cms.InputTag("tcMet"),
                          genMetCollection = cms.InputTag("genMetCalo"),
                          PFmetCollection = cms.InputTag("pfMet"),
                          calotowerCollection = cms.InputTag("lowThrCaloTowers"),
                          hbheInput = cms.InputTag("hbhereco"),
                          hoInput = cms.InputTag("horeco"),
                          hfInput = cms.InputTag("hfreco"),
                          ecalInputs = cms.VInputTag(cms.InputTag("ecalRecHit","EcalRecHitsEB"),
                                                     cms.InputTag("ecalRecHit","EcalRecHitsEE")),
                          hepMcCollection = cms.InputTag("source"),
                          genInfoCollection = cms.InputTag("source"),
                          genWeightCollection = cms.untracked.string('CSA07WeightProducer'),
                          nameFile = cms.untracked.string('analysisTree.root'),
                          nameTree = cms.untracked.string('ntp1'),
                          # switch ON/OFF the candidate collections to dump
                          dumpRunInfo = cms.untracked.bool(True),
                          dumpElectrons = cms.untracked.bool(True),
                          dumpPFlowElectrons = cms.untracked.bool(True),
                          dumpMuons = cms.untracked.bool(True),
                          dumpTracks = cms.untracked.bool(False),
                          dumpGsfTracks = cms.untracked.bool(True),
                          dumpMuonTracks = cms.untracked.bool(True),
                          dumpVertices = cms.untracked.bool(False),
                          dumpK0s = cms.untracked.bool(False),
                          dumpCaloTowers = cms.untracked.bool(False),
                          dumpSCs = cms.untracked.bool(False),
                          dumpBCs = cms.untracked.bool(False),
                          dumpJets = cms.untracked.bool(True),
                          dumpMet = cms.untracked.bool(True),
                          # switch ON/OFF the particle flow objects to dump
                          dumpParticleFlowObjects = cms.untracked.bool(False),
                          # switch ON/OFF the additional informations to dump
                          saveEcal = cms.untracked.bool(True),
                          saveFatEcal = cms.untracked.bool(True),
                          saveTrk = cms.untracked.bool(True),
                          saveFatTrk = cms.untracked.bool(True),
                          saveTrackDeDx = cms.untracked.bool(False),
                          saveEleID = cms.untracked.bool(True),
                          savePFEleGsfTrk = cms.untracked.bool(True),
                          savePFEleBasic = cms.untracked.bool(True),
                          saveJetAlpha = cms.untracked.bool(True),
                          saveJet1BTag = cms.untracked.bool(True),
                          saveJet2BTag = cms.untracked.bool(False),
                          # MC truth
                          mcTruthCollection = cms.InputTag("genParticles"),
                          electronMatchMap = cms.InputTag("electronMatchMap"),
                          muonMatchMap = cms.InputTag("muonMatchMap"),
                          dumpGenMet = cms.untracked.bool(True),
                          dumpGenJets = cms.untracked.bool(True),
                          dumpMCTruth = cms.untracked.bool(True),
                          dumpGenInfo = cms.untracked.bool(True),
                          dumpPreselInfo = cms.untracked.bool(False),
                          dumpSignalKfactor = cms.untracked.bool(True),
                          doMCEleMatch = cms.untracked.bool(False),
                          doMCMuonMatch = cms.untracked.bool(False),
                          # trigger results
                          dumpTriggerResults = cms.untracked.bool(False),
                          # effectively dump the data into the tree
                          dumpTree = cms.untracked.bool(False)
                          )
