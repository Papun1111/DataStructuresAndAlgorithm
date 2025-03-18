
# Sudoku Solver Using Backtracking

This C++ program solves a given Sudoku puzzle using a backtracking algorithm. The puzzle is represented as a 9x9 grid where empty cells are denoted by the character `'.'`.

## Problem Statement

The task is to fill the 9x9 Sudoku board so that every row, every column, and every 3×3 subgrid (also known as a box) contains the digits `'1'` through `'9'` without repetition. The program takes an initial board with some pre-filled values and attempts to complete it.

## Approach

The solution is based on the **backtracking** technique:
1. **Recursion:** The program recursively attempts to fill the board one cell at a time.
2. **Safety Check:** For every empty cell, it tries placing digits from `'1'` to `'9'` while ensuring that placing a digit does not violate Sudoku rules (i.e., the digit is not already present in the current row, column, or 3×3 subgrid).
3. **Backtracking:** If placing a digit leads to a dead-end (no valid solution can be found later), the algorithm backtracks by resetting the cell to `'.'` and trying the next digit.
4. **Completion:** If the entire board is filled following the rules, the puzzle is solved.

## Methods Used

### `isSafe` Function

- **Purpose:** Checks whether it is safe to place a digit in a specific cell.
- **Functionality:**
  - **Row and Column Check:** Iterates over the current row and column to ensure the digit is not present.
  - **Subgrid Check:** Computes the starting indices of the 3×3 subgrid and checks all its cells to ensure the digit does not already exist.
- **Return:** `true` if it is safe to place the digit; otherwise, `false`.

### `solveSudoku` Function

- **Purpose:** Recursively solves the Sudoku board using backtracking.
- **Functionality:**
  - **Base Case:** If the function reaches the end of the board (i.e., row equals 9), the puzzle is solved.
  - **Row Completion:** If the current column index reaches 9, it moves to the next row.
  - **Pre-filled Cell:** If a cell is already filled (not `'.'`), the function skips it.
  - **Trying Digits:** For each empty cell, it iterates through digits `'1'` to `'9'`:
    - If `isSafe` returns true for a digit, the digit is placed in the cell.
    - The function recursively calls itself for the next cell.
    - If the recursion returns `true`, the solution is found.
    - If none of the digits work, the function backtracks by resetting the cell to `'.'`.
- **Return:** `true` if the board can be solved; otherwise, `false`.

### `main` Function

- **Purpose:** Initializes the board, calls the solver, and prints the solved board if a solution is found.
- **Functionality:**
  - Initializes an example Sudoku puzzle with empty cells represented by `'.'`.
  - Calls the `solveSudoku` function starting from the first cell (0,0).
  - Prints the solved board if a solution exists; otherwise, it prints that no solution exists.

## Code Explanation

The complete code is as follows:

```cpp
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
```

## Complexity Analysis

### Time Complexity

- **Worst-case Scenario:**  
  In the worst-case scenario, where the board is completely empty, the algorithm may try every possibility for each of the 81 cells. This results in an upper bound of \(O(9^{81})\) combinations. However, due to the constraints enforced by the Sudoku rules and the backtracking pruning, the practical performance is much better than this worst-case bound.

### Space Complexity

- **Space for Board:**  
  The board uses \(O(81)\) space, which is constant.
- **Recursive Stack:**  
  In the worst-case, the recursion can go as deep as 81 calls, resulting in \(O(81)\) space, which is also constant.

Overall, both time and space complexities are manageable for a standard 9x9 Sudoku board despite the exponential worst-case time complexity.

## Conclusion

This program provides a straightforward implementation of a Sudoku solver using recursion and backtracking. The `isSafe` function ensures that the Sudoku constraints are maintained, and the `solveSudoku` function explores possible solutions recursively, backtracking when necessary. The overall design and complexity are tailored for a standard 9x9 Sudoku board, making it efficient for typical use cases.

---