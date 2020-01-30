#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
      created: 2020-01-28
last modified: 2020-01-30
       author: teragump
"""

import sys
import os

def parse():
    prototxt = sys.argv[1]
    print "Start parsing %s" % prototxt

    keyword = "type: "
    layerDict = {}

    for line in open(prototxt, "r"):
        index = line.find(keyword)
        if (index != -1):
            begin = line.find('\"');
            if (line[begin + 1] >= 'A' and line[begin + 1] <= 'Z'):
                end = line.rfind('\"');
                layerName = line[(begin + 1):end]
                if (layerDict.has_key(layerName)):
                    layerDict[layerName] += 1
                else:
                    print "Get a new layer name: %s" % layerName
                    layerDict[layerName] = 1
    
    print "================"
    print "Types and counts of the layers: "
    print layerDict
            
if __name__ == '__main__':
    if(len(sys.argv) != 2):
        print "Usage: python parsePrototxt.py prototxt_path"
    elif(os.path.isfile(sys.argv[1])):
        parse()
    else:
        print "%s does not exist" % sys.argv[1]
