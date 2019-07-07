#include <cstdio>
#include <algorithm>
using namespace std;
char MAP[3] = {'W', 'T', 'L'};
int main() {
  char ret[3];
  double rate = 1.0;
  for (int i = 0; i < 3; ++i) {
    double max = 0.0;
    char c;
    for (int j = 0; j < 3; ++j) {
      double tmp;
      scanf("%lf", &tmp);
      if (tmp > max) {
        max = tmp;
        c = MAP[j];
      }
    }
    rate *= max;
    ret[i] = c;
  }
  printf("%c %c %c %.2lf\n",
    ret[0],
    ret[1],
    ret[2],
    (rate * 0.65 - 1)*2);
  return 0;
}