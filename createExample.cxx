{
  
  TFile* test = new TFile ("testinput.root", "RECREATE");
  
  int nevents = 10000;
   
  int           Category;
  float         var1;
  float         var2;
  float         var3;
  float         tar1;
  float         tar2;
  float         tar3;
   
  TTree *tree = new TTree("tree","test tree");
  tree->Branch("Category",&Category,"Category/I");
  tree->Branch("var1",&var1,"var1/F");
  tree->Branch("var2",&var2,"var2/F");
  tree->Branch("var3",&var3,"var3/F");
  tree->Branch("tar1",&tar1,"tar1/F");
  tree->Branch("tar2",&tar2,"tar2/F");
  tree->Branch("tar3",&tar3,"tar3/F");
  
  for (int i=0; i<nevents; i++) {
    var1 =  gRandom->Gaus(0,1);
    var2 =  gRandom->Gaus(0,2);
    var3 =  gRandom->Gaus(0,3);
    
    tar1 = var1 + var2 + gRandom->Gaus(0,0.01);
    tar2 = var2 + var3 + gRandom->Gaus(0,0.01);
    tar3 = var1 * var2 + var3 + gRandom->Gaus(0,0.01);
  
    tree->Fill();
  }
  
  tree->Write();
  
  
}