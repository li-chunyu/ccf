/*
 * author: lichunyu
 * 最长回文
 * page 436
*/

#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 100;
int dp[MAXN][MAXN];
char str[MAXN];

int main() {
    gets(str);
    int len = strlen(str);
    int ret = 1;
    // initialize
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len; ++i) {
        dp[i][i] = 1;
        if (i < len - 1) {
            if (str[i] == str[i+1]) {
                dp[i][i+1] = 1;
                ret = 2;
            }
        }
    }
    for (int slen = 3; slen <= len; ++slen) {
        for (int left_idx = 0; left_idx <= len - slen; ++left_idx) {
            int right_idx = left_idx + slen - 1;
            if (str[left_idx] == str[right_idx]) {
                dp[left_idx][right_idx] = dp[left_idx+1][right_idx-1];
                if (dp[left_idx][right_idx] == 1) {
                    ret = slen;
                }
            } else {
                dp[left_idx][right_idx] = 0;
            }
        }
    }
    printf("%d\n", ret);
    return 0;
}