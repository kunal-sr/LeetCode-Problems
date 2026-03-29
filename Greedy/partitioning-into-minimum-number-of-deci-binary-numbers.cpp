#include <bits/stdc++.h>
using namespace std;

int minPartitions(string n) {
    int maxDigit = 0;

    for (char c : n) {
        maxDigit = max(maxDigit, c - '0');
    }

    return maxDigit;
}

int main() {
    string n = "82734";
    cout << "Minimum deci-binary numbers: "
         << minPartitions(n) << endl;
    return 0;
}
