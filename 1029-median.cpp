#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 4E5 + 10;
int a[N];
int main(){
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i ++ )    scanf("%d", &a[i]);
    cin >> m;
    for(int i = n; i < m + n; i ++ ) scanf("%d", &a[i]);
    sort(a, a + n + m);
    cout << a[m + n - 1 >> 1] << endl;
    return 0;
}