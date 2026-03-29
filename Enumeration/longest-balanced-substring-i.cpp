#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalancedSubstring(string s) {
        int n = s.size();
        int i = 0;
        int maxLen = 0;

        while (i < n) {
            int count0 = 0, count1 = 0;

            while (i < n && s[i] == '0') {
                count0++;
                i++;
            }

            while (i < n && s[i] == '1') {
                count1++;
                i++;
            }
            maxLen = max(maxLen, 2 * min(count0, count1));
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    string s = "001110011";

    cout << sol.longestBalancedSubstring(s) << endl;

    return 0;
}
