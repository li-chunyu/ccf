/*
 * @Description: 201409-2
 * @Author: your name
 * @Date: 2018-12-15 19:36:42
 * @LastEditTime: 2018-12-15 20:13:33
 * @LastEditors: Please set LastEditors
 */

#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;

void split(char *p, vector<int> &v) {
    char *tmp = strtok(p, " ");
    while (tmp) {
        v.push_back(atoi(tmp));
        tmp = strtok(NULL, " ");
    }
}

int main() {
    /*
    streambuf *backup = cin.rdbuf();
    ifstream fin;
    fin.open("input.txt");
    cin.rdbuf(fin.rdbuf());
    */
    int n;
    vector<vector<int> > v;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i=0; i<n; ++i) {
        string s;
        vector<int> tmp;
        getline(cin, s);
        split(const_cast<char*>(s.c_str()), tmp);
        v.push_back(tmp);
    }
    int x = 0;
    int y = 0;
    for (auto t : v) {
        x = max(x, max(t[0], t[2]));
        y = max(y, max(t[1], t[3]));
    }

    vector<vector<int> > g(y+1, vector<int>(x+1, 0));

    for (auto t : v) {
        for (int i=t[0]; i<t[2]; ++i){
            for (int j=t[1]; j<t[3]; ++j){
                g[j][i] = 1;
            }
        }
    }

    int cnt = 0;
    for (auto t : g) {
        for (auto tt : t) {
            if(tt == 1)
                cnt += 1;
        }
    }

    cout << cnt << endl;
    //cin.rdbuf(backup);

}