#include <bits/stdc++.h>
using namespace std;

int reverseNum(int x) {
    int rev = 0;
    while (x > 0) {
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev;
}

int minMirrorPairDistance(vector<int>& nums) {
    unordered_map<int, int> mp; // value -> last index
    int ans = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
        int rev = reverseNum(nums[i]);

        if (mp.find(rev) != mp.end()) {
            ans = min(ans, i - mp[rev]);
        }

        mp[nums[i]] = i;
    }

    return (ans == INT_MAX) ? -1 : ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = minMirrorPairDistance(nums);
    cout << result << endl;

    return 0;
}
