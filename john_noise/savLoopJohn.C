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
   
   // open and write the new file to save the data
   //fstream fout;
   //fout.open("noise.csv", ios::out|ios::app);// name can be changed as per requirement
   //
   

   Long64_t nentries = fChain->GetEntriesFast();
   //cout << "nentries " << nentries << endl; // nentries == 4998 will be output 
   Long64_t nbytes = 0, nb = 0;
   
   
   //saving the data into the file
   fstream fout; //8, out9, out10, out11, outall;
   
   //for(int main_loop=0;main_loop<4;main_loop++){ // this is use to make noise.csv of around 25 K rows
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
      //if (main_loop == 0){
      fout.open("noise_raw.csv",ios::out|ios::app);
	//out9.open("noise9.csv",ios::out|ios::app);
	//out10.open("noise10.csv",ios::out|ios::app);
	//out11.open("noise11.csv",ios::out|ios::app);

      int i; int j;
      for(i=0;i<128;i++){

       if(i ==8 or i ==9 or i ==10 or i ==11){ 

	for(j = 0; j < 31; j++){

	  if(j < 30)
	   {fout << adc[i][j] << ",";}
	   // out9 << adc[9][j] << ",";
	   // out10 << adc[10][j] << ",";
	   // out11 << adc[11][j] << ",";}

          if(j == 30)
	   {fout << adc[i][j] << endl;}
	   //out9 << adc[9][j] << endl;
	   //out10 << adc[10][j] << endl;
	   //out11 << adc[11][j] << endl;}
	   }}}
       fout.close();
 	//out9.close();
	//out10.close();
	//out11.close();}
	
	/*
      outall.open("noise.csv",ios::out|ios::app);
	int k; int l;
	for(k=0;k<128;k++){
	 if(k==8 or k ==9 or k==10 or k==11){
	  for(l=0;l<31;l++){
	   if(l<30){
		outall << adc[k][l] << ",";}
	   if(l==30){
		outall << adc[k][l] << endl;}
	}}}
      outall.close();
	*/


	//if(i<128){cout << pedestal[i] << endl;} //get output of pedestal
	//for every 31 adc values there is one pedestal value
	/*for(j =0; j<31;j++)
	 {
	   if(j<30){fout << adc[i][j] << ",";}
	   if(j == 30){fout << adc[i][j];}
    	 }*/
	// fout << endl;
	}

      // if (Cut(ientry) < 0) continue;
   //}
}
