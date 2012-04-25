import FWCore.ParameterSet.Config as cms

process = cms.Process("Tree")

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

from glob import glob
process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring())
process.source.fileNames += ['file:%s'%x for x in glob('/home/avartak/CMS/Higgs/CMSSW_4_2_8/src/WWAnalysis/SkimStep/skims/gghzz4l130/*.root')]

process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.boostedElectronsHZZ = cms.EDProducer("PatElectronBoosterBDTID",
    src = cms.InputTag("boostedElectrons")
)

process.cleanedEl = cms.EDProducer("PATElectronCleaner",
    src = cms.InputTag("boostedElectronsHZZ"),
    preselection = cms.string(""),
    checkOverlaps = cms.PSet(
        muons = cms.PSet(
           src = cms.InputTag("boostedMuons"),
           algorithm = cms.string("byDeltaR"),
           preselection = cms.string("pt > 2 && (isGlobalMuon || numberOfMatches > 1)"),
           deltaR  = cms.double(0.05),
           checkRecoComponents = cms.bool(False),
           pairCut  = cms.string(""),
           requireNoOverlaps  = cms.bool(True),
        )
    ),
    finalCut = cms.string(''),
)


process.recMu = cms.EDFilter("PATMuonSelector",
    src = cms.InputTag("boostedMuons"),
    cut = cms.string("pt > 5 && abs(eta) < 2.4 && (isGlobalMuon || isTrackerMuon)"),
)

process.recEl = cms.EDFilter("PATElectronSelector",
    src = cms.InputTag("cleanedEl"),
    cut = cms.string("pt > 7 && abs(eta) < 2.5"),
)

process.recLep = cms.EDProducer("CandViewMerger",
    src = cms.VInputTag("recMu", "recEl")
)

# Here starts the Z1 step

process.recEE = cms.EDProducer("CandViewShallowCloneCombiner",
    decay = cms.string("recEl@+ recEl@-"),
    cut = cms.string("mass > 12")
)

process.recMM = cms.EDProducer("CandViewShallowCloneCombiner",
    decay = cms.string("recMu@+ recMu@-"),
    cut = cms.string("mass > 12")
)

process.recLL = cms.EDProducer("CandViewMerger",
    src = cms.VInputTag("recMM", "recEE")
)

process.zll = cms.EDProducer("SkimEvent2LProducer",
    src = cms.InputTag("recLL"),
    pfMet = cms.InputTag("pfMet"),
    vertices = cms.InputTag("goodPrimaryVertices")
)

process.selectedZs = cms.EDFilter("SkimEvent2LSelector",
    src = cms.InputTag("zll"),
    #cut = cms.string("passID(0) && passID(1) && combinedPairRelativeIso() < 0.35"),
    cut = cms.string("passID(0) && passID(1) && getTkIso(0)/daughter(0).pt() < 0.7 && getTkIso(1)/daughter(1).pt() < 0.7"),
)

process.bestZ = cms.EDFilter("SkimEvent2LSorter",
    src = cms.InputTag("selectedZs"),
    sortBy = cms.string("abs(mass - 91.188)"),
    sortAscending = cms.bool(True), 
    maxNumber = cms.uint32(1),
)


process.selectedZ1 = cms.EDFilter("SkimEvent2LSelector",
    src = cms.InputTag("bestZ"),
    cut = cms.string("mass > 50 && ((daughter(0).pt>10 && daughter(1).pt>20) || (daughter(0).pt>20 && daughter(1).pt>10)) && passIP(0) && passIP(1) && combinedPairRelativeIso() < 0.35"),
    #cut = cms.string("mass > 50 && ((daughter(0).pt>10 && daughter(1).pt>20) || (daughter(0).pt>20 && daughter(1).pt>10))"),
)


