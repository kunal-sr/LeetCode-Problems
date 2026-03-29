#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {

                int bits = __builtin_popcount(h) + __builtin_popcount(m);

                if (bits == turnedOn) {

                    string time = to_string(h) + ":";

                    if (m < 10) time += "0";
                    time += to_string(m);

                    result.push_back(time);
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    int turnedOn = 1;
    vector<string> ans = sol.readBinaryWatch(turnedOn);

    for (auto &t : ans) {
        cout << t << endl;
    }

    return 0;
}
