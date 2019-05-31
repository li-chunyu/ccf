#include <iostream>
using namespace std;

void dfs(int rst, int& nplan) {
    if (rst == 0) {
        nplan++;
        return;
    }
    if (rst >= 2) {
        dfs(rst - 2, nplan);
    }
    dfs(rst - 1, nplan);
}

int main() {
    int N = 0;
    int nplan = 0;
    cin >> N;
    if (N == 0) {
        cout << 0 << endl;
        return 0;
    }
    dfs(N, nplan);
    cout << nplan << endl;
    return 0;
}