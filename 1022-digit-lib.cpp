#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

unordered_map<string, set<string>> names, authors,
             keys, publisher, years;


void print(set<string>& s) {
    if (s.empty()) cout << "Not Found\n";
    
    for (auto t: s) {
        cout << t << "\n";
    }
}
int main() {
    int n, q;
    cin >> n;
    while(n --) {
        string s = "", id;
        cin >> id;
        getchar();
        getline(cin, s);
        names[s].insert(id);
        getline(cin, s);
        authors[s].insert(id);

        while(cin >> s) {
            keys[s].insert(id);

            if (getchar() == '\n')  break;
        }

        getline(cin, s);
        publisher[s].insert(id);
        getline(cin, s);
        years[s].insert(id);
    }

    cin >> q;
    
    getchar();
    while(q --) {
        string qs;
        getline(cin, qs);
        cout << qs << "\n";
        switch (stoi(qs.substr(0, 1))) {
            case 1:
                print(names[qs.substr(3)]);
                break;
            case 2:
                print(authors[qs.substr(3)]);
                break;
            case 3:
                print(keys[qs.substr(3)]);
                break;
            case 4:
                print(publisher[qs.substr(3)]);
                break;
            case 5:
                print(years[qs.substr(3)]);
                break;
        }
    }

    return 0;
}