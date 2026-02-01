#include <bits/stdc++.h>
using namespace std;

bool searchTarget(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // if target found
        if (nums[mid] == target) {
            return true;
        }

        // if we can't decide due to duplicates
        if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
            left++;
            right--;
        }
        // left side is sorted
        else if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        // right side is sorted
        else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return false;
}

int main() {
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    bool found = searchTarget(nums, target);

    if (found) {
        cout << "Target found in array" << endl;
    } else {
        cout << "Target not found in array" << endl;
    }

    return 0;
}