#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;  // target found
        }
        else if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    // target not found, return insert position
    return low;
}

int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;

    int index = searchInsert(nums, target);

    cout << "Insert position is: " << index << endl;

    return 0;
}