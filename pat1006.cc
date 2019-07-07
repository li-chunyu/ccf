#include <string>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

bool less_comp_start_time(const string& s1, const string& s2) {
    string sub_s1 = s1.substr(s1.find_first_of(" ") + 1, s1.find_last_of(" ") - s1.find_first_of(" ") - 1);
    string sub_s2 = s2.substr(s2.find_first_of(" ") + 1, s2.find_last_of(" ") - s2.find_first_of(" ") - 1);
    return sub_s1 < sub_s2;
}

bool bigger_comp_end_time(const string& s1, const string& s2) {
    string sub_s1 = s1.substr(s1.find_last_of(" ") + 1);
    string sub_s2 = s2.substr(s2.find_last_of(" ") + 1);
    return sub_s1 > sub_s2;
}

int main() {
    int n = 0;
    vector<string> rec;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        rec.push_back(s);
    }
    sort(rec.begin(), rec.end(), less_comp_start_time);
    cout << rec[0].substr(0, rec[0].find_first_of(" "));
    cout << " ";
    sort(rec.begin(), rec.end(), bigger_comp_end_time);
    cout << rec[0].substr(0, rec[0].find_first_of(" "));
    cout << "\n";
    return 0;
}