#define loopJohnWtree_cxx
#include "loopJohnWtree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLeaf.h>
#include <fstream>
#include <iostream>


void loopJohnWtree::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L loopJohnWtree.C
//      Root > loopJohnWtree t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1: 
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;
   
   // open and write the new files to save the data
   // files are named 8, 9, 10, 11 to read adc[i] th row
   fstream fout;//fout8, fout9, fout10, fout11, fout24, fout25, fout26, fout27;
   //fstream fout40, fout41, fout42, fout43, fout56, fout57, fout58, fout59;
   
   //fout.open("noise.csv", ios::out|ios::app);
   /*
   fout8.open("noise8.csv", ios::out|ios::app);
   fout9.open("noise9.csv",ios::out|ios::app);
   fout10.open("noise10.csv", ios::out|ios::app);
   fout11.open("noise11.csv", ios::out|ios::app);
   */

   Long64_t nentries = fChain->GetEntriesFast();
   //cout << "nentries " << nentries << endl; // nentries == 4998 will be output 
   Long64_t nbytes = 0, nb = 0;
   
   
   for (Long64_t jentry=0; jentry<nentries;jentry++)
   //for (Long64_t jentry=0; jentry<5;jentry++) //number instead of nentries (huge num) 
	{
      Long64_t ientry = LoadTree(jentry); //ientry gives the entry number in current tree 
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
	// there are 4998 jentry values and each of them have 21032 data (nb)
	// nbytes are sum of all nb
	// nentries is the maximum value of jentry 
      //cout << "jentry " << jentry << " nb "<< nb << " nentries " << nentries<< endl;     
     
      
      // the dimension of adc is 128*31; pedestal has length of 128;
      
      // goal: to make "noise.csv" file of 24576 (at least) * 31 dimensions
      // since the reference file has 384,000 rows (in Tim's code).....
      // .....we will make file of same dimension
      //
      // this will give the output of adc for each value of jentry
      // use to save file seperately for 8, 9, 10, 11 rows
      // so we have 11 files each with 4998 rows
      // we can merge them using concat from terminal to get final noise.csv file
 
      cout << adc[9][30] << pedestals[9] << endl;
	/* 
      int i; int j;
      
      for(i=0;i<128;i++){
      //int j;
	for(j = 0; j < 31; j++){
	  if(j < 30)
	   {fout << adc[i][j] << ",";
	    //fout8 << adc[8][j] << ",";
	    //fout9 << adc[9][j] << ",";
	    //fout10 << adc[10][j] << ",";
	    //fout11 << adc[11][j] << ",";
	   }

          if(j == 30)
	   {fout << adc[i][j] << endl;
	    //fout8 << adc[8][j] << endl;
	    //fout9 << adc[9][j] << endl;
	    //fout10 << adc[10][j] << endl;
            //fout11 << adc[11][j] << endl;
	   }
	   }
	 }*/
	}
 //fout.close();
 //fout8.close();
 //fout9.close();
 //fout10.close();
 //fout11.close();

      // if (Cut(ientry) < 0) continue;
   //}
}
