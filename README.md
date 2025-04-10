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


# Run BDT4 analyzer: 
Edit `run.sh` with output directory and uncomment desired samples

To add samples, edit `samples.yml`

Then run:
```
./run.sh  
```

Alternatively, can run directly:

```
python3 run_analyzer --filter=[filter] --output=[]
```

Test over a file individually:
```
root -b -q src/analyzer_MC_131_triplets.C+(\"/eos/cms/store/group/phys_bphys/DiElectronX/sgottlie/BParkingNANO/BuToKEE_SoftQCD_TuneCP5_13p6TeV_pythia8-evtgen/crab_BuToKee_v1_postEE/250302_012404/0000/BParkingNANO_Run3_mc_2025Mar02_1.root\", \"output\", \"KEE_MC_1\", 1, 0)
```
Parameters: file path, output path, output name, output index, mode
