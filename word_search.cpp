#include <bits/stdc++.h>
using namespace std;

int m, n;

bool dfs(vector<vector<char>>& board, string& word,
         int i, int j, int index) {

    // if all characters are matched
    if (index == word.length()) {
        return true;
    }

    // boundary and mismatch check
    if (i < 0 || i >= m || j < 0 || j >= n ||
        board[i][j] != word[index]) {
        return false;
    }

    char temp = board[i][j];
    board[i][j] = '#';  // mark as visited

    // explore all 4 directions
    bool found =
        dfs(board, word, i + 1, j, index + 1) ||
        dfs(board, word, i - 1, j, index + 1) ||
        dfs(board, word, i, j + 1, index + 1) ||
        dfs(board, word, i, j - 1, index + 1);

    board[i][j] = temp; // backtrack

    return found;
}

int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    m = board.size();
    n = board[0].size();

    bool exists = false;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(board, word, i, j, 0)) {
                exists = true;
                break;
            }
        }
        if (exists) break;
    }

    if (exists)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}