# MLrecovery

ML for ECAL recovery


How to run
----

Download 

    https://twiki.cern.ch/twiki/pub/CMS/ECALTriggerOperation/EcalTPGParam.root


Download the notebook on your eos.

Go to

    https://swan.cern.ch/
    
and load the notebook




Local
----

where:

    /home/amassiro/Cern/Code/ECAL/MLrecovery

train:

    r99t massageTree.cxx\(\"output_5.root\",\"newfile.root\"\)

    r99t -q massageTree.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/bmarzocc/ECAL_Recovery_2022/TEST/EGamma_Run2022D-ZElectron-PromptReco-v2_RAW-RECO/output_1.root\",\"/tmp/amassiro/newfile1.root\"\)
    r99t -q massageTree.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/bmarzocc/ECAL_Recovery_2022/TEST/EGamma_Run2022D-ZElectron-PromptReco-v2_RAW-RECO/output_2.root\",\"/tmp/amassiro/newfile2.root\"\)
    r99t -q massageTree.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/bmarzocc/ECAL_Recovery_2022/TEST/EGamma_Run2022D-ZElectron-PromptReco-v2_RAW-RECO/output_3.root\",\"/tmp/amassiro/newfile3.root\"\)
    r99t -q massageTree.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/bmarzocc/ECAL_Recovery_2022/TEST/EGamma_Run2022D-ZElectron-PromptReco-v2_RAW-RECO/output_4.root\",\"/tmp/amassiro/newfile4.root\"\)
    r99t -q massageTree.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/bmarzocc/ECAL_Recovery_2022/TEST/EGamma_Run2022D-ZElectron-PromptReco-v2_RAW-RECO/output_5.root\",\"/tmp/amassiro/newfile5.root\"\)
    
    r99t -q massageTree.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/bmarzocc/ECAL_Recovery_2022/TEST/JetMET_Run2022D-JetHTJetPlusHOFilter-PromptReco-v2_RAW-RECO/output_1.root\",\"/tmp/amassiro/jetmetnewfile1.root\"\)
    r99t -q massageTree.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/bmarzocc/ECAL_Recovery_2022/TEST/JetMET_Run2022D-JetHTJetPlusHOFilter-PromptReco-v2_RAW-RECO/output_2.root\",\"/tmp/amassiro/jetmetnewfile2.root\"\)
    r99t -q massageTree.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/bmarzocc/ECAL_Recovery_2022/TEST/JetMET_Run2022D-JetHTJetPlusHOFilter-PromptReco-v2_RAW-RECO/output_3.root\",\"/tmp/amassiro/jetmetnewfile3.root\"\)
    r99t -q massageTree.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/bmarzocc/ECAL_Recovery_2022/TEST/JetMET_Run2022D-JetHTJetPlusHOFilter-PromptReco-v2_RAW-RECO/output_4.root\",\"/tmp/amassiro/jetmetnewfile4.root\"\)
    r99t -q massageTree.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/bmarzocc/ECAL_Recovery_2022/TEST/JetMET_Run2022D-JetHTJetPlusHOFilter-PromptReco-v2_RAW-RECO/output_5.root\",\"/tmp/amassiro/jetmetnewfile5.root\"\)

    
    r99t train.cxx\(\"MLP\",\"testout.root\"\)
    r99t train.cxx
    
    
    r99t createExample.cxx
    
    r99t trainExample.cxx\(\"MLP\",\"testout.root\"\)
    r99t trainExample.cxx\(\"BDTG\",\"testout.root\"\) --> no
    
    
    r99t superMassageTree.cxx\(\"added.root\",\"addedmerged.root\"\)
    r99t superMassageTree.cxx\(\"added.root\",\"/media/amassiro/ExWindows/DataCERN/addedmerged.root\"\)

    r99t trainSimple.cxx\(\"MLP\",\"testoutmerged.root\"\)
    r99t trainSimple.cxx\(\"BDT\",\"testoutmerged.root\"\)
    r99t trainSimple.cxx\(\"LD\",\"testoutmerged.root\"\)

    r99t trainSimple.cxx\(\"BDTG\",\"testoutmerged.root\"\)
    
    
    
    

    
Prepare:

    /eos/home-a/amassiro/SWAN_projects/MLrecovery

    ls -alrth /eos/cms/store/group/dpg_ecal/alca_ecalcalib/bmarzocc/ECAL_Recovery_2022/EGamma_Run2022D-ZElectron-PromptReco-v2_RechitDumper/ | awk '{print $9}' > list.txt
    
    r99t -q massageTree.cxx\(\"/eos/cms/store/group/dpg_ecal/alca_ecalcalib/bmarzocc/ECAL_Recovery_2022/EGamma_Run2022D-ZElectron-PromptReco-v2_RechitDumper/
    
    
Draw:

    r99t addedmerged.root
    mytree->Draw("ES_plane1/ECAL:ECAL >> h\(100, 0, 100, 1000, 0, 0.01\)", "ECAL>1", "colz")
    mytree->Draw("ixECAL:iyECAL", "ECAL>1", "colz")
    
    
    
    
    
    
    