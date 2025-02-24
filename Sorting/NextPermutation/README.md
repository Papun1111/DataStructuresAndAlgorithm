# Lexicographical Next Permutation  

This C++ program finds the next lexicographical permutation of a given sequence of numbers. If the sequence is the highest possible permutation, it rearranges it to the lowest possible order (i.e., sorted in ascending order).  

---

## Table of Contents  
1. [Problem Statement](#problem-statement)  
2. [Approach](#approach)  
3. [Code Explanation](#code-explanation)  
4. [Complexity Analysis](#complexity-analysis)  
5. [Example](#example)  
6. [How to Run](#how-to-run)  

---

## Problem Statement  
Given an array of integers representing a sequence, find the **next lexicographical permutation** of that sequence.  
- If the sequence is the highest permutation, rearrange it to the lowest possible order (sorted in ascending order).  
- The next permutation of a sequence is the smallest permutation that is greater than the current one.  

---

## Approach  
To find the next lexicographical permutation:  

1. **Identify the Pivot:**  
   - Traverse the array from right to left to find the first element that is smaller than the element to its right.  
   - This element is called the "pivot."  
   - If no such element is found, the sequence is the highest permutation, so reverse the entire array to get the lowest permutation.  

2. **Find the Successor:**  
   - If a pivot is found, find the smallest element on the right of the pivot that is larger than the pivot.  

3. **Swap the Pivot and Successor:**  
   - Swap the pivot with this successor.  

4. **Reverse the Suffix:**  
   - Reverse the sequence to the right of the pivot to get the next smallest lexicographical order.  

---

## Code Explanation  
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to find the pivot index
int pivotIdx(vector<int>& arr) {
    int piv = -1;
    int n = arr.size();
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) { // Find first decreasing element from the end
            piv = i;
            return piv;
        }
    }
    return -1;
}

// Function to reverse the array
void reverseArr(vector<int>& arr) {
    int i = 0;
    int j = arr.size() - 1;
    while (i < j) {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

// Function to find the next lexicographical permutation
void lexicographicalNext(vector<int>& arr) {
    int n = arr.size();
    int pivot = pivotIdx(arr);

    // If no pivot, reverse the array (it was the highest permutation)
    if (pivot == -1) {
        reverseArr(arr);
        return;
    }

    // Find the smallest element larger than pivot from the right
    for (int i = n - 1; i > pivot; i--) {
        if (arr[i] > arr[pivot]) {
            swap(arr[i], arr[pivot]); // Swap with pivot
            reverseArr(vector<int>(arr.begin() + pivot + 1, arr.end())); // Reverse suffix
            return;
        }
    }
}

// Function to print the array
void print(vector<int>& arr) {
    for (int i : arr)
        cout << i << ",";
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3}; // Initial sequence
    lexicographicalNext(arr);    // Find next permutation
    print(arr);                  // Output the result
    return 0;
}
```

---

## Complexity Analysis  
- **Time Complexity:**  
  - Finding the pivot: **O(n)**  
  - Finding the successor: **O(n)**  
  - Reversing the suffix: **O(n/2)** ≈ **O(n)**  
  - Overall time complexity: **O(n)**  

- **Space Complexity:**  
  - The space complexity is **O(1)** (ignoring input and output storage) as no extra space proportional to input size is used.  

---

## Example  
For the input:  
```cpp
vector<int> arr = {1, 2, 3};
```
The output will be:  
```
1,3,2,
```

For the input:  
```cpp
vector<int> arr = {3, 2, 1};
```
The output will be:  
```
1,2,3,
```

---

## How to Run  
1. Make sure you have a C++ compiler (like g++) installed.  
2. Save the code in a file named `nextPermutation.cpp`.  
3. Open a terminal and navigate to the directory containing the file.  
4. Compile the program using:  
    ```sh
    g++ nextPermutation.cpp -o nextPerm
    ```
5. Run the executable:  
    ```sh
    ./nextPerm
    ```

---

## Key Takeaways  
- This approach efficiently finds the next lexicographical permutation using the **two-pointer technique**.  
- The solution is optimal in terms of time complexity (**O(n)**) and space complexity (**O(1)**).  
- The code is modular with separate functions for finding the pivot, reversing the array, and calculating the next permutation, enhancing readability and maintainability.  