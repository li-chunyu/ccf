/*
 * @Description: ball
 * @Author: lichunyu
 * @Date: 2018-12-14 20:22:42
 * @LastEditTime: 2018-12-14 21:32:45
 * @LastEditors: Please set LastEditors
 */
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <limits>
#include <cstdlib>

using namespace std;

void split(char *p, vector<int> &v) {
    char *tmp = strtok(p, " ");
    while (tmp) {
        v.push_back(atoi(tmp));
        tmp = strtok(NULL, " ");
    }
}

int main() {
    // #ball, length, time
    int n, l, t;
    string s;
    cin >> n >> l >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> pos;
    vector<int> direc(n+1, 1); // 1 for right , -1 for left.
    getline(cin, s);
    split(const_cast<char*>(s.c_str()), pos);
    pos.insert(pos.begin(), 0);

    for (int time=0; time<t; ++time) {
        vector<int> ground(l, 0);
        for (int i=1; i<pos.size(); ++i) {
            pos[i] = pos[i] + direc[i];
            if (pos[i] == 0 || pos[i] == l)
                direc[i] = -direc[i];
            else {
                ground[pos[i]] += i;
                if (ground[pos[i]] != i) {
                    int ball_1 = i;
                    int ball_2 = ground[pos[i]] - i;
                    direc[ball_1] = - direc[ball_1];
                    direc[ball_2] = - direc[ball_2];
                }
            }
        }
    }
    for (int i=1; i<pos.size(); ++i) {
        cout << pos[i] << " ";
    }
    cout << endl;
    return 0;
}