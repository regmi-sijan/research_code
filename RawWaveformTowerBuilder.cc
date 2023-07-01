#include "RawWaveformTowerBuilder.h"

#include <fun4all/Fun4AllReturnCodes.h>
#include <fun4all/SubsysReco.h>  // for SubsysReco

#include <calobase/RawTower.h>  // for RawTower
#include <calobase/RawTowerContainer.h>
#include <calobase/RawTowerDefs.h>           // for encode_towerid
#include <calobase/RawTowerGeom.h>           // for RawTowerGeom
#include <calobase/RawTowerGeomContainer.h>  // for RawTowerGeomC...
#include <calobase/RawTowerGeomContainer_Cylinderv1.h>
#include <calobase/RawTowerGeomv1.h>
#include <calobase/RawTowerv1.h>

#include <phool/PHCompositeNode.h>
#include <phool/PHIODataNode.h>    // for PHIODataNode
#include <phool/PHNodeIterator.h>  // for PHNodeIterator
#include <phool/PHObject.h>        // for PHObject
#include <phool/getClass.h>
#include <phool/PHNode.h>  // for PHNode
#include <phool/phool.h>  // for PHWHERE

#include <Event/Event.h>
#include <Event/EventTypes.h>
#include <Event/packet.h>

#include <savecatonode/ClonesContainer.h>
#include <savecatonode/CaloInfo.h>
#include <savecatonode/TowerInfoContainer.h>
#include <savecatonode/TowerInfo.h>
#include <TRandom3.h>

#include <g4detectors/PHG4CylinderCellGeom.h>
#include <g4detectors/PHG4CylinderCellGeomContainer.h>
#include <g4detectors/PHG4Cell.h>
#include <g4detectors/PHG4CellContainer.h>
#include <g4detectors/PHG4CellDefs.h>

#include <cmath>      // for fabs, tan, atan2
#include <cstdlib>    // for exit
#include <exception>  // for exception
#include <iostream>
#include <map>
#include <stdexcept>
#include <utility>  // for pair, make_pair

#include <boost/io/ios_state.hpp>
#include <g4main/PHG4Utils.h>

//____________________________________________________________________________..
RawWaveformTowerBuilder::RawWaveformTowerBuilder(const std::string &name):
 SubsysReco(name)
 , m_dettype(RawWaveformTowerBuilder::CEMC)
 , m_CaloInfoContainer(0)
 , m_detector("CEMC")
 , m_packet_low(6017)
 , m_packet_high(6032)
 , m_isdata(false)
{
  std::cout << "RawWaveformTowerBuilder::" << name << std::endl;
}

//____________________________________________________________________________..
RawWaveformTowerBuilder::~RawWaveformTowerBuilder()
{
  std::cout << "RawWaveformTowerBuilder::~RawWaveformTowerBuilder()" << std::endl;
}

