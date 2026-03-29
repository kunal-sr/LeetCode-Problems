#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {

                vector<int> elements;

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        elements.push_back(grid[x][y]);
                    }
                }

                sort(elements.begin(), elements.end());

                int minDiff = INT_MAX;
                for (int t = 1; t < elements.size(); t++) {
                    minDiff = min(minDiff, elements[t] - elements[t - 1]);
                }

                result[i][j] = minDiff;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {1,3,6},
        {7,2,5},
        {4,8,9}
    };

    int k = 2;

    vector<vector<int>> ans = sol.minAbsDiff(grid, k);

    for (auto &row : ans) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}
