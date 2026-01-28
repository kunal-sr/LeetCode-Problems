#include <bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxReach = 0;

    for (int i = 0; i < nums.size(); i++) {

        // if current index is not reachable
        if (i > maxReach) {
            return false;
        }

        // update the farthest index we can reach
        maxReach = max(maxReach, i + nums[i]);
    }

    return true;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};   // example input

    if (canJump(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}