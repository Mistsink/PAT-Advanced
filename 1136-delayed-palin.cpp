#include <iostream>
#include <vector>

using namespace std;

bool is_palin(vector<int> &a) {
    for (int i = 0, j = a.size() - 1; i < j; i ++, j --) {
        if (a[i] != a[j]) return false;
    }
    return true;
}

string to_str(vector<int> &a) {
    string str;
    for (auto i : a) str += to_string(i);
    return str;
}

vector<int> add(vector<int> &a, vector<int> &b) {
    vector<int> res;

    int t = 0, s;
    for (int i = a.size() - 1; i >= 0; i--) {
        s = t + a[i] + b[i];
        t = s / 10;
        s %= 10;
        res.insert(res.begin(), s);
    }
    if (t)  res.insert(res.begin(), t);
    return res;
}

int main() {
    string n;
    cin >> n;
    vector<int> a, b, res;
    for (auto c: n) a.push_back(c - '0');
    res = a;

    int cnt = 0;
    while (!is_palin(res) && cnt < 10) {
        cnt ++;
        b = vector<int>(res.rbegin(), res.rend());

        a = res;
        res = add(res, b);

        cout << to_str(a) << " + " << to_str(b) << " = " << to_str(res) << endl;
    }

    if (!is_palin(res)) cout << "Not found in 10 iterations.\n";
    else cout << to_str(res) << " is a palindromic number.\n";

    return 0;
}