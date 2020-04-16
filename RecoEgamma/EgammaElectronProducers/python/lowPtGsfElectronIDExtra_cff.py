import FWCore.ParameterSet.Config as cms

from RecoEgamma.EgammaElectronProducers.defaultLowPtGsfElectronIDExtra_cfi import defaultLowPtGsfElectronIDExtra

lowPtGsfElectronIDExtra = defaultLowPtGsfElectronIDExtra.clone(
    ModelNames = cms.vstring(['']),
    ModelWeights = cms.vstring([
#            'RecoEgamma/ElectronIdentification/data/LowPtElectrons/2020Feb24__cmssw_mva_id_nnclean2_BDT__paramChiara.fixed.xml.gz',  
            'RecoEgamma/ElectronIdentification/data/LowPtElectrons/2020Feb24__cmssw_mva_id_nnclean2_BDT__paramRob.fixed.xml.gz',  
            ]),
    ModelThresholds = cms.vdouble([-10.])
    )
