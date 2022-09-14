#include <iostream>
#include <unordered_map>
#include <queue>
#include <cstring>

using namespace std;
const int N = 40;
int h[N], e[N], ne[N], idx;
int n;

int l[N], r[N];

int ins[N], posts[N]; 
unordered_map<int, int> map, posOfIns;

//  [l, r]
int build(int ins_l, int ins_r, int post_l, int post_r) {
    int root = posts[post_r];

    int pos_r = posOfIns[root];

    if (pos_r > ins_l)
        l[root] = build(ins_l, pos_r-1, post_l, post_l + (pos_r-1-ins_l));
    if (pos_r < ins_r)
        r[root] = build(pos_r + 1, ins_r, post_l + (pos_r-1-ins_l) + 1, post_r -1);

    return root;
}   

void bfs(int root) {
    queue<int> q;
    q.push(root);

    bool is_first = true;
    while (q.size()) {
        int t = q.front();
        q.pop();

        if (is_first) {
            cout << t;
            is_first = false;
        } else cout << " " << t;

        if (l[t] != -1) q.push(l[t]);
        if (r[t] != -1) q.push(r[t]);
    }
}
int main() {
    cin >> n;
    
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);

    for (int i = 0; i < n; i ++) {
        cin >> posts[i];
    }

    for (int i = 0; i < n; i ++) {
        cin >> ins[i];
        posOfIns[ins[i]] = i;
    }

    int root = build(0, n-1, 0, n-1);

    bfs(root);

    return 0;
}