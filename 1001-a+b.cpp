#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    //  FEAT: 数值转字符串用 to_string
    string res = to_string(a + b), ret = "";

    for (int i = res.length() -1, j = 0; i >= 0; i --) {
        ret = res[i] + ret;
        j ++;

        if (j % 3 == 0 && i && res[i-1] != '-') {
            j = 0;
            ret = ',' + ret;
        }
    }

    cout << ret << endl;

}