# 4Sum Problem

This repository contains a C++ solution for the 4Sum problem. The goal is to find all unique quadruplets in an array that add up to a given target sum.

---

## Problem Statement

Given an array of integers and a target value, the task is to identify all unique quadruplets (four numbers) in the array that sum up to the target. Each quadruplet should be unique, meaning that even if the same set of numbers appears in different orders, it should be returned only once.

### Example 1

- **Input:**  
  `arr = [-2, -1, -1, 1, 1, 2, 2]`  
  `target = 0`

- **Output:**  
  ```
  [
    [-2, -1, 1, 2],
    [-1, -1, 1, 1]
  ]
  ```

- **Explanation:**  
  - The quadruplet `[-2, -1, 1, 2]` sums up to 0.
  - The quadruplet `[-1, -1, 1, 1]` also sums up to 0.
  - These are the only two unique quadruplets that add up to the target value.

### Example 2

- **Input:**  
  `arr = [1, 0, -1, 0, -2, 2]`  
  `target = 0`

- **Output:**  
  ```
  [
    [-2, -1, 1, 2],
    [-2, 0, 0, 2],
    [-1, 0, 0, 1]
  ]
  ```

- **Explanation:**  
  - The quadruplet `[-2, -1, 1, 2]` sums up to 0.
  - The quadruplet `[-2, 0, 0, 2]` sums up to 0.
  - The quadruplet `[-1, 0, 0, 1]` sums up to 0.
  - Duplicate quadruplets are avoided by skipping repeated elements during processing.

---

## Constraints

- **Input Array Size:**  
  The array must contain at least 4 integers. If there are fewer than 4 numbers, it is impossible to form a quadruplet, and the function should return an empty list.

- **Value Range:**  
  The array can include negative, zero, and positive integers. The algorithm works with any values that fit within the limits of the C++ `int` type.

- **Duplicates:**  
  The input array may contain duplicate values. The solution explicitly handles duplicates by skipping over repeated values during iteration, ensuring that each quadruplet in the result is unique.

- **Performance Constraints:**  
  - **Sorting:** Sorting the array takes **O(n log n)** time.
  - **Iteration and Two-Pointer Approach:** The nested loops combined with the two-pointer method result in a worst-case time complexity of **O(n³)**.
  - The algorithm is efficient for moderate-sized arrays; however, for very large arrays the cubic time complexity may become a performance bottleneck.

- **Space Complexity:**  
  - **Auxiliary Space:** Excluding the output, the extra space used is **O(1)**.
  - **Output Space:** The worst-case space required to store the output could be significant if many quadruplets exist, but in practice duplicate avoidance usually keeps it manageable.

---

## Code Explanation

The solution is divided into two main parts: the `find4Sum` function and the `main` function.

### `find4Sum` Function

- **Input:**  
  - A reference to a vector of integers `arr`.
  - An integer `target`.

- **Output:**  
  - A vector of integer vectors, where each inner vector represents a quadruplet that sums to the target.

- **Procedure:**
  1. **Sorting:**  
     The array is sorted to simplify duplicate handling and to facilitate the two-pointer technique.
  
  2. **Fixing Two Elements:**  
     Two nested loops are used:
     - The outer loop (index `i`) fixes the first element.
     - The inner loop (index `j`) fixes the second element.
  
  3. **Two-Pointer Technique:**  
     After fixing two elements, two pointers (`p` and `q`) are used to find the remaining two numbers:
     - `p` starts just after `j`.
     - `q` starts at the end of the array.
     - These pointers move towards each other. If the sum of the quadruplet is less than the target, `p` is incremented; if it is more, `q` is decremented.
  
  4. **Recording Valid Quadruplets:**  
     When the sum of `arr[i] + arr[j] + arr[p] + arr[q]` equals the target, the quadruplet is added to the result.
  
  5. **Handling Duplicates:**  
     Duplicate elements are skipped for all indices (`i`, `j`, `p`, and `q`) to ensure that each quadruplet is unique.

### `main` Function

- **Purpose:**  
  Demonstrates the usage of the `find4Sum` function.
  
- **Steps:**  
  1. A sample vector and a target value are defined.
  2. The `find4Sum` function is invoked with these parameters.
  3. The resulting quadruplets are iterated over and printed.

---

## Intuition and Approach

- **Sorting:**  
  Sorting the array helps in handling duplicates easily and sets the stage for an efficient two-pointer method.

- **Reducing the Problem:**  
  By fixing two numbers with nested loops, the problem is reduced to finding a pair of numbers that sum to a specific value (target minus the sum of the fixed numbers).

- **Two-Pointer Technique:**  
  This technique efficiently finds a pair that meets the remaining sum requirement by scanning through the sorted array from both ends.

- **Avoiding Duplicates:**  
  By skipping consecutive duplicate numbers for each fixed index and for the two-pointer scan, the code ensures that no duplicate quadruplets are added to the result.

---

## Time and Space Complexity

- **Time Complexity:**  
  - Sorting takes **O(n log n)**.
  - The nested loops combined with the two-pointer technique yield a worst-case time complexity of **O(n³)**.
  
- **Space Complexity:**  
  - **Auxiliary Space:** **O(1)**, excluding the space used for the output.
  - **Output Space:** In the worst case, the space to store all unique quadruplets could be significant, but duplicate avoidance generally keeps it within manageable limits.

---
