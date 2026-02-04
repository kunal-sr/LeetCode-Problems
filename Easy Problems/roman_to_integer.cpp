#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int total = 0;

    for (int i = 0; i < s.length(); i++) {
        // If current value is less than next value → subtract
        if (i + 1 < s.length() && roman[s[i]] < roman[s[i + 1]]) {
            total -= roman[s[i]];
        } else {
            total += roman[s[i]];
        }
    }

    return total;
}

int main() {
    string s;
    cout << "Enter Roman Numeral: ";
    cin >> s;

    cout << "Integer value: " << romanToInt(s) << endl;

    return 0;
}