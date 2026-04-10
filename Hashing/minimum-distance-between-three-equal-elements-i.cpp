#include <bits/stdc++.h>
using namespace std;

int minimumDistance(vector<int>& nums) {
    unordered_map<int, vector<int>> mp;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        mp[nums[i]].push_back(i);
    }

    int ans = INT_MAX;

    for (auto &p : mp) {
        vector<int> &idx = p.second;

        if (idx.size() < 3) continue;

        for (int i = 0; i + 2 < idx.size(); i++) {
            int dist = 2 * (idx[i + 2] - idx[i]);
            ans = min(ans, dist);
        }
    }

    return (ans == INT_MAX) ? -1 : ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = minimumDistance(nums);
    cout << "Minimum Distance: " << result << endl;

    return 0;
}
