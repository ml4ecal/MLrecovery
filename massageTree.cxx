//
// massage the ttree to make it easier for ML
//


void massageTree(TString inputName = "oldtree.root", TString outputName = "newtree.root") {
  
//
//  616 xtals
//

  TFile* oldfile = new TFile (inputName.Data(), "READ");  
  
  TTree* oldtree = (TTree*) oldfile -> Get ("rechitdumper/caloTree");
  
  
  
  TFile* newfile = new TFile (outputName.Data(), "RECREATE");  

  TTree* newtree = new TTree ("mytree", "");
  
  
  //    Long64_t        eventId;
  //    Int_t           lumiId;
  //    Int_t           runId;
  //    Float_t         rho;
  //    Int_t           nVtx;
  //    vector<unsigned int> *ecalRecHit_rawId;
  //    vector<int>     *ecalRecHit_chStatus;
  //    vector<float>   *ecalRecHit_energy;
  //    vector<float>   *ecalRecHit_eta;
  //    vector<float>   *ecalRecHit_phi;
  //    vector<int>     *ecalRecHit_ix;
  //    vector<int>     *ecalRecHit_iy;
  //    vector<int>     *ecalRecHit_iz;
  //    vector<vector<unsigned int> > *matchedHcalRecHit_rawId;
  //    vector<vector<float> > *matchedHcalRecHit_energy;
  //    vector<vector<float> > *matchedHcalRecHit_eta;
  //    vector<vector<float> > *matchedHcalRecHit_phi;
  //    vector<vector<int> > *matchedHcalRecHit_ieta;
  //    vector<vector<int> > *matchedHcalRecHit_iphi;
  //    vector<vector<int> > *matchedHcalRecHit_iz;
  //    vector<vector<int> > *matchedHcalRecHit_depth;
  //    vector<vector<unsigned int> > *matchedESRecHit_rawId;
  //    vector<vector<float> > *matchedESRecHit_energy;
  //    vector<vector<float> > *matchedESRecHit_eta;
  //    vector<vector<float> > *matchedESRecHit_phi;
  //    vector<vector<int> > *matchedESRecHit_ix;
  //    vector<vector<int> > *matchedESRecHit_iy;
  //    vector<vector<int> > *matchedESRecHit_iz;
  //    vector<vector<int> > *matchedESRecHit_strip;
  //    vector<vector<int> > *matchedESRecHit_plane;
  
//   
//   
//   --->
//   
//   

  
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
 
  gInterpreter->GenerateDictionary("vector<vector<float> >", "vector");
  gInterpreter->GenerateDictionary("vector<vector<int> >", "vector");
  
  // setup reading
  
  Long64_t        eventId;
  Int_t           lumiId;
  Int_t           runId;
  Float_t         rho;
  Int_t           nVtx;
  vector<unsigned int> *ecalRecHit_rawId;
  vector<int>     *ecalRecHit_chStatus;
  vector<float>   *ecalRecHit_energy;
  vector<float>   *ecalRecHit_eta;
  vector<float>   *ecalRecHit_phi;
  vector<int>     *ecalRecHit_ix;
  vector<int>     *ecalRecHit_iy;
  vector<int>     *ecalRecHit_iz;
  vector<vector<unsigned int> > *matchedHcalRecHit_rawId;
  vector<vector<float> > *matchedHcalRecHit_energy;
  vector<vector<float> > *matchedHcalRecHit_eta;
  vector<vector<float> > *matchedHcalRecHit_phi;
  vector<vector<int> > *matchedHcalRecHit_ieta;
  vector<vector<int> > *matchedHcalRecHit_iphi;
  vector<vector<int> > *matchedHcalRecHit_iz;
  vector<vector<int> > *matchedHcalRecHit_depth;
  vector<vector<unsigned int> > *matchedESRecHit_rawId;
  vector<vector<float> > *matchedESRecHit_energy;
  vector<vector<float> > *matchedESRecHit_eta;
  vector<vector<float> > *matchedESRecHit_phi;
  vector<vector<int> > *matchedESRecHit_ix;
  vector<vector<int> > *matchedESRecHit_iy;
  vector<vector<int> > *matchedESRecHit_iz;
  vector<vector<int> > *matchedESRecHit_strip;
  vector<vector<int> > *matchedESRecHit_plane;
  
  TBranch        *b_eventId;   //!
  TBranch        *b_lumiId;   //!
  TBranch        *b_runId;   //!
  TBranch        *b_rho;   //!
  TBranch        *b_nVtx;   //!
  TBranch        *b_ecalRecHit_rawId;   //!
  TBranch        *b_ecalRecHit_chStatus;   //!
  TBranch        *b_ecalRecHit_energy;   //!
  TBranch        *b_ecalRecHit_eta;   //!
  TBranch        *b_ecalRecHit_phi;   //!
  TBranch        *b_ecalRecHit_ix;   //!
  TBranch        *b_ecalRecHit_iy;   //!
  TBranch        *b_ecalRecHit_iz;   //!
  TBranch        *b_matchedHcalRecHit_rawId;   //!
  TBranch        *b_matchedHcalRecHit_energy;   //!
  TBranch        *b_matchedHcalRecHit_eta;   //!
  TBranch        *b_matchedHcalRecHit_phi;   //!
  TBranch        *b_matchedHcalRecHit_ieta;   //!
  TBranch        *b_matchedHcalRecHit_iphi;   //!
  TBranch        *b_matchedHcalRecHit_iz;   //!
  TBranch        *b_matchedHcalRecHit_depth;   //!
  TBranch        *b_matchedESRecHit_rawId;   //!
  TBranch        *b_matchedESRecHit_energy;   //!
  TBranch        *b_matchedESRecHit_eta;   //!
  TBranch        *b_matchedESRecHit_phi;   //!
  TBranch        *b_matchedESRecHit_ix;   //!
  TBranch        *b_matchedESRecHit_iy;   //!
  TBranch        *b_matchedESRecHit_iz;   //!
  TBranch        *b_matchedESRecHit_strip;   //!
  TBranch        *b_matchedESRecHit_plane;   //!
  
  ecalRecHit_rawId = 0;
  ecalRecHit_chStatus = 0;
  ecalRecHit_energy = 0;
  ecalRecHit_eta = 0;
  ecalRecHit_phi = 0;
  ecalRecHit_ix = 0;
  ecalRecHit_iy = 0;
  ecalRecHit_iz = 0;
  matchedHcalRecHit_rawId = 0;
  matchedHcalRecHit_energy = 0;
  matchedHcalRecHit_eta = 0;
  matchedHcalRecHit_phi = 0;
  matchedHcalRecHit_ieta = 0;
  matchedHcalRecHit_iphi = 0;
  matchedHcalRecHit_iz = 0;
  matchedHcalRecHit_depth = 0;
  matchedESRecHit_rawId = 0;
  matchedESRecHit_energy = 0;
  matchedESRecHit_eta = 0;
  matchedESRecHit_phi = 0;
  matchedESRecHit_ix = 0;
  matchedESRecHit_iy = 0;
  matchedESRecHit_iz = 0;
  matchedESRecHit_strip = 0;
  matchedESRecHit_plane = 0;
  
  std::cout << " oldtree = " << oldtree << std::endl;
  
  oldtree->SetBranchAddress("eventId", &eventId, &b_eventId);
  oldtree->SetBranchAddress("lumiId", &lumiId, &b_lumiId);
  oldtree->SetBranchAddress("runId", &runId, &b_runId);
  oldtree->SetBranchAddress("rho", &rho, &b_rho);
  oldtree->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
  oldtree->SetBranchAddress("ecalRecHit_rawId", &ecalRecHit_rawId, &b_ecalRecHit_rawId);
  oldtree->SetBranchAddress("ecalRecHit_chStatus", &ecalRecHit_chStatus, &b_ecalRecHit_chStatus);
  oldtree->SetBranchAddress("ecalRecHit_energy", &ecalRecHit_energy, &b_ecalRecHit_energy);
  oldtree->SetBranchAddress("ecalRecHit_eta", &ecalRecHit_eta, &b_ecalRecHit_eta);
  oldtree->SetBranchAddress("ecalRecHit_phi", &ecalRecHit_phi, &b_ecalRecHit_phi);
  oldtree->SetBranchAddress("ecalRecHit_ix", &ecalRecHit_ix, &b_ecalRecHit_ix);
  oldtree->SetBranchAddress("ecalRecHit_iy", &ecalRecHit_iy, &b_ecalRecHit_iy);
  oldtree->SetBranchAddress("ecalRecHit_iz", &ecalRecHit_iz, &b_ecalRecHit_iz);
  oldtree->SetBranchAddress("matchedHcalRecHit_rawId", &matchedHcalRecHit_rawId, &b_matchedHcalRecHit_rawId);
  oldtree->SetBranchAddress("matchedHcalRecHit_energy", &matchedHcalRecHit_energy, &b_matchedHcalRecHit_energy);
  oldtree->SetBranchAddress("matchedHcalRecHit_eta", &matchedHcalRecHit_eta, &b_matchedHcalRecHit_eta);
  oldtree->SetBranchAddress("matchedHcalRecHit_phi", &matchedHcalRecHit_phi, &b_matchedHcalRecHit_phi);
  oldtree->SetBranchAddress("matchedHcalRecHit_ieta", &matchedHcalRecHit_ieta, &b_matchedHcalRecHit_ieta);
  oldtree->SetBranchAddress("matchedHcalRecHit_iphi", &matchedHcalRecHit_iphi, &b_matchedHcalRecHit_iphi);
  oldtree->SetBranchAddress("matchedHcalRecHit_iz", &matchedHcalRecHit_iz, &b_matchedHcalRecHit_iz);
  oldtree->SetBranchAddress("matchedHcalRecHit_depth", &matchedHcalRecHit_depth, &b_matchedHcalRecHit_depth);
  oldtree->SetBranchAddress("matchedESRecHit_rawId", &matchedESRecHit_rawId, &b_matchedESRecHit_rawId);
  oldtree->SetBranchAddress("matchedESRecHit_energy", &matchedESRecHit_energy, &b_matchedESRecHit_energy);
  oldtree->SetBranchAddress("matchedESRecHit_eta", &matchedESRecHit_eta, &b_matchedESRecHit_eta);
  oldtree->SetBranchAddress("matchedESRecHit_phi", &matchedESRecHit_phi, &b_matchedESRecHit_phi);
  oldtree->SetBranchAddress("matchedESRecHit_ix", &matchedESRecHit_ix, &b_matchedESRecHit_ix);
  oldtree->SetBranchAddress("matchedESRecHit_iy", &matchedESRecHit_iy, &b_matchedESRecHit_iy);
  oldtree->SetBranchAddress("matchedESRecHit_iz", &matchedESRecHit_iz, &b_matchedESRecHit_iz);
  oldtree->SetBranchAddress("matchedESRecHit_strip", &matchedESRecHit_strip, &b_matchedESRecHit_strip);
  oldtree->SetBranchAddress("matchedESRecHit_plane", &matchedESRecHit_plane, &b_matchedESRecHit_plane);
  
  
  
  
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
  
  float ECAL[616];
  float ES_plane1[616];
  float ES_plane2[616];
  float HCAL_depth1[616];
  float HCAL_depth2[616];
  float HCAL_depth3[616];
  float HCAL_depth4[616];
  
  newtree->Branch("ECAL",        ECAL,            "ECAL[616]/F");
  newtree->Branch("ES_plane1",   ES_plane1,       "ES_plane1[616]/F");
  newtree->Branch("ES_plane2",   ES_plane2,       "ES_plane2[616]/F");
  newtree->Branch("HCAL_depth1", HCAL_depth1,     "HCAL_depth1[616]/F");
  newtree->Branch("HCAL_depth2", HCAL_depth2,     "HCAL_depth2[616]/F");
  newtree->Branch("HCAL_depth3", HCAL_depth3,     "HCAL_depth3[616]/F");
  newtree->Branch("HCAL_depth4", HCAL_depth4,     "HCAL_depth4[616]/F");
  
  std::vector<int> rawidMasked = {
    872432455,872432456,872432457,872432458,872432459,872432583,872432584,872432585,872432586,872432587,872432711,872432712,872432713,872432714,872432715,
    872432839,872432840,872432841,872432842,872432843,872432967,872432968,872432969,872432970,872432971,872433095,872433096,872433097,872433098,872433099,
    872433100,872433101,872433102,872433103,872433104,872433223,872433224,872433225,872433226,872433227,872433228,872433229,872433230,872433231,872433232,
    872433351,872433352,872433353,872433354,872433355,872433356,872433357,872433358,872433359,872433360,872433479,872433480,872433481,872433482,872433483,
    872433484,872433485,872433486,872433487,872433488,872433489,872433490,872433491,872433492,872433493,872433607,872433608,872433609,872433610,872433611,
    872433612,872433613,872433614,872433615,872433616,872433617,872433618,872433619,872433620,872433621,872433735,872433736,872433737,872433738,872433739,
    872433740,872433741,872433742,872433743,872433744,872433745,872433746,872433747,872433748,872433749,872433750,872433751,872433863,872433864,872433865,
    872433866,872433867,872433868,872433869,872433870,872433871,872433872,872433873,872433874,872433875,872433876,872433877,872433878,872433879,872433991,
    872433992,872433993,872433994,872433995,872433996,872433997,872433998,872433999,872434000,872434001,872434002,872434003,872434004,872434005,872434006,
    872434007,872434119,872434120,872434121,872434122,872434123,872434124,872434125,872434126,872434127,872434128,872434129,872434130,872434131,872434132,
    872434133,872434134,872434135,872434247,872434248,872434249,872434250,872434251,872434252,872434253,872434254,872434255,872434256,872434257,872434258,
    872434259,872434260,872434261,872434262,872434263,872434380,872434381,872434382,872434383,872434384,872434385,872434386,872434387,872434388,872434389,
    872434390,872434391,872434392,872434393,872434394,872434395,872434396,872434508,872434509,872434510,872434511,872434512,872434513,872434514,872434515,
    872434516,872434517,872434518,872434519,872434520,872434521,872434522,872434523,872434524,872434636,872434637,872434638,872434639,872434640,872434641,
    872434642,872434643,872434644,872434645,872434646,872434647,872434648,872434649,872434650,872434651,872434652,872434764,872434765,872434766,872434767,
    872434768,872434769,872434770,872434771,872434772,872434773,872434774,872434775,872434776,872434777,872434778,872434779,872434780,872434892,872434893,
    872434894,872434895,872434896,872434897,872434898,872434899,872434900,872434901,872434902,872434903,872434904,872434905,872434906,872434907,872434908,
    872435020,872435021,872435022,872435023,872435024,872435025,872435026,872435027,872435028,872435029,872435030,872435031,872435032,872435033,872435034,
    872435035,872435036,872435037,872435038,872435039,872435148,872435149,872435150,872435151,872435152,872435153,872435154,872435155,872435156,872435157,
    872435158,872435159,872435160,872435161,872435162,872435163,872435164,872435165,872435166,872435167,872435276,872435277,872435278,872435279,872435280,
    872435281,872435282,872435283,872435284,872435285,872435286,872435287,872435288,872435289,872435290,872435291,872435292,872435293,872435294,872435295,
    872435404,872435405,872435406,872435407,872435408,872435409,872435410,872435411,872435412,872435413,872435414,872435415,872435416,872435417,872435418,
    872435419,872435420,872435421,872435422,872435423,872435532,872435533,872435534,872435535,872435536,872435537,872435538,872435539,872435540,872435541,
    872435542,872435543,872435544,872435545,872435546,872435547,872435548,872435549,872435550,872435551,872435655,872435656,872435657,872435658,872435659,
    872435660,872435661,872435662,872435663,872435664,872435665,872435666,872435667,872435668,872435669,872435670,872435671,872435672,872435673,872435674,
    872435675,872435676,872435677,872435678,872435679,872435783,872435784,872435785,872435786,872435787,872435788,872435789,872435790,872435791,872435792,
    872435793,872435794,872435795,872435796,872435797,872435798,872435799,872435800,872435801,872435802,872435803,872435804,872435805,872435806,872435807,
    872435911,872435912,872435913,872435914,872435915,872435916,872435917,872435918,872435919,872435920,872435921,872435922,872435923,872435924,872435925,
    872435926,872435927,872435928,872435929,872435930,872435931,872435932,872435933,872435934,872435935,872436039,872436040,872436041,872436042,872436043,
    872436044,872436045,872436046,872436047,872436048,872436049,872436050,872436051,872436052,872436053,872436054,872436055,872436056,872436057,872436058,
    872436059,872436060,872436061,872436062,872436063,872436167,872436168,872436169,872436170,872436171,872436172,872436173,872436174,872436175,872436176,
    872436177,872436178,872436179,872436180,872436181,872436182,872436183,872436184,872436185,872436186,872436187,872436188,872436189,872436190,872436191,
    872436295,872436296,872436297,872436298,872436299,872436300,872436301,872436302,872436303,872436304,872436305,872436306,872436307,872436308,872436309,
    872436310,872436311,872436312,872436313,872436314,872436315,872436316,872436317,872436318,872436319,872436320,872436321,872436423,872436424,872436425,
    872436426,872436427,872436428,872436429,872436430,872436431,872436432,872436433,872436434,872436435,872436436,872436437,872436438,872436439,872436440,
    872436441,872436442,872436443,872436444,872436445,872436446,872436447,872436448,872436449,872436551,872436552,872436553,872436554,872436555,872436556,
    872436557,872436558,872436559,872436560,872436561,872436562,872436563,872436564,872436565,872436566,872436567,872436568,872436569,872436570,872436571,
    872436572,872436573,872436574,872436575,872436576,872436577,872436679,872436680,872436681,872436682,872436683,872436684,872436685,872436686,872436687,
    872436688,872436689,872436690,872436691,872436692,872436693,872436694,872436695,872436696,872436697,872436698,872436699,872436700,872436701,872436702,
    872436703,872436704,872436705,872436807,872436808,872436809,872436810,872436811,872436812,872436813,872436814,872436815,872436816,872436817,872436818,
    872436819,872436820,872436821,872436822,872436823,872436824,872436825,872436826,872436827,872436828,872436829,872436830,872436831,872436832,872436833,
    872436922};
    
  
  int entries = oldtree->GetEntries();
  int nxtals = 616;
  
  std::cout << " entries = " << entries << std::endl;
  
  for (int iEntry = 0; iEntry < entries; iEntry++) {
  
    for (int ixtal=0; ixtal<nxtals; ixtal++) {
      ECAL[ixtal] = 0;
      ES_plane1[ixtal] = 0;
      ES_plane2[ixtal] = 0;
      HCAL_depth1[ixtal] = 0;
      HCAL_depth2[ixtal] = 0;
      HCAL_depth3[ixtal] = 0;
      HCAL_depth4[ixtal] = 0;
    }
    
    if ((iEntry%5) == 0) std::cout << " iEntry = " << iEntry << " :: " << entries << std::endl;
    
    oldtree->GetEntry(iEntry);
    
    int activeXtals = ecalRecHit_rawId->size();
    for (int i=0; i<activeXtals; i++) {
      auto valuefound = std::find(rawidMasked.begin(), rawidMasked.end(), ecalRecHit_rawId->at(i));
      if(valuefound != rawidMasked.end()) {
        int xtalIndex = (int) (valuefound - rawidMasked.begin());
        ECAL       [xtalIndex] = ecalRecHit_energy->at(i);
        
//         std::cout << " matchedHcalRecHit_energy = " << matchedHcalRecHit_energy << std::endl;
        for (int ihcal = 0; ihcal < matchedHcalRecHit_energy->at(i).size(); ihcal++) {
          if (matchedHcalRecHit_depth->at(i).at(ihcal) == 1) HCAL_depth1[xtalIndex] += matchedHcalRecHit_energy->at(i).at(ihcal);
          if (matchedHcalRecHit_depth->at(i).at(ihcal) == 2) HCAL_depth2[xtalIndex] += matchedHcalRecHit_energy->at(i).at(ihcal);
          if (matchedHcalRecHit_depth->at(i).at(ihcal) == 3) HCAL_depth3[xtalIndex] += matchedHcalRecHit_energy->at(i).at(ihcal);
          if (matchedHcalRecHit_depth->at(i).at(ihcal) == 4) HCAL_depth4[xtalIndex] += matchedHcalRecHit_energy->at(i).at(ihcal);
        }
        
        for (int ies = 0; ies < matchedESRecHit_energy->at(i).size(); ies++) {
          if (matchedESRecHit_plane->at(i).at(ies) == 1) ES_plane1[xtalIndex] += matchedESRecHit_energy->at(i).at(ies);
          if (matchedESRecHit_plane->at(i).at(ies) == 2) ES_plane2[xtalIndex] += matchedESRecHit_energy->at(i).at(ies);
//           std::cout << " matchedESRecHit_plane->at(i).at(ies) = " << matchedESRecHit_plane->at(i).at(ies) << std::endl;
        }
        
      }
    }
    
    newtree->Fill();    
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