# Permutation Generator in C++

This README explains the C++ program that generates all possible permutations of a given array of integers. The code employs recursion with backtracking to systematically generate and print each permutation.

---

## Problem Statement

The goal is to generate all unique permutations of a given array of integers. For example, given the array `{1, 2, 3}`, the program should output all 6 possible arrangements:
- `1 2 3`
- `1 3 2`
- `2 1 3`
- `2 3 1`
- `3 2 1`
- `3 1 2`

---

## Approach

The solution uses **recursion** combined with **backtracking**:
- **Recursion:** The problem is solved by fixing one element at a time and recursively generating the permutations of the remaining elements.
- **Backtracking:** After a recursive call, the elements are swapped back to restore the original array order. This step is essential to ensure that subsequent recursive calls work with the correct configuration.

---

## Intuition

Imagine filling positions in a sequence:
- For the first position, any element can be placed.
- Once the first element is chosen, the problem reduces to generating permutations for the remaining elements.
- This process repeats recursively.
- Backtracking (swapping back) ensures that each decision is undone so that other possibilities can be explored without interference from previous choices.

This method systematically covers all arrangements by exploring every branch of possibilities.

---

## Code Explanation

### Function: `print`
- **Purpose:** Prints the contents of the vector.
- **Parameters:** A constant reference to a vector of integers.
- **Operation:** Iterates over each element in the vector and prints it, followed by a newline.

### Function: `printAllPermutation`
- **Purpose:** Recursively generates and prints all permutations of the vector.
- **Parameters:** 
  - A reference to the vector of integers.
  - An index `idx` (default is 0) indicating the current position to fix.
- **Base Case:** When `idx` equals the size of the array, a complete permutation is formed, and the `print` function is called.
- **Recursive Case:** 
  - Loop through indices from `idx` to the end of the array.
  - Swap the element at `idx` with the element at the current loop index `i`.
  - Recursively call `printAllPermutation` with `idx + 1` to fix the next element.
  - Swap the elements back (backtracking) to restore the array before the next iteration.

### Function: `main`
- **Operation:** 
  - Creates a vector with the integers `{1, 2, 3}`.
  - Calls `printAllPermutation` to generate and print all permutations.

---

## Time and Space Complexity

### Time Complexity
- **O(n * n!):**  
  - There are `n!` permutations.
  - For each permutation, printing takes O(n) time.

### Space Complexity
- **O(n):**  
  - The maximum depth of the recursion tree is `n`, leading to a space complexity of O(n) for the recursion call stack.

---

This program provides a clear and efficient solution for generating all permutations of a set of numbers using recursion and backtracking.