#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
      created: 2018-08-27
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

  diff = float(0)
  max_diff = float(0)
  big_diff_cnt = int(0)
  very_big_diff_cnt = int(0)
   
  for index in range(len(float_array_a)):
    diff = abs(float_array_a[index] - float_array_b[index])
    if max_diff < diff:
      max_diff = diff
    if diff > 1e-3:
      big_diff_cnt = big_diff_cnt + 1
    if diff > 1e-1:
#      print float_array_a[index], float_array_b[index]
      very_big_diff_cnt = very_big_diff_cnt + 1

  print "max diff: %f" % max_diff
  print "big_diff_cnt (>1e-3) = %d" % big_diff_cnt
  print "very_big_diff_cnt (>1e-1) = %d" % very_big_diff_cnt

if __name__ == '__main__':
    main()
