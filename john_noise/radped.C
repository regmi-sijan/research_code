{
  Int_t pedchan[] = {8,9,10,11,
		     8+16,9+16,10+16,11+16,
		     8+32,9+32,10+32,11+32,
		     8+48,9+48,10+48,11+48 };// 8, 9, 10, 11 are important SiPM(check why?).
  
  gStyle->SetOptFit(111);
  TCanvas *cp = new TCanvas("cp","Radiation damged pedestals",400,1600);
  cp->Divide(2,8);
 
 TString drawstring;
 TString hname;
 Int_t ican = 1;
 TH1F *h;
 Double_t sig[sizeof(pedchan)/sizeof(pedchan[0])];
 Double_t sigerr[sizeof(pedchan)/sizeof(pedchan[0])];
  for (Int_t i = 0; i < sizeof(pedchan)/sizeof(pedchan[0]); i++) {
    hname = "p";
    hname += i;
    drawstring = "pedestal[";
    drawstring += pedchan[i];
    drawstring += "]>>";
    drawstring += hname;
    drawstring += "(600,0,3000)";
    cp->cd(ican);
    //    W->Draw(drawstring);
    W->Fit("gaus",drawstring);
    ican++;
    
    _file0->GetObject(hname,h);
    TF1 *myfit = (TF1*) h->GetFunction("gaus");
    sig[i]  = 0.0;
    sigerr[i] = 0.0;
    if ( myfit ) {
      sig[i]  = myfit->GetParameter(2);
      sigerr[i] = myfit->GetParError(2);
    }
    std::cout << i << ": " << sig[i] << "+/-" << sigerr[i] << std::endl;

  }

  for (Int_t i = 0; i < sizeof(pedchan)/sizeof(pedchan[0]); i++) {
    std::cout << i << "," << sig[i] << "," << sigerr[i] << std::endl;
  }
}
