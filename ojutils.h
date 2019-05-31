#include <cstring>
#include <cstdlib>
#include <vector>

#ifndef H_OJUTILS
#define H_OJUTILS

void split(char* p, std::vector<int>& v) {
    char* tmp = std::strtok(p, " ");
    while (tmp) {
        v.push_back(atoi(tmp));
        tmp = std::strtok(NULL, " ");
    }
}

#endif