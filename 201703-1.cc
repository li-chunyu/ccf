#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <limits>
using namespace std;


void split(char* p, vector<int> &v) {
    v.clear();
    char* tmp = strtok(p, " ");
    while(tmp) {
        v.push_back(stoi(tmp));
        tmp = strtok(NULL, " ");
    }
}

int main() {
    int n, m;
    string s;
    vector<int> v;
    cin >> n >> m;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, s);
    split(const_cast<char*>(s.c_str()), v);

    int cur = 0;
    int cnt = 0;
    for (int i=0; i<v.size(); ++i) {
        cur += v[i];
        if (cur>=m) {
            cnt++;
            cur = 0;
        }
    }   
    if (cur > 0)    cnt++;
    cout << cnt;
}