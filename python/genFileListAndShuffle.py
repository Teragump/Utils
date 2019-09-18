import os
import random

"""
      created: 2018-09-01
last modified: 2019-09-18
       author: ganjian
"""

def generate(dir):
    files = os.listdir(dir)
    print('****************')
    print('input :',dir)
    print('start...')
    listText = open('dataset.txt','w')
    random.shuffle(files)  #shuffle list
    for file in files:
        fileType = os.path.split(file)
        if fileType[1] == '.txt':
            continue
        name = file + '\n'
        listText.write(name)
    listText.close()
    print('done!')
    print('****************')

if __name__ == '__main__':
    generate('test_data/canon/')
