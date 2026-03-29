#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;
    mp[0] = -1;

    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < nums.size(); i++) {
        // convert 0 → -1
        if (nums[i] == 0)
            sum -= 1;
        else
            sum += 1;

        if (mp.find(sum) != mp.end()) {
            maxLen = max(maxLen, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    vector<int> nums = {0, 1, 0, 1, 1, 0, 0};
    cout << "Longest balanced subarray: "
         << findMaxLength(nums) << endl;
    return 0;
}
