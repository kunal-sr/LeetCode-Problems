#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int index = -1;

    // Step 1: find first element from right which is smaller than next
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }

    // Step 2: find just larger element and swap
    if (index != -1) {
        for (int i = n - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
    }

    // Step 3: reverse the remaining part
    reverse(nums.begin() + index + 1, nums.end());
}

int main() {
    vector<int> nums = {1, 2, 3};

    nextPermutation(nums);

    // print result
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}