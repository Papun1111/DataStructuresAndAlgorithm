# Two-Sum Problem Solution Using Two-Pointer Approach

This C++ code solves the two-sum problem for a sorted array using an efficient two-pointer approach. Below is an explanation of the problem, the approach taken, and the complexity analysis.

---

## Problem Statement

Given a **sorted array of integers** and a target value, find two distinct numbers in the array that add up to the target. Assume there is exactly one valid solution, and return the pair of numbers once found.

**Example:**  
Input: `arr = [2, 7, 11, 15]`, Target = `9`  
Output: `pair is 2,7`

---

## Approach

The code uses the **two-pointer technique**, which is efficient for sorted arrays. Here’s how it works:

1. **Initialize Pointers**:  
   - `i` starts at the beginning of the array (index 0).  
   - `j` starts at the end of the array (index `size-1`).

2. **Check Sum**:  
   Calculate the sum of elements at `i` and `j`.  
   - If the sum **equals the target**, print the pair and exit.  
   - If the sum is **less than the target**, increment `i` to try a larger value.  
   - If the sum is **greater than the target**, decrement `j` to try a smaller value.

3. **Termination**:  
   The loop runs until `i` and `j` meet, ensuring all valid pairs are checked.

---

## Code Explanation

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    vector<int> arr = {2, 7, 11, 15}; // Sorted input array
    int i = 0;                        // Left pointer
    int j = arr.size() - 1;           // Right pointer

    cout << "Enter target: ";
    int n;
    cin >> n;                          // Read target value

    while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == n) {
            cout << "pair is " << arr[i] << "," << arr[j] << endl;
            break;                     // Exit after finding the first valid pair
        } else if (sum < n) {
            i++;                       // Move left pointer right for a larger sum
        } else {
            j--;                       // Move right pointer left for a smaller sum
        }
    }
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity**: **O(n)**  
  - Each element is visited at most once by the two pointers. In the worst case, the loop runs `n-1` times (where `n` is the array size).

- **Space Complexity**: **O(1)**  
  - Only constant extra space is used for variables (`i`, `j`, `sum`, etc.).

---

## Key Considerations

1. **Sorted Array Requirement**:  
   The two-pointer approach works because the input array is sorted. For unsorted arrays, this method would not work directly.

2. **Single Pair Output**:  
   The code stops after finding the first valid pair. If multiple pairs exist, it will not return all of them.

3. **No Solution Handling**:  
   The code assumes a valid pair exists. If no solution exists, the loop exits without outputting a result. Modify the code to handle this case if needed.

---

## Example Execution

```
Enter target: 9
pair is 2,7
```