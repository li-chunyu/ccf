#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int tower[n][n], dp[n][n];
  int trace[n][n];
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < i; ++j) {
      scanf("%d", &tower[i-1][j]);
      dp[i-1][j] = INT_MIN;
    }
  }
  for (int i = 0; i < n; ++i) {
    dp[n-1][i] = tower[n-1][i];
    trace[n-1][i] = i;
  }
  for (int i = n-2; i >= 0; --i) {
    for (int ele = 0; ele < i+1; ++ele) {
      int element;
      if (dp[i+1][ele] > dp[i+1][ele+1]) {
        dp[i][ele] = dp[i+1][ele];
        trace[i][ele] = ele;
      } else {
        dp[i][ele] = dp[i+1][ele+1];
        trace[i][ele] = ele + 1;
      }
      dp[i][ele] += tower[i][ele];
    }
  }
  printf("%d\n", dp[0][0]);
  int next = trace[0][0];
  int level = 1;
  printf("%d", tower[0][0]);
  while (level != n) {
    printf(" %d", tower[level][next]);
    next = trace[level][next];
    level++;
  }
  printf("\n");
  return 0;
}