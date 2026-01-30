#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int low = 0;
    int high = m * n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        int row = mid / n;
        int col = mid % n;

        int value = matrix[row][col];

        if (value == target) {
            return true;
        } 
        else if (value < target) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    if (searchMatrix(matrix, target)) {
        cout << "Target found in matrix" << endl;
    } else {
        cout << "Target not found in matrix" << endl;
    }

    return 0;
}