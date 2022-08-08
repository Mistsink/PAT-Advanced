#include <iostream>
#include <vector>

using namespace std;

bool is_palin(vector<int> a) {
    for (int i = 0, j = a.size() -1; i < j; i ++, j --) {
        if (a[i] != a[j]) return false;
    }
    return true;
}

vector<int> add(vector<int> a, vector<int> b) {
    vector<int> res;

    int t = 0, s = 0;  // 进位
    for (int i = a.size() - 1; i >= 0; i --) {
        s = a[i] + b[i] + t;
        res.insert(res.begin(), s % 10);
        t = s / 10;
    }
    if (t) res.insert(res.begin(), t);

    return res;
}


int main() {
    string n;
    int steps;
    cin >> n >> steps;

    vector<int> a(n.size()), b(n.size());
    for (int i = 0; i < n.size(); i ++) {
        a[i] = n[i] - '0';
    }

    int cnt = 0;
    while(!is_palin(a) && cnt < steps) {
        cnt ++;
        b = vector<int>(a.rbegin(), a.rend());
        // for (auto i : a)
        //     cout << i;
        // cout << endl;
        // for (auto i : b)
        //     cout << i;
        // cout << endl;
        a = add(a, b);
    }

    for (auto i: a) cout << i;
    cout << "\n" << cnt << endl;

    return 0;
}