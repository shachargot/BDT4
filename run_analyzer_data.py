import os
import sys
import re

# Command: 
# python3 run_analyzer.py [output_path] [mode] 

if __name__ == '__main__':
    args = sys.argv
    if len(args) > 1:
        output_path = str(args[1])
    else:
        output_path = "output/"
    if len(args) > 2:  # mode = 0 (B+), 10 (B0)
        mode = int(args[2])
    else:
        mode = 0

    if not os.path.exists(output_path):
        os.makedirs(output_path)

    file = open("files.txt", "r")
    for line in file:
        outname = "outputTree"
        idx = 0
        if line[0] == '#':
            continue
        path = line.replace("\n", "")
        data_list = os.listdir(path)
        text = re.search('crab_(.+?)/', path)
        if text:
            run = text.group(1)
            outname = run + "_" + outname
        for input in data_list:
            output_name = outname
            if not re.search('\.root', input):
                continue 
            text = re.search("([0-9]+)\.root", input)
            if text:
                index = int(text.group(1))
            else:
                index = idx
                idx += 1
            print(path + input)
            os.system('root -b -q \'src/analyzer_Data_131_triplets.C+("%s", "%s", "%s", %d, %d)\'' % (path + input, output_path, output_name, index, mode))
