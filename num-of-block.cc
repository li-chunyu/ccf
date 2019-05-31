#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool is_valid(int x, int y, int m, int n, vector<vector<int> >& matrix, vector<vector<int> >& mark) {
    if (x >= m || x< 0 ||y >= n || y < 0) return false;
    if (matrix[x][y] == 0 || mark[x][y] == 1) return false;
    return true;
}

void BFS(vector<vector<int> >& matrix, vector<vector<int> >& mark,
        int x, int y, int m, int n) {
    queue<pair<int, int> > Q;
    auto node = make_pair(x, y);
    Q.push(node);
    mark[x][y] = 1;
    while (!Q.empty()) {
        auto p = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int new_x = p.first + X[i];
            int new_y = p.second + Y[i];
            if (is_valid(new_x, new_y, m, n, matrix, mark)) {
                Q.push(make_pair(new_x, new_y));
                mark[new_x][new_y] = 1;
            }
        }
    }
}

int main() {
    int nblock = 0;
    vector<vector<int> > mark;
    vector<vector<int> > matrix;
    int ret = 0;
    int m = 0, n = 0;
    int tmp;
    scanf("%d%d", &m, &n);
    for (int row = 0; row < m; ++row) {
        vector<int> v;
        vector<int> mark_v;
        for (int col = 0; col < n; ++col) {
            scanf("%d", &tmp);
            v.push_back(tmp); 
            mark_v.push_back(0);
        }
        matrix.push_back(v);
        mark.push_back(mark_v);
    }
    for (int row = 0; row < m; ++row) {
        for (int col = 0; col < n; ++col) {
            if (matrix[row][col] == 1 && mark[row][col] == 0) {
                ret++;
                BFS(matrix, mark, row, col, m, n);
            }
        }
    }
    printf("%d\n", ret);
    return 0;
}