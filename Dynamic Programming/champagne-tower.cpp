#include <bits/stdc++.h>
using namespace std;

double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> dp(101, vector<double>(101, 0.0));

    dp[0][0] = poured;

    for (int i = 0; i <= query_row; i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[i][j] > 1.0) {
                double overflow = (dp[i][j] - 1.0) / 2.0;
                dp[i + 1][j] += overflow;
                dp[i + 1][j + 1] += overflow;
            }
        }
    }

    return min(1.0, dp[query_row][query_glass]);
}

int main() {
    int poured = 10;
    int query_row = 3;
    int query_glass = 1;

    cout << "Champagne in glass: "
         << champagneTower(poured, query_row, query_glass) << endl;

    return 0;
}
