#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 60;

unordered_set<int> sets[N];

void calSimilarity(int a, int b) {
    if (sets[a].size() > sets[b].size()) swap(a, b);

    int cnt = 0;
    for (auto i : sets[a])
        if (sets[b].count(i)) cnt ++;
    printf("%.1f%%\n",
     (double)cnt / (sets[a].size() + sets[b].size() - cnt) * 100.0);
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        int m;
        cin >> m;
        while (m --) {
            int t;
            cin >> t;
            sets[i].insert(t);
        }
    }

    int q;
    cin >> q;
    while (q --) {
        int a, b;
        cin >> a >> b;
        calSimilarity(a, b);
    }

    return 0;
}