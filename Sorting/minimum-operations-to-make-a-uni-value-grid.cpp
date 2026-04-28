#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;

        // flatten grid
        for (auto &row : grid) {
            for (int v : row)
                arr.push_back(v);
        }

        // check if possible
        int base = arr[0];
        for (int v : arr) {
            if (abs(v - base) % x != 0)
                return -1;
        }

        // sort
        sort(arr.begin(), arr.end());

        // median
        int median = arr[arr.size() / 2];

        // count operations
        int ops = 0;
        for (int v : arr) {
            ops += abs(v - median) / x;
        }

        return ops;
    }
};

int main() {
    int m, n, x;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    cout << "Enter grid values:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "Enter x: ";
    cin >> x;

    Solution obj;
    int result = obj.minOperations(grid, x);

    cout << "Minimum operations: " << result << endl;

    return 0;
}
