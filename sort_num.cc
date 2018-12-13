/*
 * @Description: 201503-2
 * @Author: lichunyu
 * @Date: 2018-12-13 21:58:23
 * @LastEditTime: 2018-12-13 22:26:01
 * @LastEditors: Please set LastEditors
 */

#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second > b.second)
        return true;
    if (a.second == b.second)
        return a.first < b.first;
    return false; 
}

int main() {
    map<int, int> m;
    int n;
    int num;
    cin >> n;
    for (int i=0; i<n; ++i) {
        try{
            cin >> num;
            m[num] = m[num] + 1;
        } catch(out_of_range) {
            m[num] = 1;
        }
    }
    vector<pair<int, int> > m_v(m.begin(), m.end());
    sort(m_v.begin(), m_v.end(), cmp);
    for (auto each : m_v) {
        cout << each.first << " " << each.second << endl;
    }
    return 0;

}