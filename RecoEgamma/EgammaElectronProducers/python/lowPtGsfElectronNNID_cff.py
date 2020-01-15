import FWCore.ParameterSet.Config as cms

from RecoEgamma.EgammaElectronProducers.defaultLowPtGsfElectronNNID_cfi import defaultLowPtGsfElectronNNID

lowPtGsfElectronNNID = defaultLowPtGsfElectronNNID.clone(
    ModelName = cms.string(''),
    ModelThresholds = cms.double(-50.)
    )
