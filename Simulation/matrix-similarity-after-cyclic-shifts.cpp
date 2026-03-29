#include <bits/stdc++.h>
using namespace std;

bool areSimilar(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int newCol;

            if (i % 2 == 0) {

                newCol = (j + k) % n;
            } else {

                newCol = (j - k % n + n) % n;
            }

            if (mat[i][j] != mat[i][newCol]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 1, 2},
        {5, 5, 5, 5},
        {6, 3, 6, 3}
    };

    int k = 2;

    if (areSimilar(mat, k))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