process.zeetree = cms.EDFilter("ProbeTreeProducer",
    src = cms.InputTag("selectedZ1"),
    cut = cms.string("abs(daughter(1).pdgId) == 11"),
    variables   = cms.PSet(
       l1pt     = cms.string("daughter(0).pt"),
       l1eta    = cms.string("daughter(0).eta"),
       l1phi    = cms.string("daughter(0).phi"),
       l2pt     = cms.string("daughter(1).pt"),
       l2eta    = cms.string("daughter(1).eta"),
       l2phi    = cms.string("daughter(1).phi"),
       zmass    = cms.string("mass"),
       zpt      = cms.string("pt"),
       zeta     = cms.string("eta"),
       zphi     = cms.string("phi"),
       l1tkIso  = cms.string("daughter(0).masterClone.userFloat('tkZZ4L')"),
       l1ecalIso= cms.string("daughter(0).masterClone.userFloat('ecalZZ4L')"),
       l1hcalIso= cms.string("daughter(0).masterClone.userFloat('hcalZZ4L')"),
       l2tkIso  = cms.string("daughter(1).masterClone.userFloat('tkZZ4L')"),
       l2ecalIso= cms.string("daughter(1).masterClone.userFloat('ecalZZ4L')"),
       l2hcalIso= cms.string("daughter(1).masterClone.userFloat('hcalZZ4L')"),
       rho      = cms.string("daughter(1).masterClone.userFloat('rhoEl')"),
       nvtx     = cms.string("numvertices")
    ),
    flags = cms.PSet(
       l1id     = cms.string("test_bit(daughter(0).masterClone.electronID('cicTight'),0) == 1 && daughter(0).masterClone.gsfTrack.trackerExpectedHitsInner.numberOfHits <= 1"), 
       l2id     = cms.string("test_bit(daughter(1).masterClone.electronID('cicTight'),0) == 1 && daughter(1).masterClone.gsfTrack.trackerExpectedHitsInner.numberOfHits <= 1"), 
       l1trig   = cms.string("daughter(0).masterClone.triggerObjectMatchesByPath('HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v*').size() > 0 || " + 
                             "daughter(0).masterClone.triggerObjectMatchesByPath('HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v*').size() > 0"),
       l2trig   = cms.string("daughter(1).masterClone.triggerObjectMatchesByPath('HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v*').size() > 0 || " +
                             "daughter(1).masterClone.triggerObjectMatchesByPath('HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v*').size() > 0")
    )
)

process.zmmtree = cms.EDFilter("ProbeTreeProducer",
    src = cms.InputTag("selectedZ1"),
    cut = cms.string("abs(daughter(1).pdgId) == 13"),
    variables   = cms.PSet(
       l1pt     = cms.string("daughter(0).pt"),
       l1eta    = cms.string("daughter(0).eta"),
       l1phi    = cms.string("daughter(0).phi"),
       l2pt     = cms.string("daughter(1).pt"),
       l2eta    = cms.string("daughter(1).eta"),
       l2phi    = cms.string("daughter(1).phi"),
       zmass    = cms.string("mass"),
       zpt      = cms.string("pt"),
       zeta     = cms.string("eta"),
       zphi     = cms.string("phi"),
       l1tkIso  = cms.string("daughter(0).masterClone.userFloat('tkZZ4L')"),
       l1ecalIso= cms.string("daughter(0).masterClone.userFloat('ecalZZ4L')"),
       l1hcalIso= cms.string("daughter(0).masterClone.userFloat('hcalZZ4L')"),
       l2tkIso  = cms.string("daughter(1).masterClone.userFloat('tkZZ4L')"),
       l2ecalIso= cms.string("daughter(1).masterClone.userFloat('ecalZZ4L')"),
       l2hcalIso= cms.string("daughter(1).masterClone.userFloat('hcalZZ4L')"),
       rho      = cms.string("daughter(1).masterClone.userFloat('rhoMu')"),
       nvtx     = cms.string("numvertices")
    ),
    flags = cms.PSet(
       l1id     = cms.string("daughter(0).masterClone.isGlobalMuon && daughter(0).masterClone.track.numberOfValidHits() > 10"), 
       l2id     = cms.string("daughter(1).masterClone.isGlobalMuon && daughter(1).masterClone.track.numberOfValidHits() > 10"), 
       l1trig   = cms.string("daughter(0).masterClone.triggerObjectMatchesByPath('HLT_Mu17_Mu8_v*').size() > 0 || daughter(0).masterClone.triggerObjectMatchesByPath('HLT_Mu13_Mu8_v*').size() > 0"),
       l2trig   = cms.string("daughter(1).masterClone.triggerObjectMatchesByPath('HLT_Mu17_Mu8_v*').size() > 0 || daughter(1).masterClone.triggerObjectMatchesByPath('HLT_Mu13_Mu8_v*').size() > 0"),
    )
)


