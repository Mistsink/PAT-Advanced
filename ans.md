# 第一章 字符串处理

## 1	AcWing 1473. A + B 格式	PAT甲级真题1001

![image-20220801234752261](https://s2.loli.net/2022/08/09/OF7fpwMBrAdLhDS.png)

```c++
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c = a + b;
    string num = to_string(c);
    string res;

    for (int i = num.size() - 1, j = 0; i >= 0; i -- )
    {
        res = num[i] + res;
        ++ j;
        if (j % 3 == 0 && i && num[i - 1] != '-') res = ',' + res;
    }
    
    cout << res << endl;
    
    return 0;

}
```

## 2	AcWing 1477. 拼写正确	PAT甲级真题1005

![image-20220801235849969](https://s2.loli.net/2022/08/09/1tJh38zMTL9iYgn.png)

```c++
#include <iostream>

using namespace std;

int main()
{
    string n;
    cin >> n;

    int s = 0;
    for (auto c : n) s += c - '0';  // 计算每一位的总和
    
    string str = to_string(s);
    
    char word[10][10] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine",
    };
    
    cout << word[str[0] - '0'];
    for (int i = 1; i < str.size(); i ++ ) cout << ' ' << word[str[i] - '0'];
    
    return 0;

}
```

## 3	AcWing 1478. 签到与签出 	PAT甲级真题1006

![image-20220801235917376](https://s2.loli.net/2022/08/09/pvVf8esYlgIH6Gq.png)

```c++
#include <iostream>

using namespace std;

int main()
{
    string open_id, open_time;
    string close_id, close_time;

    int m;
    cin >> m;
    
    for (int i = 0; i < m; i ++ )
    {
        string id, in_time, out_time;
        cin >> id >> in_time >> out_time;
    
        // 更新开门的人
        if (!i || in_time < open_time)
        {
            open_id = id;
            open_time = in_time;
        }
    
        // 更新锁门的人
        if (!i || out_time > close_time)
        {
            close_id = id;
            close_time = out_time;
        }
    }
    
    cout << open_id << ' ' << close_id << endl;
    
    return 0;

}
```

## 4	AcWing 1519. 密码	PAT甲级真题1035

![image-20220801235817043](https://s2.loli.net/2022/08/09/GKrMiD4Qhaq76A3.png)

```c++
#include <iostream>

using namespace std;

const int N = 1010;

string name[N], pwd[N];

string change(string str)
{
    string res;

​    for (auto c : str)
​        if (c == '1') res += '@';
​        else if (c == '0') res += '%';
​        else if (c == 'l') res += 'L';
​        else if (c == 'O') res += 'o';
​        else res += c;
​    
​    return res;

}

int main()
{
    int n;
    cin >> n;

​    int m = 0;
​    for (int i = 0; i < n; i ++ )
​    {
​        string cur_name, cur_pwd;
​        cin >> cur_name >> cur_pwd;
​        string changed_pwd = change(cur_pwd);
​    
​        if (changed_pwd != cur_pwd)
​        {
​            name[m] = cur_name;
​            pwd[m] = changed_pwd;
​            m ++ ;
​        }
​    }
​    
​    if (!m)
​    {
​        if (n == 1) puts("There is 1 account and no account is modified");
​        else printf("There are %d accounts and no account is modified\n", n);
​    }
​    else
​    {
​        cout << m << endl;
​        for (int i = 0; i < m; i ++ ) cout << name[i] << ' ' << pwd[i] << endl;
​    }
​    
​    return 0;

}
```



## 5	AcWing 1520. 男孩 vs 女孩	PAT甲级真题1006

![image-20220802000016025](https://s2.loli.net/2022/08/09/yOThVsBfHeCSWDQ.png)

```c++
#include <iostream>

using namespace std;

int main()
{
    int n;

​    string girl_name, girl_id;  // 女生第一名的信息
​    int girl_score;
​    string boy_name, boy_id;  // 男生第一名的信息
​    int boy_score;
​    
​    cin >> n;
​    for (int i = 0; i < n; i ++ )
​    {
​        string name, sex, id;
​        int score;
​        cin >> name >> sex >> id >> score;
​    
​        if (sex == "F")  // 如果当前同学是女生
​        {
​            if (girl_name.empty() || girl_score < score)
​            {
​                girl_name = name;
​                girl_id = id;
​                girl_score = score;
​            }
​        }
​        else  // 男生
​        {
​            if (boy_name.empty() || boy_score > score)
​            {
​                boy_name = name;
​                boy_id = id;
​                boy_score = score;
​            }
​        }
​    }
​    
​    if (girl_name.empty()) puts("Absent");
​    else cout << girl_name << ' ' << girl_id << endl;
​    
​    if (boy_name.empty()) puts("Absent");
​    else cout << boy_name << ' ' << boy_id << endl;
​    
​    if (girl_name.size() && boy_name.size()) cout << girl_score - boy_score << endl;
​    else cout << "NA" << endl;
​    
​    return 0;

}
```

## 6	AcWing 1534. 字符串减法	PAT甲级真题1050

![image-20220802000232720](https://s2.loli.net/2022/08/09/SbaeyWt9chpHV8Q.png)

```c++
#include <iostream>
#include <unordered_set>

using namespace std;

string s1, s2;

int main()
{
    getline(cin, s1);
    getline(cin, s2);

    unordered_set<char> hash;  // 定义哈希表
    for (auto c : s2) hash.insert(c);  // 将s2中的字符插入哈希表
    
    string res;
    for (auto c : s1)
        if (!hash.count(c))
            res += c;
    
    cout << res << endl;
    
    return 0;

}
```



## 7	AcWing 1557. 说话方式	PAT甲级真题1071

![image-20220802000515108](https://s2.loli.net/2022/08/09/OEYl1xKs693LVDU.png)

```
#include <iostream>
#include <unordered_map>

using namespace std;

bool check(char c)
{
    if (c >= '0' && c <= '9') return true;
    if (c >= 'A' && c <= 'Z') return true;
    if (c >= 'a' && c <= 'z') return true;
    return false;
}

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}

int main()
{
    string str;
    getline(cin, str);

    unordered_map<string, int> hash;
    
    for (int i = 0; i < str.size(); i ++ )
        if (check(str[i]))
        {
            string word;
            int j = i;
            while (j < str.size() && check(str[j])) word += to_lower(str[j ++ ]);
    
            hash[word] ++ ;
            i = j;
        }
    
    string word;
    int cnt = -1;
    for (auto item : hash)
        if (item.second > cnt || item.second == cnt && item.first < word)
        {
            word = item.first;
            cnt = item.second;
        }
    
    cout << word << ' ' << cnt << endl;
    
    return 0;

}
```



## 8	AcWing 1547. 约会	PAT甲级真题1061

![image-20220802000558372](https://s2.loli.net/2022/08/09/kUXgSL3zcuQ8tpV.png)

```c++
#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    string a, b, c, d;
    cin >> a >> b >> c >> d;

    int k = 0;
    while (true)
    {
        if (a[k] == b[k] && a[k] >= 'A' && a[k] <= 'G') break;
        k ++ ;
    }

    char weekdays[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    printf("%s ", weekdays[a[k] - 'A']);

    k ++ ;
    while (true)
    {
        if (a[k] == b[k] && (a[k] >= '0' && a[k] <= '9' || a[k] >= 'A' && a[k] <= 'N')) break;
        k ++ ;
    }

    printf("%02d:", a[k] <= '9' ? a[k] - '0' : a[k] - 'A' + 10);

    for (int i = 0;; i ++ )
        if (c[i] == d[i] && (c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z'))
        {
            printf("%02d\n", i);
            break;
        }

    return 0;
}


```



## 9	AcWing 1493. 电话账单	PAT甲级真题1016

![image-20220802000641768](https://s2.loli.net/2022/08/09/pO24ELPgkCKNq19.png)

```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int N = 1010, M = 31 * 1440 + 10;

int n;
int cost[24];  // 每个时间段的话费
double sum[M];  // 从当月1号00:00开始到每个时刻所花费的钱数

struct Record
{
    int minutes;
    string state;
    string format_time;

    bool operator< (const Record& t) const
    {
        return minutes < t.minutes;
    }
};

map<string, vector<Record>> persons;

int main()
{
    for (int i = 0; i < 24; i ++ ) cin >> cost[i];
    for (int i = 1; i < M; i ++ ) sum[i] = sum[i - 1] + cost[(i - 1) % 1440 / 60] / 100.0;

    cin >> n;
    char name[25], state[10], format_time[20];
    int month, day, hour, minute;
    for (int i = 0; i < n; i ++ )
    {
        scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minute, state);
        sprintf(format_time, "%02d:%02d:%02d", day, hour, minute);

        int minutes = (day - 1) * 1440 + hour * 60 + minute;
        persons[name].push_back({minutes, state, format_time});
    }

    for (auto &person : persons)
    {
        auto name = person.first;
        auto records = person.second;
        sort(records.begin(), records.end());

        double total = 0;
        for (int i = 0; i + 1 < records.size(); i ++ )
        {
            auto a = records[i], b = records[i + 1];
            if (a.state == "on-line" && b.state == "off-line")
            {
                if (!total) printf("%s %02d\n", name.c_str(), month);
                cout << a.format_time << ' ' << b.format_time;

                double c = sum[b.minutes] - sum[a.minutes];
                printf(" %d $%.2lf\n", b.minutes - a.minutes, c);
                total += c;
            }
        }

        if (total) printf("Total amount: $%.2lf\n", total);
    }

    return 0;
}

```



## 10	AcWing 1494. 银行排队	PAT甲级真题1017

![image-20220802000741828](https://s2.loli.net/2022/08/09/9bklPW25g6MYXTq.png)

```
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 10010, M = 110;

int n, m;

struct Person
{
    int arrive_time;
    int service_time;

    bool operator< (const Person& t) const  // 按到达时间排序
    {
        return arrive_time < t.arrive_time;
    }
}persons[N];

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i ++ )
    {
        int hour, minute, second, service_time;
        scanf("%d:%d:%d %d", &hour, &minute, &second, &service_time);
        service_time = min(service_time, 60);

        persons[i] = {hour * 3600 + minute * 60 + second, service_time * 60};
    }

    priority_queue<int, vector<int>, greater<int>> windows;

    for (int i = 0; i < m; i ++ ) windows.push(8 * 3600);  // 先把m个窗口安排好

    sort(persons, persons + n);

    int sum = 0, cnt = 0;

    for (int i = 0; i < n; i ++ )
    {
        auto person = persons[i];
        int w = windows.top();
        windows.pop();
        if (person.arrive_time > 17 * 3600) break;  // 来晚了，则忽略

        int start_time = max(person.arrive_time, w);
        sum += start_time - person.arrive_time;
        cnt ++ ;

        windows.push(start_time + person.service_time);
    }

    printf("%.1lf\n", (double)sum / cnt / 60);

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/262814/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 11	AcWing 1503. 乒乓球	PAT甲级真题1026

![image-20220802000831046](https://s2.loli.net/2022/08/09/fPVegaCdITY2s59.png)

```
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

const int N = 10010, M = 110, INF = 1000000;

int n, k, m;

struct Person  // 球员
{
    int arrive_time, play_time;
    int start_time, waiting_time;

    bool operator< (const Person& t) const  // sort排序
    {
        if (start_time != t.start_time) return start_time < t.start_time;
        return arrive_time < t.arrive_time;
    }

    bool operator> (const Person& t) const  // 优先队列中比较大小
    {
        return arrive_time > t.arrive_time;
    }
};

struct Table  // 球桌
{
    int id;
    int end_time;

    bool operator> (const Table& t) const  // 优先队列中比较大小
    {
        if (end_time != t.end_time) return end_time > t.end_time;
        return id > t.id;
    }
};

bool is_vip_table[M];
int table_cnt[M];

vector<Person> persons;

void assign(priority_queue<Person, vector<Person>, greater<Person>>& ps,
            priority_queue<Table, vector<Table>, greater<Table>>& ts)
{
    auto p = ps.top(); ps.pop();
    auto t = ts.top(); ts.pop();
    p.waiting_time = round((t.end_time - p.arrive_time) / 60.0);
    p.start_time = t.end_time;
    table_cnt[t.id] ++ ;
    persons.push_back(p);
    ts.push({t.id, t.end_time + p.play_time});
}

string get_time(int secs)
{
    char str[20];
    sprintf(str, "%02d:%02d:%02d", secs / 3600, secs % 3600 / 60, secs % 60);
    return str;
}

int main()
{
    cin >> n;

    priority_queue<Person, vector<Person>, greater<Person>> normal_persons;
    priority_queue<Person, vector<Person>, greater<Person>> vip_persons;

    normal_persons.push({INF});
    vip_persons.push({INF});

    for (int i = 0; i < n; i ++ )
    {
        int hour, minute, second;
        int play_time, is_vip;
        scanf("%d:%d:%d %d %d", &hour, &minute, &second, &play_time, &is_vip);

        int secs = hour * 3600 + minute * 60 + second;
        play_time = min(play_time, 120);
        play_time *= 60;

        if (is_vip) vip_persons.push({secs, play_time});
        else normal_persons.push({secs, play_time});
    }

    priority_queue<Table, vector<Table>, greater<Table>> normal_tables;
    priority_queue<Table, vector<Table>, greater<Table>> vip_tables;
    normal_tables.push({-1, INF});
    vip_tables.push({-1, INF});

    cin >> k >> m;
    for (int i = 0; i < m; i ++ )
    {
        int id;
        cin >> id;
        is_vip_table[id] = true;
    }

    for (int i = 1; i <= k; i ++ )
        if (is_vip_table[i]) vip_tables.push({i, 8 * 3600});
        else normal_tables.push({i, 8 * 3600});

    while (normal_persons.size() > 1 || vip_persons.size() > 1)
    {
        auto np = normal_persons.top();
        auto vp = vip_persons.top();
        int arrive_time = min(np.arrive_time, vp.arrive_time);

        while (normal_tables.top().end_time < arrive_time)  // O(klogk)
        {
            auto t = normal_tables.top();
            normal_tables.pop();
            t.end_time = arrive_time;
            normal_tables.push(t);
        }
        while (vip_tables.top().end_time < arrive_time)
        {
            auto t = vip_tables.top();
            vip_tables.pop();
            t.end_time = arrive_time;
            vip_tables.push(t);
        }

        auto nt = normal_tables.top();
        auto vt = vip_tables.top();
        int end_time = min(nt.end_time, vt.end_time);

        if (end_time >= 21 * 3600) break;

        if (vp.arrive_time <= end_time && vt.end_time == end_time) assign(vip_persons, vip_tables);
        else if (np.arrive_time < vp.arrive_time)
        {
            if (nt > vt) assign(normal_persons, vip_tables);
            else assign(normal_persons, normal_tables);
        }
        else
        {
            if (nt > vt) assign(vip_persons, vip_tables);
            else assign(vip_persons, normal_tables);
        }
    }

    sort(persons.begin(), persons.end());

    for (auto person : persons)
    {
        cout << get_time(person.arrive_time) << ' ' << get_time(person.start_time) << ' ';
        cout << person.waiting_time << endl;
    }

    cout << table_cnt[1];
    for (int i = 2; i <= k; i ++ ) cout << ' ' << table_cnt[i];
    cout << endl;
    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/262962/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 12	AcWing 1546. 它们是否相等	PAT甲级真题1060

![image-20220802000938028](https://s2.loli.net/2022/08/09/Jx1Vqde7f6luhLg.png)

```
#include <iostream>
#include <cstring>

using namespace std;

string change(string a, int n)
{
    int k = a.find(".");
    if (k == -1) a += '.', k = a.find(".");

    string s = a.substr(0, k) + a.substr(k + 1);
    while (s.size() && s[0] == '0') s = s.substr(1), k -- ;

    if (s.empty()) k = 0;
    if (s.size() > n) s = s.substr(0, n);
    else s += string(n - s.size(), '0');

    return "0." + s + "*10^" + to_string(k);
}

int main()
{
    int n;
    string a, b;
    cin >> n >> a >> b;

    a = change(a, n);
    b = change(b, n);

    if (a == b) cout << "YES " << a << endl;
    else cout << "NO " << a << ' ' << b << endl;

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/317838/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 13	AcWing 1559. 科学计数法

![image-20220802001045577](https://s2.loli.net/2022/08/09/fsuEW8r47aLPenq.png)

```
#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    if (s[0] == '-') cout << '-';

    int k = s.find("E");
    string a = s[1] + s.substr(3, k - 3);
    int b = stoi(s.substr(k + 1));
    b ++ ;

    if (b <= 0) a = "0." + string(-b, '0') + a;
    else if (b >= a.size()) a += string(b - a.size(), '0');
    else a = a.substr(0, b) + '.' + a.substr(b);

    cout << a << endl;

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/317851/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 14	AcWing 1563. Kuchiguse	PAT甲级真题1077

![image-20220802001255020](https://s2.loli.net/2022/08/09/Tv4Uj7wDPtWp1yo.png)

```
#include <iostream>

using namespace std;

const int N = 110;

int n;
string s[N];

int main()
{
    cin >> n;
    getchar();
    for (int i = 0; i < n; i ++ ) getline(cin, s[i]);

    for (int k = s[0].size(); k; k -- )
    {
        string sf = s[0].substr(s[0].size() - k);
        bool is_matched = true;

        for (int i = 1; i < n; i ++ )
            if (k > s[i].size() || s[i].substr(s[i].size() - k) != sf)
            {
                is_matched = false;
                break;
            }

        if (is_matched)
        {
            cout << sf << endl;
            return 0;
        }
    }

    puts("nai");

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/317855/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 15	AcWing 1568. 中文读数字	PAT甲级真题1082

![image-20220802001343372](https://s2.loli.net/2022/08/09/hRirnlC1SF4PmxE.png)

```
#include <iostream>
#include <vector>

using namespace std;

string num1[] = {
    "ling", "yi", "er", "san", "si",
    "wu", "liu", "qi", "ba", "jiu"
};

bool check(string s)  // 判断末尾是否是 "ling "
{
    return s.size() >= 5 && s.substr(s.size() - 5) == "ling ";
}

string work(int n)
{
    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;

    string num2[] = {"", "Shi", "Bai", "Qian"};
    string res;

    for (int i = nums.size() - 1; i >= 0; i -- )
    {
        int t = nums[i];
        if (t) res += num1[t] + ' ';
        else if (!check(res)) res += "ling ";
        if (t && i) res += num2[i] + ' ';
    }

    if (check(res)) res = res.substr(0, res.size() - 5);

    return res;
}

int main()
{
    int n;
    cin >> n;

    if (!n) puts("ling");
    else
    {
        if (n < 0) cout << "Fu ", n = -n;

        vector<int> nums;

        string num3[] = {"", "Wan", "Yi"};
        while (n) nums.push_back(n % 10000), n /= 10000;

        string res;
        for (int i = nums.size() - 1; i >= 0; i -- )
        {
            int t = nums[i];
            if (res.size() && t < 1000 && !(res.size() >= 5 && res.substr(res.size() - 5) == "ling ")) res += "ling ";
            if (t) res += work(t);
            if (t && i) res += num3[i] + ' ';
        }

        while (check(res)) res = res.substr(0, res.size() - 5);

        res.pop_back();
        cout << res << endl;
    }

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/317871/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 16	AcWing 1570. 坏掉的键盘	PAT甲级真题1084

![image-20220802001425367](https://s2.loli.net/2022/08/09/fhqkvERd4je5AgV.png)

```
#include <iostream>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    bool st[200] = {0};
    b += '#';
    for (int i = 0, j = 0; i < a.size(); i ++ )
    {
        char x = toupper(a[i]), y = toupper(b[j]);
        if (x == y) j ++ ;
        else
        {
            if (!st[x]) cout << x, st[x] = true;
        }
    }

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/323458/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 17	AcWing 1598. 求平均值	PAT甲级真题1108

![image-20220802001458968](https://s2.loli.net/2022/08/09/48JKPUSmEph5dY3.png)

```
#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int cnt = 0;
    double sum = 0;

    while (n -- )
    {
        string num;
        cin >> num;
        double x;

        bool success = true;
        try
        {
            size_t idx;
            x = stof(num, &idx);

            if (idx < num.size()) success = false;
        }
        catch(...)
        {
            success = false;
        }

        if (x < -1000 || x > 1000) success = false;
        int k = num.find('.');
        if (k != -1 && num.size() - k > 3) success = false;

        if (success) cnt ++, sum += x;
        else printf("ERROR: %s is not a legal number\n", num.c_str());
    }

    if (cnt > 1) printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
    else if (cnt == 1) printf("The average of 1 number is %.2lf\n", sum);
    else puts("The average of 0 numbers is Undefined");

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/323460/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 18	AcWing 1617. 微博转发抽奖	PAT甲级真题1124

![image-20220802001550870](https://s2.loli.net/2022/08/09/kFsojDp3JuyBCEv.png)

```
#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 1010;

int m, n, s;
string name[N];

int main()
{
    cin >> m >> n >> s;
    for (int i = 1; i <= m; i ++ ) cin >> name[i];

    unordered_set<string> hash;
    int k = s;
    while (k <= m)
    {
        if (hash.count(name[k])) k ++ ;
        else
        {
            cout << name[k] << endl;
            hash.insert(name[k]);
            k += n;
        }
    }

    if (hash.empty()) puts("Keep going...");

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/323472/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 19	AcWing 1634. PAT单位排行

![image-20220802001636911](https://s2.loli.net/2022/08/09/OlIC5EW8wPd4Hys.png)

```
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct School
{
    string name;
    int cnt;
    double sum;

    School(): cnt(0), sum(0) {}

    bool operator< (const School &t) const
    {
        if (sum != t.sum) return sum > t.sum;
        if (cnt != t.cnt) return cnt < t.cnt;
        return name < t.name;
    }
};

int main()
{
    int n;
    cin >> n;

    unordered_map<string, School> hash;
    while (n -- )
    {
        string id, sch;
        double grade;
        cin >> id >> grade >> sch;

        for (auto& c : sch) c = tolower(c);

        if (id[0] == 'B') grade /= 1.5;
        else if (id[0] == 'T') grade *= 1.5;

        hash[sch].sum += grade;
        hash[sch].cnt ++ ;
        hash[sch].name = sch;
    }

    vector<School> schools;
    for (auto item : hash)
    {
        item.second.sum = (int)(item.second.sum + 1e-8);
        schools.push_back(item.second);
    }

    sort(schools.begin(), schools.end());
    cout << schools.size() << endl;

    int rank = 1;
    for (int i = 0; i < schools.size(); i ++ )
    {
        auto s = schools[i];
        if (i && s.sum != schools[i - 1].sum) rank = i + 1;
        printf("%d %s %d %d\n", rank, s.name.c_str(), (int)s.sum, s.cnt);
    }

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/323490/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 20	AcWing 1647. 解码PAT准考证

![image-20220802001731129](https://s2.loli.net/2022/08/09/XncrI7FLMY2biTD.png)

```
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 10010;

int n, m;
struct Person
{
    string id;
    int grade;

    bool operator< (const Person &t) const
    {
        if (grade != t.grade) return grade > t.grade;
        return id < t.id;
    }
}p[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++ ) cin >> p[i].id >> p[i].grade;

    for (int k = 1; k <= m; k ++ )
    {
        string t, c;
        cin >> t >> c;

        printf("Case %d: %s %s\n", k, t.c_str(), c.c_str());
        if (t == "1")
        {
            vector<Person> persons;
            for (int i = 0; i < n; i ++ )
                if (p[i].id[0] == c[0])
                    persons.push_back(p[i]);

            sort(persons.begin(), persons.end());

            if (persons.empty()) puts("NA");
            else
                for (auto person : persons) printf("%s %d\n", person.id.c_str(), person.grade);
        }
        else if (t == "2")
        {
            int cnt = 0, sum = 0;
            for (int i = 0; i < n; i ++ )
                if (p[i].id.substr(1, 3) == c)
                {
                    cnt ++ ;
                    sum += p[i].grade;
                }

            if (!cnt) puts("NA");
            else printf("%d %d\n", cnt, sum);
        }
        else
        {
            unordered_map<string, int> hash;
            for (int i = 0; i < n; i ++ )
                if (p[i].id.substr(4, 6) == c)
                    hash[p[i].id.substr(1, 3)] ++ ;

            vector<pair<int, string>> rooms;
            for (auto item : hash) rooms.push_back({-item.second, item.first});

            sort(rooms.begin(), rooms.end());
            if (rooms.empty()) puts("NA");
            else
                for (auto room : rooms)
                    printf("%s %d\n", room.second.c_str(), -room.first);
        }
    }

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/323501/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

# 第二章 高精度

## 1	AcWing 1474. 多项式 A + B

![image-20220802002036190](https://s2.loli.net/2022/08/09/2EKmJpCHB1qGgfe.png)

```
#include <iostream>

using namespace std;

const int N = 1010;

double a[N], b[N], c[N];

int main()
{
    int k;

    cin >> k;
    while (k -- )  // 读入第一个多项式
    {
        int n;
        double v;
        cin >> n >> v;
        a[n] = v;
    }

    cin >> k;
    while (k -- )  // 读入第二个多项式
    {
        int n;
        double v;
        cin >> n >> v;
        b[n] = v;
    }

    // 求和
    for (int i = 0; i < N; i ++ ) c[i] = a[i] + b[i];

    k = 0;
    for (int i = 0; i < N; i ++ )
        if (c[i])
            k ++ ;

    cout << k;
    for (int i = N - 1; i >= 0; i -- )
        if (c[i])
            printf(" %d %.1lf", i, c[i]);

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/269747/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 2	AcWing 1481. 多项式乘积

![image-20220802002106912](https://s2.loli.net/2022/08/09/dA3aUWVwtKzYgoe.png)

```
#include <iostream>

using namespace std;

const int N = 1010;

double a[N], b[N], c[N * 2];

void input(double a[])
{
    int k;
    cin >> k;
    while (k -- )
    {
        int n;
        double v;
        cin >> n >> v;
        a[n] = v;
    }
}

int main()
{
    input(a);
    input(b);

    // 做乘法
    for (int i = 0; i < N; i ++ )
        for (int j = 0; j < N; j ++ )
            c[i + j] += b[i] * a[j];

    int k = 0;
    for (int i = 0; i < N * 2; i ++ )
        if (c[i])
            k ++ ;

    cout << k;
    for (int i = N * 2 - 1; i >= 0; i -- )
        if (c[i])
            printf(" %d %.1lf", i, c[i]);

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/269766/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 3	AcWing 1500. 趣味数字

![image-20220802002146796](https://s2.loli.net/2022/08/09/sRFtWZreYO8KNDl.png)

```
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string A;
    vector<int> a;

    cin >> A;
    for (int i = A.size() - 1; i >= 0; i -- ) a.push_back(A[i] - '0');

    vector<int> b;
    int t = 0;
    for (int i = 0; i < a.size(); i ++ )
    {
        int s = a[i] + a[i] + t;
        b.push_back(s % 10);
        t = s / 10;
    }
    if (t) b.push_back(t);
    vector<int> c = b;
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());

    if (a == c) puts("Yes");
    else puts("No");

    for (int i = b.size() - 1; i >= 0; i -- ) cout << b[i];

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/269793/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 4	AcWing 1501. 回文数

![image-20220802002222381](https://s2.loli.net/2022/08/09/tm3ODAVBgTC4WI6.png)

```
#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>& num)
{
    for (int i = 0, j = num.size() - 1; i < j; i ++, j -- )
        if (num[i] != num[j])
            return false;
    return true;
}

vector<int> add(vector<int>& a, vector<int>& b)
{
    vector<int> c;
    for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i ++ )
    {
        int s = t;
        if (i < a.size()) s += a[i];
        if (i < b.size()) s += b[i];
        c.push_back(s % 10);
        t = s / 10;
    }
    return c;
}

int main()
{
    string n;
    int k;
    cin >> n >> k;

    vector<int> a;
    for (int i = n.size() - 1; i >= 0; i -- ) a.push_back(n[i] - '0');

    int cnt = 0;
    if (!check(a))
    {
        while (cnt < k)
        {
            vector<int> b(a.rbegin(), a.rend());
            a = add(a, b);
            cnt ++ ;
            if (check(a)) break;
        }
    }

    for (int i = a.size() - 1; i >= 0; i -- ) cout << a[i];

    cout << endl << cnt << endl;

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/269816/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 5	AcWing 1544. 霍格沃茨的 A + B       

![image-20220802002327695](https://s2.loli.net/2022/08/09/8iBfchomFqlHgsX.png)    

```
#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);
    a += d, b += e, c += f;

    b += c / 29, c %= 29;
    a += b / 17, b %= 17;

    printf("%d.%d.%d\n", a, b, c);

    return 0;
}
```



## 6	AcWing 1629. 延迟的回文数

![image-20220802002307521](https://s2.loli.net/2022/08/09/oNmQh6uC3Yt1q8s.png)

```
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool check(vector<int> A)
{
    for (int i = 0, j = A.size() - 1; i < j; i ++, j -- )
        if (A[i] != A[j])
            return false;
    return true;
}

void print(vector<int> A)
{
    for (int i = A.size() - 1; i >= 0; i -- ) cout << A[i];
}

vector<int> add(vector<int> A, vector<int> B)
{
    vector<int> C;
    for (int i = 0, t = 0; i < A.size() || i < B.size() || t; i ++ )
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }

    return C;
}

int main()
{
    string a;
    cin >> a;

    vector<int> A;
    for (int i = 0; i < a.size(); i ++ ) A.push_back(a[a.size() - 1 - i] - '0');

    for (int i = 0; i < 10; i ++ )
    {
        if (check(A)) break;
        vector<int> B(A.rbegin(), A.rend());

        print(A), cout << " + ", print(B), cout << " = ";
        A = add(A, B);

        print(A), cout << endl;
    }

    if (check(A)) print(A), cout << " is a palindromic number." << endl;
    else puts("Not found in 10 iterations.");

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/323515/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

# 第三章 进制

## 1.进制

![image-20220809131012279](https://s2.loli.net/2022/08/09/vjYtI1nWx7rLo9l.png)

```c++
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;


int get(char c)
{
    if (c <= '9') return c - '0';
    return c - 'a' + 10;
}


LL calc(string n, LL r)
{
    LL res = 0;
    for (auto c : n)
    {
        if ((double)res * r + get(c) > 1e16) return 1e18;
        res = res * r + get(c);
    }
    return res;
}


int main()
{
    string n1, n2;
    cin >> n1 >> n2;
    int tag, radix;
    cin >> tag >> radix;

    if (tag == 2) swap(n1, n2);
    LL target = calc(n1, radix);

    LL l = 0, r = max(target, 36ll);
    for (auto c : n2) l = max(l, (LL)get(c) + 1);

    while (l < r)
    {
        LL mid = l + r >> 1;
        if (calc(n2, mid) >= target) r = mid;
        else l = mid + 1;
    }

    if (calc(n2, r) != target) puts("Impossible");
    else cout << r << endl;

    return 0;
}
```

## 2.1492. 可逆质数

![image-20220809131221365](https://s2.loli.net/2022/08/09/w4cRCQidByDhoFL.png)

```c++
#include <iostream>

using namespace std;

typedef long long LL;

bool is_prime(int n)
{
    if (n == 1) return false;

    for (int i = 2; i * i <= n; i ++ )
        if (n % i == 0)
            return false;
    return true;
}

bool check(int n, int d)
{
    if (!is_prime(n)) return false;

    LL r = 0;
    while (n)
    {
        r = r * d + n % d;
        n /= d;
    }

    return is_prime(r);
}

int main()
{
    int n, d;
    while (cin >> n >> d, n >= 1)
    {
        if (check(n, d)) puts("Yes");
        else puts("No");
    }

    return 0;
}
```

## 3. 1504. 火星颜色

![image-20220809131329755](https://s2.loli.net/2022/08/09/2efqvY8THUtP5rJ.png)

```c++
#include <iostream>

using namespace std;

char get(int x)
{
    if (x <= 9) return '0' + x;
    return 'A' + x - 10;
}

int main()
{
    int a[3];
    for (int i = 0; i < 3; i ++ ) scanf("%d", &a[i]);

    cout << '#';

    for (int i = 0; i < 3; i ++ ) cout << get(a[i] / 13) << get(a[i] % 13);

    return 0;
}
```

## 4. 1590. 火星数字

![image-20220809131421624](https://s2.loli.net/2022/08/09/CTXNJuqpMAHas4Z.png)

```c++
#include <iostream>
#include <sstream>

using namespace std;

char names[][5] = {
    "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
};

int get(string word)
{
    for (int i = 0; i < 25; i ++ )
        if (names[i] == word)
        {
            if (i < 13) return i;
            return (i - 12) * 13;
        }
    return -1;  // 一定不会执行
}

int main()
{
    int n;
    cin >> n;
    getchar();

    while (n -- )
    {
        string line;
        getline(cin, line);

        stringstream ssin(line);
        if (line[0] <= '9')
        {
            int v;
            ssin >> v;
            if (v < 13) cout << names[v] << endl;
            else
            {
                cout << names[12 + v / 13];
                if (v % 13 == 0) cout << endl;
                else cout << ' ' << names[v % 13] << endl;
            }
        }
        else
        {
            int res = 0;
            string word;
            while (ssin >> word) res += get(word);
            cout << res << endl;
        }
    }

    return 0;
}
```

## 5. 1496. 普通回文数

![image-20220809131636671](https://s2.loli.net/2022/08/09/hGB8sviSaR3DOLQ.png)

```c++
#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

bool check()
{
    for (int i = 0, j = nums.size() - 1; i < j; i ++, j -- )
        if (nums[i] != nums[j])
            return false;

    return true;
}

int main()
{
    int n, b;
    cin >> n >> b;

    if (!n) nums.push_back(0);
    while (n) nums.push_back(n % b), n /= b;

    if (check()) puts("Yes");
    else puts("No");

    cout << nums.back();
    for (int i = nums.size() - 2; i >= 0; i -- ) cout << ' ' << nums[i];

    return 0;
}
```

# 第四章 排序

## 1. 最佳排名

![image-20220809131934433](https://s2.loli.net/2022/08/09/dQCsptXUAw7eaxv.png)

```c++
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cmath>

using namespace std;

unordered_map<string, vector<int>> grades;
vector<int> q[4];  // A: q[0], C: q[1], M: q[2], E: q[3]

int get_rank(vector<int>& a, int x)
{
    int l = 0, r = a.size() - 1;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (a[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return a.size() - r;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i ++ )
    {
        string id;
        int t[4] = {0};
        cin >> id;
        for (int j = 1; j < 4; j ++ )
        {
            cin >> t[j];
            t[0] += t[j];
        }
        t[0] = round(t[0] / 3.0);
        for (int j = 0; j < 4; j ++ )
        {
            q[j].push_back(t[j]);
            grades[id].push_back(t[j]);
        }
    }

    for (int i = 0; i < 4; i ++ ) sort(q[i].begin(), q[i].end());

    char names[] = "ACME";
    while (m -- )
    {
        string id;
        cin >> id;
        if (grades.count(id) == 0) puts("N/A");
        else
        {
            int res = n + 1;
            char c;
            for (int i = 0; i < 4; i ++ )
            {
                int rank = get_rank(q[i], grades[id][i]);
                if (rank < res)
                {
                    res = rank;
                    c = names[i];
                }
            }
            cout << res << ' ' << c << endl;
        }
    }

    return 0;
}
```



## 2. 数字图书馆

![image-20220809132008937](https://s2.loli.net/2022/08/09/rLTbYglcXqyD73M.png)

```c++
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

struct Book
{
    string id, name, author;
    set<string> keywords;
    string publisher, year;
};

int main()
{
    int n, m;
    cin >> n;

    vector<Book> books;
    while (n -- )
    {
        string id, name, author;
        cin >> id;
        getchar();
        getline(cin, name), getline(cin, author);
        string line;
        getline(cin, line);
        stringstream ssin(line);
        string keyword;
        set<string> keywords;
        while (ssin >> keyword) keywords.insert(keyword);
        string publisher, year;
        getline(cin, publisher);
        cin >> year;
        books.push_back({id, name, author, keywords, publisher, year});
    }

    cin >> m;
    getchar();
    string line;
    while (m -- )
    {
        getline(cin, line);
        cout << line << endl;
        string info = line.substr(3);
        char t = line[0];
        vector<string> res;
        if (t == '1')
        {
            for (auto& book : books)
                if (book.name == info)
                    res.push_back(book.id);
        }
        else if (t == '2')
        {
            for (auto& book : books)
                if (book.author == info)
                    res.push_back(book.id);
        }
        else if (t == '3')
        {
            for (auto& book : books)
                if (book.keywords.count(info))
                    res.push_back(book.id);
        }
        else if (t == '4')
        {
            for (auto& book : books)
                if (book.publisher == info)
                    res.push_back(book.id);
        }
        else
        {
            for (auto& book : books)
                if (book.year == info)
                    res.push_back(book.id);
        }

        if (res.empty()) puts("Not Found");
        else
        {
            sort(res.begin(), res.end());
            for (auto id : res) cout << id << endl;
        }
    }

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/272621/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 3. PAT排名

![image-20220809132054106](https://s2.loli.net/2022/08/09/1feqOydpM8WiNEL.png)

```c++
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 110;

struct Student
{
    string id;
    int grade;
    int location_number, local_rank, final_rank;

    bool operator< (const Student& t) const
    {
        if (grade != t.grade) return grade > t.grade;
        return id < t.id;
    }
};

vector<Student> grades[N];
vector<Student> all;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j ++ )
        {
            string id;
            int grade;
            cin >> id >> grade;
            grades[i].push_back({id, grade, i});
        }

        auto& g = grades[i];
        sort(g.begin(), g.end());
        for (int i = 0; i < g.size(); i ++ )
        {
            if (!i || g[i].grade != g[i - 1].grade)
                g[i].local_rank = i + 1;
            else
                g[i].local_rank = g[i - 1].local_rank;
            all.push_back(g[i]);
        }
    }

    sort(all.begin(), all.end());
    for (int i = 0; i < all.size(); i ++ )
        if (!i || all[i].grade != all[i - 1].grade)
            all[i].final_rank = i + 1;
        else
            all[i].final_rank = all[i - 1].final_rank;

    cout << all.size() << endl;
    for (auto& s : all)
        cout << s.id << ' ' << s.final_rank << ' ' << s.location_number << ' ' << s.local_rank << endl;

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/272643/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 4. 列表排序

![image-20220809132139669](https://s2.loli.net/2022/08/09/BSapfsAYTv1RyIP.png)

```c++
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;

struct Row
{
    string id, name;
    int grade;
}rows[N];

bool cmp1(Row a, Row b)
{
    return a.id < b.id;
}

bool cmp2(Row a, Row b)
{
    if (a.name != b.name) return a.name < b.name;
    return a.id < b.id;
}

bool cmp3(Row a, Row b)
{
    if (a.grade != b.grade) return a.grade < b.grade;
    return a.id < b.id;
}

int main()
{
    int c;
    scanf("%d%d", &n, &c);
    char id[10], name[10];
    for (int i = 0; i < n; i ++ )
    {
        int grade;
        scanf("%s%s%d", id, name, &grade);
        rows[i] = {id, name, grade};
    }

    if (c == 1) sort(rows, rows + n, cmp1);
    else if (c == 2) sort(rows, rows + n, cmp2);
    else sort(rows, rows + n, cmp3);

    for (int i = 0; i < n; i ++ )
        printf("%s %s %d\n", rows[i].id.c_str(), rows[i].name.c_str(), rows[i].grade);

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/272659/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 5. 学生课程列表

![image-20220809132227731](https://s2.loli.net/2022/08/09/9hmCY7legtrS68N.png)

```c++

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, vector<int>> students;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    while (k -- )
    {
        int id, m;
        cin >> id >> m;
        while (m -- )
        {
            string name;
            cin >> name;
            students[name].push_back(id);
        }
    }

    while (n -- )
    {
        string name;
        cin >> name;

        auto& ls = students[name];
        cout << name << ' ' << ls.size();
        sort(ls.begin(), ls.end());

        for (auto l : ls) cout << ' ' << l;
        cout << endl;
    }

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/272679/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 6. 链表排序

![image-20220809132301566](https://s2.loli.net/2022/08/09/6Ut3Tg4kSVYEdza.png)

```c++
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node
{
    string address;
    int key;
    string next;

    bool operator< (const Node& t) const
    {
        return key < t.key;
    }
};

int main()
{
    int n;
    char head[10];
    scanf("%d%s", &n, head);

    unordered_map<string, Node> map;
    char address[10], next[10];
    while (n -- )
    {
        int key;
        scanf("%s%d%s", address, &key, next);
        map[address] = {address, key, next};
    }

    vector<Node> nodes;
    for (string i = head; i != "-1"; i = map[i].next) nodes.push_back(map[i]);

    printf("%d ", nodes.size());
    if (nodes.empty()) puts("-1");
    else
    {
        sort(nodes.begin(), nodes.end());
        printf("%s\n", nodes[0].address.c_str());
        for (int i = 0; i < nodes.size(); i ++ )
        {
            if (i + 1 == nodes.size())
                printf("%s %d -1\n", nodes[i].address.c_str(), nodes[i].key);
            else
                printf("%s %d %s\n", nodes[i].address.c_str(), nodes[i].key, nodes[i + 1].address.c_str());
        }
    }

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/272708/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 7. PAT评测

![image-20220809132337266](https://s2.loli.net/2022/08/09/JteyUDfVrM26dFB.png)

```c++
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node
{
    string address;
    int key;
    string next;

    bool operator< (const Node& t) const
    {
        return key < t.key;
    }
};

int main()
{
    int n;
    char head[10];
    scanf("%d%s", &n, head);

    unordered_map<string, Node> map;
    char address[10], next[10];
    while (n -- )
    {
        int key;
        scanf("%s%d%s", address, &key, next);
        map[address] = {address, key, next};
    }

    vector<Node> nodes;
    for (string i = head; i != "-1"; i = map[i].next) nodes.push_back(map[i]);

    printf("%d ", nodes.size());
    if (nodes.empty()) puts("-1");
    else
    {
        sort(nodes.begin(), nodes.end());
        printf("%s\n", nodes[0].address.c_str());
        for (int i = 0; i < nodes.size(); i ++ )
        {
            if (i + 1 == nodes.size())
                printf("%s %d -1\n", nodes[i].address.c_str(), nodes[i].key);
            else
                printf("%s %d %s\n", nodes[i].address.c_str(), nodes[i].key, nodes[i + 1].address.c_str());
        }
    }

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/272708/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 8. 插入还是堆排序

![image-20220809132425787](https://s2.loli.net/2022/08/09/NZStyBmOzHsnb4X.png)

```c++
#include <iostream>

using namespace std;

const int N = 110;

int n;
int a[N], b[N];

void down(int u, int size)
{
    int t = u;
    if (u * 2 <= size && b[t] < b[u * 2]) t = u * 2;
    if (u * 2 + 1 <= size && b[t] < b[u * 2 + 1]) t = u * 2 + 1;
    if (t != u)
    {
        swap(b[t], b[u]);
        down(t, size);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];

    int p = 2;
    while (p <= n && b[p] >= b[p - 1]) p ++ ;
    int k = p;
    while (p <= n && a[p] == b[p]) p ++ ;
    if (p == n + 1)  // 说明是插入排序
    {
        puts("Insertion Sort");
        while (k > 1 && b[k] < b[k - 1]) swap(b[k], b[k - 1]), k -- ;
    }
    else  // 否则说明一定是堆排序
    {
        puts("Heap Sort");
        p = n;
        while (b[1] <= b[p]) p -- ;
        swap(b[1], b[p]);
        down(1, p - 1);
    }

    cout << b[1];
    for (int i = 2; i <= n; i ++ ) cout << ' ' << b[i];
    cout << endl;

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/272766/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



## 9. 插入还是归并

![image-20220809132452152](https://s2.loli.net/2022/08/09/LlfajJioWgs75UK.png)

```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int a[N], b[N];

bool check()
{
    for (int i = 0; i < n; i ++ )
        if (a[i] != b[i])
            return false;
    return true;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];
    for (int i = 0; i < n; i ++ ) cin >> b[i];

    int k = 0;
    while (b[k + 1] >= b[k]) k ++ ;

    bool match = true;
    for (int i = k + 1; i < n; i ++ )
        if (a[i] != b[i])
        {
            match = false;
            break;
        }

    if (match)
    {
        puts("Insertion Sort");
        sort(b, b + k + 2);
        cout << b[0];
        for (int i = 1; i < n; i ++ ) cout << ' ' << b[i];
        cout << endl;
    }
    else
    {
        puts("Merge Sort");

        int k = 1;
        while (true)
        {
            bool match = check();

            int len = 1 << k;
            for (int i = 0; i < n; i += len)
                sort(a + i, a + min(n, i + len));

            if (match) break;
            k ++ ;
        }

        cout << a[0];
        for (int i = 1; i < n; i ++ ) cout << ' '<< a[i];
        cout << endl;
    }

    return 0;
}

作者：yxc
链接：https://www.acwing.com/activity/content/code/content/323536/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```

