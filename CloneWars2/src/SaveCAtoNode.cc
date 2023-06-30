#include "SaveCAtoNode.h"
#include "ClonesContainer.h"
#include "CaloInfo.h"

/// Cluster/Calorimeter includes
#include <calobase/RawCluster.h>
#include <calobase/RawClusterContainer.h>
#include <calobase/RawClusterUtility.h>
#include <calobase/RawTower.h>
#include <calobase/RawTowerContainer.h>
#include <calobase/RawTowerGeom.h>
#include <calobase/RawTowerGeomContainer.h>
#include <calotrigger/CaloTriggerInfo.h>

#include <phool/phool.h>

/// Jet includes
#include <g4jets/Jetv1.h>
#include <g4jets/JetMap.h>

/// Tracking includes
#include <g4vertex/GlobalVertex.h>
#include <g4vertex/GlobalVertexMap.h>
#include <trackbase_historic/SvtxTrack.h>
#include <trackbase_historic/SvtxTrack_v4.h>
#include <trackbase_historic/SvtxTrackMap.h>
#include <trackbase_historic/SvtxVertex.h>
#include <trackbase_historic/SvtxVertexMap.h>

/// Truth evaluation includes
#include <g4eval/JetEvalStack.h>
#include <g4eval/SvtxEvalStack.h>

/// Fun4All includes
#include <fun4all/Fun4AllHistoManager.h>
#include <fun4all/Fun4AllReturnCodes.h>
#include <g4main/PHG4Hit.h>
#include <g4main/PHG4Particle.h>
#include <g4main/PHG4TruthInfoContainer.h>
#include <phool/PHCompositeNode.h>
#include <phool/getClass.h>

#include <g4jets/FastJetAlgo.h>
#include <g4jets/Jet.h>
#include <g4jets/Jetv1.h>
//#include <jetbackground/FastJetAlgoSub.h>

#include <fastjet/ClusterSequence.hh>
#include <fastjet/FunctionOfPseudoJet.hh>
#include <fastjet/JetDefinition.hh>
#include <fastjet/PseudoJet.hh>

#include <g4main/PHG4Particle.h>            // for PHG4Particle
#include <g4main/PHG4TruthInfoContainer.h>  // for PHG4TruthInfoContainer
#include <g4main/PHG4VtxPoint.h>            // for PHG4VtxPoint
#include <trackbase_historic/SvtxPHG4ParticleMap_v1.h>
#include <kfparticle_sphenix/KFParticle_truthAndDetTools.h>

/// ROOT includes
#include <TFile.h>
#include <TH1.h>
#include <TH1I.h>
#include <TMath.h>
#include <TNtuple.h>
#include <TTree.h>
#include <TDatabasePDG.h>
#include <TParticlePDG.h>
#include <TClonesArray.h>
#include <TParticle.h>

/// C++ includes
#include <cassert>
#include <sstream>
#include <string>

using namespace std;

/**
 * SaveCAtoNode is a class developed to reconstruct jets containing a D-meson
 * The class can be adapted to tag jets using any kind of particle
 * Author: Antonio Silva (antonio.sphenix@gmail.com)
 */

/**
 * Constructor of module
 */
SaveCAtoNode::SaveCAtoNode(const std::string &name, const std::string &filename, const bool read)
  : SubsysReco(name)
  , m_outfilename(filename)
  , m_hm(nullptr)
  , m_CaloInfoContainer(0)
  , m_read(read)
{
  /// Initialize variables and trees so we don't accidentally access
  /// memory that was never allocated
}

/**
 * Destructor of module
 */
SaveCAtoNode::~SaveCAtoNode()
{
  delete m_hm;

}

/**
 * Initialize the module and prepare looping over events
 */
int SaveCAtoNode::Init(PHCompositeNode *topNode)
{
  if (Verbosity() > 5)
  {
    cout << "Beginning Init in SaveCAtoNode" << endl;
  }

  m_outfile = new TFile(m_outfilename.c_str(), "RECREATE");

  m_htracks_pt = new TH1F("htracks_pt", ";#it{p}_{T} (GeV/#it{c});Entries", 20, 0., 10.);

  m_CaloInfoContainer = new ClonesContainer();

  if(!m_read) createNode(topNode);

  return 0;
}

/**
 * Main workhorse function where each event is looped over and
 * data from each event is collected from the node tree for analysis
 */
