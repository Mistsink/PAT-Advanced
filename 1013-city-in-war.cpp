#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 1010;

int p[N];

struct Edge {
    int a;
    int b;
} e[(N * (N -1)) / 2 + 10];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int n, m, q;

int buildAndCheck (int ex) {
    for (int i = 1; i <= n; i ++) p[i] = i;

    int cnt = n - 1;
    for (int i = 0; i < m; i ++) {
        if (e[i].a == ex || e[i].b == ex)   continue;
        int pa = find(e[i].a), pb = find(e[i].b);
        
        if (pa != pb) {
            p[pb] = pa;
            cnt --;
        }
    }

    return cnt;
}
int main() {
    cin >> n >> m >> q;


    for (int i = 0; i < m; i ++) {
        int a, b;
        
        cin >> a >> b;
        
        if (a < b) swap(a, b);
        

        e[i] = {a, b};
    }
    
    

    while (q --) {
        int t;
        cin >> t;

        int num = buildAndCheck(t);
        cout << num - 1<< endl;
    }

    return 0;
}