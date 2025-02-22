# Selection Sort Program in C++

## Overview
This program implements the Selection Sort algorithm to sort a vector of integers in ascending order. The Selection Sort algorithm works by repeatedly finding the minimum element from the unsorted part of the list and swapping it with the first unsorted element.

## How the Program Works
1. The `SelectionSort` class contains the `sort` method, which accepts a reference to a vector of integers.
2. The `sort` method uses two nested loops:
   - The outer loop iterates over the vector and selects the current position.
   - The inner loop searches for the smallest element from the unsorted portion of the vector.
3. Once the minimum element is found, it is swapped with the element at the current position.
4. This process repeats until the entire vector is sorted.
5. Finally, the sorted vector is printed.

## Code Explanation
- The `SelectionSort` class has a method called `sort`, which accepts a vector of integers as input.
- In the `main` function, a vector `v` is initialized with a set of unsorted integers.
- The `sort` method of the `SelectionSort` class is called to sort the vector.
- After sorting, the sorted vector is printed element by element.

## Example

### Input:
```cpp
vector<int> v = {64, 34, 25, 12, 22, 11, 90};
