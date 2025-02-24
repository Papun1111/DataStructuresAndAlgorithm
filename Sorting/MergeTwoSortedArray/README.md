# Merge Two Sorted Arrays  

This C++ program merges two sorted arrays into a single sorted array using the two-pointer technique. The merged array maintains the sorted order.  

---

## Table of Contents  
1. [Overview](#overview)  
2. [Approach](#approach)  
3. [Code Explanation](#code-explanation)  
4. [Complexity Analysis](#complexity-analysis)  
5. [Example](#example)  
6. [How to Run](#how-to-run)  

---

## Overview  
The program merges two sorted arrays (`arr1` and `arr2`) into a third array (`arr3`) while maintaining the sorted order. It uses the two-pointer technique to efficiently merge both arrays in a single pass.  

---

## Approach  
1. **Two-Pointer Technique:**  
   - Two pointers (`i` and `j`) are used to traverse `arr1` and `arr2` respectively.  
   - A third pointer (`k`) tracks the position in the merged array (`arr3`), although it isn't explicitly used as we're using `push_back()`.  

2. **Comparison and Merging:**  
   - Compare elements at `arr1[i]` and `arr2[j]`.  
   - If `arr1[i] < arr2[j]`, push `arr1[i]` to `arr3` and increment `i`.  
   - Else, push `arr2[j]` to `arr3` and increment `j`.  

3. **Handling Remaining Elements:**  
   - If one array is fully traversed while the other still has elements, append the remaining elements directly to `arr3`.  

---

## Code Explanation  
```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted arrays into a third sorted array
void mergeSorted(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
    int i = 0, j = 0;
    int arr1size = arr1.size();
    int arr2size = arr2.size();

    // Merge both arrays until one is exhausted
    while (i < arr1size && j < arr2size) {
        if (arr1[i] < arr2[j]) {
            arr3.push_back(arr1[i]); // Add element from arr1
            i++;
        } else {
            arr3.push_back(arr2[j]); // Add element from arr2
            j++;
        }
    }

    // Copy remaining elements of arr1 (if any)
    while (i < arr1size) {
        arr3.push_back(arr1[i]);
        i++;
    }

    // Copy remaining elements of arr2 (if any)
    while (j < arr2size) {
        arr3.push_back(arr2[j]);
        j++;
    }
}

// Function to print the merged array
void print(vector<int>& sortarr) {
    for (int i : sortarr) {
        cout << i << ",";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4}; // First sorted array
    vector<int> arr2 = {9, 10, 14};  // Second sorted array
    vector<int> arr3;                // Merged sorted array

    // Merge the two arrays
    mergeSorted(arr1, arr2, arr3);

    // Print the merged array
    print(arr3);

    return 0;
}
```

---

## Complexity Analysis  
- **Time Complexity:**  
  - The time complexity is **O(n + m)**, where:  
    - `n` is the size of `arr1`  
    - `m` is the size of `arr2`  
  - This is because each element is processed exactly once.  

- **Space Complexity:**  
  - The space complexity is **O(n + m)** because a new array (`arr3`) is used to store all elements of `arr1` and `arr2`.  

---

## Example  
For the input:  
```cpp
vector<int> arr1 = {1, 2, 3, 4};
vector<int> arr2 = {9, 10, 14};
```
The output will be:  
```
1,2,3,4,9,10,14,
```

---

## How to Run  
1. Make sure you have a C++ compiler (like g++) installed.  
2. Save the code in a file named `mergeSortedArrays.cpp`.  
3. Open a terminal and navigate to the directory containing the file.  
4. Compile the program using:  
    ```sh
    g++ mergeSortedArrays.cpp -o merge
    ```
5. Run the executable:  
    ```sh
    ./merge
    ```

---

## Key Takeaways  
- This approach efficiently merges two sorted arrays using the two-pointer technique.  
- The solution is optimal in terms of time complexity (**O(n + m)**) and space complexity (**O(n + m)**).  
- The code is modular with separate functions for merging and printing, enhancing readability and maintainability.  