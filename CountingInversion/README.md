# Inversion Count Using Merge Sort

This program implements a solution to count the number of inversions in an array using a modified merge sort algorithm.

---

## 1. Problem Statement

An **inversion** in an array is defined as a pair of indices `(i, j)` such that:
- `i < j`
- `arr[i] > arr[j]`

The goal is to determine the total number of such inversions in a given array. For example, given the array `[6, 3, 5, 2, 7]`, the algorithm counts how many times an element precedes another element that is smaller than it.

---

## 2. Intuition and Approach

### Intuition

A straightforward method to count inversions is to use a nested loop and compare every possible pair of elements. However, this brute-force approach would have a time complexity of **O(n²)**, which becomes inefficient for large arrays.

### Approach

To solve the problem efficiently, the algorithm uses a **divide and conquer** strategy similar to merge sort:

1. **Divide:**  
   Split the array into two halves recursively until each subarray has only one element (which by itself has no inversions).

2. **Conquer (Merge and Count):**  
   Merge the two sorted halves back together while counting the inversions:
   - When merging, if an element from the left subarray is greater than an element from the right subarray, then all remaining elements in the left subarray will also be greater than the current element in the right subarray. This situation contributes inversions equal to the number of remaining elements in the left subarray.
   
3. **Combine:**  
   Sum up the inversions counted in the left half, right half, and those counted during the merge step to obtain the total inversion count.

This approach reduces the time complexity to **O(n log n)**.

---

## 3. Code Explanation

### Functions

- **`conquer` Function:**  
  - **Purpose:** Merges two sorted subarrays (`arr[start...mid]` and `arr[mid+1...end]`) and counts the cross inversions (i.e., inversions where one element is in the left subarray and the other is in the right).
  - **Process:**  
    - Uses two pointers to traverse the subarrays.
    - When an element from the left subarray is less than or equal to the element in the right, it is simply added to the temporary array.
    - When an element from the right is smaller than an element from the left, it contributes inversions equal to the number of remaining elements in the left subarray (`mid - i + 1`).
    - The temporary array is then copied back to the original array to maintain the sorted order.
    
- **`inversionCount` Function:**  
  - **Purpose:** Recursively splits the array and uses the `conquer` function to count inversions.
  - **Process:**  
    - **Base Case:** If the subarray has one or no elements (`start >= end`), return 0 inversions.
    - **Recursive Case:**  
      - Divide the array into two halves.
      - Recursively count inversions in the left and right halves.
      - Count cross inversions during the merge step using the `conquer` function.
      - Return the sum of left, right, and cross inversions.
      
- **`print` Function:**  
  - **Purpose:** Prints the array (used for debugging or demonstration purposes).

- **`main` Function:**  
  - **Purpose:**  
    - Defines the input array (`vector<int> v = {6, 3, 5, 2, 7}`).
    - Calls `inversionCount` to compute the total number of inversions.
    - Outputs the result.

---

## 4. Time and Space Complexity

### Time Complexity

- **Divide and Conquer:**  
  - The array is divided into two halves at every step, and merging takes **O(n)** time.
  - This results in a recurrence relation similar to merge sort, leading to an overall time complexity of **O(n log n)**.

### Space Complexity

- **Auxiliary Space:**  
  - A temporary vector is used during the merge process, which in the worst case can be **O(n)**.
- **Recursive Stack:**  
  - The recursion depth is **O(log n)**.

Thus, the overall space complexity is **O(n)**.

---

This README provides a comprehensive overview of the inversion counting program, detailing the problem, the efficient approach taken, a breakdown of the code, and an analysis of its performance in terms of time and space.