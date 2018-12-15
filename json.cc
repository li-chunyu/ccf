#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <utility>
#include <cstddef>
#include <cstring>

using namespace std;

void split(char *p, vector<string> &v) {
    char *tmp = strtok(p, ".");
    while (tmp) {
        v.push_back(string(tmp));
        tmp = strtok(NULL, ".");
    }
}

int main() {
    /*
    streambuf *backup;
    ifstream fin;
    fin.open("input.txt");
    backup = cin.rdbuf();
    cin.rdbuf(fin.rdbuf());
    */
    int n, m;
    cin >> n >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string text = "";
    for (int i=0; i<n; ++i) {
        string s;
        getline(cin, s);
        text += s;
    }
    for (int i=0; i<m; ++i) {
        string query;
        getline(cin, query);
        vector<string> keys;
        split(const_cast<char*>(query.c_str()), keys);

        size_t k_pos = 0;
        for (int j=0; j<keys.size(); ++j) {
            string k = keys[j];
            size_t pos = k.find("\\");
            while (pos != string::npos) {
                k.insert(pos, "\\");
                pos = k.find("\\", pos+2);
            }
            pos = k.find("\"");
            while (pos != string::npos) {
                k.insert(pos, "\\");
                pos = k.find("\"", pos+2);
            }
            //cout << "key:" << k << endl;
            k_pos = text.find(k, k_pos);
            if (k_pos == string::npos) {
                cout << "NOTEXIST" << endl;
                break;
            }
            size_t sub_pos = k_pos + k.size() + 2;

            while (text[sub_pos] == ' ') sub_pos++;
            if (text[sub_pos] == '{' && keys.size()-j == 1){
                cout << "OBJECT" << endl;
                break;
            } else if (text[sub_pos] == '\"') {
                size_t nxt_pos = text.find("\"", sub_pos + 1);
                while (text[nxt_pos-1] == '\\')
                    nxt_pos = text.find("\"", nxt_pos + 1);
                string out = text.substr(sub_pos + 1, nxt_pos - sub_pos - 1);
                size_t tran_pos = out.find("\\");
                while (tran_pos != string::npos) {
                    out.erase(tran_pos, 1);
                    tran_pos = out.find("\\", tran_pos + 1);
                }
                cout << "STRING" << " " << out << endl;
            }
        }
        k_pos = 0;

    }

    //cin.rdbuf(backup);
    return 0;
}