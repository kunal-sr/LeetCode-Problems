#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int currentSum = 0;
    int maxSum = nums[0];

    for (int i = 0; i < nums.size(); i++) {
        currentSum += nums[i];

        // update maximum sum
        maxSum = max(maxSum, currentSum);

        // reset if current sum becomes negative
        if (currentSum < 0) {
            currentSum = 0;
        }
    }

    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArray(nums);

    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}