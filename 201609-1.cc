/*
 * @Description: 201609-1
 * @Author: lichunyu
 * @Date: 2018-12-13 21:40:17
 * @LastEditTime: 2018-12-13 21:49:33
 * @LastEditors: Please set LastEditors
 */

#include <iostream>
#include <vector>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

void split(char *p, vector<int> &v) {
    char *tmp = strtok(p, " ");
    while(tmp) {
        v.push_back(atoi(tmp));
        tmp = strtok(NULL, " ");
    }
}

int main () {
    vector<int> data;
    int d;
    int max_f = 0;
    string line;

    cin >> d;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, line);

    split(const_cast<char*>(line.c_str()), data);


    for (int i=0; i<d-1; ++i) {
        max_f = max(max_f, abs(data[i] - data[i+1]));
    }
    cout << max_f << endl;
}
