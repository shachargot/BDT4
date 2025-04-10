output_dir=output
# output_dir=/eos/cms/store/group/phys_bphys/DiElectronX/sgottlie/BDT4/test

python3 run_analyzer.py --filter=Run2022G_part* --output=$output_dir

# python3 run_analyzer.py --filter=samesign_Run2022F_part* --output=$output_dir
# python3 run_analyzer.py --filter=samesign_Run2022G_part* --output=$output_dir

# python3 run_analyzer.py --filter=BuToKEE_preEE --output=$output_dir
# python3 run_analyzer.py --filter=BuToKEE_postEE --output=$output_dir

# python3 run_analyzer.py --filter=BdToK0starEE_preEE --output=$output_dir
# python3 run_analyzer.py --filter=BdToK0starEE_postEE --output=$output_dir

# python3 run_analyzer.py --filter=BuToKstarEE_preEE --output=$output_dir
# python3 run_analyzer.py --filter=BuToKstarEE_postEE --output=$output_dir

