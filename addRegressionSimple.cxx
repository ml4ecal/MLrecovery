

void addRegressionSimple( TString inputFile = "bla.root",   TString outputFile = "blaout.root",  TString variableName = "newECAL", TString txtFile = "weights/bla.txt" ) {
  
  //
  // create TMVA::Reader object
  //
  TMVA::Reader *reader = new TMVA::Reader();
  
  // create a set of variables and declare them to the reader
  // - the variable names must corresponds in name and type to
  // those given in the weight file(s) that you use
  
  float ECAL;
  int   ixECAL;
  int   iyECAL;
  float ES_plane1;
  float ES_plane2;
  float HCAL_depth1;
  float HCAL_depth2;
  float HCAL_depth3;
  float HCAL_depth4;
  
  reader->AddVariable(( "ixECAL",      &ixECAL      );
  reader->AddVariable(( "iyECAL",      &iyECAL      );
  reader->AddVariable(( "ES_plane1",   &ES_plane1   );
  reader->AddVariable(( "ES_plane2" ,  &ES_plane2   );
  reader->AddVariable(( "HCAL_depth1", &HCAL_depth1 );
  reader->AddVariable(( "HCAL_depth2", &HCAL_depth2 );
  reader->AddVariable(( "HCAL_depth3", &HCAL_depth3 );
  reader->AddVariable(( "HCAL_depth4", &HCAL_depth4 );
  
  
  // book the MVA of your choice (prior training of these methods, ie,
  // existence of the weight files is required)
  reader->BookMVA( variableName.Data(),  txtFile.Data() );
 
 
  TFile* oldfile = new TFile (inputFile.Data(), "READ");   
  TTree* oldtree = (TTree*) oldfile -> Get ("mytree");
  
  Long64_t        eventId;
  Int_t           lumiId;
  Int_t           runId;
  Float_t         rho;
  Int_t           nVtx;
  
  TBranch        *b_eventId;   //!
  TBranch        *b_lumiId;   //!
  TBranch        *b_runId;   //!
  TBranch        *b_rho;   //!
  TBranch        *b_nVtx;   //!
  
  oldtree->SetBranchAddress("eventId", &eventId, &b_eventId);
  oldtree->SetBranchAddress("lumiId", &lumiId, &b_lumiId);
  oldtree->SetBranchAddress("runId", &runId, &b_runId);
  oldtree->SetBranchAddress("rho", &rho, &b_rho);
  oldtree->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
  
  
  oldtree->SetBranchAddress("ECAL",        &ECAL        );
  oldtree->SetBranchAddress("ixECAL",      &ixECAL      );
  oldtree->SetBranchAddress("iyECAL",      &iyECAL      );
  oldtree->SetBranchAddress("ES_plane1",   &ES_plane1   );
  oldtree->SetBranchAddress("ES_plane2",   &ES_plane2   );
  oldtree->SetBranchAddress("HCAL_depth1", &HCAL_depth1 );
  oldtree->SetBranchAddress("HCAL_depth2", &HCAL_depth2 );
  oldtree->SetBranchAddress("HCAL_depth3", &HCAL_depth3 );
  oldtree->SetBranchAddress("HCAL_depth4", &HCAL_depth4 );
  
  
  
  
  TFile* newfile = new TFile (outputFile.Data(), "RECREATE");  
  TTree* newtree = new TTree ("mytree", "");
  
  newtree->Branch("eventId", &eventId, "eventId/I");
  newtree->Branch("lumiId",  &lumiId,  "lumiId/I");
  newtree->Branch("runId",   &runId,   "runId/I");
  newtree->Branch("rho",     &rho,     "rho/F");
  newtree->Branch("nVtx",    &nVtx,    "nVtx/I");
  
  
  newtree->Branch("ECAL",        &ECAL,            "ECAL/F");
  newtree->Branch("ixECAL",      &ixECAL,          "ixECAL/I");
  newtree->Branch("iyECAL",      &iyECAL,          "iyECAL/I");
  newtree->Branch("ES_plane1",   &ES_plane1,       "ES_plane1/F");
  newtree->Branch("ES_plane2",   &ES_plane2,       "ES_plane2/F");
  newtree->Branch("HCAL_depth1", &HCAL_depth1,     "HCAL_depth1/F");
  newtree->Branch("HCAL_depth2", &HCAL_depth2,     "HCAL_depth2/F");
  newtree->Branch("HCAL_depth3", &HCAL_depth3,     "HCAL_depth3/F");
  newtree->Branch("HCAL_depth4", &HCAL_depth4,     "HCAL_depth4/F");
  
  
  float ECAL_regressed;
  TString variableName_F; variableName_F.Form("%s/F", variableName.Data());
  newtree->Branch(variableName.Data(), &ECAL_regressed,    variableName_F.Data());
  
  
  
  // ------- start your event loop
  
  for (Long64_t ievt=0; ievt<oldtree->GetEntries();ievt++) {
    
    oldtree->GetEntry(ievt);
    
    // retrieve the corresponding MVA output
    ECAL_regressed = reader->EvaluateMVA( "BDTG method"    );
    
    newtree->Fill();
    
  } // end of event loop
  
  
  
  newfile->cd();
  newtree->Write();
  
  
  
}

