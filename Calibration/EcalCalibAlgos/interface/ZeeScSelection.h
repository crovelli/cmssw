#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "DataFormats/Common/interface/Handle.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/EgammaReco/interface/SuperCluster.h"

#include "TTree.h"
#include "TBranch.h"
#include "TFile.h"
#include <string> 

#include <iostream>
#include "TLorentzVector.h"

// output tree
struct tree_struc_ {
  
  float mass;
  float massSc;
  float massPsc;
  float eta1;
  float eta2;
  float phi1;
  float phi2;
  float ene1;
  float ene2;
  float et1;
  float et2;
  float r91;
  float r92;
};

using namespace std;
using namespace edm;
using namespace reco;

class ZeeScSelection : public edm::EDAnalyzer {

public:

  explicit ZeeScSelection(const edm::ParameterSet&);
  ~ZeeScSelection();

private:
  
  edm::Service<TFileService> fs_;

  virtual void beginJob() override;
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;

  float invMassCalc(float Energy1, float Eta1, float Phi1, float Energy2, float Eta2, float Phi2);
  float cosTheta12(float Eta1, float Phi1, float Eta2, float Phi2);

  void initTreeStructure();

  // collections
  edm::InputTag ebSuperclusters_;    
  edm::InputTag eeSuperclusters_;    
  edm::InputTag electrons_; 

  // outputs
  string outputFile_;
  TTree *myTree;
  tree_struc_ tree_;
};

