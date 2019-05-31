/*
 * author: lichunyu
 * dp problem
 * page: 429 
 */
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

vector<int> seq;
vector<int> dp;

void split(char* p, vector<int>& v) {
    char* tmp = strtok(p, " ");
    while (tmp) {
        v.push_back(atoi(tmp));
        tmp = strtok(NULL, " ");
    }
}

int main() {
    string s;
    getline(cin, s);
    split(const_cast<char*>(s.c_str()), seq);
    dp.push_back(seq[0]);
    for (int i = 1; i < seq.size(); ++i) {
        dp.push_back(max(dp[i-1]+seq[i], seq[i]));
    }
    int ret = INT_MIN;
    for (auto i : dp) {
        ret = max(ret, i);
    }
    printf("%d\n", ret);
    return 0;
}
