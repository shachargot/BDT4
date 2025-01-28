import os
import sys

# python3 run_analyzer.py [output_path] [output_name] [mode] 

if __name__ == '__main__':
    args = sys.argv
    if len(args) > 1:
        output_path = args[1]
    else:
        output_path = "/eos/cms/store/group/phys_bphys/DiElectronX/sgottlie/BDT4/"
    if len(args) > 2:
        output_name = args[2]
    else:
        output_name = "outputTree"
    if len(args) > 3:  # mode = 0 (B+) or 10 (B0)
        mode = args[3]
    else:
        mode = 0

    file = open("data_paths.txt", "r")
    for path in file:
        if path[0] == '#':
            continue
        data_list = os.listdir(path)
        for input in data_list:
            print(input)
            # os.system(root -b -q analyzer_Data_131_triplets.C+(input, "/eos/cms/store/group/phys_bphys/DiElectronX/sgottlie/BDT4/", 1, 0))
