
//        created: 2021-06-29
//  last modified: 2021-06-29
//         author: chienkan

// Refer to: https://www.cnblogs.com/silentNight/p/5398788.html

#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>   // /usr/include/dirent.h
#include<climits>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int getAbsoluteFilePaths(string directory, vector<string>& filesAbsolutePath) //参数1[in]要变量的目录  参数2[out]存储文件名
{
    DIR* dir = opendir(directory.c_str()); //打开目录   DIR-->类似目录句柄的东西
    if ( dir == NULL )
    {
        cout<<directory<<" is not a directory or not exist!"<<endl;
        return -1;
    }

    struct dirent* d_ent = NULL;       //dirent-->会存储文件的各种属性
    char fullpath[128] = {0};
    char dot[3] = ".";                //linux每个下面都有一个 .  和 ..  要把这两个都去掉
    char dotdot[6] = "..";

    while ( (d_ent = readdir(dir)) != NULL )    //一行一行的读目录下的东西,这个东西的属性放到dirent的变量中
    {
        if ( (strcmp(d_ent->d_name, dot) != 0)
              && (strcmp(d_ent->d_name, dotdot) != 0) )   //忽略 . 和 ..
        {
            if ( d_ent->d_type == DT_DIR ) //d_type可以看到当前的东西的类型,DT_DIR代表当前都到的是目录,在usr/include/dirent.h中定义的
            {

                string newDirectory = directory + string("/") + string(d_ent->d_name); //d_name中存储了子目录的名字
                if( directory[directory.length()-1] == '/')
                {
                    newDirectory = directory + string(d_ent->d_name);
                }

                if ( -1 == getAbsoluteFilePaths(newDirectory, filesAbsolutePath) )  //递归子目录
                {
                    return -1;
                }
            }
            else   //如果不是目录
            {
                string absolutePath = directory + string("/") + string(d_ent->d_name);  //构建绝对路径
                if( directory[directory.length()-1] == '/')  //如果传入的目录最后是/--> 例如a/b/  那么后面直接链接文件名
                {
                    absolutePath = directory + string(d_ent->d_name); // /a/b/1.txt
                }
                filesAbsolutePath.push_back(absolutePath);
            }
        }
    }

    closedir(dir);
    return 0;
}

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << " dir_path" << std::endl;
        return -1;
    }
    char head[1024];
    if(!realpath(argv[1], head)){
        std::cout << "the file " << argv[1] << " is not exist\n";
        return -1;
    }

    std::vector<string> filepaths;
    if(getAbsoluteFilePaths(head, filepaths)) {
        std::cout << "getAbsoluteFilePaths failed" << std::endl;
        return -1;
    }

    for (auto filepath : filepaths) {
        std::cout << filepath << std::endl;
    }
    return 0;
}
