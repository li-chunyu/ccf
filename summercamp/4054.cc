#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  int nelem = N;
  int start = 1;
  vector<vector<int> > ret;
  for (int row = 0; row < N; ++row) {
    int cprow = row;
    int col = 0;
    int s = start;
    ret.push_back(vector<int>(nelem, start));
    while (cprow >0) {
      ret[--cprow][++col] = ++s;
    }
    start += (row + 1);
    nelem--;
  }
  nelem = N;
  for (auto row : ret) {
    printf("%d", row[0]);
    for (int i = 1; i < row.size(); ++i) {
      printf(" %d", row[i]);
    }
    printf("\n");
  }
  return 0;
}