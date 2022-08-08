#include <iostream>
#include <vector>

using namespace std;

char trans(char const tar)
{
    switch (tar)
    {
    case '1':
        return '@';
    case '0':
        return '%';
    case 'l':
        return 'L';
    case 'O':
        return 'o';
    default:
        return tar;
    }
}

bool transStr(string &str) {
    bool is_modified = false;
    for (int i = 0; i < str.length(); ++i) {
        char c = trans(str[i]);

        if (c != str[i]) {
            if (!is_modified) is_modified = true;

            str[i] = c;
        }
    }
    return is_modified;
}

int main()
{
    int n, cnt = 0;
    cin >> n;

    string id, password;
    vector<string> ids, passwords;
    for (int i = 0; i < n; ++i) {
        cin >> id >> password;

        if (transStr(password)) {
            cnt ++;
            ids.push_back(id);
            passwords.push_back(password);
        }
    }

    if (cnt == 0 && n == 1) cout << "There is 1 account and no account is modified" << endl;
    else if (cnt == 0) cout << "There are "<< n <<" accounts and no account is modified" << endl;
    else {
        cout << cnt << endl;

        for (int i = 0; i < cnt; i ++) cout << ids[i] << " " << passwords[i] << endl;
    }
    
    return 0;
}