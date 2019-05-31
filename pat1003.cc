#include <cstdio>
#include <vector>
using namespace std;

typedef struct road {
    /* data */
    int city;
    int len;
    road(int c, int l): city(c), len(l) {}
} road;

const int INF = 0x3fffffff;

int main() {
    int N, M, C1, C2;
    scanf("%d%d%d%d", &N, &M, &C1, &C2);
    int nteam[N];
    vector<vector<road> > adj(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &nteam[i]); 
    }
    for (int i = 0; i < M; ++i) {
        int s, e, len;
        scanf("%d%d%d", &s, &e, &len);
        adj[s].push_back(road(e, len));
        adj[e].push_back(road(s, len));
    }
    // dijkstra
    vector<int> dist_to(N, INF);
    vector<int> t(N, 0);
    vector<int> npath(N, 0);
    vector<int> vis(N, 0);
    dist_to[C1] = 0;
    t[C1] = nteam[C1];
    npath[C1] = 1;

    for (int i = 0; i < N; ++i) {
        int u = -1, min = INF;
        for (int j = 0; j < N; ++j) {
            if (vis[j] == 0 && dist_to[j] < min) {
                u = j;
                min = dist_to[j];
            }
        }
        if (u == -1) { printf("no path\n"); return 0; }
        vis[u] = 1;
        for (int v = 0; v < adj[u].size(); ++v) {
            if (vis[adj[u][v].city] == 0 && dist_to[adj[u][v].city] > dist_to[u] + adj[u][v].len) {
                dist_to[adj[u][v].city]  = dist_to[u] + adj[u][v].len;
                npath[adj[u][v].city] = npath[u];
                t[adj[u][v].city] = t[u] + nteam[adj[u][v].city];
            } else if (vis[adj[u][v].city] == 0 && dist_to[adj[u][v].city] == dist_to[u] + adj[u][v].len) {
                npath[adj[u][v].city] += npath[u];
                if (t[u] + nteam[adj[u][v].city] > t[adj[u][v].city])
                    t[adj[u][v].city] = t[u] + nteam[adj[u][v].city];
            }
        }
    }
    printf("%d %d\n", npath[C2], t[C2]);
    return 0;
}