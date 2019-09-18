#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
      created: 2019-04-17
last modified: 2019-09-18
       author: ganjian
"""

import Image
from scipy import misc
import sys 
import string

def nhwc(im, outFile):
  count = 0
  with open(outFile, 'w') as f:
    for h in range(0, height):
      for w in range(0, width):
        pixel = im.getpixel((w, h)) 
        for i in range(0, 3):
          f.write(str(pixel[i]))
          f.write(" ")
          count = count + 1
      f.write("\n")
  print "total %d" % count

def nchw(im, outFile):
  count = 0
  im = im.transpose(2, 0, 1)
  with open(outFile, 'w') as f:
    for c in range(0, 3):
      for h in range(0, height):
        for w in range(0, width):
          pixel = im[c][h][w] 
          f.write(str(pixel))
          f.write(" ")
          count = count + 1
      f.write("\n")
  print "total %d" % count

if __name__ == '__main__':
  outFile = sys.argv[2]
  
  width = string.atoi(sys.argv[3])
  height = string.atoi(sys.argv[4])
  
#  im = Image.open(sys.argv[1])
  im = misc.imread(sys.argv[1])
  im2 = misc.imresize(im, (width, height))
  #width = im2.size[0]
  #height = im2.size[1]
  #print "/* width:%d */"%(width)
  #print "/* height:%d */"%(height)

#  nhwc(im2, outFile)

#  im2 = im2.tranpose(2, 0, 1) 
  nchw(im2, outFile)

