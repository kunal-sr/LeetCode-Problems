#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

void solve(int index, vector<int>& candidates, int target, vector<int>& current) {

    // if target becomes 0, we found a valid combination
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = index; i < candidates.size(); i++) {

        // skip duplicate elements
        if (i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }

        // if current element is greater than target, stop
        if (candidates[i] > target) {
            break;
        }

        // take the element
        current.push_back(candidates[i]);
        solve(i + 1, candidates, target - candidates[i], current);

        // backtrack
        current.pop_back();
    }
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    // sort to handle duplicates
    sort(candidates.begin(), candidates.end());

    vector<int> current;
    solve(0, candidates, target, current);

    // print result
    for (auto comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}