//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Sep  5 19:04:35 2022 by ROOT version 5.34/36
// from TTree W/Waveform digitizer raw data
// found on file: junk_00003080-0000.root
//////////////////////////////////////////////////////////

#ifndef loopJohnWtree_h
#define loopJohnWtree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class loopJohnWtree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           runnumber;
   Int_t           evtnr;
   Int_t           clock;
   Int_t           femslot[2];
   Int_t           femevtnr[2];
   Int_t           femclock[2];
   Int_t           adc[128][31];
   Float_t         mean[128];
   Float_t         rms[128];
   Int_t           minadc[128];
   Int_t           maxadc[128];
   Float_t         pedestal[128];
   Float_t         pedsig[128];
   Float_t         peak[128];
   Float_t         time[128];
   Float_t         integral[128];
   Float_t         integral2[128];
   Int_t           summary;

   // List of branches
   TBranch        *b_runnumber;   //!
   TBranch        *b_evtnr;   //!
   TBranch        *b_clock;   //!
   TBranch        *b_femslot;   //!
   TBranch        *b_femevtnr;   //!
   TBranch        *b_femclock;   //!
   TBranch        *b_adc;   //!
   TBranch        *b_mean;   //!
   TBranch        *b_rms;   //!
   TBranch        *b_minadc;   //!
   TBranch        *b_maxadc;   //!
   TBranch        *b_pedestal;   //!
   TBranch        *b_pedsig;   //!
   TBranch        *b_peak;   //!
   TBranch        *b_time;   //!
   TBranch        *b_integral;   //!
   TBranch        *b_integral2;   //!
   TBranch        *b_summary;   //!

   loopJohnWtree(TTree *tree=0);
   virtual ~loopJohnWtree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef loopJohnWtree_cxx
loopJohnWtree::loopJohnWtree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("junk_00003080-0000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("junk_00003080-0000.root");
      }
      f->GetObject("W",tree);

   }
   Init(tree);
}

loopJohnWtree::~loopJohnWtree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t loopJohnWtree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t loopJohnWtree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void loopJohnWtree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runnumber", &runnumber, &b_runnumber);
   fChain->SetBranchAddress("evtnr", &evtnr, &b_evtnr);
   fChain->SetBranchAddress("clock", &clock, &b_clock);
   fChain->SetBranchAddress("femslot", femslot, &b_femslot);
   fChain->SetBranchAddress("femevtnr", femevtnr, &b_femevtnr);
   fChain->SetBranchAddress("femclock", femclock, &b_femclock);
   fChain->SetBranchAddress("adc", adc, &b_adc);
   fChain->SetBranchAddress("mean", mean, &b_mean);
   fChain->SetBranchAddress("rms", rms, &b_rms);
   fChain->SetBranchAddress("minadc", minadc, &b_minadc);
   fChain->SetBranchAddress("maxadc", maxadc, &b_maxadc);
   fChain->SetBranchAddress("pedestal", pedestal, &b_pedestal);
   fChain->SetBranchAddress("pedsig", pedsig, &b_pedsig);
   fChain->SetBranchAddress("peak", peak, &b_peak);
   fChain->SetBranchAddress("time", time, &b_time);
   fChain->SetBranchAddress("integral", integral, &b_integral);
   fChain->SetBranchAddress("integral2", integral2, &b_integral2);
   fChain->SetBranchAddress("summary", &summary, &b_summary);
   Notify();
}

Bool_t loopJohnWtree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void loopJohnWtree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t loopJohnWtree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef loopJohnWtree_cxx
