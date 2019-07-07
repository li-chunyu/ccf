#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

char SPACE = ' ';

struct cmp {
  bool operator()(const string& s1, const string& s2) const {
    int pos1 = s1.find_first_of(SPACE);
    int pos2 = s2.find_first_of(SPACE);
    int m1 = stoi(s1.substr(0, pos1));
    int m2 = stoi(s2.substr(0, pos2));
    int d1 = stoi(s1.substr(pos1+1));
    int d2 = stoi(s2.substr(pos2+1));
    if (m1 < m2)
      return true;
    else if (m1 > m2)
      return false;
    else {
      if (d1 < d2)
        return true;
    }
    return false;
  }
};

int main() {
  int n;
  cin >>n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  map<string, vector<string>, cmp> m;
  map<string, int> input_order;
  int order = 0;
  for (int i = 0; i < n; ++i) {
    string s;
    string number;
    string birth;
    getline(cin, s);
    auto index = s.find_first_of(SPACE);
    birth = s.substr(index+1);
    number = s.substr(0, index);
    if (m.find(birth) != m.end()) {
      m[birth].push_back(number);
    } else {
      m[birth] = vector<string>(1, number);
    }
    input_order[number] = order++;
  }
  for (auto ele : m) {
    cout << ele.first;
    sort(ele.second.begin(), ele.second.end(), [&input_order](string& s1, string& s2){
      return input_order[s1] < input_order[s2];
    });
    for (auto p : ele.second) {
      cout << " " << p;
    }
    cout << endl;
  }
  return 0;
}