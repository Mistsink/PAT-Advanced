#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
int main() {
    vector<int> a(3), b(3), res(3);

    scanf("%d.%d.%d %d.%d.%d", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);

    int t = 0;
    res[2] = a[2] + b[2];
    t = res[2] / 29;
    res[2] %= 29;

    res[1] = a[1] + b[1] + t;
    t = res[1] / 17;
    res[1] %= 17;

    res[0] = a[0] + b[0] + t;

    printf("%d.%d.%d\n", res[0], res[1], res[2]);
    
    return 0;
}