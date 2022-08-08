#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    string src, tar;
    unordered_set<char> chars;

    // FEAT: 读取一行输入
    getline(cin, src);
    getline(cin, tar);
    for (auto c : tar) {
        chars.insert(c);
    }

    string res = "";
    for (auto c : src) {
        if (chars.find(c) != chars.end()) continue;

        res += c;
    }

    cout << res << endl;

    return 0;
}