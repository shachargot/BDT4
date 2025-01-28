#!/bin/bash

for i in {1..999}; do 
	root -b -q "analyzer_Data_131_triplets.C+(\"/eos/cms/store/group/phys_bphys/DiElectronX/sgottlie/BParkingNANO/samesign/ParkingDoubleElectronLowMass0/crab_Run2022G_part0/250105_084529/0000/BParkingNANO_Run3_data_2025Jan05_$i.root\", $i, 0)"
done

