#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

void split(char *p, vector<int> &v1, vector<int> &v2){
    v1.clear();
    v2.clear();
    char *tmp = strtok(p, " ");
    while (tmp) {
        v1.push_back(atoi(tmp));
        v2.push_back(atoi(tmp));
        tmp = strtok(NULL, " "); 
    } 
}

int main() {
    vector<vector<int> > input;
    vector<vector<int> > flag;
    int n, m;
    cin >> n >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i=0; i<n; i++) {
        string s;
        getline(cin, s);
        input.push_back(vector<int>());
        flag.push_back(vector<int>());
        split(const_cast<char*>(s.c_str()), input[i], flag[i]);
    }

    for (int i=0; i<n; i++) {
        int index, cur;
        index = 0;
        cur = 0;
        while (index < m) {
            int cnt = 0;
            while (cur < m && input[i][cur] == input[i][index]) {
                cnt++; cur++;
            }
            if (cnt >= 3) {
                for (int ii=index; ii<cur; ii++)
                    flag[i][ii] = 0;
            }
            index = cur;
        }
    }

    for (int j=0; j<m; j++) {
        int index, cur;
        index = 0;
        cur = 0;
        while (index < n) {
            int cnt = 0;
            while(cur < n && input[cur][j] == input[index][j]) {
                cnt++; cur++;
            }
            if (cnt >= 3)
                for (int jj=index; jj<cur; ++jj) {
                    flag[jj][j] = 0;
                }
            index = cur;
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cout << flag[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}