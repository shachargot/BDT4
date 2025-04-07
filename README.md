# BDT4 
Install CMSSW
```
cmsrel CMSSW_13_1_0
cd CMSSW_13_1_0/src
cmsenv
```

Install XGBoost 
```
cd ${CMSSW_BASE}/src
git clone --recursive https://github.com/dmlc/xgboost
```

Add repository 
```
cd ${CMSSW_BASE}/src
git clone git@github.com:shachargot/BDT4.git
scram b -j 8
```

## Edit files.txt with data paths to BParkingNANO files. 
Example files:

`/eos/cms/store/group/phys_bphys/DiElectronX/sgottlie/BParkingNANO/samesign/ParkingDoubleElectronLowMass0/crab_Run2022G_part0/250105_084529/0000/` (Same-sign electron data)
`/eos/cms/store/group/phys_bphys/DiElectronX/sgottlie/BParkingNANO/BuToKEE_SoftQCD_TuneCP5_13p6TeV_pythia8-evtgen/crab_BuToKee_v1_postE
E/250302_012404/0000` (BToKEE MC)


## Run BDT4 for data:
```
python3 run_analyzer_data.py [output_path]
```

## Run BDT4 for MC
Mode is 0 for B+ and 10 for B0 (only relevant in MC)
```
python3 run_analyzer_MC.py [output_path] [mode]
```

Test over a file individually:
```
root -b -q src/analyzer_MC_131_triplets.C+(\"/eos/cms/store/group/phys_bphys/DiElectronX/sgottlie/BParkingNANO/BuToKEE_SoftQCD_TuneCP5_13p6TeV_pythia8-evtgen/crab_BuToKee_v1_postEE/250302_012404/0000/BParkingNANO_Run3_mc_2025Mar02_1.root\", \"output\", \"KEE_MC_1\", 1, 0)
```
Parameters: file path, output path, output name, output name index, mode
