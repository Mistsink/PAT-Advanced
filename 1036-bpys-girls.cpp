#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    cin >> n;

    string high_f_name, low_m_name, high_f_id, low_m_id;
    int high_f_grade = -1, low_m_grade = 999;

    string name, gender, id;
    int grade;
    for (int i = 0; i < n; i++) {
        cin >> name >> gender >> id >> grade;

        if (gender == "M") {
            if (grade < low_m_grade) {
                low_m_name = name;
                low_m_grade = grade;
                low_m_id = id;
            }
        } else {
            if (grade > high_f_grade) {
                high_f_name = name;
                high_f_grade = grade;
                high_f_id  = id;
            }
        }
    }

    //  FEAT: 字符串判空用 empty
    if (!high_f_id.empty()) cout << high_f_name << " " << high_f_id << endl;
    else cout << "Absent" << endl;

    if (!low_m_id.empty()) cout << low_m_name << " " << low_m_id << endl;
    else cout << "Absent" << endl;

    if (!high_f_id.empty() && !low_m_id.empty()) cout << abs(high_f_grade - low_m_grade) << endl;
    else cout << "NA" << endl;

    return 0;
}