# Here starts the Z1 + 1 lepton step

process.metVeto = cms.EDFilter("CandViewSelector",
    src = cms.InputTag("pfMet"),
    cut = cms.string("et < 25"),
    filter = cms.bool(True)
)

process.lepMinFilter = cms.EDFilter("CandViewCountFilter",
    src = cms.InputTag("recLep"),
    minNumber = cms.uint32(3),
)

process.lepMaxFilter = cms.EDFilter("CandViewCountFilter",
    src = cms.InputTag("recLep"),
    minNumber = cms.uint32(4),
)

process.zPlusLep = cms.EDProducer("CandViewShallowCloneCombiner",
    decay = cms.string("selectedZ1 recLep"),
    cut = cms.string("deltaR(daughter(0).daughter(0).eta, daughter(0).daughter(0).phi, daughter(1).eta, daughter(1).phi)>0.01 && "+
                     "deltaR(daughter(0).daughter(1).eta, daughter(0).daughter(1).phi, daughter(1).eta, daughter(1).phi)>0.01 && "+
                     "daughter(1).masterClone.userFloat('ip')/daughter(1).masterClone.userFloat('ip') < 4"),
    checkCharge = cms.bool(False)
)

process.zllmtree = cms.EDFilter("ProbeTreeProducer",
    src = cms.InputTag("zPlusLep"),
    cut = cms.string("abs(daughter(1).pdgId) == 13"),
    variables   = cms.PSet(
       pt       = cms.string("daughter(1).pt"),
       eta      = cms.string("daughter(1).eta"),
       phi      = cms.string("daughter(1).phi"),
       tkIso    = cms.string("daughter(1).masterClone.userFloat('tkZZ4L')"),
       ecalIso  = cms.string("daughter(1).masterClone.userFloat('ecalZZ4L')"),
       hcalIso  = cms.string("daughter(1).masterClone.userFloat('hcalZZ4L')"),
       rho      = cms.string("daughter(1).masterClone.userFloat('rhoMu')"),
    ),
    flags = cms.PSet(
       id     = cms.string("daughter(1).masterClone.isGlobalMuon && daughter(1).masterClone.track.numberOfValidHits() > 10"), 
       l1trig   = cms.string("daughter(0).daughter(0).masterClone.triggerObjectMatchesByPath('HLT_Mu17_Mu8_v*').size() > 0 || " + 
                             "daughter(0).daughter(0).masterClone.triggerObjectMatchesByPath('HLT_Mu13_Mu8_v*').size() > 0"),
       l2trig   = cms.string("daughter(0).daughter(1).masterClone.triggerObjectMatchesByPath('HLT_Mu17_Mu8_v*').size() > 0 || " + 
                             "daughter(0).daughter(1).masterClone.triggerObjectMatchesByPath('HLT_Mu13_Mu8_v*').size() > 0"),
       l3trig   = cms.string("daughter(1).masterClone.triggerObjectMatchesByPath('HLT_Mu17_Mu8_v*').size() > 0 || " + 
                             "daughter(1).masterClone.triggerObjectMatchesByPath('HLT_Mu13_Mu8_v*').size() > 0"),
    )
)

process.zlletree = cms.EDFilter("ProbeTreeProducer",
    src = cms.InputTag("zPlusLep"),
    cut = cms.string("abs(daughter(1).pdgId) == 11"),
    variables   = cms.PSet(
       pt       = cms.string("daughter(1).pt"),
       eta      = cms.string("daughter(1).eta"),
       phi      = cms.string("daughter(1).phi"),
       tkIso    = cms.string("daughter(1).masterClone.userFloat('tkZZ4L')"),
       ecalIso  = cms.string("daughter(1).masterClone.userFloat('ecalZZ4L')"),
       hcalIso  = cms.string("daughter(1).masterClone.userFloat('hcalZZ4L')"),
       rho      = cms.string("daughter(1).masterClone.userFloat('rhoEl')"),
    ),
    flags = cms.PSet(
       id     = cms.string("test_bit(daughter(1).masterClone.electronID('cicTight'),0) == 1 && daughter(1).masterClone.gsfTrack.trackerExpectedHitsInner.numberOfHits <= 1"),   
       l1trig   = cms.string("daughter(0).daughter(0).masterClone.triggerObjectMatchesByPath('HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v*').size() > 0 || " + 
                             "daughter(0).daughter(0).masterClone.triggerObjectMatchesByPath('HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v*').size() > 0"),
       l2trig   = cms.string("daughter(0).daughter(1).masterClone.triggerObjectMatchesByPath('HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v*').size() > 0 || " +
                             "daughter(0).daughter(1).masterClone.triggerObjectMatchesByPath('HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v*').size() > 0"),
       l3trig   = cms.string("daughter(1).masterClone.triggerObjectMatchesByPath('HLT_Ele17_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_Ele8_CaloIdT_CaloIsoVL_TrkIdVL_TrkIsoVL_v*').size() > 0 || " +
                             "daughter(1).masterClone.triggerObjectMatchesByPath('HLT_Ele17_CaloIdL_CaloIsoVL_Ele8_CaloIdL_CaloIsoVL_v*').size() > 0")
    )
)

