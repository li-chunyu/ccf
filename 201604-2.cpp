#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void split(char *p, vector<int> &v) {
    v.clear();
    char *tmp = strtok(p, " ");
    while(tmp) {
        v.push_back(atoi(tmp));
        tmp = strtok(NULL, " ");
    }
}


int main() {
    vector<vector<int> > pic;
    vector<vector<int> > block;
    int pos;

    for (int i=0; i<15; ++i) {
        string s;
        vector<int> line;
        getline(cin, s);
        split(const_cast<char*>(s.c_str()), line);
        pic.push_back(line);
    }

    for (int i=0; i<4; ++i) {
        string s;
        vector<int> line;
        getline(cin, s);
        split(const_cast<char*>(s.c_str()), line);
        block.push_back(line);
    }

    cin >> pos;

    
}