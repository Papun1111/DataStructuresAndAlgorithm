# 3Sum Problem

This project provides an efficient C++ solution to the classic **3Sum** problem.

---

## Problem Statement

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and:

\[
nums[i] + nums[j] + nums[k] == 0
\]

**Notice:** The solution set must not contain duplicate triplets.

### Examples

- **Example 1:**

  **Input:** `nums = [-1, 0, 1, 2, -1, -4]`  
  **Output:** `[[-1, -1, 2], [-1, 0, 1]]`

  **Explanation:**  
  - `nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0`  
  - `nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0`  
  - `nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0`  
  The distinct triplets are `[-1, 0, 1]` and `[-1, -1, 2]`.

- **Example 2:**

  **Input:** `nums = [0, 1, 1]`  
  **Output:** `[]`

  **Explanation:**  
  The only possible triplet does not sum up to 0.

- **Example 3:**

  **Input:** `nums = [0, 0, 0]`  
  **Output:** `[[0, 0, 0]]`

  **Explanation:**  
  The only possible triplet sums up to 0.

### Constraints

- \(3 \leq \text{nums.length} \leq 3000\)
- \(-10^5 \leq \text{nums[i]} \leq 10^5\)

---

## Code Explanation

The solution is implemented in C++ and involves the following steps:

1. **Sorting the Array:**
   - The array `nums` is sorted using `std::sort(nums.begin(), nums.end());`.  
   - Sorting simplifies duplicate detection and enables an efficient two-pointer approach.

2. **Iterating with a Fixed Element:**
   - The outer loop fixes one element at a time (indexed by `i`).
   - To prevent duplicate triplets, if the current element is the same as the previous one, it is skipped.

3. **Two-Pointer Technique:**
   - For each fixed element, two pointers (`j` and `k`) are used to traverse the remainder of the array.
   - The two pointers start from `i+1` (left) and the end of the array (right).
   - The sum of the triplet is calculated:
     ```cpp
     int sum = nums[i] + nums[j] + nums[k];
     ```
   - **Adjusting Pointers:**
     - If `sum < 0`, increment `j` to increase the sum.
     - If `sum > 0`, decrement `k` to decrease the sum.
     - If `sum == 0`, record the triplet, then move both pointers while skipping duplicates.

4. **Output:**
   - The `main()` function demonstrates the usage by:
     - Defining an example vector.
     - Calling the `find3Sum` function.
     - Printing out the resulting unique triplets.

---

## Approach and Optimization

### Optimized Approach: Two-Pointer Technique

- **Sorting:**  
  The initial sorting step takes \(O(n \log n)\) time and is crucial for simplifying the subsequent search and duplicate elimination.

- **Two-Pointer Search:**  
  For each fixed element, the two-pointer method finds pairs that sum to the negative of the fixed element. This step runs in \(O(n)\) time for each element, resulting in an overall time complexity of \(O(n^2)\).

- **Duplicate Handling:**  
  Duplicate elements are carefully skipped in both the outer loop and inner while loops to ensure that the same triplet is not added more than once.

### Brute Force Approach

- **Description:**  
  A brute force solution would involve three nested loops to check every possible triplet, leading to a time complexity of \(O(n^3)\).

- **Limitations:**  
  Although simple, the brute force method is not efficient for larger arrays due to its high computational cost.

### Comparison

- **Brute Force:** \(O(n^3)\) time complexity.
- **Optimized Solution:** \(O(n^2)\) time complexity, achieved through sorting and the two-pointer strategy.

---

## Time and Space Complexity

- **Time Complexity:**
  - **Sorting:** \(O(n \log n)\)
  - **Two-Pointer Search:** \(O(n^2)\) overall
  - **Total:** \(O(n^2)\)

- **Space Complexity:**
  - **Auxiliary Space:** \(O(1)\) (excluding the space used to store the output).  
  - **Sorting:** May require \(O(\log n)\) space depending on the sorting algorithm used.
  - **Output:** The space required is proportional to the number of unique triplets found.

---

## Conclusion

This C++ solution efficiently addresses the 3Sum problem by:

- Sorting the input array.
- Using the two-pointer technique to identify pairs that complement a fixed element to sum to zero.
- Skipping duplicate values to ensure each triplet in the output is unique.

This method significantly improves upon the brute force approach, reducing the overall time complexity from \(O(n^3)\) to \(O(n^2)\), making it well-suited for larger input sizes.
