#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int, greater<int>> st;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                st.insert(grid[i][j]);

                for (int k = 1; ; k++) {
                    if (i - k < 0 || i + k >= m || j - k < 0 || j + k >= n)
                        break;

                    int sum = 0;

                    int x = i - k, y = j;

                    for (int d = 0; d < k; d++) {
                        sum += grid[x + d][y + d];
                    }

                    for (int d = 0; d < k; d++) {
                        sum += grid[i + d][j + k - d];
                    }

                    for (int d = 0; d < k; d++) {
                        sum += grid[i + k - d][j - d];
                    }

                    for (int d = 0; d < k; d++) {
                        sum += grid[i - d][j - k + d];
                    }

                    st.insert(sum);
                }
            }
        }

        vector<int> result;
        for (int val : st) {
            result.push_back(val);
            if (result.size() == 3) break;
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid = {
        {3,4,5,1,3},
        {3,3,4,2,3},
        {20,30,200,40,10},
        {1,5,5,4,1},
        {4,3,2,2,5}
    };

    vector<int> ans = sol.getBiggestThree(grid);

    for (int x : ans) cout << x << " ";

    return 0;
}
