/*
 * @Description: 201809-2
 * @Author: your name
 * @Date: 2018-12-13 22:41:59
 * @LastEditTime: 2018-12-13 22:53:40
 * @LastEditors: Please set LastEditors
 */

#include <iostream>
#include <utility>
#include <vector>
#include <limits>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

void split(char *p, vector<int> &v) {
    char *tmp = strtok(p, " ");
    while (tmp) {
        v.push_back(atoi(tmp));
        tmp = strtok(NULL, " ");
    }
}

int main() {
    int n;
    vector<pair<int, int>> h;
    vector<pair<int, int>> w;

    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i=0; i<n; ++i) {
        string s;
        vector<int> tmp_v;
        pair<int, int> p;
        getline(cin, s);
        split(const_cast<char*>(s.c_str()), tmp_v);
        p.first = tmp_v[0];
        p.second = tmp_v[1];
        h.push_back(p);
    }

    for (int i=0; i<n; ++i) {
        string s;
        vector<int> tmp_v;
        pair<int, int> p;
        getline(cin, s);
        split(const_cast<char*>(s.c_str()), tmp_v);
        p.first = tmp_v[0];
        p.second = tmp_v[1];
        w.push_back(p);
    }
    int re = 0;
    for (auto h_i : h){
        for (auto w_i : w){
            int begin = max(h_i.first, w_i.first);
            int end = min(h_i.second, w_i.second);
            if (end - begin > 0)
                re += end - begin;
        }
    }
    cout << re << endl;
    return 0;
}