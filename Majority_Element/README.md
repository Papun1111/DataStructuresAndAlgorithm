# Majority Element Finder using Moore's Voting Algorithm

This repository contains a C++ implementation to find the **majority element** in an array using the **Moore's Voting Algorithm**. The majority element is defined as the element that appears more than ⌊n/2⌋ times in the array. It is assumed that the array always contains a majority element.

---

## Problem Statement

Given an array of integers, the task is to find the element that appears more than ⌊n/2⌋ times. For example, in the array:

```cpp
vector<int> arr = {1, 2, 2, 2, 1, 2, 1, 2, 1, 1};
```

The majority element is `2` if it appears more than half the time (depending on the input guarantee). In our code example, the input is assumed to always contain a valid majority element.

---

## Approach: Moore's Voting Algorithm

The solution leverages **Moore's Voting Algorithm**, which works in two steps:

1. **Candidate Identification:**  
   Traverse through the array while maintaining a candidate and a counter.  
   - If the counter is 0, select the current element as the candidate.
   - For every element in the array, increment the counter if it matches the candidate, otherwise decrement the counter.

2. **Result:**  
   The candidate left after the iteration is the majority element. (In some implementations, a second pass may be required to verify that the candidate is indeed the majority, but this is skipped here because the problem guarantees the existence of a majority element.)

This algorithm is highly efficient for this problem.

---

## Complexity Analysis

- **Time Complexity:**  
  The algorithm makes a single pass through the array, so the time complexity is **O(n)**, where *n* is the number of elements in the array.

- **Space Complexity:**  
  Only a few extra variables are used (the candidate and a counter), so the space complexity is **O(1)**.

---

## Code Explanation

```cpp
#include<iostream>
#include<vector>
using namespace std;

// Function to find the majority element using Moore's Voting Algorithm
int majority(vector<int>& arr) {
    int freq = 0, ans = 0;
    for (int i : arr) {
        // When count drops to 0, choose the new element as a candidate
        if (freq == 0) {
            ans = i;
        }
        // Increase count if the current element matches the candidate, otherwise decrease it
        if (ans == i) {
            freq++;
        } else {
            freq--;
        }
    }
    return ans; // The candidate is the majority element
}

int main(int argc, char const *argv[]) {
    // Example array
    vector<int> arr = {1, 2, 2, 2, 1, 2, 1, 2, 1, 1};
    
    // Find the majority element
    int major = majority(arr);
    
    // Output the majority element
    cout << "Majority Element is: " << major;
    return 0;
}
```

### Step-by-Step Explanation:

1. **Include Headers and Setup:**
   - The program includes `<iostream>` for input/output operations and `<vector>` to use the dynamic array container.

2. **The `majority` Function:**
   - **Variables:**  
     - `freq`: Keeps track of the frequency of the current candidate.
     - `ans`: Holds the current candidate for the majority element.
   - **Iteration through the Array:**  
     - For each element `i` in the array, if `freq` is zero, the candidate `ans` is set to `i`.
     - If `i` equals the candidate `ans`, the counter is incremented.
     - Otherwise, the counter is decremented.
   - **Return:**  
     - After iterating through the array, the function returns the candidate, which is the majority element.

3. **`main` Function:**
   - Initializes the example array.
   - Calls the `majority` function to determine the majority element.
   - Outputs the result using `cout`.

---

## Usage

1. **Compilation:**
   Compile the code using a C++ compiler:
   ```bash
   g++ -o majority_element majority_element.cpp
   ```
2. **Execution:**
   Run the compiled executable:
   ```bash
   ./majority_element
   ```

---

## Conclusion

This implementation efficiently finds the majority element in an array using Moore's Voting Algorithm with O(n) time complexity and O(1) space complexity. The provided code is simple and demonstrates how the algorithm works step-by-step.

Happy coding!