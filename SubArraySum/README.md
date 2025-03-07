
# Subarray Sum Count

This project contains a C++ solution to count the number of subarrays in a given integer vector that sum to a specified target value.

## Problem Statement

Given an array of integers, the goal is to count the number of continuous subarrays whose sum equals a given target integer. For example, if the array is `[9, 4, 20, 3, 10, 5]` and the target is a user-provided value `k`, the program outputs the count of all subarrays that sum exactly to `k`.

## Intuition and Approach

A naive solution would involve checking every possible subarray and summing its elements, resulting in a time complexity of O(n²) or worse. Instead, this solution leverages the concept of prefix sums and a hash map (unordered_map) to reduce the time complexity.

### Key Insights

- **Prefix Sum Array:**  
  The prefix sum array stores the cumulative sum from the start of the vector to the current index. This allows the sum of any subarray `[i, j]` to be computed as `prefixSum[j] - prefixSum[i-1]` (with an appropriate check for when `i` is 0).

- **Using a Hash Map:**  
  A hash map is used to store the frequency of each prefix sum encountered. For each element in the array, the difference between the current prefix sum and the target is computed. If this difference exists in the hash map, it means that there is a subarray ending at the current index that sums to the target.

- **Single Pass Computation:**  
  By calculating the prefix sum and updating the hash map in a single pass through the array, the solution avoids the need for a nested loop, resulting in a more efficient algorithm.

## Code Explanation

1. **Initialization:**  
   - The code initializes the vector `prefixSum` with the cumulative sums.
   - The first element of `prefixSum` is set to the first element of the input vector.

2. **Building the Prefix Sum Array:**  
   - A loop from index `1` to `n-1` computes the prefix sum for each index:
     ```cpp
     prefixSum[i] = prefixSum[i - 1] + v[i];
     ```

3. **Counting Valid Subarrays:**  
   - An unordered_map `m` is used to keep track of the frequencies of prefix sums.
   - For each index `j` in the prefix sum array:
     - If the prefix sum equals the target, then the subarray from the start to `j` sums to the target.
     - The value `prefixSum[j] - target` is computed, and if it exists in the map, its frequency is added to the count.
     - Finally, the frequency of the current prefix sum is incremented in the map.

4. **Main Function:**  
   - The `main` function reads the target from the user, calls the `subArrayExist` function with the test vector and target, and prints the result.

## Time and Space Complexity

- **Time Complexity:**  
  - **O(n):** The algorithm iterates over the array once to compute the prefix sum, and then once more to count the valid subarrays using the hash map. Both operations are linear in terms of the number of elements.

- **Space Complexity:**  
  - **O(n):** The prefix sum array requires O(n) space, and the hash map may store up to O(n) unique prefix sums in the worst-case scenario.

## How to Run

1. **Compilation:**  
   Use a C++ compiler (e.g., `g++`) to compile the code:
   ```bash
   g++ -std=c++11 -o subarray_sum_count main.cpp
   ```

2. **Execution:**  
   Run the compiled executable:
   ```bash
   ./subarray_sum_count
   ```

3. **Input:**  
   The program will prompt you to enter a target value. Provide an integer and the program will output the number of subarrays with that sum.

---

This README should give you a clear understanding of how the solution works and the reasoning behind the implementation.