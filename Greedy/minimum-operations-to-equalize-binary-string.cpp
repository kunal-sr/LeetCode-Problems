#include <bits/stdc++.h>
using namespace std;

int minOperations(string s) {
    int groups = 1;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            groups++;
        }
    }

    return groups - 1;
}

int main() {
    string s = "00110011";
    cout << "Minimum operations: " << minOperations(s) << endl;
    return 0;
}
