#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, char ch) {

    // check row and column
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == ch) return false;
        if (board[i][col] == ch) return false;
    }

    // check 3x3 box
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == ch) return false;
        }
    }

    return true;
}

bool solveSudokuUtil(vector<vector<char>>& board) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.') {

                for (char ch = '1'; ch <= '9'; ch++) {

                    if (isSafe(board, i, j, ch)) {
                        board[i][j] = ch;

                        if (solveSudokuUtil(board)) {
                            return true;
                        }

                        // backtrack
                        board[i][j] = '.';
                    }
                }

                return false; // no number fits here
            }
        }
    }

    return true; // board solved
}

void solveSudoku(vector<vector<char>>& board) {
    solveSudokuUtil(board);
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

    solveSudoku(board);

    cout << "Solved Sudoku Board:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}