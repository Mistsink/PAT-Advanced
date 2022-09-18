#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4 + 10;

string nums[N];

bool cmp(string &a, string &b) {
    return a + b < b + a;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
    }

    sort(nums, nums + n, cmp);
    
    string res;
    for (int i = 0; i < n; i ++) res += nums[i];

    bool is_start = true;
    for (auto c : res) {
        if (is_start && c == '0') {
            continue;
        }
        is_start = false;
        cout << c;
        
    }

    if (is_start) puts("0");

    return 0;
}