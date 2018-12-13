#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstring>
#include <cstdlib>

using namespace std;

void split(char*p, vector<int>& v) {
    v.clear();
    char* tmp = strtok(p, " ");
    while (tmp) {
        v.push_back(atoi(tmp));
        tmp = strtok(NULL, " ");
    }
}

int find_sit(vector<int> &v, int num) {
    int left = 0, right = 0;
    while (right != v.size()) {
        if (v[left] == -1) {
            left += 1;
            right = left;
        } else if (right != -1) {
            right += 1;
        } else {
            if (right-left >= num)
                break; 
        }
    }
    return right-left >= num? left: -1;
}

int main() {
    vector<vector<int> > sits;
    vector<int> records;
    int n;
    for (int i=0; i<20; i++) {
        vector<int> line(5, 1);
        sits.push_back(line);
    }
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string s;
    getline(cin, s);
    split(const_cast<char*>(s.c_str()), records);


    for (int i=0; i<records.size(); ++i) {
        int flag = 0;
        for (int j=0; j<20; ++j) {
            int sit_n;
            sit_n = find_sit(sits[j], records[i]);
            // cout << "i : " << i << "||" << sit_n << endl;
            if (sit_n != -1) {
                flag = 1;
                for (int t=0; t<records[i]; ++t){
                    sits[j][sit_n + t] = -1;
                    cout << 5*j + t + sit_n + 1 << " ";
                }
                break;
            }
        }
        if (flag == 0) {
            int re = records[i];
            for (int j=0; j<20; ++j) {
                int sit_n;
                sit_n = find_sit(sits[j], 1);
                while (sit_n!=-1 && re!=0) {
                    sits[j][sit_n] = -1;
                    cout << 5*j + sit_n + 1 << " ";
                    re -= 1;
                    sit_n = find_sit(sits[j], 1);
                }
            }
        }
        cout << endl;
    }
}