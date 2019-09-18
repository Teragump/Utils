#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
      created: 2018-09-01
last modified: 2019-09-18
       author: ganjian
"""

import sys
import struct
import re

def main():
  filepath_in = sys.argv[1]
  filepath_out = sys.argv[2]

  file_in = open(filepath_in, 'r')
  file_out = open(filepath_out, 'wb')
  
  lines = file_in.readlines()  
  for line in lines:
#    curLine = line.split(' ')
    curLine = re.split(r"\s|, |\t", line)
    for i in range(len(curLine)):
      if len(curLine[i]) == 0:
        continue
      parsedata = struct.pack("f", float(curLine[i]))
      file_out.write(parsedata)

  file_out.close()
  file_in.close()

if __name__ == '__main__':
    main()
