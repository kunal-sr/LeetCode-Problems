#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                int forward = (i - startIndex + n) % n;
                int backward = (startIndex - i + n) % n;
                ans = min(ans, min(forward, backward));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int main() {
    Solution sol;

    vector<string> words = {"hello", "i", "am", "leetcode", "hello"};
    string target = "hello";
    int startIndex = 1;

    int result = sol.closestTarget(words, target, startIndex);

    cout << "Output: " << result << endl;

    return 0;
}
