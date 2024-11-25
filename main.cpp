#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>>& board, int val) {
    for (int i = 0; i < board.size(); i++) {
        // Row check
        if (board[row][i] == val)
            return false;
        // Column check
        if (board[i][col] == val)
            return false;
        // 3x3 grid check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}


bool solve(vector<vector<int>>& board) {
    for (int row = 0; row < board.size(); row++) {
        for (int col = 0; col < board.size(); col++) {
            if (board[row][col] == 0) {
                for (int val = 1; val <= 9; val++) {
                    if (isSafe(row, col, board, val)) {
                        board[row][col] = val;
                        bool nextPossibleSolution = solve(board);
                        if (nextPossibleSolution)
                            return true;
                        else
                            board[row][col] = 0; 
                    }
                }
                return false; 
            }
        }
    }
    return true; 
}


void displaySudoku(const vector<vector<int>>& board) {
    cout << "\nSolved Sudoku:\n";
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "------+-------+------\n"; 
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "| ";
            }
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cout << "Welcome To Sudoku Solver\n";
    vector<vector<int>> board(9, vector<int>(9, 0));

    cout << "Enter the Sudoku grid (use 0 for empty cells):\n";
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cin >> board[row][col];
        }
    }

    if (solve(board)) {
        displaySudoku(board);
    } else {
        cout << "No solution exists for the given Sudoku.\n";
    }

    return 0;
}
