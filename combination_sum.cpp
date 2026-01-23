#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

void solve(int index, vector<int>& candidates, int target, vector<int>& current) {

    // if target becomes 0, we found a valid combination
    if (target == 0) {
        result.push_back(current);
        return;
    }

    // if target becomes negative or index goes out of bounds
    if (target < 0 || index == candidates.size()) {
        return;
    }

    // take the current number
    current.push_back(candidates[index]);
    solve(index, candidates, target - candidates[index], current);

    // backtrack
    current.pop_back();

    // skip the current number
    solve(index + 1, candidates, target, current);
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

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
