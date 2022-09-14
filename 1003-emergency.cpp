#include <iostream>
#include <cstring>

using namespace std;

const int N = 610;

int g[N][N], nums[N];
int n, m, src, dst;

int dist[N], cnt[N], max_num[N];
bool st[N];

void dijtstra(int s) {
    memset(dist, 0x3f, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, false, sizeof st);
    memset(max_num, -1, sizeof max_num);

    dist[s] = 0;
    cnt[s] = 1;
    max_num[s] = nums[s];

    for (int i = 0; i < n; i ++) {
        int t = -1;

        for (int j = 0; j < n; j ++) {
            if (!st[j] && (t == -1 || dist[j] < dist[t])) {
                t = j;
            }
        }
        st[t] = true;

        for (int j = 0; j < n; j ++) {
            if (dist[j] > dist[t] + g[t][j]) {
                cnt[j] = cnt[t];
                dist[j] = dist[t] + g[t][j];
                max_num[j] = max_num[t] + nums[j];
            } else if (dist[j] == dist[t] + g[t][j]) {
                cnt[j] += cnt[t];
                max_num[j] = max(max_num[j], max_num[t] + nums[j]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> src >> dst;

    memset(g, 0x3f, sizeof g);

    for (int i = 0; i < n; i ++) cin >> nums[i];

    for (int i = 0; i < m; i ++) {
        int a, b, l;
        cin >> a >> b >> l;
        g[a][b] = g[b][a] = min(g[a][b], l);
        
    }

    dijtstra(src);

    cout << cnt[dst] << " " << max_num[dst];

    return 0;
}