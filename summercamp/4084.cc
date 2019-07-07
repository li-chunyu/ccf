#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int levenshtein_distance(const string& s1, const string& s2) {
  const int ns1 = s1.size(), ns2 = s2.size();
  if (ns1 == 0 || ns2 == 0) {
    return ns1 == 0? ns2: ns1;
  }
  int dp[ns1+1][ns2+1];
  dp[0][0] = 0;
  for (int i = 1; i <= ns1; ++i) {
    dp[i][0] = i;
  }
  for (int i = 1; i <= ns2; ++i) {
    dp[0][i] = i;
  }
  for (int i = 1; i <= ns1; ++i) {
    for (int j = 1; j <= ns2; ++j) {
      dp[i][j] = min(dp[i-1][j]+1,
                     min(dp[i][j-1]+1,
                         dp[i-1][j-1]+(s1[i-1] != s2[j-1]?1:0)));
    }
  }
  return dp[ns1][ns2];
}

int main() {
  string input;
  map<int, vector<string> > word_sym;
  map<string, int> word_order;
  int word_size = 0;
  int order = 0;
  while (1) {
    getline(cin, input);
    if (input == "#") break;
    word_order[input] = order++;
    word_size = input.size();
    auto it_word_size = word_sym.find(word_size);
    if (it_word_size == word_sym.end()) {
      word_sym[word_size] = vector<string>(1, input);
    } else {
      it_word_size->second.push_back(input);
    }
  }
  while (1) {
    getline(cin, input);
    if (input == "#") break;
    word_size = input.size();
    vector<string> ret;
    auto iter_change = word_sym.find(word_size);
    if (iter_change != word_sym.end()) {
      if (find(iter_change->second.begin(), iter_change->second.end(), input) != iter_change->second.end()) {
        cout << input << " is correct" << endl;;
        continue;
      }
      for (auto word : iter_change->second) {
        if (levenshtein_distance(input, word) == 1)
          ret.push_back(word);
      }
    }
    auto iter_deletion = word_sym.find(word_size-1);
    if (iter_deletion != word_sym.end()) {
      for (auto word : iter_deletion->second) {
        if (levenshtein_distance(input, word) == 1)
          ret.push_back(word);
      }
    }
    auto iter_insertion = word_sym.find(word_size+1);
    if (iter_insertion != word_sym.end()) {
      for (auto word : iter_insertion->second) {
        if (levenshtein_distance(input, word) == 1)
          ret.push_back(word);
      }
    }
    sort(ret.begin(), ret.end(), [&word_order](string s1, string s2){
      return word_order[s1] < word_order[s2];
    });
    cout << input << ":";
    for (auto word : ret) {
      cout << " " << word;
    }
    cout << endl;
  }
  return 0;
}