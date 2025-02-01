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

Edit files.txt with data paths to BParkingNANO files. Example files (samesign):
`/eos/cms/store/group/phys_bphys/DiElectronX/sgottlie/BParkingNANO/samesign/ParkingDoubleElectronLowMass0/crab_Run2022G_part0/250105_084529/0000/`

Run BDT4 for data
```
python3 run_analyzer_data.py [output_path] [mode]
```

Mode is 0 for B+ and 10 for B0 (only relevant in MC)
