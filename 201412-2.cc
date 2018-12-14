/*
 * @Description: Z-scan
 * @Author: lichunyu
 * @Date: 2018-12-14 10:30:55
 * @LastEditTime: 2018-12-14 12:17:40
 * @LastEditors: Please set LastEditors
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <limits>

using namespace std;

void split(char *p, vector<int> &v) {
    char *tmp = strtok(p, " ");
    while (tmp) {
        v.push_back(atoi(tmp));
        tmp = strtok(NULL, " ");
    }
}

bool movable_upright(pair<int, int> &pos, int &shape) {
    if (pos.first == 0 || pos.second == shape-1)
        return false;
    return true;
}

bool movable_downleft(pair<int, int> &pos, int &shape) {
    if (pos.first == shape-1 || pos.second == 0)
        return false;
    return true;
}

int main() {
    vector<vector<int> > pic;
    auto pos = make_pair(0, 1);
    int shape;
    vector<int> oseq;
    int dl_flag = 1;
    cin >> shape;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i=0; i<shape; ++i) {
        vector<int> v;
        string s;
        getline(cin, s);
        split(const_cast<char*>(s.c_str()), v);
        pic.push_back(v);
    }

    if (shape == 1) {
        cout << pic[0][0] << " " << endl;
        return 0;
    }

    for (int i=2; i<=shape; ++i) {
        if (dl_flag) {
            for (int j=0; j<i; j++) {
                oseq.push_back(pic[0+j][i-1-j]);
            }
            dl_flag = 0;
        } else {
            for (int j=0; j<i; j++) {
                oseq.push_back(pic[i-1-j][0+j]);
            }
            dl_flag = 1;
        }
    }
    for (int i=shape-1; i>=2; --i) {
        if (dl_flag) {
            for (int j=0; j<i; j++) {
                oseq.push_back(pic[shape-i+j][shape-1-j]);
            }
            dl_flag = 0;
        } else {
            for (int j=0; j<i; j++) {
                oseq.push_back(pic[shape-1-j][shape-i+j]);
            }
            dl_flag = 1;
        }
    }
    
    cout << pic[0][0] << " ";
    for (auto each : oseq) {
        cout << each << " ";
    }
    cout << pic[shape-1][shape-1] << " " << endl;
    return 0;
}
