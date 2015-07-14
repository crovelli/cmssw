from CRABClient.UserUtilities import config
config = config()

config.section_("General")
config.General.requestName = 'ZSkimData2012B'
config.General.transferLogs = False

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'skimZeeOfficial.py'

config.section_("Data")
config.Data.inputDataset = '/DoubleEG/Run2015B-PromptReco-v1/AOD'
config.Data.inputDBS = 'global'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 100 
config.Data.lumiMask = '/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions15/13TeV/DCSOnly/json_DCSONLY_Run2015B.txt'
config.Data.publication = False
config.Data.outLFNDirBase = "/store/user/crovelli/zeeCalib/2012B/DoubleEG_bis"

config.section_("Site")
config.Site.storageSite = "T2_IT_Rome"
