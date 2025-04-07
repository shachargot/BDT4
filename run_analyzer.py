import os
import sys
import re
import yaml
from fnmatch import fnmatch
from argparse import ArgumentParser

# Command: 
# python3 run_analyzer.py --filter=[sample]  

if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument('-y', '--yaml', default = 'samples.yml', help = 'File with dataset descriptions')
    parser.add_argument('-f', '--filter', default='*', help = 'Filter samples, POSIX regular expressions allowed')
    parser.add_argument('-o', '--output', default='output/', help = 'Output directory')
    parser.add_argument('-m', '--mode', default='0', help = 'Mode = 0 (Bu) or 10 (Bd)')
    args = parser.parse_args()
    
    input_path = '/eos/cms/store/group/phys_bphys/DiElectronX/'
    output_path = args.output
    mode = int(args.mode) # (MC only, not used currently)
    
    if not os.path.exists(output_path): # Create output directory
        os.makedirs(output_path)

    with open(args.yaml) as f:
        doc = yaml.load(f,Loader=yaml.FullLoader) # Parse YAML file
        for sample, info in doc['samples'].items():
            parts = info['parts'] if 'parts' in info else [None] 
            for part in parts:
                part_num = re.search('part([0-9]+)', part)
                sample_name = sample.replace('%d',str(part_num.group(1))) if part_num is not None else sample

                if not fnmatch(sample_name, args.filter): continue
                
                # outname = "outputTree"
                idx = 0
                
                isMC = info['isMC']
                input_path += info['dataset'].replace('%d',str(part_num.group(1))) + "/" + part \
                                   if part is not None else \
                                      info['dataset'] 

                data_list = os.listdir(input_path)
                # text = re.search('crab_(.+?)/', input_path)  # Extract run ID
                # if text:
                #    run = text.group(1)
                #    outname = run + "_" + outname
                for input in data_list:
                    output_name = "outputTree_" + sample_name
                    if not re.search('\.root', input):  # Skip non-ROOT files
                        continue 
                    text = re.search('([0-9]+)\.root', input)  # Extract file index
                    if text:
                        index = int(text.group(1))
                    else:
                        index = idx
                        idx += 1
                    # if os.path.isfile(output_path + "/" + output_name + "_" + str(index) + ".root"):  # Skip files already in place
                    #    continue
                    print(input_path + input)
                    # if isMC:
                    #    os.system('root -b -q \'src/analyzer_MC_131_triplets.C+("%s", "%s", "%s", %d, %d)\'' % (input_path + input, output_path, output_name, index, mode))
                    # else: 
                    os.system('root -b -q \'src/analyzer_Data_131_triplets.C+("%s", "%s", "%s", %d, %d)\'' % (input_path + input, output_path, output_name, index, mode))
