#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 100;

struct node {
    int x;
    int y;
    int step;
}S, T, Node;

char matrix[maxn][maxn];
bool inq[maxn][maxn];
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};
int m = 0, n = 0;

bool is_valid(int x, int y) {
    if (x >= m || x < 0 || y >=n || y < 0) return false;
    if (matrix[x][y] == '*') return false;
    if (inq[x][y] == true) return false;
    return true;
}

int BFS() {
    queue<node> Q;
    Q.push(S);
    inq[S.x][S.y] = true;
    while (!Q.empty()) {
        node top = Q.front();
        Q.pop();
        if (top.x == T.x && top.y == T.y) {
            return top.step;
        }
        for (int i = 0; i < 4; ++i) {
            int newx = top.x + X[i];
            int newy = top.y + Y[i];
            if (is_valid(newx, newy)) {
                Node.x = newx;
                Node.y = newy;
                Node.step = top.step + 1;
                Q.push(Node);
                inq[newx][newy] = true; 
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i) {
        getchar();
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = getchar(); 
            printf("%c", matrix[i][j]);
            inq[i][j] = false;
            if (matrix[i][j] == 'S') {
                S.x = i;
                S.y = j;
                S.step = 0;
            }
            if (matrix[i][j] == 'T') {
                T.x = i;
                T.y = j;
                T.step = 0;
            }
        }
    }
    // T S 的坐标有问题。
    printf("%d %d\n", T.x, T.y);
    printf("%d %d\n", S.x, S.y);
    printf("%d\n", BFS());
}