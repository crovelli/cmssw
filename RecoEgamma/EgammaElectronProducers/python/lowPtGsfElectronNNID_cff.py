import FWCore.ParameterSet.Config as cms

from RecoEgamma.EgammaElectronProducers.defaultLowPtGsfElectronNNID_cfi import defaultLowPtGsfElectronNNID

lowPtGsfElectronNNID = defaultLowPtGsfElectronNNID.clone(
    ModelName = cms.string(''),
    ModelWeights = cms.string('RecoEgamma/ElectronIdentification/data/LowPtElectrons/test_short_LP_NV_rew_NV_99'),
    ModelThresholds = cms.double(-50.)
    )
