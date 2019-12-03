//        created: 2019-12-03
//  last modified: 2019-12-03
//         author: Teragump

#include <unistd.h>
#include <sys/syscall.h>

#include <climits>
#include <string>
#include <fstream>
#include <iostream>

pid_t gettid() { return syscall(SYS_gettid); }

// get max threads from /proc/$tid/limits
int getMaxThreads()
{
  const std::string keyWord = "Max processes";
  const std::string noLimitsWord = "unlimited";

  std::string tidAscii = std::to_string(gettid());
  std::string limitsFile = std::string("/proc/") + tidAscii + std::string("/limits");
  std::ifstream fLimits(limitsFile.c_str());
  int maxThreads = 0;

  if(fLimits.good()) {
      std::string line;
      while(getline(fLimits, line)) {
          std::string::size_type pos = line.find(keyWord);
          if(line.npos == pos)
              continue;
          else {
              pos += keyWord.length();
              for (;isblank(line[pos]);pos++) {}
              std::string::size_type curPos = pos;
              if (isdigit(line[pos])) {
                  for(;isdigit(line[pos]);pos++) {}
                  std::string getMax = line.substr(curPos, pos - curPos);
                  maxThreads = std::stoi(getMax);
              } else if (isalpha(line[pos])) {
                  for(;isalpha(line[pos]);pos++) {}
                  std::string getMax = line.substr(curPos, pos - curPos);
                  if (noLimitsWord == getMax) {
                      maxThreads = INT_MAX;
                  } else {
                      std::cerr << "Get max num of threads error" << std::endl;
                      return -1;
                  }
              } else {
                  std::cerr << "Get max num of threads error" << std::endl;
                  return -1;
              }
              break;
          }
      }
  } else {
      std::cerr << "open " << limitsFile.c_str() << " failed" << std::endl;
      return -1;
  }

  return maxThreads;
}

int main(void)
{
    std::cout << "the max num of threads: " << getMaxThreads() << std::endl;
    return 0;
}
