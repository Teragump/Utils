#!/bin/bash
# -*- coding: utf-8 -*-

#       created: 2019-09-26
# last modified: 2019-10-22
#        author: ganjian

images=`cat ./images.txt`
#jpgBatchSize=`wc -l ./images.txt`

for image in $images
do
  #echo "converting $image"
  filename=${image%.*}
  yuvSuffix=".yuv"
  yuv=$filename$yuvSuffix

  echo "generating $yuv"
  `ffmpeg -i $image -s 960:540 -pix_fmt yuv420p $yuv`
done
