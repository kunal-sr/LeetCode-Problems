#include <bits/stdc++.h>
using namespace std;

bool isEqual(vector<vector<int>>& a, vector<vector<int>>& b) {
    return a == b;
}

void rotate90(vector<vector<int>>& mat) {
    int n = mat.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}

bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    for (int i = 0; i < 4; i++) {
        if (isEqual(mat, target)) return true;
        rotate90(mat);
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {
        {0,1},
        {1,0}
    };

    vector<vector<int>> target = {
        {1,0},
        {0,1}
    };

    if (findRotation(mat, target))
        cout << "True\n";
    else
        cout << "False\n";

    return 0;
}
