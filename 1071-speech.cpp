#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool is_al(char c) {
    if (c <= 'z' && c >= 'a') return true;
    if (c <= '9' && c >= '0') return true;

    return false;
}


int main() {
    string speech;
    
    getline(cin, speech);

    // 是否是字母
    bool isAl = false, is_end = false, is_started = false;
    unordered_map<string, int> words;

    string word = "";
    for (auto c : speech) {        
        c = char(tolower(c));
        if (!is_al(c)) {

            if (word.empty()) continue;

            words[word] ++;
            word = "";
        } else word += c;
    }
    if (!word.empty()) words[word] ++;

    int cnt = 0;
    word = "";
    for (auto i : words) {
        // cout << i.first << " " << i.second << endl;
        if (i.second > cnt) {
            word = i.first;
            cnt = i.second;
        } else if (i.second == cnt && word > i.first) {
            word = i.first;
        } else continue;
    }

    cout << word << " " << cnt << endl;

    return 0;
}