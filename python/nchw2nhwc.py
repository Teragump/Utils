#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
      created: 2018-09-06
last modified: 2019-09-18
       author: ganjian
"""

import sys
import tensorflow as tf
import numpy as np

def main():
  filepath_in = sys.argv[1]
  filepath_out = sys.argv[2]
  
  x = np.fromfile(filepath_in, dtype=np.float32)
#  print x

  # array -> tensor
  tx = tf.convert_to_tensor(x, dtype = tf.float32)
  tx = tf.reshape(tx, [1, 6, 256, 256])
  outx = tf.transpose(tx, [0, 2, 3, 1])
#  print "----------------"
#  print tx.shape
#  print outx.shape

  # tensor -> array
  sess = tf.InteractiveSession()  # 创建一个新的计算图
  sess.run(tf.global_variables_initializer())
  result = outx.eval()
#  print result

  file_out = open(filepath_out, 'wb')
  result.tofile(file_out)

if __name__ == '__main__':
    main()
