#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    // sort the array
    sort(nums.begin(), nums.end());

    int n = nums.size();

    // initial closest sum
    int closestSum = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < n; i++) {

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];

            // update closest sum if this is closer
            if (abs(currentSum - target) < abs(closestSum - target)) {
                closestSum = currentSum;
            }

            // move pointers
            if (currentSum < target) {
                left++;
            }
            else if (currentSum > target) {
                right--;
            }
            else {
                // exact match found
                return currentSum;
            }
        }
    }

    return closestSum;
}

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int result = threeSumClosest(nums, target);

    cout << "Closest sum to target: " << result << endl;

    return 0;
}
