#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    // Step 1: Replace negative numbers and numbers greater than n
    for (int i = 0; i < n; i++) {
        if (nums[i] <= 0 || nums[i] > n) {
            nums[i] = n + 1;
        }
    }

    // Step 2: Mark existing numbers
    for (int i = 0; i < n; i++) {
        int val = abs(nums[i]);

        if (val >= 1 && val <= n) {
            nums[val - 1] = -abs(nums[val - 1]);
        }
    }

    // Step 3: Find the first positive index
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            return i + 1;
        }
    }

    return n + 1;
}

int main() {
    vector<int> nums = {3, 4, -1, 1};

    int result = firstMissingPositive(nums);

    cout << "First missing positive number: " << result << endl;

    return 0;
}