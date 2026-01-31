#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<int>& nums, vector<int>& current,
           vector<vector<int>>& result) {

    // store the current subset
    result.push_back(current);

    for (int i = index; i < nums.size(); i++) {
        // include nums[i]
        current.push_back(nums[i]);

        // go to next index
        solve(i + 1, nums, current, result);

        // backtrack (remove last element)
        current.pop_back();
    }
}

int main() {
    vector<int> nums = {1, 2, 3};   // input array

    vector<vector<int>> result;
    vector<int> current;

    solve(0, nums, current, result);

    // print all subsets
    for (auto subset : result) {
        cout << "[";
        for (int i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i != subset.size() - 1)
                cout << ",";
        }
        cout << "]" << endl;
    }

    return 0;
}
