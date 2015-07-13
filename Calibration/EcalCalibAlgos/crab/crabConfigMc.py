from CRABClient.UserUtilities import config
config = config()

config.section_("General")
config.General.requestName = 'DYJetsToLL_Phys14DR_zeeSkim'
config.General.transferLogs = False

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'skimZee.py'

config.section_("Data")
config.Data.inputDataset = '/DYJetsToLL_M-50_13TeV-madgraph-pythia8/Phys14DR-PU20bx25_PHYS14_25_V1-v1/AODSIM'
config.Data.inputDBS = 'global'
config.Data.splitting = "FileBased"
config.Data.unitsPerJob = 10
config.Data.publication = False
config.Data.outLFNDirBase = "/store/user/crovelli/zeeCalib"

config.section_("Site")
config.Site.storageSite = "T2_IT_Rome"
