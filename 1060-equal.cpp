#include <iostream>
using namespace std;

string change(string& s, int n) {
    int k = s.find('.');
    if (k == -1) s += '.', k  = s.find('.');

    s = s.substr(0, k) + s.substr(k + 1);
    while(s.size() && s[0] == '0') s = s.substr(1), k --;
    
    if (s.empty()) k = 0;
    if (s.size() < n) s += string(n - s.size(), '0');
    else s = s.substr(0, n);


    return  "0." + s + "*10^" + to_string(k);
}

int main() {
    int n;
    string a, b;
    cin >> n >> a >> b;

    a = change(a, n);
    b = change(b, n);

    if (a == b) cout << "YES " << a << endl;
    else cout << "NO " << a << " " << b << endl;

    return 0;
}