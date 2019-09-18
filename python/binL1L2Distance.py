#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
      created: 2018-09-01
last modified: 2019-09-18
       author: ganjian
"""

import numpy as np
import sys

def main():
  file_a = sys.argv[1]
  file_b = sys.argv[2]

  float_array_a = np.fromfile(file_a, dtype=np.float32)
  float_array_b = np.fromfile(file_b, dtype=np.float32)

  diff_abs = float(0)
  diff_sum = float(0)
  diff_square_sum = float(0)
   
  for index in range(len(float_array_a)):
    diff_abs = abs(float_array_a[index] - float_array_b[index])
    diff_sum = diff_sum + diff_abs
    diff_square_sum = diff_square_sum + np.square(diff_abs)
  
  print "L1 Distance: %f" % diff_sum
  l2_distance = np.sqrt(diff_square_sum)
  print "L2 Distance: %f" % l2_distance

if __name__ == '__main__':
    main()
