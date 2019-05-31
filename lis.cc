/*
 * Longest Increasing Sequence.
 * page 432
*/
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "ojutils.h" // split

using namespace std;

int main() {
    vector<int> seq;
    string s;
    getline(cin, s);
    split(const_cast<char*>(s.c_str()), seq);
    if (seq.size() == 0) {
        printf("%d\n", 0);
        return 0;
    }
    vector<int> dp(seq.size(), 1);

    for (int i = 1; i < seq.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (seq[i] >= seq[j]) {
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
    }

    int ret = 0;
    for (auto i : dp) {
        ret = max(i, ret);
    }
    printf("%d\n", ret);
    return 0;
}