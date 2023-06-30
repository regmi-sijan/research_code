#ifndef SAVECATONODE_H__
#define SAVECATONODE_H__


#define HomogeneousField

#include "ClonesContainer.h"
#include "CaloInfo.h"


#include <fun4all/SubsysReco.h>

#include <fastjet/ClusterSequence.hh>
#include <fastjet/FunctionOfPseudoJet.hh>
#include <fastjet/JetDefinition.hh>
#include <fastjet/PseudoJet.hh>

#include <calobase/RawCluster.h>
#include <calobase/RawClusterContainer.h>
#include <calobase/RawClusterUtility.h>
#include <calobase/RawTower.h>
#include <calobase/RawTowerContainer.h>
#include <calobase/RawTowerGeom.h>
#include <calobase/RawTowerGeomContainer.h>
#include <calotrigger/CaloTriggerInfo.h>

#include <g4jets/Jetv1.h>
#include <g4jets/JetMapv1.h>

#include <vector>

#include <TClonesArray.h>
#include <TParticle.h>


/// Class declarations for use in the analysis module
class Fun4AllHistoManager;
class PHCompositeNode;
class TFile;
class TTree;
class TH1;
class TH1I;
class PHCompositeNode;
class RawClusterContainer;
class RawCluster;
class SvtxTrackMap;
class GlobalVertex;
class PHHepMCGenEventMap;
class JetRecoEval;
class SvtxTrackEval;
class PHG4TruthInfoContainer;
class PHHepMCGenEvent;
class SvtxTrack;
class PHG4Particle;

/// Definition of this analysis module class
class SaveCAtoNode : public SubsysReco
{
 public:

  /// Constructor
  SaveCAtoNode(const std::string &name = "SaveCAtoNode",
              const std::string &fname = "SaveCAtoNode.root", const bool read = false);

  // Destructor
  virtual ~SaveCAtoNode();

  /// SubsysReco initialize processing method
  int Init(PHCompositeNode *);

  /// SubsysReco event processing method
  int process_event(PHCompositeNode *);

  /// SubsysReco end processing method
  int End(PHCompositeNode *);

  int createNode(PHCompositeNode* topNode);



 private:
  /// String to contain the outfile name containing the trees
  std::string m_outfilename;
  std::string m_jetcontainer_name;

  /// Fun4All Histogram Manager tool
  Fun4AllHistoManager *m_hm;
  TH1 *m_htracks_pt;



  /// TFile to hold the following TTrees and histograms
  TFile *m_outfile;
  ClonesContainer *m_CaloInfoContainer; //! Calo info
  bool m_read = false;


  /**
   * Make variables for the relevant trees
   */


};

#endif
