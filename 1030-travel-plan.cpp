#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 510;
int g[N][N], g_cost[N][N];

int n, m, src, dst;

int dist[N], cost[N], pre[N];
bool visited[N];

void dijtstra(int s) {
    memset(dist, 0x3f, sizeof dist);
    memset(cost, 0x3f, sizeof cost);
    memset(visited, false, sizeof visited);

    dist[s] = 0;
    cost[s] = 0;

    for (int i = 0; i < n; i ++) {
        int t = -1;
        for (int j = 0; j < n; j ++) {
            if (!visited[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }
        visited[t] = true;
        
        for (int j = 0; j < n; j ++) {
            if (dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j];
                cost[j] = cost[t] + g_cost[t][j];
                pre[j] = t;
            } else if (dist[j] == dist[t] + g[t][j] && cost[j] > cost[t] + g_cost[t][j]) {
                cost[j] = cost[t] + g_cost[t][j];
                pre[j] = t;
            }
        }
    }
}

int main() {
    cin >> n >>m >> src >> dst;

    memset(g, 0x3f, sizeof g);
    memset(g_cost, 0x3f, sizeof g_cost);

    while (m --) {
        int a, b, l, c;
        cin >> a >> b >> l >> c;
        g[a][b] = g[b][a] = l;
        g_cost[a][b] = g_cost[b][a] = c;
    }

    dijtstra(src);

    int p = dst;
    vector<int> res;
    while (p != src) {
        res.push_back(p);
        p = pre[p];
    }

    cout << src;
    for (auto i = res.rbegin(); i != res.rend(); i ++) {
        cout << " " << *i;
    }

    cout << " " << dist[dst] << " " << cost[dst];

    return 0;
}
