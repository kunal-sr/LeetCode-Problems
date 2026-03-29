#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBalancedSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int sum = 0, maxLen = 0;

        mp[0] = -1;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0) sum += -1;
            else sum += 1;

            if (mp.find(sum) != mp.end()) {
                maxLen = max(maxLen, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0, 1, 0, 1, 1, 0, 0};

    cout << sol.longestBalancedSubarray(nums) << endl;

    return 0;
}
