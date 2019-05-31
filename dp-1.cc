/*
 * dp probelm
 * test data: dp1-test.txt
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int nlevel = 0;
    vector<vector<int> > num_tower;
    vector<vector<int> > dp;
    scanf("%d", &nlevel);
    for (int i = 1; i <= nlevel; ++i) {
        vector<int> tmp;
        vector<int> tmp_dp(i, -1);
        dp.push_back(tmp_dp);
        for (int j = 0; j < i; ++j) {
            int num = 0;
            scanf("%d", &num);
            tmp.push_back(num);
        }
        num_tower.push_back(tmp);
    }
    
    // initialize
    for (int i = 0; i < nlevel; ++i) {
        dp[nlevel-1][i] = num_tower[nlevel-1][i];
    }
    for (int level = nlevel - 2; level >= 0; --level) {
        for (int j = 0; j < level+1; ++j) {
            dp[level][j] = max(dp[level+1][j], dp[level+1][j+1]) + num_tower[level][j];
        }
    }
    printf("%d\n", dp[0][0]);
    return 0;
}