#include <iostream>
#include <unordered_set>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

string e[N];
int h1, h2, ne[N];

int n;
unordered_set<int> h1_set;

int main() {
    cin >> h1 >> h2 >> n;

    memset(ne, -1, sizeof ne);

    for (int i = 0; i < n; i ++) {
        string c;
        int add, ne_add;
        cin >> add >> c >> ne_add;

        e[add] = c;
        ne[add] = ne_add;
    }

    int l1 = h1;
    while (l1 != -1) {
        h1_set.insert(l1);
        l1 = ne[l1];
    }

    int l2 = h2;
    for (; l2 != -1; l2 = ne[l2]) {
        if (h1_set.count(l2))
            break;
    }
    if (l2 == -1)
        puts("-1");
    else printf("%05d", l2);

    return 0;
}