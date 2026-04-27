#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m, n;

    static constexpr int dirs[7][4] = {
        {},
        {1, 1, 0, 0},
        {0, 0, 1, 1}, 
        {1, 0, 0, 1},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 1, 0}
    };

    int dx[4] = {0, 0, -1, 1};  // left, right, up, down
    int dy[4] = {-1, 1, 0, 0};

    static inline bool connected(int a, int b, int dir) {
        return dirs[a][dir] && dirs[b][dir ^ 1];
    }

    bool dfs(vector<vector<int>>& grid, int x, int y) {
        if (x == m - 1 && y == n - 1) return true;

        int type = grid[x][y];
        grid[x][y] = 0; // mark visited

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == 0)
                continue;

            if (connected(type, grid[nx][ny], dir) && dfs(grid, nx, ny))
                return true;
        }

        return false;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        return dfs(grid, 0, 0);
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<vector<int>> grid = {
        {2, 4, 3},
        {6, 5, 2}
    };

    bool result = sol.hasValidPath(grid);

    cout << (result ? "Valid Path Exists" : "No Valid Path") << endl;

    return 0;
}
