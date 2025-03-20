# Merge Sort Implementation in C++

This project demonstrates an implementation of the merge sort algorithm in C++. Merge sort is an efficient, general-purpose, comparison-based sorting algorithm that utilizes the divide and conquer approach.

---

## Problem Statement

The goal of this code is to sort a vector of integers in ascending order using the merge sort algorithm. The key challenge is to efficiently divide the unsorted array, sort the individual segments, and then merge them back together in a sorted order.

---

## Overview of the Approach

Merge sort works by:
1. **Dividing**: Recursively splitting the array into two halves until each subarray has one or zero elements.
2. **Conquering**: Merging the sorted subarrays to form a larger sorted subarray.
3. **Combining**: Repeating the merge process until the entire array is sorted.

---

## Code Breakdown

### `conquer` Function

- **Purpose:**  
  Merges two sorted halves of the array into a single sorted segment.

- **Parameters:**
  - `arr`: The vector of integers.
  - `start`: The starting index of the current segment.
  - `mid`: The ending index of the first sorted subarray.
  - `end`: The ending index of the second sorted subarray.

- **Process:**
  - A temporary vector `temp` is used to store the merged result.
  - Two pointers, `i` and `j`, are used to traverse the two subarrays.
  - The function compares elements from each subarray and appends the smaller element to `temp`.
  - Remaining elements in either subarray (if any) are appended to `temp`.
  - Finally, the sorted elements in `temp` are copied back into the original array starting at index `start`.

### `mergeSort` Function

- **Purpose:**  
  Recursively sorts the vector by dividing it into halves and then merging them.

- **Parameters:**
  - `arr`: The vector of integers.
  - `start`: The starting index of the current segment.
  - `end`: The ending index of the current segment.

- **Base Case:**
  - When `start >= end`, the segment contains one or no elements and is inherently sorted, so the function returns.

- **Recursive Process:**
  - The middle index (`mid`) is calculated.
  - The function recursively calls itself to sort the left half (`start` to `mid`) and the right half (`mid + 1` to `end`).
  - The sorted halves are then merged by calling the `conquer` function.

### `print` Function

- **Purpose:**  
  Outputs the elements of the sorted vector to the console.

- **Parameters:**  
  - `v`: The vector of integers.

- **Process:**  
  - Iterates over the vector and prints each element followed by a space.

### `main` Function

- **Purpose:**  
  Acts as the entry point for the program.

- **Process:**
  1. A vector of integers is initialized.
  2. The `mergeSort` function is called to sort the vector.
  3. The `print` function is used to display the sorted vector.

---

## Complexity Analysis

- **Time Complexity:**  
  The merge sort algorithm has a time complexity of **O(n log n)** in the average and worst cases. This is because:
  - The array is divided in half at each recursive call (log n divisions).
  - Merging the divided arrays takes linear time (n).

- **Space Complexity:**  
  The space complexity is **O(n)**, due to the additional temporary vector used in the `conquer` function for merging.

---

## Conclusion

This implementation of merge sort in C++ serves as a clear example of how to apply the divide and conquer strategy to sort an array. By recursively breaking down the array and merging the sorted segments, merge sort efficiently handles sorting tasks with a consistent O(n log n) time complexity.

Feel free to explore and modify the code to further understand its workings or to adapt it for other data types and sorting needs.