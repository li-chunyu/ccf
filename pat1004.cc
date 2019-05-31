#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    map<string, vector<string> > childof;
    for (int i = 0; i < M; ++i) {
        int nchild  = 0;
        char id[20];
        scanf("%s%d", id, &nchild);
        vector<string> childs;
        for (int j = 0; j < nchild; ++j) {
            char child_id[20];
            scanf("%s", child_id);
            childs.push_back(child_id);
        }
        childof[id] = childs;
    }
    bool last_level = false;
    vector<int> nleaves;
    vector<string> level;
    level.push_back("01");
    while (!last_level) {
        vector<string> next_level;
        nleaves.push_back(0);
        for (auto n : level) {
            if (childof.find(n) == childof.end()) {
                nleaves[nleaves.size() - 1] += 1;
            } else {
                for (auto c : childof[n])
                    next_level.push_back(c);
            }
        }
        if (next_level.size() == 0) {
            last_level = true;
        } else {
            level = next_level;
        }
    }
    printf("%d", nleaves[0]);
    for (int i = 1; i < nleaves.size(); ++i) {
        printf(" %d", nleaves[i]);
    }
    printf("\n");
    return 0;
}