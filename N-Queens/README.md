---

# N-Queens Problem Solver in C++

This project implements the N-Queens problem in C++ using a backtracking algorithm. The N-Queens problem requires placing `n` queens on an `n x n` chessboard so that no two queens threaten each other—that is, no two queens share the same row, column, or diagonal.

## Approach and Intuition

The solution uses a **backtracking** approach:
- **Recursive Placement:** Queens are placed row by row. For each row, we try placing a queen in every column.
- **Safety Check:** Before placing a queen, the algorithm checks if the cell is "safe" (i.e., no other queen can attack it) by:
  - Scanning the same column in previous rows.
  - Checking the upper left diagonal.
  - Checking the upper right diagonal.
- **Backtracking:** If placing a queen leads to no valid solutions for subsequent rows, the algorithm removes (backtracks) the queen and tries the next possible column.
- **Base Case:** Once queens have been placed in all rows (i.e., the row index equals `n`), a valid solution is found and stored.

This systematic trial-and-error process ensures all possible configurations are explored.

## Code Walkthrough

### 1. `isSafe` Function

- **Purpose:** Checks whether it is safe to place a queen at a given position `(row, col)` on the board.
- **Logic:**
  - **Column Check:** Iterates over all rows above the current row to ensure no queen is in the same column.
  - **Upper Left Diagonal Check:** Iterates diagonally up and to the left.
  - **Upper Right Diagonal Check:** Iterates diagonally up and to the right.

```cpp
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
```

### 2. `nQueens` Function

- **Purpose:** Uses recursion and backtracking to place queens on the board.
- **Logic:**
  - **Base Case:** If `row == n`, all queens are placed successfully; the current board configuration is added to the solutions.
  - **Recursive Case:** For each column in the current row:
    - Check if placing a queen at `(row, col)` is safe.
    - Place the queen, then recursively call `nQueens` for the next row.
    - Backtrack by removing the queen from `(row, col)` to try alternative placements.

```cpp
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
```

### 3. `main` Function

- **Board Initialization:** The board is initialized as an `n x n` grid of dots (`'.'`), representing empty positions.
- **Solution Storage:** A 2D vector is used to store all valid board configurations.
- **Execution:** The `nQueens` function is called starting from row `0`.
- **Output:** Each valid solution is printed to the console.

```cpp
int main() {
    int n = 4;  // Change n for different board sizes
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
```

## Backtracking Concept in Detail

1. **Exploration:** The algorithm starts from the first row and explores placing a queen in each column.
2. **Recursive Descent:** For every valid placement, it moves to the next row and repeats the process.
3. **Conflict Detection:** The `isSafe` function ensures that a queen placement does not lead to conflicts.
4. **Backtracking:** If no valid position exists in a row (or a subsequent row), the algorithm backtracks—removing the last placed queen and trying the next available position.
5. **Solution Capture:** When a valid configuration is found (i.e., when `row == n`), it is stored in the solutions vector.

## Complexity Analysis

### Time Complexity
- **Worst-case:** The backtracking solution explores all possible placements. The number of possibilities can be approximated by O(n!) since each queen placed reduces the options for subsequent rows.
- **Explanation:** For each row, there are up to `n` columns to try. While many placements are pruned early by the `isSafe` function, the worst-case scenario still remains exponential.

### Space Complexity
- **Recursion Stack:** The recursion depth can go up to `n`, so the recursion stack takes O(n) space.
- **Board Storage:** Each solution is stored as an `n x n` grid. In the worst case, if many solutions exist, the storage required is proportional to the number of solutions multiplied by O(n²) per solution.
- **Overall:** Space complexity is O(n) for recursion plus additional space for storing solutions, which depends on the number of valid configurations.

## Compilation and Execution

To compile and run this program, use the following commands:

```bash
g++ -o nqueens nqueens.cpp
./nqueens
```

This will compile the code and execute the program, printing all valid solutions for the 4-Queens problem. To solve the problem for a different board size, simply change the value of `n` in the `main` function.

## Conclusion

This C++ implementation of the N-Queens problem demonstrates an efficient use of recursion and backtracking. It systematically explores possible board configurations, leveraging the `isSafe` check to ensure valid queen placements. The code provides a clear example of how to tackle constraint satisfaction problems using backtracking, while also analyzing the computational complexity of such approaches.

---
