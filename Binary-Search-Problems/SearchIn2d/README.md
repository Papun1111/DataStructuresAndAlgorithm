
## Problem Statement
The goal of this program is to efficiently search for a target value within a 2D matrix. The matrix is assumed to have the following properties:
- Each row is sorted in ascending order.
- The first element of each row is greater than the last element of the previous row.

Given these properties, the matrix can be thought of as a flattened sorted array. The task is to determine whether a given target exists within the matrix using a binary search approach.

## Code Explanation
The program is structured into two main functions:

### `searchInRow`
- **Purpose:** Searches for the target within a single sorted row.
- **Method:** Implements a standard binary search algorithm:
  - Initializes two pointers (`left` and `right`) to the beginning and end of the row.
  - Repeatedly calculates the middle index (`mid`).
  - Compares the element at `mid` with the target:
    - If equal, returns `true`.
    - If less than the target, moves the `left` pointer to `mid + 1`.
    - If greater than the target, moves the `right` pointer to `mid - 1`.
  - If the target is not found, returns `false`.

### `searchMatrix`
- **Purpose:** Searches for the target in the 2D matrix by first identifying the potential row that may contain the target, then searching within that row.
- **Method:**
  - Checks if the matrix is empty.
  - Uses binary search on the rows by comparing the target with the first and last elements of the middle row:
    - If the target lies within the range of the current row, it calls `searchInRow` to search within that row.
    - If the target is less than the first element of the current row, it adjusts the search to the upper half of the matrix.
    - If the target is greater than the last element, it adjusts the search to the lower half.
  - Returns `true` if the target is found; otherwise, returns `false`.

### `main`
- Initializes the matrix with sample values.
- Sets a target value to search for.
- Uses `searchMatrix` to determine if the target exists in the matrix.
- Outputs the result to the console.

## Time Complexity
- **Row Search:** The binary search on rows takes \(O(\log m)\), where \(m\) is the number of rows.
- **Column Search:** The binary search within a row takes \(O(\log n)\), where \(n\) is the number of columns.
- **Overall Time Complexity:** \(O(\log m + \log n)\)

## Space Complexity
- The algorithm uses a constant amount of extra space.
- **Overall Space Complexity:** \(O(1)\)

This README provides an overview of the problem, detailed code explanation, and analysis of time and space complexities.