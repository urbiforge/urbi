#! /usr/bin/env python3

""" Embed files in a C++ header

    First argument is output file
    Second argument is base path
    Remaining arguments can be remain_path or base_path:remain_path.
    The second form overrides default base path

    Creates a unordered_map<string,string> 'embeded_files'
    with key remain_path and value the content of the file
"""
import sys
import os
output = sys.argv[1]
base_path = sys.argv[2]
inputs = sys.argv[3:]


with open(output, 'w') as out:
    out.write("""
#include <string>
#include <unordered_map>


std::unordered_map<std::string, std::string> embeded_files = {
""")
    for f in inputs:
        bpart = base_path
        fpart = f
        if f.index(':')!=-1:
            fb = f.split(':')
            if len(fb) == 3:
                bpart = fb[0] + ':' + fb[1]
                fpart = fb[2]
            else:
                bpart = fb[0]
                fpart = fb[1]
        with open(os.path.join(bpart, fpart), 'r') as inp:
            data = inp.read()
            vals = ','.join(map(lambda x: str(ord(x)), data))
            out.write('{"' + fpart + '", {' + vals + '}},\n')
    out.write('};')
