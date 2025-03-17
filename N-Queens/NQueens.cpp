#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<string>& board, int row, int col, int n) {
    // Check column above current row
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q')
            return false;
    }
    // Check upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }
    // Check upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}

void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';    // Place queen
            nQueens(board, row + 1, n, ans);
            board[row][col] = '.';    // Backtrack
        }
    }
}

int main() {
    int n = 4;
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> solutions;
    
    nQueens(board, 0, n, solutions);
  
    for (auto& sol : solutions) {
        for (auto& row : sol) {
            cout << row << endl;
        }
        cout << endl;
    }
    
    return 0;
}
