/*
 * 最大子列问题
 */
#include <vector>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstdlib>
using namespace std;

int sum_of_max_sub_arry(vector<int>& v) {
  vector<int> dp;
  dp.push_back(v[0]);
  for (int i = 1; i < v.size(); ++i) {
    dp.push_back(max(v[i], v[i]+dp[i-1]));
  }
  int ret = INT_MIN;
  for (int i = 0; i < dp.size(); ++i) {
    ret = max(dp[i], ret);
  }
  return ret;
}

int sum_of_min_sub_arry(vector<int>& v) {
  vector<int> dp;
  dp.push_back(v[0]);
  for (int i = 1; i < v.size(); ++i) {
    dp.push_back(min(v[i], v[i]+dp[i-1]));
  }
  int ret = INT_MAX;
  for (int i = 0; i < dp.size(); ++i) {
    ret = min(dp[i], ret);
  }
  return ret;
}

int main() {
  int n, w;
  scanf("%d%d", &n, &w);
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    int tmp;
    scanf("%d", &tmp);
    a[i] = tmp;
  }
  int submax = sum_of_max_sub_arry(a);
  int submin = sum_of_min_sub_arry(a);
  int ret;
  if (abs(submax) > abs(submin)) {
    ret = w - submax + 1;
  } else {
    ret = w + submin + 1;
  }
  printf("%d\n", max(0, ret));
  return 0;
}