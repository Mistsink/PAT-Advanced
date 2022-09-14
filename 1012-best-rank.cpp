#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

const int N = 2010;
int n, q;

unordered_map<string, vector<int>> map;
vector<int> grades[4];

int getRank(vector<int> &arr, int tar) {
    for (int i = 0; i < arr.size(); i ++) {
        if (arr[i] == tar) return i +1;
    }
}

int main() {

    cin >> n >> q;

    string id;
    int c, m, e;
    for (int i = 0; i < n; i++) {
        cin >> id >> c >> m >> e;
        int t[4] = {round((c + m + e) / 3.0), c, m, e};
        for( int j = 0; j < 4; j ++) {
            map[id].push_back(t[j]);
            grades[j].push_back(t[j]);
        }
    }

    for (int i = 0; i < 4; i ++) sort(grades[i].begin(), grades[i].end(), less<int>()); 


    char courses[] = "ACME";
    while (q --)
    {
        cin >> id;
        if (map.count(id) == 0) puts("N/A");

        int rank = 999, rank_i = -1;
        for (int i = 0; i < 4; i ++) {
            int t_r = getRank(grades[i], map[id][i]);
            if (rank > t_r) {
                rank = t_r;
                rank_i = i;
            }
        }

        cout << rank << " " << courses[rank_i] << endl;
    }
    
    return 0;
}