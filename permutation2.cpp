#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;
vector<int> temp;

void backtrack(vector<int>& nums, vector<bool>& used) {
    // if one permutation is complete
    if (temp.size() == nums.size()) {
        result.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {

        // skip if already used
        if (used[i]) continue;

        // skip duplicates
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        used[i] = true;
        temp.push_back(nums[i]);

        backtrack(nums, used);

        // backtrack
        temp.pop_back();
        used[i] = false;
    }
}

int main() {
    vector<int> nums = {1, 1, 2};

    sort(nums.begin(), nums.end());

    vector<bool> used(nums.size(), false);

    backtrack(nums, used);

    // print all unique permutations
    for (auto &perm : result) {
        for (int x : perm) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}