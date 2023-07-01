#pragma once
#if ROOT_VERSION_CODE >= ROOT_VERSION(6,00,0)
#include <fun4all/SubsysReco.h>
#include <fun4all/Fun4AllServer.h>
#include <fun4all/Fun4AllInputManager.h>
#include <fun4allraw/Fun4AllPrdfInputManager.h>
#include <fun4all/Fun4AllDstInputManager.h>
#include <calotowerbuilder/CaloTowerBuilder.h>
#include <fun4all/Fun4AllDstOutputManager.h>

R__LOAD_LIBRARY(libfun4all.so)
R__LOAD_LIBRARY(libfun4allraw.so)
R__LOAD_LIBRARY(libCaloTowerBuilder.so)

#endif

// void Fun4All_TowerBuilder(const char *fname = "/sphenix/data/data02/sphenix/cemc/combinedEvents/EmCalSEB01-000000222-0000_x.prdf", const char *outfile = "trees/0.root")
void Fun4All_TowerBuilder(const char *fname = "/gpfs/mnt/gpfs02/sphenix/user/trinn/calo_reco_software_dev/analysis/Calo_waveform_sim/macro/testdst.root", const char *outfile = "trees/first_run.root")
{
  gSystem->Load("libg4dst");

  Fun4AllServer *se = Fun4AllServer::instance();

  // CaloWaveFormSim *ca = new CaloWaveFormSim("CALOWAVEFORMSIM",outfile);
  // ca->Detector("CEMC");
  // se->registerSubsystem(ca);

  // Fun4AllInputManager *in = new Fun4AllPrdfInputManager("in");
  // in->fileopen(fname);

  Fun4AllInputManager *in = new Fun4AllDstInputManager("in");

  in->fileopen(fname);
  CaloTowerBuilder *ca = new CaloTowerBuilder();

  ca->set_detector_type(CaloTowerBuilder::CEMC);
  se->registerSubsystem(ca);

  // in->AddListFile("g4hits.list");

// Fun4All
  se->registerInputManager(in);

  Fun4AllDstOutputManager *out = new Fun4AllDstOutputManager("DSTOUT", "testoutput_simfile.root");

  out->StripNode("WAVEFORMS_CEMC");
  se->registerOutputManager(out);

  se->run(1);
  se->End();
  se->PrintTimer();
  gSystem->Exit(0);
}
