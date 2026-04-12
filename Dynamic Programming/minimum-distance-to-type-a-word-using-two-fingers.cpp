#include <bits/stdc++.h>
using namespace std;

int dist(int a, int b) {
    if (a == -1) return 0;
    return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
}

int minimumDistance(string word) {
    int n = word.size();
    vector<vector<int>> dp(n, vector<int>(26, INT_MAX));

    for (int j = 0; j < 26; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i < n; i++) {
        int curr = word[i] - 'A';
        int prev = word[i - 1] - 'A';

        for (int j = 0; j < 26; j++) {
            if (dp[i - 1][j] == INT_MAX) continue;

            dp[i][j] = min(dp[i][j],
                           dp[i - 1][j] + dist(prev, curr));

            dp[i][prev] = min(dp[i][prev],
                              dp[i - 1][j] + dist(j, curr));
        }
    }

    int ans = INT_MAX;
    for (int j = 0; j < 26; j++) {
        ans = min(ans, dp[n - 1][j]);
    }
    return ans;
}

int main() {
    string word;
    cout << "Enter word (CAPITAL letters only): ";
    cin >> word;

    cout << "Minimum Distance: " << minimumDistance(word) << endl;

    return 0;
}
