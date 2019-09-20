#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
      created: 2018-09-20
last modified: 2019-09-18
       author: ganjian
"""

import sys
import os

path = sys.argv[1]
target = sys.argv[2]
filelist=os.listdir(path)
for item in filelist:
  print item

newfile=open(target,'w')
for item in filelist:
  for txt in open(path+item,'r'):
    newfile.write(txt)

newfile.close()
