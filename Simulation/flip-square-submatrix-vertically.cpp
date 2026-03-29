#include <bits/stdc++.h>
using namespace std;

void flipSubmatrix(vector<vector<int>>& grid, int r, int c, int k) {

    for (int i = 0; i < k / 2; i++) {
        for (int j = 0; j < k; j++) {
            swap(grid[r + i][c + j], grid[r + k - 1 - i][c + j]);
        }
    }
}

void printGrid(vector<vector<int>>& grid) {
    for (auto& row : grid) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12},
        {13,14,15,16}
    };

    int r = 1, c = 1, k = 2;

    cout << "Before:\n";
    printGrid(grid);

    flipSubmatrix(grid, r, c, k);

    cout << "\nAfter:\n";
    printGrid(grid);

    return 0;
}
