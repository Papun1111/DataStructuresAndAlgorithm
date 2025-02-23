
---

### **Code Explanation:**  

The code aims to find the **maximum subset sum** of a given array using **Kadane’s Algorithm**.  

```cpp
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
```
- **Header Files:**  
  - `<iostream>` is for input and output.  
  - `<vector>` is for using dynamic arrays.  
  - `<limits.h>` provides the `INT_MIN` constant, representing the smallest possible integer value.  

---

```cpp
int maxsubsetsum(vector<int>& arr) {
    int currSum = 0, maxSum = INT_MIN;
    for (int i : arr) {
        currSum += i;
        maxSum = max(maxSum, currSum);
        if (currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
}
```

- **Function `maxsubsetsum`:**  
  - Takes a **reference** to a vector of integers `arr`.  
  - Initializes `currSum` to `0` and `maxSum` to `INT_MIN`.  
  - **Iterates** through each element `i` of `arr`:  
    - **Add** the current element to `currSum`.  
    - **Update** `maxSum` with the **maximum** of `maxSum` and `currSum`.  
    - If `currSum` becomes **negative**, **reset** it to `0`.  
  - **Returns** the `maxSum` found.  

---

```cpp
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int maxSum = maxsubsetsum(arr);
    cout << "Maximum subset sum is " << maxSum << endl;
    return 0;
}
```
- **Main Function:**  
  - Initializes a vector `arr` with elements `{1, 2, 3, 4, 5}`.  
  - Calls the `maxsubsetsum` function.  
  - Outputs the **maximum subset sum** to the console.  

---

### **Approach & Algorithm:**  

1. **Initialization:**  
   - `currSum` to track the current sum of the subset.  
   - `maxSum` to track the maximum sum found.  

2. **Iteration:**  
   - Traverse through each element of the array.  
   - Add the element to `currSum`.  
   - If `currSum` exceeds `maxSum`, update `maxSum`.  

3. **Handling Negatives:**  
   - If `currSum` drops below `0`, reset it.  
   - This step ensures that negative sums are discarded to maximize the subset sum.  

4. **Result:**  
   - After traversing the array, `maxSum` holds the result.  

---

### **Algorithm Used: Kadane’s Algorithm**  

**Kadane’s Algorithm** is an efficient method to find the **maximum sum subarray** (continuous subset) in an array.  

- It involves a **greedy approach** and **dynamic programming** concepts.  
- By keeping a running sum (`currSum`) and comparing it to a global maximum (`maxSum`), the algorithm efficiently determines the **best possible sum** without needing nested loops.  

---

### **Time Complexity:**  

- **Time Complexity:** **O(n)**  
  - The algorithm **traverses** the array only **once**, resulting in **linear time complexity**.  

- **Space Complexity:** **O(1)**  
  - The algorithm uses only **a few variables** (`currSum`, `maxSum`), requiring **constant extra space**.  

---

### **Example:**  

**Input:** `arr = {1, 2, 3, 4, 5}`  
**Output:** `Maximum subset sum is 15`  

- **Calculation:**  
  - `1 + 2 + 3 + 4 + 5 = 15`  
  - Since all elements are **positive**, the entire array is the **maximum subset**.  

---
