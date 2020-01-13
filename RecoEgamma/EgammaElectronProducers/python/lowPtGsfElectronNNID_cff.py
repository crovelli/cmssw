import FWCore.ParameterSet.Config as cms

from RecoEgamma.EgammaElectronProducers.defaultLowPtGsfElectronNNID_cfi import defaultLowPtGsfElectronNNID

lowPtGsfElectronNNID = defaultLowPtGsfElectronNNID.clone(
    ModelName = cms.string(''),
    ModelWeights = cms.string('RecoEgamma/ElectronIdentification/data/LowPtElectrons/test_short_latest.txt'),
    ModelThresholds = cms.double(-50.)
    )