# Here starts the Z1 + 2 SS Leptons step

process.fakeEE = cms.EDProducer("CandViewShallowCloneCombiner",
    decay = cms.string("recEl recEl"),
    cut = cms.string("mass > 12 && charge != 0"),
    checkCharge = cms.bool(False)
)

process.fakeMM = cms.EDProducer("CandViewShallowCloneCombiner",
    decay = cms.string("recMu recMu"),
    cut = cms.string("mass > 12 && charge != 0"),
    checkCharge = cms.bool(False)
)

process.fakes = cms.EDProducer("CandViewMerger",
    src = cms.VInputTag("fakeEE", "fakeMM")
)

process.fakeLL = cms.EDProducer("SkimEvent2LProducer",
    src = cms.InputTag("fakes"),
    pfMet = cms.InputTag("pfMet"),
    vertices = cms.InputTag("goodPrimaryVertices")
)


process.zx = cms.EDProducer("CandViewShallowCloneCombiner",
    decay = cms.string("selectedZ1 fakeLL"),
    cut = cms.string("deltaR(daughter(0).daughter(0).eta, daughter(0).daughter(0).phi, daughter(1).daughter(0).eta, daughter(1).daughter(0).phi)>0.01 &&"+
                     "deltaR(daughter(0).daughter(0).eta, daughter(0).daughter(0).phi, daughter(1).daughter(1).eta, daughter(1).daughter(1).phi)>0.01 &&"+
                     "deltaR(daughter(0).daughter(1).eta, daughter(0).daughter(1).phi, daughter(1).daughter(0).eta, daughter(1).daughter(0).phi)>0.01 &&"+
                     "deltaR(daughter(0).daughter(1).eta, daughter(0).daughter(1).phi, daughter(1).daughter(1).eta, daughter(1).daughter(1).phi)>0.01 &&"+
                     "daughter(1).masterClone.passIP(0) && daughter(1).masterClone.passIP(1)"),
    checkCharge = cms.bool(False)
)

process.skimEventZXNoArb = cms.EDProducer("SkimEvent4LProducer",
    src = cms.InputTag("zx"),
    reducedPFCands = cms.InputTag("reducedPFCands"),
    jets = cms.InputTag("slimPatJets"),
    pfMet = cms.InputTag("pfMet"),
    vertices = cms.InputTag("goodPrimaryVertices"),
    isMC = cms.bool(False),
    mcMatch = cms.InputTag(""),
    doswap = cms.bool(False)
)

process.skimEventZX = cms.EDFilter("SkimEvent4LSorter",
    src = cms.InputTag("skimEventZXNoArb"),
    sortBy = cms.string("daughter(1).daughter(0).pt + daughter(1).daughter(1).pt"),
    sortAscending = cms.bool(False), 
    maxNumber = cms.uint32(1),
)


process.load("WWAnalysis.AnalysisStep.zz4lTree_cfi")
process.zx4lTree = process.zz4lTree.clone(src = cms.InputTag("skimEventZX"))


# Here starts the Zbb+tt control step

process.hfMu = cms.EDFilter("PATMuonSelector",
    src = cms.InputTag("boostedMuons"),
    cut = cms.string("pt > 5 && abs(eta) < 2.4 && isGlobalMuon && track.numberOfValidHits > 10 && userFloat('ip')/userFloat('ipErr') > 5"),
)