//____________________________________________________________________________..
int RawWaveformTowerBuilder::Init(PHCompositeNode *topNode)
{
  std::cout << "RawWaveformTowerBuilder::Init(PHCompositeNode *topNode) Initializing" << std::endl;
  std::cout << "topNode = " << *topNode << std::endl;

  rnd = new TRandom3();

  WaveformProcessing = new CaloWaveformProcessing();
  WaveformProcessing->set_processing_type(CaloWaveformProcessing::TEMPLATE);

  if (m_dettype == RawWaveformTowerBuilder::CEMC)
    {
      m_detector = "CEMC";
      // m_packet_low = 6001;
      // m_packet_high = 6128;
      m_packet_low = 6017;   // temporary to run over the subset file i have
      m_packet_high = 6032; // temporary to run over the subset file i have
      WaveformProcessing->set_template_file("testbeam_cemc_template.root");
    }
  else if (m_dettype == RawWaveformTowerBuilder::HCALIN)
    {
      m_packet_low  = 7001;
      m_packet_high = 7032;
      m_detector = "HCALIN";
      WaveformProcessing->set_template_file("testbeam_ihcal_template.root");
    }
  else if (m_dettype == RawWaveformTowerBuilder::HCALOUT)
    {
      m_detector = "HCALOUT";
      m_packet_low = 8001;
      m_packet_high = 8032;
      WaveformProcessing->set_template_file("testbeam_ohcal_template.root");
    }
  else if (m_dettype == RawWaveformTowerBuilder::EPD)
    {
      m_detector = "EPD";
      m_packet_low = 9001;
      m_packet_high = 9003;
      WaveformProcessing->set_template_file("testbeam_cemc_template.root"); // place holder until we have EPD templates
    }

  WaveformProcessing->initialize_processing();

/////////////////////////////////////////////////////////
/*
  std::string geonodename = "CYLINDERCELLGEOM_" + m_detector;
  PHG4CylinderCellGeomContainer *cellgeos = findNode::getClass<PHG4CylinderCellGeomContainer>(topNode, geonodename);
  if (!cellgeos)
  {
    std::cout << PHWHERE << " " << geonodename
              << " Node missing, doing nothing." << std::endl;
    throw std::runtime_error(
        "Failed to find " + geonodename + " node in RawTowerBuilder::CreateNodes");
  }

  // fill the number of layers in the calorimeter
  m_NumLayers = cellgeos->get_NLayers();
*/

  // Looking for the DST node
  PHNodeIterator iter(topNode);
  PHCompositeNode *dstNode = dynamic_cast<PHCompositeNode *>(iter.findFirst("PHCompositeNode", "DST"));

  if (!dstNode)
  { 
   std::cout << PHWHERE << "DST Node missing, doing nothing." << std::endl;
    exit(1);
  }

  try
  {
    CreateNodes(topNode);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    //exit(1);
  }

/*
  if (Verbosity() >= 1)
  {
    std::cout << "RawTowerBuilder::InitRun :";
    if (m_TowerEnergySrcEnum == kEnergyDeposition)
    {
      std::cout << "save Geant4 energy deposition as the weight of the cells"
                << std::endl;
    }
    else if (m_TowerEnergySrcEnum == kLightYield)
    {
      std::cout << "save light yield as the weight of the cells" << std::endl;
    }
  }
*/

////////////////////////////////////////////////////////

  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int RawWaveformTowerBuilder::InitRun(PHCompositeNode *topNode)
{
  std::cout << "RawWaveformTowerBuilder::InitRun(PHCompositeNode *topNode) Initializing " << std::endl;
  std::cout << "topNode =  " << *topNode << std::endl;
  CreateNodes(topNode);
  topNode->print();
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int RawWaveformTowerBuilder::process_event(PHCompositeNode *topNode)
{
  if (Verbosity()>=0)
   {
    std::cout << "RawWaveformTowerBuilder::process_event(PHCompositeNode *topNode)" << std::endl;
    std::cout << "topNode = " << *topNode << std::endl;
   }

  _nevents++;
  int nsamples = 16;
  std::vector<std::vector<float>> waveforms;

  if (m_isdata)
    { 
      _event = findNode::getClass<Event>(topNode, "PRDF");
      if (_event == 0)
	{
	  std::cout << "CaloUnpackPRDF::Process_Event - Event not found" << std::endl;
	  return -1;
	}
      if ( _event->getEvtType() >= 7)/// special event where we do not read out the calorimeters
	{
	  return Fun4AllReturnCodes::DISCARDEVENT;
	}
      for ( int pid = m_packet_low; pid <= m_packet_high; pid++)
	{
	  Packet *packet = _event->getPacket(pid);
	  if (!packet)
	    {
	      return Fun4AllReturnCodes::DISCARDEVENT;
	    }
	  for ( int channel = 0; channel <  packet->iValue(0,"CHANNELS"); channel++)
	    {
	      std::vector<float> waveform;
	      for (int samp = 0; samp < nsamples;samp++)
		{
		  waveform.push_back(packet->iValue(samp,channel));
		}
	      waveforms.push_back(waveform);
	      waveform.clear();
	    }
	}
    }
  else
    {
      ClonesContainer *readwaveforms = findNode::getClass<ClonesContainer>(topNode, "WAVEFORMS_CEMC");
      if (!readwaveforms)
	{
	  std::cout << PHWHERE
	       << "ClonesContainer node is missing, can't collect clones"
		    << std::endl;
	  return 0;
	}

      for(int i = 0; i < readwaveforms->size(); i++)
	{
	  CaloInfo *ci = readwaveforms->at(i);
	  // cout << "CaloInfo time: " << ci->getTime() << endl;

	  std::vector<float> waveform;
	  for (int j = 0; j < nsamples;j++)
	    {
	      waveform.push_back(ci->getVWaveform(j));
	    }
	  waveforms.push_back(waveform);
	  waveform.clear();
	}

    }

  std::vector<std::vector<float>> processed_waveforms =  WaveformProcessing->process_waveform(waveforms);

  int n_channels = processed_waveforms.size();
  
  for (int i = 0 ; i < n_channels;i++)
    {

      //TowerInfo *caloinfo = new TowerInfo();
      float amplitudetmp = processed_waveforms.at(i).at(0);

      int test;
      if (amplitudetmp < 10)
      	{
      	  test = round(amplitudetmp*1000)*0.001;
      	}
      else if ( amplitudetmp< 100)
      	{
      	  test = round(amplitudetmp*100)*0.01;
      	}
      else if (amplitudetmp < 1000)
      	{
      	  test = round(amplitudetmp*10)*0.1;
      	}
      else if ( amplitudetmp< 10000)
      	{
      	  test = round(amplitudetmp*1)*1;
      	}
      else if (amplitudetmp < 100000)
      	{
      	  test = round(amplitudetmp*0.1)*10;
      	}
      else
      	{
      	  test = amplitudetmp;
        }
      //short timetmp;

      if (amplitudetmp <=6)
      	{
      	  test = round (amplitudetmp);
      	  //timetmp = -1;
      	}

      /*	
      else
	{
	   timetmp = short(round(processed_waveforms.at(i).at(1)));
	}

       */
      //caloinfo->setTime(timetmp);
      //caloinfo->setAmplitude(test);
      //m_CaloInfoContainer->add(caloinfo,i);
  
       // if we do not need following code at some point, we can just remove them as they are copy of few lines below
      RawTower *tower = nullptr;
      short int firstpar;
      short int secondpar;

      firstpar = i%96; //getting etabin for EMCAL
      secondpar = i/96; //getting phibin for EMCAL
	// here we must define how to get towers for different Calorimeter:: now justing doing for EMCAL only
	// once we define things properly then have to double check with other lines of code
      tower = m_TowerContainer->getTower(firstpar, secondpar);

      if (!tower)
       {
         tower = new RawTowerv1();
         tower->set_energy(0);
         m_TowerContainer->AddTower(firstpar, secondpar, tower);
       }
      
     tower->set_energy(test);
     m_TowerContainer->compress(m_Emin);
    }


/////////////////////////////////////////////////////////////////////////
/*
  // get cells
  std::string cellnodename = "G4CELL_" + m_detector;
  PHG4CellContainer *cells = findNode::getClass<PHG4CellContainer>(topNode, cellnodename);
  
  std::cout << "Do we get this????" << std::endl;

  if (!cells)
  {
    std::cout << PHWHERE << " " << cellnodename
              << " Node missing, doing nothing." << std::endl;
    return Fun4AllReturnCodes::ABORTEVENT;
  }

  // loop over all cells in an event
  PHG4CellContainer::ConstIterator cell_iter;
  PHG4CellContainer::ConstRange cell_range = cells->getCells();
  for (cell_iter = cell_range.first; cell_iter != cell_range.second; ++cell_iter)
  {
    PHG4Cell *cell = cell_iter->second;

    if (Verbosity() > 2)
    {
      std::cout << PHWHERE << " print out the cell:" << std::endl;
      cell->identify();
    }
    // add the energy to the corresponding tower
    RawTower *tower = nullptr;
    short int firstpar;
    short int secondpar;


    if (cell->has_binning(PHG4CellDefs::sizebinning))
    {
      firstpar = PHG4CellDefs::SizeBinning::get_zbin(cell->get_cellid());
      secondpar = PHG4CellDefs::SizeBinning::get_phibin(cell->get_cellid());
    }
    else if (cell->has_binning(PHG4CellDefs::spacalbinning))
    {
      firstpar = PHG4CellDefs::SpacalBinning::get_etabin(cell->get_cellid());
      secondpar = PHG4CellDefs::SpacalBinning::get_phibin(cell->get_cellid());
    }
    else
    {
      boost::io::ios_flags_saver ifs(std::cout);
      std::cout << "unknown cell binning, implement 0x" << std::hex << PHG4CellDefs::get_binning(cell->get_cellid()) << std::dec << std::endl;
      exit(1);
    }
    
    tower = m_TowerContainer->getTower(firstpar, secondpar);
    if (!tower)
    {
      tower = new RawTowerv1();
      tower->set_energy(0);
      m_TowerContainer->AddTower(firstpar, secondpar, tower);
    }
    
    float cell_weight = 0;
    if (m_TowerEnergySrcEnum == kEnergyDeposition)
    {
      cell_weight = cell->get_edep();
    }
    else if (m_TowerEnergySrcEnum == kLightYield)
    {
      cell_weight = cell->get_light_yield();
    }

    tower->add_ecell(cell->get_cellid(), cell_weight);

    PHG4Cell::ShowerEdepConstRange range = cell->get_g4showers();
    for (PHG4Cell::ShowerEdepConstIterator shower_iter = range.first;
         shower_iter != range.second;
         ++shower_iter)
    {
      tower->add_eshower(shower_iter->first, shower_iter->second);
    }

    tower->set_energy(tower->get_energy() + cell_weight);
    
    if (Verbosity() > 2)
    {
      m_RawTowerGeomContainer = findNode::getClass<RawTowerGeomContainer>(topNode, m_TowerGeomNodeName);
      tower->identify();
    }
   }
  double towerE = 0;
  if (m_ChkEnergyConservationFlag)
  {
    double cellE = cells->getTotalEdep();
    towerE = m_TowerContainer->getTotalEdep();
    if (fabs(cellE - towerE) / cellE > 1e-5)
    {
      std::cout << "towerE: " << towerE << ", cellE: " << cellE << ", delta: "
                << cellE - towerE << std::endl;
    }
  }

  if (Verbosity())
  {
    towerE = m_TowerContainer->getTotalEdep();
  }

  m_TowerContainer->compress(m_Emin);
  
  if (Verbosity())
  {
    std::cout << "Energy lost by dropping towers with less than " << m_Emin
              << " GeV energy, lost energy: " << towerE - m_TowerContainer->getTotalEdep()
              << std::endl;
    m_TowerContainer->identify();
    RawTowerContainer::ConstRange begin_end = m_TowerContainer->getTowers();
    RawTowerContainer::ConstIterator iter;
    for (iter = begin_end.first; iter != begin_end.second; ++iter)
    {
      iter->second->identify();
    }
  }
*/
///////////////////////////////////////////////////////////////////////////

  //Quick test script to see if i can read things back:
  //-----------------------------------------------------------------------
  /*
  int csize = m_CaloInfoContainer->size();
  std::cout << csize << std::endl;
  for(int j = 0; j < csize; j++)
    {
       TowerInfo *ci = m_CaloInfoContainer->at(j);
       float v1 = ci->getTime();
       float v2 = ci->getAmplitude();
       std::cout << "time: " << v1 << ", " << "Amplitude: " << v2 << std::endl;
     }
  */
  //-----------------------------------------------------------------------

  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int RawWaveformTowerBuilder::ResetEvent(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int RawWaveformTowerBuilder::EndRun(const int runnumber)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int RawWaveformTowerBuilder::End(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
int RawWaveformTowerBuilder::Reset(PHCompositeNode *topNode)
{
  return Fun4AllReturnCodes::EVENT_OK;
}

//____________________________________________________________________________..
void RawWaveformTowerBuilder::Print(const std::string &what) const
{
}


void RawWaveformTowerBuilder::CreateNodes(PHCompositeNode *topNode)
{/*
  PHNodeIterator iter(topNode);
  PHCompositeNode *runNode = dynamic_cast<PHCompositeNode *>(iter.findFirst("PHCompositeNode", "RUN"));
  std::cout << "RawWaveformTowerBuilder::CreateNodes(PHCompositeNode *topNode) Initializing" << std::endl;
  std::cout << " *topNode = " << *topNode << std::endl;

  if (!runNode)
  {
    std::cout << PHWHERE << "Run Node missing, doing nothing." << std::endl;
    throw std::runtime_error("Failed to find Run node in RawWaveformTowerBuilder::CreateNodes");
  }

  PHNodeIterator runIter(runNode);
  //PHNodeIterator iter(topNode);
  PHCompositeNode *RunDetNode = dynamic_cast<PHCompositeNode *>(runIter.findFirst("PHCompositeNode", m_detector));

  if (!RunDetNode)
  {
    RunDetNode = new PHCompositeNode(m_detector);
    runNode->addNode(RunDetNode);
  }

  const RawTowerDefs::CalorimeterId caloid = RawTowerDefs::convert_name_to_caloid(m_detector);
  
  // get the cell geometry and build up the tower geometry object
  std::string geonodename = "CYLINDERCELLGEOM_" + m_detector;

  PHG4CylinderCellGeomContainer *cellgeos = findNode::getClass<PHG4CylinderCellGeomContainer>(topNode, geonodename);
  if (!cellgeos)
  {
    std::cout << PHWHERE << " " << geonodename
              << " Node missing, doing nothing." << std::endl;
    throw std::runtime_error(
        "Failed to find " + geonodename + " node in RawWaveformTowerBuilder::CreateNodes");
  }

  m_TowerGeomNodeName = "TOWERGEOM_" + m_detector;
  m_RawTowerGeomContainer = findNode::getClass<RawTowerGeomContainer>(topNode, m_TowerGeomNodeName);
  if (!m_RawTowerGeomContainer)
  {
    m_RawTowerGeomContainer = new RawTowerGeomContainer_Cylinderv1(caloid);
    PHIODataNode<PHObject> *newNode = new PHIODataNode<PHObject>(m_RawTowerGeomContainer, m_TowerGeomNodeName, "PHObject");
    RunDetNode->addNode(newNode);
  }
  // fill the number of layers in the calorimeter
  m_NumLayers = cellgeos->get_NLayers();

  // Create the tower nodes on the tree
  PHG4CylinderCellGeomContainer::ConstIterator miter;
  PHG4CylinderCellGeomContainer::ConstRange begin_end =
      cellgeos->get_begin_end();
  int ifirst = 1;
  int first_layer = -1;
  PHG4CylinderCellGeom *first_cellgeo = nullptr;
  double inner_radius = 0;
  double thickness = 0;
  for (miter = begin_end.first; miter != begin_end.second; ++miter)
  {
    PHG4CylinderCellGeom *cellgeo = miter->second;

    if (Verbosity())
    {
      cellgeo->identify();
    }
    thickness += cellgeo->get_thickness();
    if (ifirst)
    {
      first_cellgeo = miter->second;
      m_CellBinning = cellgeo->get_binning();
      m_NumPhiBins = cellgeo->get_phibins();
      m_PhiMin = cellgeo->get_phimin();
      m_PhiStep = cellgeo->get_phistep();
      if (m_CellBinning == PHG4CellDefs::etaphibinning || m_CellBinning == PHG4CellDefs::etaslatbinning)
      {
        m_NumEtaBins = cellgeo->get_etabins();
        m_EtaMin = cellgeo->get_etamin();
        m_EtaStep = cellgeo->get_etastep();
      }
      else if (m_CellBinning == PHG4CellDefs::sizebinning)
      {
        m_NumEtaBins = cellgeo->get_zbins();  // bin eta in the same number of z bins
      }
      else if (m_CellBinning == PHG4CellDefs::spacalbinning)
      {
        // use eta definiton for each row of towers
        m_NumEtaBins = cellgeo->get_etabins();
      }
      else
      {
        std::cout << "RawWaveformTowerBuilder::CreateNodes::" << Name()
                  << " - Fatal Error - unsupported cell binning method "
                  << m_CellBinning << std::endl;
      }
      inner_radius = cellgeo->get_radius();
      first_layer = cellgeo->get_layer();
      ifirst = 0;
    }
    else
    {
      if (m_CellBinning != cellgeo->get_binning())
      {
        std::cout << "inconsistent binning method from " << m_CellBinning
                  << " layer " << cellgeo->get_layer() << ": "
                  << cellgeo->get_binning() << std::endl;
        exit(1);
      }
      if (inner_radius > cellgeo->get_radius())
      {
        std::cout << "radius of layer " << cellgeo->get_layer() << " is "
                  << cellgeo->get_radius() << " which smaller than radius "
                  << inner_radius << " of first layer in list " << first_layer
                  << std::endl;
      }
      if (m_NumPhiBins != cellgeo->get_phibins())
      {
        std::cout << "mixing number of phibins, fisrt layer: " << m_NumPhiBins
                  << " layer " << cellgeo->get_layer() << ": "
                  << cellgeo->get_phibins() << std::endl;
        exit(1);
      }
      if (m_PhiMin != cellgeo->get_phimin())
      {
        std::cout << "mixing number of phimin, fisrt layer: " << m_PhiMin
                  << " layer " << cellgeo->get_layer() << ": "
                  << cellgeo->get_phimin() << std::endl;
        exit(1);
      }
      if (m_PhiStep != cellgeo->get_phistep())
      {
        std::cout << "mixing phisteps first layer: " << m_PhiStep << " layer "
                  << cellgeo->get_layer() << ": " << cellgeo->get_phistep()
                  << " diff: " << m_PhiStep - cellgeo->get_phistep() << std::endl;
        exit(1);
      }
      if (m_CellBinning == PHG4CellDefs::etaphibinning || m_CellBinning == PHG4CellDefs::etaslatbinning)
      {
        if (m_NumEtaBins != cellgeo->get_etabins())
        {
          std::cout << "mixing number of EtaBins , first layer: "
                    << m_NumEtaBins << " layer " << cellgeo->get_layer() << ": "
                    << cellgeo->get_etabins() << std::endl;
          exit(1);
        }
        if (fabs(m_EtaMin - cellgeo->get_etamin()) > 1e-9)
        {
          std::cout << "mixing etamin, fisrt layer: " << m_EtaMin << " layer "
                    << cellgeo->get_layer() << ": " << cellgeo->get_etamin()
                    << " diff: " << m_EtaMin - cellgeo->get_etamin() << std::endl;
          exit(1);
        }
        if (fabs(m_EtaStep - cellgeo->get_etastep()) > 1e-9)
        {
          std::cout << "mixing eta steps first layer: " << m_EtaStep
                    << " layer " << cellgeo->get_layer() << ": "
                    << cellgeo->get_etastep() << " diff: "
                    << m_EtaStep - cellgeo->get_etastep() << std::endl;
          exit(1);
        }
      }

      else if (m_CellBinning == PHG4CellDefs::sizebinning)
      {
        if (m_NumEtaBins != cellgeo->get_zbins())
        {
          std::cout << "mixing number of z bins , first layer: " << m_NumEtaBins
                    << " layer " << cellgeo->get_layer() << ": "
                    << cellgeo->get_zbins() << std::endl;
          exit(1);
        }
      }
    }
  }
  m_RawTowerGeomContainer->set_radius(inner_radius);
  m_RawTowerGeomContainer->set_thickness(thickness);
  m_RawTowerGeomContainer->set_phibins(m_NumPhiBins);
  //m_RawTowerGeomContainer->set_phistep(m_PhiStep);
  //m_RawTowerGeomContainer->set_phimin(m_PhiMin);
  m_RawTowerGeomContainer->set_etabins(m_NumEtaBins);

  if (!first_cellgeo)
  {
    std::cout << "RawWaveformTowerBuilder::CreateNodes - ERROR - can not find first layer of cells "
              << std::endl;

    exit(1);
  }

  for (int ibin = 0; ibin < first_cellgeo->get_phibins(); ibin++)
  {
    const std::pair<double, double> range = first_cellgeo->get_phibounds(ibin);

    m_RawTowerGeomContainer->set_phibounds(ibin, range);
  }

  if (m_CellBinning == PHG4CellDefs::etaphibinning || m_CellBinning == PHG4CellDefs::etaslatbinning || m_CellBinning == PHG4CellDefs::spacalbinning)
  {
    const double r = inner_radius;

    for (int ibin = 0; ibin < first_cellgeo->get_etabins(); ibin++)
    {
      const std::pair<double, double> range = first_cellgeo->get_etabounds(ibin);

      m_RawTowerGeomContainer->set_etabounds(ibin, range);
    }

    // setup location of all towers
    for (int iphi = 0; iphi < m_RawTowerGeomContainer->get_phibins(); iphi++)
    {
      for (int ieta = 0; ieta < m_RawTowerGeomContainer->get_etabins(); ieta++)
      {
        const RawTowerDefs::keytype key =
            RawTowerDefs::encode_towerid(caloid, ieta, iphi);

        const double x(r * cos(m_RawTowerGeomContainer->get_phicenter(iphi)));
        const double y(r * sin(m_RawTowerGeomContainer->get_phicenter(iphi)));
        //const double z(r / tan(PHG4Utils::get_theta(m_RawTowerGeomContainer->get_etacenter(ieta))));
        const double z(r / tan(2*atan(exp(-(m_RawTowerGeomContainer->get_etacenter(ieta))))));

        RawTowerGeom *tg = m_RawTowerGeomContainer->get_tower_geometry(key);
        if (tg)
        {
          if (Verbosity() > 0)
          {
            std::cout << "RawWaveformTowerBuilder::CreateNodes - Tower geometry " << key << " already exists" << std::endl;
          }

          if (fabs(tg->get_center_x() - x) > 1e-4)
          {
            std::cout << "RawWaveformTowerBuilder::CreateNodes - Fatal Error - duplicated Tower geometry " << key << " with existing x = " << tg->get_center_x() << " and expected x = " << x
                      << std::endl;

            exit(1);
          }
          if (fabs(tg->get_center_y() - y) > 1e-4)
          {
            std::cout << "RawWaveformTowerBuilder::CreateNodes - Fatal Error - duplicated Tower geometry " << key << " with existing y = " << tg->get_center_y() << " and expected y = " << y
                      << std::endl;
            exit(1);
          }
          if (fabs(tg->get_center_z() - z) > 1e-4)
          {
            std::cout << "RawWaveformTowerBuilder::CreateNodes - Fatal Error - duplicated Tower geometry " << key << " with existing z= " << tg->get_center_z() << " and expected z = " << z
                      << std::endl;
            exit(1);
          }
        }
        else
        {
          if (Verbosity() > 0)
          {
            std::cout << "RawWaveformTowerBuilder::CreateNodes - building tower geometry " << key << "" << std::endl;
          }

          tg = new RawTowerGeomv1(key);

          tg->set_center_x(x);
          tg->set_center_y(y);
          tg->set_center_z(z);
          m_RawTowerGeomContainer->add_tower_geometry(tg);
        }
      }
    }
  }
  else if (m_CellBinning == PHG4CellDefs::sizebinning)
  {
    const double r = inner_radius;

    for (int ibin = 0; ibin < first_cellgeo->get_zbins(); ibin++)
    {
      const std::pair<double, double> z_range = first_cellgeo->get_zbounds(ibin);
      //          const double r = first_cellgeo->get_radius();
      const double eta1 = -log(tan(atan2(r, z_range.first) / 2.));
      const double eta2 = -log(tan(atan2(r, z_range.second) / 2.));
      m_RawTowerGeomContainer->set_etabounds(ibin, std::make_pair(eta1, eta2));
    }

    // setup location of all towers
    for (int iphi = 0; iphi < m_RawTowerGeomContainer->get_phibins(); iphi++)
    {
      for (int ibin = 0; ibin < first_cellgeo->get_zbins(); ibin++)
      {
        const RawTowerDefs::keytype key = RawTowerDefs::encode_towerid(caloid, ibin, iphi);

        const double x(r * cos(m_RawTowerGeomContainer->get_phicenter(iphi)));
        const double y(r * sin(m_RawTowerGeomContainer->get_phicenter(iphi)));
        const double z(first_cellgeo->get_zcenter(ibin));

        RawTowerGeom *tg = m_RawTowerGeomContainer->get_tower_geometry(key);
        if (tg)
        {
          if (Verbosity() > 0)
          {
            std::cout << "RawWaveformTowerBuilder::CreateNodes - Tower geometry " << key << " already exists" << std::endl;
          }

          if (fabs(tg->get_center_x() - x) > 1e-4)
          {
            std::cout << "RawWaveformTowerBuilder::CreateNodes - Fatal Error - duplicated Tower geometry " << key << " with existing x = " << tg->get_center_x() << " and expected x = " << x
                      << std::endl;

            exit(1);
          }
          if (fabs(tg->get_center_y() - y) > 1e-4)
          {
            std::cout << "RawWaveformTowerBuilder::CreateNodes - Fatal Error - duplicated Tower geometry " << key << " with existing y = " << tg->get_center_y() << " and expected y = " << y
                      << std::endl;
            exit(1);
          }
          if (fabs(tg->get_center_z() - z) > 1e-4)
          {
            std::cout << "RawWaveformTowerBuilder::CreateNodes - Fatal Error - duplicated Tower geometry " << key << " with existing z= " << tg->get_center_z() << " and expected z = " << z
                      << std::endl;
            exit(1);
          }
        }
        else
        {
          if (Verbosity() > 0)
          {
            std::cout << "RawWaveformTowerBuilder::CreateNodes - building tower geometry " << key << "" << std::endl;
          }

          tg = new RawTowerGeomv1(key);

          tg->set_center_x(x);
          tg->set_center_y(y);
          tg->set_center_z(z);
          m_RawTowerGeomContainer->add_tower_geometry(tg);
        }
      }
    }
  }
  else
  {
    std::cout << "RawWaveformTowerBuilder::CreateNodes - ERROR - unsupported cell geometry "
              << m_CellBinning << std::endl;
    exit(1);
  }

  if (Verbosity() >= 1)
  {
    m_RawTowerGeomContainer->identify();
  }

*/
  const RawTowerDefs::CalorimeterId caloid = RawTowerDefs::convert_name_to_caloid(m_detector);

  PHNodeIterator iter(topNode);
  PHCompositeNode *dstNode = dynamic_cast<PHCompositeNode *>(iter.findFirst("PHCompositeNode", "DST"));
  if (!dstNode)
  {
    std::cout << PHWHERE << "DST Node missing, doing nothing." << std::endl;
    throw std::runtime_error(
        "Failed to find DST node");
  }
/*
  PHNodeIterator dstiter(dstNode);
  PHCompositeNode *DetNode = dynamic_cast<PHCompositeNode *>(dstiter.findFirst("PHCompositeNode", m_detector));

  if (!DetNode)
  {
    DetNode = new PHCompositeNode(m_detector);
    dstNode->addNode(DetNode);
  }
*/
  // Create the tower nodes on the tree
  if (m_SimTowerNodePrefix.empty())
  {
    // no prefix, consistent with older convention
    m_TowerNodeName = "RAW_WAVEFORM_TOWER_" + m_detector;
  }
  else
  {
    m_TowerNodeName = "RAW_WAVEFORM_TOWER_" + m_SimTowerNodePrefix + "_" + m_detector;
  }


  m_TowerContainer = findNode::getClass<RawTowerContainer>(dstNode, m_TowerNodeName.c_str());
  if (m_TowerContainer == nullptr)
  {
    m_TowerContainer = new RawTowerContainer(caloid);

    PHIODataNode<PHObject> *towerNode = new PHIODataNode<PHObject>(m_TowerContainer, m_TowerNodeName, "PHObject");
    dstNode->addNode(towerNode);
  }

  return;
}
