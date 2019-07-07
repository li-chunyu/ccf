#include <cstdio>
#include <vector>
using namespace std;

int main() {
    vector<float> p1(1000, 0.0);
    vector<float> p2(1000, 0.0);
    int b1, b2;
    int n = 0;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int exp = 0;
        float conff = 0.0;
        scanf("%d%f", &exp, &conff);
        p1[exp] = conff;
        if (i == 0) b1 = exp;
    }
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int exp = 0;
        float conff = 0.0;
        scanf("%d%f", &exp, &conff);
        p2[exp] = conff;
        if (i == 0) b2 = exp;
    }
    vector<float> ret(b1+b2+1, 0.0);
    int nonzero = 0;
    for (int i = 0; i < 1000; ++i) {
        if (p1[i] == 0.0) continue;
        for (int j = 0; j < 1000; ++j) {
            if (p2[j] == 0.0) continue;
            if (ret[i + j] == 0.0) nonzero++;
            ret[i+j] += (p1[i] * p2[j]);
            // printf("%d %d %f %f\n", i, j, p1[i], p2[j]);
        }
    }
    int iter = b1+b2+1;
    printf("%d", nonzero);
    for (int i = iter-1; i >= 0; --i) {
        if (ret[i] != 0) {
            printf(" %d %.1f", i, ret[i]);
        }
    }
    printf("\n");
    return 0;
}