#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int N = 1010;

void input(vector<double>& a) {
    int n;
    cin >> n;
    while(n--) {
        int d;
        double v;
        cin >> d >> v;
        a[d] = v;
    }
}

int main() {
    vector<double> a(N), b(N), res(2 * N);
    input(a);
    input(b);

    for (int i = 0; i < N; i ++) {
        if (!a[i]) continue;
        for (int j = 0; j < N; j ++) {
            if (!b[j]) continue;

            res[i + j] += a[i] * b[j];
        }
    }

    int n = 0;
    for (int i = 0; i < 2 * N; i ++) if (res[i]) n ++;

    cout << n;

    for (int i = N * 2; i >= 0; i --) {
        if (!res[i]) continue;

        // cout << " " << i << " " << res[i];
        printf(" %d %.1lf", i, res[i]);
    }
    cout << endl;

    return 0;
}