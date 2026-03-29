#include <bits/stdc++.h>
using namespace std;

bool checkPartition(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    long long total = 0;
    for (auto &row : grid)
        for (int x : row)
            total += x;

    vector<long long> rowSum(m, 0);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            rowSum[i] += grid[i][j];

    vector<long long> colSum(n, 0);
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m; i++)
            colSum[j] += grid[i][j];

    unordered_map<int, int> freq;
    for (auto &row : grid)
        for (int x : row)
            freq[x]++;

    long long top = 0;
    for (int i = 0; i < m - 1; i++) {
        top += rowSum[i];
        long long bottom = total - top;

        if (top == bottom) return true;

        long long diff = abs(top - bottom);

        if (top > bottom) {
            // need to remove diff from top
            for (int r = 0; r <= i; r++) {
                for (int c = 0; c < n; c++) {
                    if (grid[r][c] == diff) return true;
                }
            }
        } else {
            
            for (int r = i + 1; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    if (grid[r][c] == diff) return true;
                }
            }
        }
    }

    long long left = 0;
    for (int j = 0; j < n - 1; j++) {
        left += colSum[j];
        long long right = total - left;

        if (left == right) return true;

        long long diff = abs(left - right);

        if (left > right) {

            for (int c = 0; c <= j; c++) {
                for (int r = 0; r < m; r++) {
                    if (grid[r][c] == diff) return true;
                }
            }
        } else {

            for (int c = j + 1; c < n; c++) {
                for (int r = 0; r < m; r++) {
                    if (grid[r][c] == diff) return true;
                }
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3},
        {3, 2, 1}
    };

    if (checkPartition(grid))
        cout << "Possible\n";
    else
        cout << "Not Possible\n";

    return 0;
}
