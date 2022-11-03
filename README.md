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

    r99t train.cxx
    
    
    r99t createExample.cxx
    
    r99t trainExample.cxx\(\"MLP\",\"testout.root\"\)
    
    
    
    