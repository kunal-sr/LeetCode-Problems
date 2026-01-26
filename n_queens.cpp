#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;
vector<string> board;

bool isSafe(int row, int col, int n) {
    // check upper column
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == 'Q')
            return false;
    }

    // check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    // check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void solve(int row, int n) {
    // if all queens are placed
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row][col] = 'Q';
            solve(row + 1, n);
            board[row][col] = '.'; // backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    board.resize(n, string(n, '.'));

    solve(0, n);

    // print all solutions
    for (int i = 0; i < ans.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (string row : ans[i]) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}