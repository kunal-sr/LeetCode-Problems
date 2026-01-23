#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
vector<int> current;
vector<bool> used;

void backtrack(vector<int>& nums) {
    // if current permutation is complete
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (used[i] == true)
            continue;

        // choose
        current.push_back(nums[i]);
        used[i] = true;

        // explore
        backtrack(nums);

        // backtrack
        current.pop_back();
        used[i] = false;
    }
}

int main() {
    vector<int> nums = {1, 2, 3};

    used.resize(nums.size(), false);
    backtrack(nums);

    // print all permutations
    for (auto perm : result) {
        cout << "[ ";
        for (int x : perm) {
            cout << x << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}