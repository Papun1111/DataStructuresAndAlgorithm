# Bubble Sort Program in C++

## Overview
This program implements the Bubble Sort algorithm to sort a vector of integers in ascending order. The Bubble Sort algorithm works by repeatedly stepping through the list, comparing adjacent elements and swapping them if they are in the wrong order. The process is repeated until the list is sorted.

## How the Program Works
1. The `Bubble` class contains the `sort` method, which accepts a reference to a vector of integers.
2. The `sort` method uses two nested loops:
   - The outer loop determines the number of passes through the list.
   - The inner loop compares adjacent elements and swaps them if necessary, ensuring the largest unsorted element "bubbles" to the correct position at the end of the list.
3. This process repeats until the entire vector is sorted.
4. Finally, the sorted vector is printed.

## Code Explanation
- The `Bubble` class has a method called `sort`, which accepts a vector of integers as input.
- In the `main` function, a vector `v` is initialized with a set of unsorted integers.
- The `sort` method of the `Bubble` class is called to sort the vector.
- After sorting, the sorted vector is printed element by element.

## Time and Space Complexity

### Time Complexity:
- **Best Case:** `O(n)` — This occurs when the list is already sorted. In the first pass, no swaps are needed, and the algorithm can terminate early (if optimized with a flag to check if a swap was made). Without such an optimization, the time complexity remains `O(n^2)`.
  
- **Average Case:** `O(n^2)` — This is the typical time complexity when the list is in random order. Every element must be compared with every other element, resulting in nested loops.

- **Worst Case:** `O(n^2)` — This occurs when the list is sorted in reverse order, requiring the maximum number of comparisons and swaps to arrange the elements.

### Space Complexity:
- **Space Complexity:** `O(1)` — Bubble Sort is an in-place sorting algorithm, meaning it does not require any additional space proportional to the input size. It only uses a constant amount of extra memory for the swap operations.

## Example

### Input:
```cpp
vector<int> v = {64, 34, 25, 12, 22, 11, 90};
