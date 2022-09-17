#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    int n, tar;
    cin >> n >> tar;

    unordered_map<int, int> record;
    set<int> nums;
    for (int i = 0; i < n; i ++) {
        int t;
        cin >> t;
        nums.insert(t);
        if (record.count(t))
            record[t] ++;
        else record[t] = 1;
        
    }

    int v1, v2;
    for (auto i : nums) {
        v1 = i;
        if (v1 > tar) break;

        record[v1] --;

        v2 = tar - v1;
        if (record[v2] >= 1) {
            cout << v1 << " " << v2 << endl;
            return 0;
        }

        record[v1] ++;
    }

    puts("No Solution");

    return 0;
}