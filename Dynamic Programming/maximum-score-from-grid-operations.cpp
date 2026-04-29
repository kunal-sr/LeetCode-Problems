#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<vector<int>>& grid) {
        int n = grid.size();

        // Prefix sum for each column
        vector<vector<int>> pref(n, vector<int>(n + 1, 0));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                pref[j][i + 1] = pref[j][i] + grid[i][j];
            }
        }

        // dp[j][h] = max score till column j with height h at column j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Transition
        for (int j = 1; j < n; j++) {
            for (int h = 0; h < n; h++) {
                int best = 0;
                for (int prev = 0; prev < n; prev++) {

                    int add = 0;

                    if (prev > h) {
                        // rows (h+1 to prev) from column j
                        add += pref[j][prev + 1] - pref[j][h + 1];
                    } else if (h > prev) {
                        // rows (prev+1 to h) from column j-1
                        add += pref[j - 1][h + 1] - pref[j - 1][prev + 1];
                    }

                    best = max(best, dp[j - 1][prev] + add);
                }
                dp[j][h] = best;
            }
        }

        // Final answer
        int ans = 0;
        for (int h = 0; h < n; h++) {
            ans = max(ans, dp[n - 1][h]);
        }

        return ans;
    }
};
