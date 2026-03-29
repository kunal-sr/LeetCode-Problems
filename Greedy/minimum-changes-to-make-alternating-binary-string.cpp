#include <bits/stdc++.h>
using namespace std;

int minOperations(string s) {
    int n = s.size();
    int diff1 = 0, diff2 = 0;

    for (int i = 0; i < n; i++) {
        char expected1 = (i % 2 == 0) ? '0' : '1';
        char expected2 = (i % 2 == 0) ? '1' : '0';

        if (s[i] != expected1) diff1++;
        if (s[i] != expected2) diff2++;
    }

    return min(diff1, diff2);
}

int main() {
    string s = "0100";
    cout << "Minimum changes: " << minOperations(s) << endl;
    return 0;
}
