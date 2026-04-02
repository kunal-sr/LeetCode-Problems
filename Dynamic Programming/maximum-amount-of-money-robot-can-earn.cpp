#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));

        for (int k = 0; k < 3; k++) {
            if (coins[0][0] >= 0) {
                dp[0][0][k] = coins[0][0];
            } else {
                if (k > 0)
                    dp[0][0][k] = 0;
                else
                    dp[0][0][k] = coins[0][0];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                for (int k = 0; k < 3; k++) {
                    int val = coins[i][j];

                    if (i > 0) {
                        if (dp[i-1][j][k] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + val);

                        if (val < 0 && k > 0 && dp[i-1][j][k-1] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1]);
                    }

                    // From left
                    if (j > 0) {
                        if (dp[i][j-1][k] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + val);

                        if (val < 0 && k > 0 && dp[i][j-1][k-1] != INT_MIN)
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1]);
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> coins(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> coins[i][j];
        }
    }

    Solution sol;
    cout << sol.maximumAmount(coins) << endl;

    return 0;
}
