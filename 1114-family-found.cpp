#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

const int N = 10010;

int n;

struct Family {
    int cnt;
    int m_estate;
    int area;
} fs[N];

struct Res {
    int id;
    int cnt;
    double avg_sets;
    double avg_area;

    bool operator< (const Res& o) const {
        if (avg_area != o.avg_area) return avg_area > o.avg_area;
        return id < o.id;
    }
};

unordered_map<int, Family> all_f;
set<int> peoples;

int p[N];
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

string refine_str(string tar) {
    while (tar.size() != 4) {
        tar = '0' + tar;
    }
    return tar;
}

int main() {

    cin >> n;

    for (int i = 0; i < N; i ++) p[i] = i;

    for (int i = 0; i < n; i ++) {
        string id;
        int father, mother, k;
        cin >> id >> father >> mother >> k;
        peoples.insert(stoi(id));
        vector<string> childs;
        string child_id;
        int pid = find(stoi(id)), min_id = pid;

        
        while (k --) {
            cin >> child_id;
            peoples.insert(stoi(child_id));
            childs.push_back(child_id);
            min_id = min(min_id, find(stoi(child_id)));
        }

        int m_estate, area;
        cin >> m_estate >> area;

        if (~father) {
            min_id = min(min_id, find(father));
            peoples.insert(father);
        }
        if (~mother) {
            min_id = min(min_id, find(mother));
            peoples.insert(mother);
        }
        p[find(pid)] = min_id;
        if (~father) p[find(father)] = min_id;
        if (~mother) p[find(mother)] = min_id;
        for (auto j : childs) {
            p[find(stoi(j))] = min_id;
        }

        all_f[stoi(id)] = {-1, m_estate, area};
    }

    unordered_map<int, Family> res_f;

    for (int i: peoples) {
        int pid = find(i);
        
        res_f[pid].cnt ++;
        if (!all_f.count(i)) continue;
        res_f[pid].m_estate += all_f[i].m_estate;
        res_f[pid].area += all_f[i].area;
    }

    vector<Res> res;
    for (auto i: res_f) {
        int id = i.first;
        Family f = i.second;
        res.push_back({id, f.cnt, f.m_estate * 1.0 / f.cnt, f.area * 1.0 / f.cnt});
    }

    sort(res.begin(), res.end());

    cout << res.size() << endl;
    for (auto i : res) {
        printf("%04d %d %.3lf %.3lf\n", i.id, i.cnt, i.avg_sets, i.avg_area);
    }

    return 0;
}
