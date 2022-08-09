#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int get(char c)
{
    if (c <= '9') return c - '0';
    return c - 'a' + 10;
}


ll trans_10_ll(string a, ll radix) {
    ll res = 0;

    for (auto c: a) {
        // (double) 转型能存入更多的数字，防止计算溢出导致错误！！！！！！！
        if ((double)res * radix + get(c) > 1e16) return 1e18;
        res = radix * res + get(c);
    }

    return res;
}

int main() {
    string n1, n2, t;
    ll tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    t = n1;

    if (tag == 2) {
        swap(n1, n2);
    }

    ll n1_ll = trans_10_ll(n1, radix);

    ll l = 0, r = max(36ll, n1_ll + 1);
    for (auto c : n2) l = max(l, (ll)get(c) + 1);

    while (l < r) {

        ll mid = l + r >> 1;

        ll res = trans_10_ll(n2, mid);
        
        if (res >= n1_ll) {
            r = mid;
        } else l = mid + 1;
    }

    if (trans_10_ll(n2, r) == n1_ll) cout << r << endl;
    else cout << "Impossible\n";


    return 0;
}