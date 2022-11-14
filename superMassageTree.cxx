//
// massage the ttree to make it easier for ML
//


void superMassageTree(TString inputName = "oldtree.root", TString outputName = "newtree.root") {
  
//
//  616 xtals
//

  TFile* oldfile = new TFile (inputName.Data(), "READ");  
  
  TTree* oldtree = (TTree*) oldfile -> Get ("mytree");
  
  
  
  TFile* newfile = new TFile (outputName.Data(), "RECREATE");  

  TTree* newtree = new TTree ("mytree", "");
  
  //    Long64_t        eventId;
  //    Int_t           lumiId;
  //    Int_t           runId;
  //    Float_t         rho;
  //    Int_t           nVtx;
  //    ECAL_%d   [616] ...
  //    ES_plane1_%d   [616] ...
  //    ES_plane2_%d   [616] ...
  //    HCAL_depth1_%d   [616] ...
  //    HCAL_depth2_%d   [616] ...
  //    HCAL_depth3_%d   [616] ...
  //    HCAL_depth4_%d   [616] ...
 
  // setup reading
  
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
  
  std::cout << " oldtree = " << oldtree << std::endl;
  
  oldtree->SetBranchAddress("eventId", &eventId, &b_eventId);
  oldtree->SetBranchAddress("lumiId", &lumiId, &b_lumiId);
  oldtree->SetBranchAddress("runId", &runId, &b_runId);
  oldtree->SetBranchAddress("rho", &rho, &b_rho);
  oldtree->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
 
  float ECAL[616];
  float ES_plane1[616];
  float ES_plane2[616];
  float HCAL_depth1[616];
  float HCAL_depth2[616];
  float HCAL_depth3[616];
  float HCAL_depth4[616];
  
  oldtree->SetBranchAddress("ECAL",        ECAL        );
  oldtree->SetBranchAddress("ES_plane1",   ES_plane1   );
  oldtree->SetBranchAddress("ES_plane2",   ES_plane2   );
  oldtree->SetBranchAddress("HCAL_depth1", HCAL_depth1 );
  oldtree->SetBranchAddress("HCAL_depth2", HCAL_depth2 );
  oldtree->SetBranchAddress("HCAL_depth3", HCAL_depth3 );
  oldtree->SetBranchAddress("HCAL_depth4", HCAL_depth4 );
  
  
  // setup writing
  
  //    Long64_t        eventId;
  //    Int_t           lumiId;
  //    Int_t           runId;
  //    Float_t         rho;
  //    Int_t           nVtx;
  //    ECAL_%d   [616] ...
  //    ES_plane1_%d   [616] ...
  //    ES_plane2_%d   [616] ...
  //    HCAL_depth1_%d   [616] ...
  //    HCAL_depth2_%d   [616] ...
  //    HCAL_depth3_%d   [616] ...
  //    HCAL_depth4_%d   [616] ...
  
  newtree->Branch("eventId", &eventId, "eventId/I");
  newtree->Branch("lumiId",  &lumiId,  "lumiId/I");
  newtree->Branch("runId",   &runId,   "runId/I");
  newtree->Branch("rho",     &rho,     "rho/F");
  newtree->Branch("nVtx",    &nVtx,    "nVtx/I");
  
  float all_ECAL;
  float all_ES_plane1;
  float all_ES_plane2;
  float all_HCAL_depth1;
  float all_HCAL_depth2;
  float all_HCAL_depth3;
  float all_HCAL_depth4;
  
  newtree->Branch("ECAL",        &all_ECAL,            "ECAL/F");
  newtree->Branch("ES_plane1",   &all_ES_plane1,       "ES_plane1/F");
  newtree->Branch("ES_plane2",   &all_ES_plane2,       "ES_plane2/F");
  newtree->Branch("HCAL_depth1", &all_HCAL_depth1,     "HCAL_depth1/F");
  newtree->Branch("HCAL_depth2", &all_HCAL_depth2,     "HCAL_depth2/F");
  newtree->Branch("HCAL_depth3", &all_HCAL_depth3,     "HCAL_depth3/F");
  newtree->Branch("HCAL_depth4", &all_HCAL_depth4,     "HCAL_depth4/F");
  
  int entries = oldtree->GetEntries();
  int nxtals = 616;
//   int nxtals = 10;
  
  std::cout << " entries = " << entries << std::endl;
  
  for (int iEntry = 0; iEntry < entries; iEntry++) {
    
    all_ECAL = 0;
    all_ES_plane1 = 0;
    all_ES_plane2 = 0;
    all_HCAL_depth1 = 0;
    all_HCAL_depth2 = 0;
    all_HCAL_depth3 = 0;
    all_HCAL_depth4 = 0;
    
    if ((iEntry%50) == 0) std::cout << " iEntry = " << iEntry << " :: " << entries << std::endl;
    
    oldtree->GetEntry(iEntry);
    
    for (int ixtal=0; ixtal<nxtals; ixtal++) {
      if (ECAL[ixtal] > 0) {
        all_ECAL =          ECAL        [ixtal];     
        all_ES_plane1 =     ES_plane1   [ixtal];
        all_ES_plane2 =     ES_plane2   [ixtal];
        all_HCAL_depth1 =   HCAL_depth1 [ixtal];
        all_HCAL_depth2 =   HCAL_depth2 [ixtal];
        all_HCAL_depth3 =   HCAL_depth3 [ixtal];
        all_HCAL_depth4 =   HCAL_depth4 [ixtal];
        newtree->Fill();    
        if (ES_plane1   [ixtal] >0 ) std::cout << " iEntry = " << iEntry << " :: " << entries << " ES_plane1   [" << ixtal << "] = " << ES_plane1   [ixtal] << std::endl;
        if (ES_plane2   [ixtal] >0 ) std::cout << " iEntry = " << iEntry << " :: " << entries << " ES_plane2   [" << ixtal << "] = " << ES_plane2   [ixtal] << std::endl;
      }
    }     
  }
  
  
  newfile->cd();
  newtree->Write();
  
  
//   for (int i=0; i<nxtals; i++) {
//     TString name = Form ("ES_strip_1_%d", i);
//     dataloader->AddVariable( name.Data(), name.Data(), "GeV", 'F' );
//   }
//   for (int i=0; i<nxtals; i++) {
//     TString name = Form ("ES_strip_2_%d", i);
//     dataloader->AddVariable( name.Data(), name.Data(), "GeV", 'F' );
//   }
//   
//   for (int i=0; i<nxtals; i++) {
//     TString name = Form ("HCAL_layer1_%d", i);
//     dataloader->AddVariable( name.Data(), name.Data(), "GeV", 'F' );
//   }
//   
//   for (int i=0; i<nxtals; i++) {
//     TString name = Form ("HCAL_layer2_%d", i);
//     dataloader->AddVariable( name.Data(), name.Data(), "GeV", 'F' );
//   }
  
  
  
}