from CRABClient.UserUtilities import config
config = config()

config.section_("General")
config.General.requestName = 'ZSkimDataRelvals74x'
config.General.transferLogs = False

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'data_RAW2DIGI_RECO_SkimZee.py'
#config.JobType.inputFiles = ['./ecalcovariances_popcon_data.db','./ecalcovariances_popcon_mc.db','./ecalnoisecorrelation_popcon_data.db','./ecalnoisecorrelation_popcon_mc.db','./ecaltemplates_popcon_data.db','./ecaltemplates_popcon_mc.db']

config.section_("Data")
#config.Data.inputDataset = '/MinimumBias/Commissioning2015-PromptReco-v1/RECO'
config.Data.inputDataset = '/DoubleElectron/CMSSW_7_4_2-GR_R_74_V12_19May_RelVal_zEl2012D-v1/RAW'
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 100 # 200
#config.Data.lumiMask = 'https://cms-service-dqm.web.cern.ch/cms-service-dqm/CAF/certification/Collisions12/8TeV/Reprocessing/Cert_190456-208686_8TeV_22Jan2013ReReco_Collisions12_JSON.txt'
config.Data.lumiMask = 'Cert_190456-208686_8TeV_22Jan2013ReReco_Collisions12_JSON.txt' # if you downloaded the file in the working directory
config.Data.runRange = '208306-238354' # '193093-194075'
config.Data.splitting = "FileBased"
config.Data.unitsPerJob = 10
config.Data.publication = False
#config.Data.publishDBS = 'phys03'
#config.Data.publishDataName = 'ECAL-multifit-50ns'
config.Data.outLFNDirBase = "/store/user/crovelli/zeeCalib/relval2012"

config.section_("Site")
config.Site.storageSite = "T2_CH_CERN"
