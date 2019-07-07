#include <string>
#include <cstdio>
#include <iostream>
#include <limits>
using namespace std;

void rev(string &s, int l, int r) {
  while (l < r) {
    auto tmp = s[l];
    s[l] = s[r];
    s[r] = tmp;
    ++l;
    --r;
  }
}

int main() {
  int n = 0; 
  scanf("%d", &n);
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  int l = 0;
  int r = 0;
  for (int i = 0; i < n; ++i) {
    l = 0;
    r = 0;
    string s;
    getline(cin, s);
    while ((r = s.find(' ', l)) != string::npos) {
      rev(s, l, r-1);
      l = r + 1;
    }
    rev(s, l, s.size()-1);
    printf("%s\n", s.c_str());
  }
}