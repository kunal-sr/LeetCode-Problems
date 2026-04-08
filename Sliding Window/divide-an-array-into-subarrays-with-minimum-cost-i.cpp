#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        vector<int> temp(nums.begin() + 1, nums.end());

        sort(temp.begin(), temp.end());

        int cost = nums[0];

        for (int i = 0; i < k - 1; i++) {
            cost += temp[i];
        }

        return cost;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,2,6,4,2};
    int k = 3;

    cout << sol.minimumCost(nums, k) << endl;
}
