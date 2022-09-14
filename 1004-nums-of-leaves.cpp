#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 110;
int h[N], e[N], ne[N], idx;
int res[N], max_level;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int root, int level) {
    int cur = h[root];
    if (cur == -1) {
        res[level] += 1;
        max_level = max(max_level, level);
        return;
    }

    for (int i = cur; i != -1; i = ne[i]) {
        int j = e[i];
        dfs(j, level +1);
    }
}

int n, m;
int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);
    while(m --) {
        int root, k, child;
        cin >> root >> k;
        while(k --) {
            cin >> child;
            add(root, child);
        }
    }

    dfs(1, 0);

    cout << res[0];
    for (int i = 1; i <= max_level; i ++) {
        cout << " " << res[i];
    }
    return 0;










    
}