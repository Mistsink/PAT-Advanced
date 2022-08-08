#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int gn = 1010;
int input(vector<double>& a) {
    int n;
    cin >> n;

    int max_d, d;
    double v;
    cin >> d >> v;
    max_d = d;
    a[d] = v;
    n --;
    while(n--) {
        cin >> d >> v;
        a[d] = v;
    }
    return max_d;
}

int main() {
    vector<double> M(gn), N(gn), res(gn);

    // cout << M.size() << "===========" << M[0] << endl;

    int d1 = input(M), d2 = input(N);



    for(int i = 0; i <= gn; i ++) {
        if (M[i] != 0.0 || N[i] != 0.0) {
            res[i] = M[i] + N[i];
        }
    }
    
    int n = 0;
    for(auto i: res) if (i) n ++;
    cout << n;
    for(int i = gn; i >= 0; i --) {
        if (res[i] != 0) {
            printf(" %d %.1lf", i, res[i]);
        }
    }
    cout << endl;

    return 0;
}