process.hfEl = cms.EDFilter("PATElectronSelector",
    src = cms.InputTag("cleanedEl"),
    cut = cms.string("pt > 7 && abs(eta) < 2.5 && userFloat('ip')/userFloat('ipErr') > 5 && test_bit(electronID('cicTight'),0) == 1 && gsfTrack.trackerExpectedHitsInner.numberOfHits <= 1"),
)

process.hfLep = cms.EDProducer("CandViewMerger",
    src = cms.VInputTag("hfMu", "hfEl")
)


process.hfLL = cms.EDProducer("CandViewShallowCloneCombiner",
    decay = cms.string("hfLep hfLep"),
    cut = cms.string("mass > 12"),
    checkCharge = cms.bool(False)
)   

process.zzhf = cms.EDProducer("CandViewShallowCloneCombiner",
    decay = cms.string("selectedZ1 hfLL"),
    cut = cms.string(""),
    checkCharge = cms.bool(False)
)

process.skimEventHFNoArb = cms.EDProducer("SkimEvent4LProducer",
    src = cms.InputTag("zzhf"),
    reducedPFCands = cms.InputTag("reducedPFCands"),
    jets = cms.InputTag("slimPatJets"),
    pfMet = cms.InputTag("pfMet"),
    vertices = cms.InputTag("goodPrimaryVertices"),
    isMC = cms.bool(False),
    mcMatch = cms.InputTag(""),
    doswap = cms.bool(False)
)   


process.skimEventHF = cms.EDFilter("SkimEvent4LSorter",
    src = cms.InputTag("skimEventHFNoArb"),
    sortBy = cms.string("daughter(1).daughter(0).pt + daughter(1).daughter(1).pt"),
    sortAscending = cms.bool(False),
    maxNumber = cms.uint32(1),
)

process.zzhf4lTree = process.zz4lTree.clone(src = cms.InputTag("skimEventHF"))

# Here starts the ZZ step

process.zz = cms.EDProducer("CandViewShallowCloneCombiner",
    decay = cms.string("selectedZ1 selectedZs"),
    cut = cms.string("deltaR(daughter(0).daughter(0).eta, daughter(0).daughter(0).phi, daughter(1).daughter(0).eta, daughter(1).daughter(0).phi)>0.01 &&"+
                     "deltaR(daughter(0).daughter(0).eta, daughter(0).daughter(0).phi, daughter(1).daughter(1).eta, daughter(1).daughter(1).phi)>0.01 &&"+
                     "deltaR(daughter(0).daughter(1).eta, daughter(0).daughter(1).phi, daughter(1).daughter(0).eta, daughter(1).daughter(0).phi)>0.01 &&"+
                     "deltaR(daughter(0).daughter(1).eta, daughter(0).daughter(1).phi, daughter(1).daughter(1).eta, daughter(1).daughter(1).phi)>0.01 &&"+
                     "daughter(1).masterClone.passIP(0) && daughter(1).masterClone.passIP(1)")
)

process.skimEvent4LNoArb = cms.EDProducer("SkimEvent4LProducer",
    src = cms.InputTag("zz"),
    reducedPFCands = cms.InputTag("reducedPFCands"),
    jets = cms.InputTag("slimPatJets"),
    pfMet = cms.InputTag("pfMet"),
    vertices = cms.InputTag("goodPrimaryVertices"),
    isMC = cms.bool(False),
    mcMatch = cms.InputTag(""),
    doswap = cms.bool(False)
)

process.selectedZZs = cms.EDFilter("SkimEvent4LSelector",
    src = cms.InputTag("skimEvent4LNoArb"),
    cut = cms.string("worsePairCombRelIsoBaseline < 0.35 && (hypo == 4 || hypo == 5 || nGoodPairs(\"mass > 12\", 0) >= 3)"),
)   

process.skimEvent4L = cms.EDFilter("SkimEvent4LSorter",
    src = cms.InputTag("selectedZZs"),
    sortBy = cms.string("daughter(1).daughter(0).pt + daughter(1).daughter(1).pt"),
    sortAscending = cms.bool(False),
    maxNumber = cms.uint32(1),
)


# Here is the step for studying isolation - basically no selection on the leptons

