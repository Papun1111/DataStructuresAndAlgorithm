# Combination Sum Using Recursion and Backtracking

This project implements a C++ program that finds all possible combinations of numbers from a given array that sum up to a target value entered by the user. The code uses recursion and backtracking to explore different combinations.

---

## Problem Statement

Given an array of integers (in this example, `{2, 3, 5}`) and a target sum provided by the user, the goal is to find all unique combinations of numbers from the array whose sum equals the target. The solution should consider different ways to include or exclude each element from the array.

---

## Approach Taken

The solution employs **recursion with backtracking**. The primary idea is to:
- Traverse the array using an index.
- Maintain an accumulator that holds the current combination of numbers.
- Explore different possibilities by including the current element (and potentially including it again) and by excluding it.
- Once the target sum is reached (i.e., the remaining target becomes zero), the current combination is stored as a valid solution.
- The recursion stops if the current index exceeds the array's size or if the target becomes negative.

Even though the code makes three recursive calls to explore various branches, it does so while retaining the original logical structure. This ensures that all potential combinations (including cases where an element can be reused) are considered.

---

## Code Explanation

### `helper` Function

- **Purpose:**  
  Recursively explores different combinations by deciding whether to include or exclude the current element.
  
- **Parameters:**  
  - `arr`: The input array containing candidate numbers.
  - `accumulator`: A vector that stores the current combination of numbers.
  - `ans`: A vector of vectors that collects all valid combinations.
  - `target`: The remaining sum required to reach the desired target.
  - `i`: The current index in the array.
  
- **Logic:**  
  1. **Base Case (Success):**  
     If `target` is exactly 0, the current combination in `accumulator` is a valid solution and is added to `ans`.
  2. **Base Case (Failure):**  
     If the index `i` exceeds the array size or the `target` becomes negative, the recursion stops.
  3. **Recursive Steps:**  
     - **Include Current Element (Moving Forward):**  
       The current element is added to the accumulator, and the function recurses with `target - arr[i]` and `i + 1`.
     - **Include Current Element (Without Advancing):**  
       This recursive call allows the possibility of reusing the same element by not advancing the index (`i` remains the same).
     - **Exclude Current Element:**  
       After backtracking (popping the last element), the function recurses by moving to the next index without changing the target.

### `findSumCombination` Function

- **Purpose:**  
  Sets up the necessary data structures and initiates the recursive process.
  
- **Logic:**  
  It initializes the `accumulator` and `ans` vectors and calls the `helper` function starting from index `0`.

### `print` Function

- **Purpose:**  
  Iterates over the results stored in `ans` and prints each combination.
  
- **Output:**  
  Each combination is printed on a new line with numbers separated by commas.

### `main` Function

- **Purpose:**  
  Serves as the entry point of the program.
  
- **Logic:**  
  1. Initializes the array with `{2, 3, 5}`.
  2. Prompts the user to input a target sum.
  3. Calls `findSumCombination` to generate all valid combinations.
  4. Prints the resulting combinations using the `print` function.

---

## Time and Space Complexity

### Time Complexity

The recursive function explores multiple branches for each element in the array. In the worst-case scenario, the number of recursive calls can be exponential. Specifically, because each element has multiple recursive calls (including and excluding, with two different approaches for inclusion), the worst-case time complexity is approximately **O(3^n)**, where `n` is the number of elements in the array. Note that pruning (e.g., when the target becomes negative) may reduce the practical number of recursive calls.

### Space Complexity

The space complexity is determined by:
- **Recursion Stack:**  
  In the worst-case scenario, the recursion depth is `O(n)`.
- **Accumulator Storage:**  
  The accumulator vector also requires space proportional to the depth, i.e., `O(n)`.
- **Output Storage:**  
  The `ans` vector stores all valid combinations, which in the worst-case scenario can be exponential in size.

Thus, the overall space complexity is **O(n)** for the recursion stack and accumulator, plus additional space for the output combinations.

---
