#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string Month;
vector<int> Tolls(24);

const int HOUR = 60;
const int DAY = 24 * HOUR;

typedef struct Record
{
    string timeS;
    int day;
    int hour;
    int min;
    int timeI;
    bool is_onLine;
}Record;
bool sortRecord(Record a, Record b)
{
    return a.timeI < b.timeI;
};
int calCost(Record begin, Record end)
{
    int res = 0;

    if (begin.day == end.day)
    {
        if (begin.hour < end.hour)
        {
            for (int i = begin.hour + 1; i < end.hour; i++)
            {
                res += Tolls[i] * HOUR;
            }

            res += (HOUR - begin.min) * Tolls[begin.hour];
            res += end.min * Tolls[end.hour];
        }
        else
        {
            res += (end.min - begin.min) * Tolls[begin.hour];
        }
    } else {
        for (int i = begin.day + 1; i < end.day; i++) {
            for (int j = 0; j < 24; j ++) {
                res += Tolls[j] * HOUR;
            }
        }

        for (int i = begin.hour + 1; i < 24; i++)
        {
            res += Tolls[i] * HOUR;
        }
        res += (HOUR - begin.min) * Tolls[begin.hour];

        for (int i = 0; i < end.hour; i++)
        {
            res += Tolls[i] * HOUR;
        }
        res += end.min * Tolls[end.hour];
    }

    return res;
}

typedef struct PairedRecord
{
    string timeBegin;
    string timeEnd;
    int du;
    int cost; // cents
}PairedRecord;

typedef struct Customer
{
    string name;
    vector<Record> records;
    vector<PairedRecord> pairs;
}Customer;

string transStr(int s)
{
    string res = to_string(s);
    if (res.size() < 2)
        res = "0" + res;
    return res;
}


string dollar(int tar) {
    return "$" + to_string(tar / 100) + "." + to_string(tar % 100);
}

map<string, Customer> cusMap;
int main()
{
    int t_i;
    for (int i = 0; i < 24; i++)
    {
        cin >> t_i;
        Tolls[i] = t_i;
    }

    int n;
    cin >> n;

    char t_name[25], t_onOrOffLine[25];
    // string name, onOrOffLine;
    int month, day, hour, min;
    for (int i = 0; i < n; i++)
    {
        // init customer
        scanf("%s %d:%d:%d:%d %s", &t_name, &month, &day, &hour, &min, &t_onOrOffLine);
        string name = t_name, onOrOffLine = t_onOrOffLine;

        // cout << onOrOffLine << " " << (onOrOffLine == "on-line") << endl;

        if (Month.empty())
            Month = transStr(month);

        if (cusMap.find(name) == cusMap.end())
        {
            Customer customer = Customer{
                name,
                // vector<Record>(0),
                // vector<PairedRecord>(0),
            };

            customer.records.push_back(Record{
                transStr(day) + ":" + transStr(hour) + ":" + transStr(min),
                day,
                hour,
                min,
                day * DAY + hour * HOUR + min,
                onOrOffLine == "on-line",
            });

            cusMap[name] = customer;

            // cout << "init" << cusMap[name].name << endl;
        }
        else
        {
            // Customer *customer = &cusMap[name];

            cusMap[name].records.push_back(Record{
                transStr(day) + ":" + transStr(hour) + ":" + transStr(min),
                day,
                hour,
                min,
                day * DAY + hour * HOUR + min,
                onOrOffLine == "on-line",
            });
            // cout << "\n push " << day << " " << hour << " " << min << "\t";

            // for (auto j : cusMap[name].records) {
            //     cout << j.timeS << " " << j.timeI << "========";
            // }
            // cout << endl;
        }
    }

    // sort & find pairs
    for (auto &i : cusMap)
    {

        sort(i.second.records.begin(), i.second.records.end(), sortRecord);
        
        // cout << i.first << endl;
        // for (auto j : i.second.records) {
        //     cout << "\t" << j.timeS << j.timeI << "\t" << j.is_onLine << endl;
        // }

        for (int j = 0; j < i.second.records.size() - 1; j++)
        {
            if (!i.second.records[j].is_onLine) continue;

            if (i.second.records[j + 1].is_onLine)
                continue;

            // cal pair
            Record begin = i.second.records[j], end = i.second.records[j + 1];
            int duration = end.timeI - begin.timeI;
            int cost = calCost(begin, end);
            i.second.pairs.push_back(PairedRecord{
                transStr(begin.day) + ":" + transStr(begin.hour) + ":" + transStr(begin.min),
                transStr(end.day) + ":" + transStr(end.hour) + ":" + transStr(end.min),
                duration,
                cost,
            });
        }

        // for (auto j : i.second.pairs) {
        //     cout << "pair :\t" << j.timeBegin << endl;
        // }
    }

    // print
    for (auto i : cusMap) {
        if (i.second.pairs.size() > 0) {
            cout << i.first << " " << Month << endl;

            int tol_cost = 0;
            for (auto j : i.second.pairs) {
                tol_cost += j.cost;
                cout << j.timeBegin << " " << j.timeEnd << " " << j.du << " " << dollar(j.cost) << endl;
            }
            cout << "Total amount: " << dollar(tol_cost) << endl;
        }
    }

    return 0;
}