process.recLLLLdups = cms.EDProducer("CandViewShallowCloneCombiner",
    decay = cms.string("recLL recLL"),
    cut = cms.string("daughter(0).daughter(0).pt != daughter(1).daughter(0).pt && daughter(0).daughter(1).pt != daughter(1).daughter(1).pt && "+
                     "daughter(0).daughter(1).pt != daughter(1).daughter(0).pt && daughter(0).daughter(0).pt != daughter(1).daughter(1).pt")
)

process.recLLLL = cms.EDProducer("CompositeCandidateDuplicateCleaner",
    src = cms.InputTag("recLLLLdups"),
    algo = cms.string("BestZ1Mass"),
)


process.skimEvent4LIso = cms.EDProducer("SkimEvent4LProducer",
    src = cms.InputTag("recLLLL"),
    reducedPFCands = cms.InputTag("reducedPFCands"),
    jets = cms.InputTag("slimPatJets"),
    pfMet = cms.InputTag("pfMet"),
    vertices = cms.InputTag("goodPrimaryVertices"),
    isMC = cms.bool(False),
    mcMatch = cms.InputTag(""),
    doswap = cms.bool(True)
)

process.zz4lIsoTree = process.zz4lTree.clone(src = cms.InputTag("skimEvent4LIso"))

# Setting up paths

process.zPath = cms.Path(
    process.boostedElectronsHZZ +
    process.cleanedEl +
    process.recMu +
    process.recEl +
    process.recLep +
    process.recEE +
    process.recMM +
    process.recLL +
    process.zll +
    process.selectedZs +
    process.bestZ +
    process.selectedZ1 +
    process.zmmtree +
    process.zeetree
)

process.zpluslepPath = cms.Path(
    process.boostedElectronsHZZ +
    process.cleanedEl +
    process.recMu +
    process.recEl +
    process.recLep +
    process.metVeto +
    process.lepMinFilter +    
    ~process.lepMaxFilter +    
    process.recEE +
    process.recMM +
    process.recLL +
    process.zll +
    process.selectedZs +
    process.bestZ +
    process.selectedZ1 +
    process.zPlusLep +
    process.zllmtree + 
    process.zlletree
)

process.zxPath = cms.Path(
    process.boostedElectronsHZZ +
    process.cleanedEl   +
    process.recMu       +
    process.recEl       +
    process.recLep      +
    process.recEE       +
    process.recMM       +
    process.recLL       +
    process.zll         +
    process.selectedZs  +
    process.bestZ       +
    process.selectedZ1  +
    process.fakeEE      +
    process.fakeMM      +
    process.fakes       +
    process.fakeLL      +
    process.zx          +
    process.skimEventZXNoArb +
    process.skimEventZX +
    process.zx4lTree

)

process.hfPath = cms.Path(
    process.boostedElectronsHZZ +
    process.cleanedEl   +
    process.recMu       +
    process.recEl       +
    process.recLep      +
    process.recEE       +
    process.recMM       +
    process.recLL       +
    process.zll         +
    process.selectedZs  +
    process.bestZ       +
    process.selectedZ1  +
    process.hfMu        +
    process.hfEl        +
    process.hfLep       +
    process.hfLL        +
    process.zzhf        +
    process.skimEventHFNoArb +
    process.skimEventHF +
    process.zzhf4lTree

)


process.zzPath = cms.Path(
    process.boostedElectronsHZZ +
    process.cleanedEl +
    process.recMu +
    process.recEl +
    process.recLep +
    process.recEE       +
    process.recMM       +
    process.recLL       +
    process.zll         +
    process.selectedZs  +
    process.bestZ       +
    process.selectedZ1  +
    process.zz          +
    process.skimEvent4LNoArb     +
    process.selectedZZs +
    process.skimEvent4L +
    process.zz4lTree

)

process.isoPath = cms.Path(
    process.boostedElectronsHZZ +
    process.cleanedEl   +
    process.recMu       +
    process.recEl       +
    process.recLep      +
    process.recEE       +
    process.recMM       +
    process.recLL       +
    process.recLLLLdups +
    process.recLLLL     +
    process.skimEvent4LIso +
    process.zz4lIsoTree

)

#process.schedule = cms.Schedule(process.zPath, process.zpluslepPath, process.zxPath, process.hfPath, process.zzPath, process.isoPath)
process.schedule = cms.Schedule(process.zPath, process.zpluslepPath, process.zxPath, process.zzPath)

process.TFileService = cms.Service("TFileService", fileName = cms.string("hzzTree.root"))
