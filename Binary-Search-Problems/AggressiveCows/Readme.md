# Aggressive Cows Problem - README

This project implements a solution to the classic "Aggressive Cows" problem using C++. The goal is to place **C** cows in **N** stalls (given as positions in an array) such that the minimum distance between any two cows is maximized.

---

## Overview

The solution leverages a binary search algorithm on the potential minimum distance between cows. The key idea is to check whether it is possible to place all cows in the stalls with at least a given minimum separation, and then adjust the search accordingly to find the optimal (largest possible) minimum distance.

---

## Code Explanation

### Key Functions

1. **`maxVal(vector<int>& arr)`**  
   - **Purpose:** Finds and returns the maximum value in the array.
   - **Operation:** Iterates through the array, updating the maximum value encountered.
   - **Time Complexity:** O(N), where N is the size of the array.

2. **`minVal(vector<int>& arr)`**  
   - **Purpose:** Finds and returns the minimum value in the array.
   - **Operation:** Iterates through the array, updating the minimum value encountered.
   - **Time Complexity:** O(N).

3. **`isPossible(vector<int>& arr, int N, int C, int minAllowedDist)`**  
   - **Purpose:** Checks if it is possible to place **C** cows in the stalls such that the distance between any two cows is at least `minAllowedDist`.
   - **Operation:**  
     - Starts by placing the first cow in the first stall.
     - Iterates through the sorted stall positions, placing a cow whenever the distance from the last placed cow is at least `minAllowedDist`.
     - Returns `true` if all cows are successfully placed; otherwise, returns `false`.
   - **Time Complexity:** O(N).

4. **`getDistance(vector<int>& arr, int N, int C)`**  
   - **Purpose:** Determines the largest minimum distance possible between any two cows.
   - **Operation:**  
     - **Sorts** the stall positions to ensure they are in increasing order.
     - Uses **binary search** on the distance range:
       - **Start (`st`):** Minimum possible distance (initialized to 1).
       - **End (`end`):** Maximum possible distance calculated as the difference between the maximum and minimum stall positions.
       - In each iteration, computes the mid-distance and uses the `isPossible` function to check feasibility.
       - Adjusts the search space based on whether placement was possible.
     - Returns the optimal (largest valid) minimum distance found.
   - **Time Complexity:** O(N log M), where M is the difference between the maximum and minimum stall positions.

5. **`main()` Function**  
   - **Purpose:** Demonstrates the solution with a sample input.
   - **Operation:**  
     - Initializes the number of stalls (`N`), the number of cows (`C`), and the stall positions.
     - Calls `getDistance` to compute and output the result.

---

## Approach and Algorithm

1. **Sorting:**  
   The stall positions are sorted to ensure that the cows are placed in increasing order. This step is crucial for correctly applying the greedy placement strategy.

2. **Binary Search on Answer:**  
   - The problem is rephrased as: "What is the largest minimum distance `d` such that all cows can be placed with at least `d` distance between them?"
   - A binary search is conducted over the range of possible distances (from 1 to the difference between the maximum and minimum positions).
   - For each candidate distance (`mid`), the `isPossible` function is called to verify if the cows can be placed successfully.
   - The binary search narrows down the candidate distance until the maximum possible minimum distance is determined.

3. **Greedy Placement Check:**  
   The `isPossible` function implements a greedy approach to place cows. Starting from the first stall, it places each subsequent cow at the earliest stall that satisfies the minimum distance requirement.

---

## Time Complexity

- **Sorting:** O(N log N)
- **Binary Search:** Each iteration of the binary search requires an O(N) check (`isPossible`). If the search space is defined by the difference \( M = \text{maxVal} - \text{minVal} \), then binary search takes O(log M) iterations.
- **Overall Complexity:**  
  \[
  O(N \log N) + O(N \log M)
  \]
  For large inputs, this is efficient and scalable.

---

## Compilation and Execution

To compile and run the code:

1. **Compilation:**
   ```bash
   g++ -o aggressive_cows aggressive_cows.cpp
   ```

2. **Execution:**
   ```bash
   ./aggressive_cows
   ```

The sample input provided in the `main` function will produce the output for the maximum minimum distance between cows.

---

## Additional Details

- **Robustness:**  
  The code handles any array of stall positions and adjusts for arbitrary distances between stalls.
  
- **Extensibility:**  
  With minor modifications, the code can be adapted to different constraints or integrated into larger systems requiring similar greedy or binary search methodologies.

---

This README provides a comprehensive explanation of the approach, key functions, and overall time complexity. The code is designed to be both efficient and clear, making it a solid solution for the "Aggressive Cows" problem.