int SaveCAtoNode::process_event(PHCompositeNode *topNode)
{
  if (Verbosity() > 5)
  {
    cout << "Beginning process_event in AnaTutorial" << endl;
  }

  if(!m_read)
  {
    m_CaloInfoContainer->Reset();

    SvtxTrackMap *trackmap = findNode::getClass<SvtxTrackMap>(topNode, "SvtxTrackMap");

    if (!trackmap)
    {
      cout << PHWHERE
           << "SvtxTrackMap node is missing, can't collect tracks"
           << endl;
      return 0;
    }

    SvtxTrack *track = 0;
    int i = 0;
    //TParticle *part = new TParticle();
    CaloInfo *caloinfo = new CaloInfo();

    for (SvtxTrackMap::Iter iter = trackmap->begin();
         iter != trackmap->end();
         ++iter)
    {
      track = iter->second;

      if(!track) continue;

      m_htracks_pt->Fill(track->get_pt());
      cout << "pt: " << track->get_pt() << endl;

      caloinfo->setTime(track->get_pt());
      caloinfo->setAmplitude(track->get_pt());
      // caloinfo->setVTime(track->get_pt(), 0);
      // caloinfo->setVTime(2.*track->get_pt(), 1);

      //part->SetMomentum(track->get_px(), track->get_py(), track->get_pz(), 0);
      m_CaloInfoContainer->add(caloinfo,i);
      //new ((*m_CaloInfo)[i]) TParticle(*part);
      i++;
    }

    // int csize = m_CaloInfoContainer->size();


    // for(int j = 0; j < csize; j++)
    // {
    //   CaloInfo *ci = m_CaloInfoContainer->at(j);
    //   float v1 = ci->getVTime(0);
    //   float v2 = ci->getVTime(1);
    //   cout << "From Clones pt: " << ci->getTime() << endl;
    //   cout << "v1: " << v1 << endl;
    //   cout << "v2: " << v2 << endl;
    // }
  }
  else
  {
    ClonesContainer *clones = findNode::getClass<ClonesContainer>(topNode, "caloInfo_Container");

    if (!clones)
    {
      cout << PHWHERE
           << "ClonesContainer node is missing, can't collect clones"
           << endl;
      return 0;
    }


    // for(int i = 0; i < clones->size(); i++)
    // {
    //   CaloInfo *ci = clones->at(i);
    //   cout << "CaloInfo time: " << ci->getTime() << endl;
    // }
  }




  return Fun4AllReturnCodes::EVENT_OK;
}

/**
 * End the module and finish any data collection. Clean up any remaining
 * loose ends
 */
int SaveCAtoNode::End(PHCompositeNode *topNode)
{
  if (Verbosity() > 1)
  {
    cout << "Ending SaveCAtoNode analysis package" << endl;
  }

  /// Change to the outfile
  m_outfile->cd();

  /// Write and close the outfile
  m_outfile->Write();
  m_outfile->Close();

  /// Clean up pointers and associated histos/trees in TFile
  delete m_outfile;

  if (Verbosity() > 1)
  {
    cout << "Finished SaveCAtoNode analysis package" << endl;
  }

  return 0;
}

int SaveCAtoNode::createNode(PHCompositeNode* topNode)
{
  PHNodeIterator iter(topNode);

  PHCompositeNode* lowerNode = dynamic_cast<PHCompositeNode*>(iter.findFirst("PHCompositeNode", "DST"));
  if (!lowerNode)
  {
    lowerNode = new PHCompositeNode("DST");
    topNode->addNode(lowerNode);
    std::cout << "DST node added" << std::endl;
  }

  std::string baseName;
  std::string jetNodeName;

  if (m_jetcontainer_name.empty())
    baseName = "caloInfo";
  else
    baseName = m_jetcontainer_name;

  //Cant have forward slashes in DST or else you make a subdirectory on save!!!
  std::string undrscr = "_";
  std::string nothing = "";
  std::map<std::string, std::string> forbiddenStrings;
  forbiddenStrings["/"] = undrscr;
  forbiddenStrings["("] = undrscr;
  forbiddenStrings[")"] = nothing;
  forbiddenStrings["+"] = "plus";
  forbiddenStrings["-"] = "minus";
  forbiddenStrings["*"] = "star";
  for (auto const& [badString, goodString] : forbiddenStrings)
  {
    size_t pos;
    while ((pos = baseName.find(badString)) != std::string::npos) baseName.replace(pos, 1, goodString);
  }

  jetNodeName = baseName + "_Container";

  PHIODataNode<PHObject>* caloInfoNode = new PHIODataNode<PHObject>(m_CaloInfoContainer, jetNodeName.c_str(), "PHObject");
  lowerNode->addNode(caloInfoNode);
  std::cout << jetNodeName << " node added" << std::endl;



  return Fun4AllReturnCodes::EVENT_OK;
}
