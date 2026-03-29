#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false; 

        int i = 0;

        while (i + 1 < n && nums[i] < nums[i + 1]) {
            i++;
        }
        if (i == 0) return false; 

        int j = i;
        while (j + 1 < n && nums[j] > nums[j + 1]) {
            j++;
        }
        if (j == i) return false; // no decreasing part

        // 3. Increasing again
        int k = j;
        while (k + 1 < n && nums[k] < nums[k + 1]) {
            k++;
        }
        if (k == j) return false; // no final increasing

        // Must reach end
        return k == n - 1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 4, 7, 5, 2, 6, 9};

    if (sol.isTrionic(nums)) {
        cout << "Trionic array ✅" << endl;
    } else {
        cout << "Not trionic ❌" << endl;
    }

    return 0;
}
