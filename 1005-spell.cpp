#include <iostream>

using namespace std;

string formart_arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    string n;
    cin >> n;

    int sum = 0;

    for (int i = 0; i < n.length(); i++) {
        sum += n[i] - '0';
    }

    string sum_str = to_string(sum);

    cout << formart_arr[sum_str[0] - '0'];
    for (int i = 1; i < sum_str.length(); i++) {
        cout << " " << formart_arr[sum_str[i] - '0'];
    }
   
    cout << endl;
    return 0;
}