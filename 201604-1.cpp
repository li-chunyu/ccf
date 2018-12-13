#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

void split(char* p, vector<int> &v) {
    v.clear();
    char* tmp = strtok(p, " ");
    while(tmp) {
        v.push_back(atoi(tmp));
        tmp = strtok(NULL, " ");
    }
}

int main() {
    int n;
    vector<int> v;
    string s;
    cin >> n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, s);
    split(const_cast<char*>(s.c_str()), v);

    if (v.size() < 3) {
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    for (int i=1; i<=(v.size()-2); ++i) {
        if ((v[i] - v[i-1])*(v[i] - v[i+1]) > 0)
            ++cnt;
    }
    cout << cnt << endl;
    return 0;
}