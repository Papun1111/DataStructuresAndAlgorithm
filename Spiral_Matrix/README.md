
# Spiral Matrix Printer

## Problem Statement

Given a 2D matrix of integers, the goal is to print its elements in spiral order. The traversal starts at the top-left corner, moves right, then down, left, and up in a loop until every element has been printed. For example, for the matrix:

```
1 2 3
4 5 6
7 8 9
```

The spiral order would be: `1 2 3 6 9 8 7 4 5`.

## Code Explanation

The C++ code defines a function `printInSpiral` that takes a 2D vector (matrix) as input and prints the elements in spiral order. The code uses four index variables:
- `srow` (starting row) and `scol` (starting column) for the top-left corner.
- `erow` (ending row) and `ecol` (ending column) for the bottom-right corner.

The algorithm works by iteratively:
1. Traversing the top row from left to right.
2. Traversing the right column from top to bottom.
3. Traversing the bottom row from right to left (if any rows remain).
4. Traversing the left column from bottom to top (if any columns remain).

After each step, the corresponding boundary is adjusted (incremented or decremented) until the entire matrix is processed.

## Approach Taken

1. **Initialization:**  
   Set the initial boundaries of the matrix (`srow`, `scol`, `erow`, and `ecol`).

2. **Spiral Traversal Loop:**  
   While the starting indices are less than or equal to the ending indices:
   - Traverse the top row from `scol` to `ecol`, then increment `srow`.
   - Traverse the right column from `srow` to `erow`, then decrement `ecol`.
   - If the new starting row is still within the bounds, traverse the bottom row from `ecol` to `scol`, then decrement `erow`.
   - If the new starting column is still within the bounds, traverse the left column from `erow` to `srow`, then increment `scol`.

3. **Termination:**  
   The loop ends when the starting indices cross the ending indices, indicating that all elements have been printed.

## Time Complexity

Each element in the matrix is visited exactly once, leading to a time complexity of:
- **O(m * n)**
  
where `m` is the number of rows and `n` is the number of columns in the matrix.

## Space Complexity

The algorithm uses a constant amount of extra space for variables (`srow`, `scol`, `erow`, `ecol`, and loop counters). The space used does not scale with the size of the input matrix, so the space complexity is:
- **O(1)**

## How to Compile and Run

1. **Save the Code:**  
   Save the following code in a file called `spiral_matrix.cpp`:

   ```cpp
   #include<iostream>
   #include<vector>
   using namespace std;

   void printInSpiral(vector<vector<int>> matrix) {
       int srow = 0, scol = 0, erow = matrix.size() - 1, ecol = matrix[0].size() - 1;
       while (srow <= erow && scol <= ecol) {
           for (int i = scol; i <= ecol; i++) {
               cout << matrix[srow][i] << " ";
           }
           srow++;
           for (int i = srow; i <= erow; i++) {
               cout << matrix[i][ecol] << " ";
           }
           ecol--;
           if (srow <= erow) {
               for (int i = ecol; i >= scol; i--) {
                   cout << matrix[erow][i] << " ";
               }
               erow--;
           }
           if (scol <= ecol) {
               for (int i = erow; i >= srow; i--) {
                   cout << matrix[i][scol] << " ";
               }
               scol++;
           }
       }
   }

   int main() {
       vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
       printInSpiral(matrix);
       return 0;
   }
   ```

2. **Compile the Code:**  
   Use a C++ compiler such as `g++`:
   ```bash
   g++ spiral_matrix.cpp -o spiral_matrix
   ```

3. **Run the Executable:**  
   Execute the compiled program:
   ```bash
   ./spiral_matrix
   ```

   The output should display the matrix elements in spiral order:  
   `1 2 3 6 9 8 7 4 5`

---

This README file covers the problem statement, explains the code and approach, and includes details on time and space complexity as well as instructions for compiling and running the code.