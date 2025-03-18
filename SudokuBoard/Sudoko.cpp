#include <iostream>
#include <vector>
using namespace std;

// Function to check if placing 'c' at board[row][col] is valid.
bool isSafe(vector<vector<char>>& board, int row, int col, char c) {
    // Check the row and column.
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == c) return false;
        if (board[i][col] == c) return false;
    }
    // Check the 3x3 subgrid.
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[startRow + i][startCol + j] == c)
                return false;
        }
    }
    return true;
}

// Recursive function to solve the sudoku using backtracking.
bool solveSudoku(vector<vector<char>>& board, int row, int col) {
    // If reached the end of the board, the puzzle is solved.
    if (row == 9)
        return true;
    
    // Move to the next row if we have reached the end of the current row.
    if (col == 9)
        return solveSudoku(board, row + 1, 0);
    
    // If the cell is already filled, move to the next cell.
    if (board[row][col] != '.')
        return solveSudoku(board, row, col + 1);
    
    // Try digits '1' to '9' in the empty cell.
    for (char c = '1'; c <= '9'; c++) {
        if (isSafe(board, row, col, c)) {
            board[row][col] = c;  // Place the digit.
            if (solveSudoku(board, row, col + 1))
                return true;      // If successful, puzzle solved.
            board[row][col] = '.'; // Otherwise, backtrack.
        }
    }
    return false; // Trigger backtracking.
}

int main() {
    // Example Sudoku board with '.' representing empty cells.
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

    if (solveSudoku(board, 0, 0)) {
        cout << "Solved Sudoku:" << endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
