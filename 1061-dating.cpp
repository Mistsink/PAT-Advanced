#include <iostream>

using namespace std;

string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

bool is_cap(char tar) {
    return tar <= 'Z' && tar >= 'A';
}

bool is_week(char tar) {
    return tar <= 'G' && tar >= 'A';
}


bool is_letter(char tar) {
    return (tar >= 'a' && tar <= 'z') || (tar <= 'Z' && tar >= 'A');
}

bool is_num(char tar) {
    return (tar <= '9' && tar >= '0');
}
bool is_hour(char tar) {
    return (tar <= 'N' && tar >= 'A') || is_num(tar);
}

bool is_common(char tar) {
    return is_letter(tar) || is_num(tar);
}

int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();

    string weekDate;
    int hour, minute;

    //  travel s1
    for (int i = 0; i < len1; i++) {
        // for week day
        if (weekDate.empty()) {
            if (is_week(s1[i])) {
                if (s1[i] == s2[i]) weekDate = week[s1[i] - 'A'];
                else continue;
            } else continue;
        } else {
            // for hour
            if (is_hour(s1[i]) && s1[i] == s2[i]) {
                if (is_cap(s1[i])) {
                    hour = 10 + (s1[i] - 'A');
                } else if (is_num(s1[i])) {
                    hour = s1[i] - '0';
                } else continue;
                break;

            } else continue;
        }
    }


    // travel 
    for (int i = 0; i < len3; i ++) {
        if (is_letter(s3[i]) && s3[i] == s4[i]) {
            minute = i;
            break;
        }
    }

    string hour_s = to_string(hour);
    if (hour_s.size() < 2) hour_s = "0" + hour_s;
    string hour_m = to_string(minute);
    if (hour_m.size() < 2) hour_m = "0" + hour_m;
    
    cout << weekDate << " " << hour_s << ":" << hour_m << endl;

    return 0;
}