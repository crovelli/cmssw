import FWCore.ParameterSet.Config as cms

from RecoEgamma.EgammaElectronProducers.defaultLowPtGsfElectronIDExtra_cfi import defaultLowPtGsfElectronIDExtra

lowPtGsfElectronIDExtra = defaultLowPtGsfElectronIDExtra.clone(
    ModelNames = cms.vstring(['']),
    ModelWeights = cms.vstring([
#            'RecoEgamma/ElectronIdentification/data/LowPtElectrons/2020Feb24_LowPtElectronsBDT_nnclean2_depth10.xml.gz',  
            'RecoEgamma/ElectronIdentification/data/LowPtElectrons/2020Feb24_LowPtElectronsBDT_nnclean2_depth15.xml.gz',  
            ]),
    ModelThresholds = cms.vdouble([-10.])
    )
