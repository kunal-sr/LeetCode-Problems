#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    int num = 1;

    while (top <= bottom && left <= right) {

        // left to right
        for (int i = left; i <= right; i++) {
            matrix[top][i] = num;
            num++;
        }
        top++;

        // top to bottom
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = num;
            num++;
        }
        right--;

        // right to left
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                matrix[bottom][i] = num;
                num++;
            }
            bottom--;
        }

        // bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                matrix[i][left] = num;
                num++;
            }
            left++;
        }
    }

    return matrix;
}

int main() {
    int n = 3;

    vector<vector<int>> result = generateMatrix(n);

    // print the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}