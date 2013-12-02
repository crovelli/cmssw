#! /bin/sh
# usage: bash install.sh TAG

if [[ $# < 1 ]];
then
    echo "Provide the tag. Usage:  bash install.sh TAG"
    exit
fi;

echo "===> Installing VECBOS in CMSSW release " $CMSSW_VERSION " with the tag: " $1

cd $CMSSW_BASE/src

if [[ "$CMSSW_VERSION" == CMSSW_5_3_* ]];
then

    rm install.sh
    git clone -n -b vecbos-run2-light -o my-cmssw git@github.com:emanueledimarco/cmssw.git $CMSSW_BASE/src
    git config core.sparsecheckout true

    echo HiggsAnalysis/HiggsToWW2e > .git/info/sparse-checkout
    echo HiggsAnalysis/HiggsToWW2Leptons >> .git/info/sparse-checkout
    echo HiggsAnalysis/HiggsToGammaGamma >> .git/info/sparse-checkout
    echo HiggsAnalysis/Tools >> .git/info/sparse-checkout
    echo MyAnalysis/IsolationTools >> .git/info/sparse-checkout
    echo MyAnalysis/METFlags >> .git/info/sparse-checkout
    echo RecoBTag/ImpactParameter >> .git/info/sparse-checkout
    echo PhysicsTools/EcalAnomalousEventFilter >> .git/info/sparse-checkout
    echo WWAnalysis/DataFormats >> .git/info/sparse-checkout
    echo WWAnalysis/Tools >> .git/info/sparse-checkout
    echo WWAnalysis/Filters >> .git/info/sparse-checkout
    echo WWAnalysis/TreeModifiers >> .git/info/sparse-checkout
    echo Muon/MuonAnalysisTools >> .git/info/sparse-checkout
    echo ElectroWeakAnalysis/Utilities >> .git/info/sparse-checkout
    echo JetMETAnalysis/ecalDeadCellTools >> .git/info/sparse-checkout
    echo JetMETCorrections/Objects >> .git/info/sparse-checkout
    echo JetMETCorrections/Modules >> .git/info/sparse-checkout
    echo JetMETCorrections/Type1MET >> .git/info/sparse-checkout
    echo DataFormats/METReco >> .git/info/sparse-checkout
    echo CommonTools/RecoAlgos >> .git/info/sparse-checkout
    echo RecoMET/METAnalyzers >> .git/info/sparse-checkout
    echo RecoMET/METFilters >> .git/info/sparse-checkout
    echo DataFormats/TrackerCommon >> .git/info/sparse-checkout
    echo DPGAnalysis/SiStripTools >> .git/info/sparse-checkout
    echo DPGAnalysis/Skims >> .git/info/sparse-checkout
    echo RecoLocalTracker/SubCollectionProducers >> .git/info/sparse-checkout
    echo ElectroWeakAnalysis/Utilities >> .git/info/sparse-checkout
    echo CMGTools/External >> .git/info/sparse-checkout
    echo RecoTauTag/Configuration >> .git/info/sparse-checkout
    echo CondFormats/EgammaObjects >> .git/info/sparse-checkout
    echo DataFormats/PatCandidates >> .git/info/sparse-checkout
    echo RecoEgamma/EgammaTools >> .git/info/sparse-checkout
    echo RecoTauTag/RecoTau >> .git/info/sparse-checkout
    echo EgammaAnalysis/ElectronTools >> .git/info/sparse-checkout
    echo Muon/MuonAnalysisTools >> .git/info/sparse-checkout
    echo QuarkGluonTagger/EightTeV >> .git/info/sparse-checkout
    echo MuScleFit/Calibration >> .git/info/sparse-checkout 

    git pull my-cmssw $1
    git checkout

fi;
