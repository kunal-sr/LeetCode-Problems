#include <bits/stdc++.h>
using namespace std;

int numSteps(string s) {
    int steps = 0;
    int carry = 0;

    for (int i = s.size() - 1; i > 0; i--) {
        int bit = s[i] - '0';

        if (bit + carry == 1) {

            steps += 2;
            carry = 1;
        } else {

            steps += 1;
        }
    }

    return steps + carry;
}

int main() {
    string s = "1101";
    cout << "Steps: " << numSteps(s) << endl;
    return 0;
}
