#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int k = 0;  // pointer for placing elements

    for (int i = 0; i < nums.size(); i++) {
        // keep element if less than 2 elements are placed
        // or current element is different from nums[k - 2]
        if (k < 2 || nums[i] != nums[k - 2]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    int k = removeDuplicates(nums);

    cout << "k = " << k << endl;
    cout << "Modified array: ";

    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}