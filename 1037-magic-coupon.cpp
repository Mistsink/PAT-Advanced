#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> add_coupon, div_coupon;
vector<int> add_good, div_good;


int main() {
    cin >> n;
    int t;
    for (int i = 0; i < n; i ++) {
        cin >> t;
        if (t == 0) continue;
        if (t < 0) div_coupon.push_back(abs(t));
        if (t > 0) add_coupon.push_back(t);
    }

    cin >> m;
    for (int i = 0; i < m; i ++) {
        cin >> t;
        if (t == 0) continue;
        if (t < 0) div_good.push_back(abs(t));
        if (t > 0) add_good.push_back(t);
    }

    sort(add_coupon.begin(), add_coupon.end(), greater<int>());
    sort(div_coupon.begin(), div_coupon.end(), greater<int>());
    sort(add_good.begin(), add_good.end(), greater<int>());
    sort(div_good.begin(), div_good.end(), greater<int>());

    int res = 0;
    while (add_coupon.size() && add_good.size()) {
        res += add_coupon[0] * add_good[0];
        add_coupon.erase(add_coupon.begin());
        add_good.erase(add_good.begin());
    }

    while (div_coupon.size() && div_good.size()) {
        res += div_coupon[0] * div_good[0];
        div_coupon.erase(div_coupon.begin());
        div_good.erase(div_good.begin());
    }

    cout << res;

    return 0;
}