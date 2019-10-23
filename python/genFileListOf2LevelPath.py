import os
# import random

"""
      created: 2019-09-24
last modified: 2019-09-26
       author: ganjian
"""

def generate(dir):
    parents = os.listdir(dir)
    print('****************')
    print('input :',dir)
    print('start...')
    listText = open('../dataset.txt','w')
    # random.shuffle(files)
    for parent in parents:
        path = os.path.abspath(parent)
        files = os.listdir(parent)
        for file in files:
            fileExtension = os.path.splitext(file)
            if fileExtension[1] == '.txt':
                continue
            
            pathname = path + '/' + file + '\n'
            listText.write(pathname)
    listText.close()
    print('done!')
    print('****************')

if __name__ == '__main__':
    generate('.')
