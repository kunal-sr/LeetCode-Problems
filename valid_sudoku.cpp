#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {

    vector<vector<int>> row(9, vector<int>(9, 0));
    vector<vector<int>> col(9, vector<int>(9, 0));
    vector<vector<int>> box(9, vector<int>(9, 0));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.') {
                continue;
            }

            int num = board[i][j] - '1';   // convert char to index 0-8
            int boxIndex = (i / 3) * 3 + (j / 3);

            if (row[i][num] == 1 || col[j][num] == 1 || box[boxIndex][num] == 1) {
                return false;
            }

            row[i][num] = 1;
            col[j][num] = 1;
            box[boxIndex][num] = 1;
        }
    }

    return true;
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    if (isValidSudoku(board)) {
        cout << "Sudoku board is valid" << endl;
    } else {
        cout << "Sudoku board is NOT valid" << endl;
    }

    return 0;
}
