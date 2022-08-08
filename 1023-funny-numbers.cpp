#include <iostream>
#include <unordered_map>
using namespace std;

string doubleed(string v) {
    string res;

    int c = 0, t = 0;
    char ch;
    for (int i = v.size() - 1; i >= 0; i --) {
        t = (v[i] - '0') + (v[i] - '0') + c;
        c = t / 10;
        t %= 10;
        ch = '0' + t;
        res = ch + res;
    }

    if (c) {
        ch = '0' + c;
        res = ch + res;
    }

    return res;
}

int main() {
    string n;
    cin >> n;

    unordered_map<int, int> number_map;
    for (auto c: n) {
        if (number_map.find(c - '0') != number_map.end())  number_map[c - '0'] += 1;
        else number_map[c - '0'] = 1;
    }

    string res = doubleed(n);
    
    bool ok = true;
    for (auto c: res) {
        number_map[c - '0'] -= 1;
    }
    for (auto number: number_map) {
        if (number.second) {
            ok = false;
            break;
        }
    }

    if (ok) {
        if (res == n) ok = false;
    }

    if (ok) cout << "Yes\n" << res << endl;
    else cout << "No\n" << res << endl;



    return 0;
}