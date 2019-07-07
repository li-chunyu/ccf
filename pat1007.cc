#include <cstdio>
using namespace std;

int main() {
    int K = 0;
    scanf("%d", &K);
    int A[K], dp[K], pre[K];
    for (int i = 0; i < K; ++i) {
        scanf("%d", &A[i]);
        dp[i] = A[i];
        pre[i] = i;
    }
    for (int i = 1; i < K; ++i) {
        if (dp[i-1] > 0) {
            dp[i] += dp[i-1];
            pre[i] = i - 1;
        }
    }
    int max = -0x3fffffff;
    int right = 0;
    for (int i = 0; i < K; ++i) {
        if (dp[i] > max) {
            max = dp[i];
            right = i;
        } 
    }
    int left = pre[right];
    while (pre[left] != left) {
        left = pre[left];
    }
    if (max >= 0)
        printf("%d %d %d\n", max, A[left], A[right]);
    else 
        printf("%d %d %d\n", 0, A[0], A[K-1]);
    return 0;
}