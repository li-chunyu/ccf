#include <iostream>
#include <cstdlib>
#include <limits>
#include <vector>
#include <cstring>

using namespace std;


void split(char*p, vector<int>& v) {
    v.clear();
    char* tmp = strtok(p, " ");
    while (tmp) {
        v.push_back(atoi(tmp));
        tmp = strtok(NULL, " ");
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<vector<int> > v;
    for (int i=0; i<n; ++i) {
        string s;
        getline(cin, s);
        v.push_back(vector<int>());
        split(const_cast<char*>(s.c_str()), v[i]);
    }


    for (int i=m-1; i>=0; --i) {
        for (int j=0; j<n; ++j) {
            cout << v[j][i] << " ";
        }
        cout << '\n';
    }

}