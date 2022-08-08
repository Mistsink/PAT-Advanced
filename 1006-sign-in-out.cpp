#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string lock_id, lock_time = "0", unlock_id, unlock_time = "999999999";
    string id, in_time, out_time;

    for (int i = 0; i < n; i ++) {
        cin >> id >> in_time >> out_time;

        //  find lock-man
        if (out_time > lock_time) {
            lock_time = out_time;
            lock_id = id;
        }

        //  find unlock-man
        if (in_time < unlock_time) {
            unlock_time = in_time;
            unlock_id = id;
        }
    }
    cout << unlock_id << " " << lock_id << endl;

    return 0;
}