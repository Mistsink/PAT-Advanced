#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int nums[N];
int ne[N], e[N];

int n, start, k;

int main() {
    cin >> start >> n >> k;

    int add, data, next;
    for (int i = 0; i < n; i ++) {
        cin >> add >> data >> next;

        e[add] = data;
        ne[add] = next;
    }

    int l = start, i =0;
    for (; l != -1; i ++, l = ne[l]) {
        nums[i] = l;
    }
    nums[i] = -1;
    i ++;

    int j = 0;
    for (;j + k < i; j += k) reverse(nums + j, nums + j + k);
    
    int k = 0;
    for (; k < i - 2; k ++) {
        printf("%05d %d %05d\n", nums[k], e[nums[k]], nums[k+1]);
    }
    printf("%05d %d -1", nums[k], e[nums[k]]);

    return 0;
}