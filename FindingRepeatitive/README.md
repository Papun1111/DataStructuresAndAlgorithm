# Find the Duplicate Number

This repository contains a solution to the "Find the Duplicate Number" problem using Floyd's Tortoise and Hare (Cycle Detection) algorithm. The approach efficiently detects the duplicate number in an array without modifying it and using only constant extra space.

---

## Problem Statement

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive, there is exactly one repeated number in `nums`. Your task is to find and return this repeated number.

**Constraints:**
- `1 <= n <= 10^5`
- `nums.length == n + 1`
- `1 <= nums[i] <= n`
- All integers in `nums` appear only once except for precisely one integer which appears two or more times.

**Example 1:**
```
Input: nums = [1, 3, 4, 2, 2]
Output: 2
```

**Example 2:**
```
Input: nums = [3, 1, 3, 4, 2]
Output: 3
```

**Example 3:**
```
Input: nums = [3, 3, 3, 3, 3]
Output: 3
```

---

## Explanation

The problem guarantees that there is exactly one duplicate in the array. Given that the numbers are in the range `[1, n]` and the array size is `n + 1`, the array can be seen as representing a linked list where each value in the array points to the next index. Due to the duplicate, a cycle will be formed in this "linked list."

---

## Approach & Intuition

### Floyd's Tortoise and Hare Algorithm

The solution leverages the cycle detection algorithm known as Floyd's Tortoise and Hare. Here's how it works:

1. **Cycle Detection:**
   - **Initialization:** Two pointers, `slow` and `fast`, are both initialized to the first element of the array.
   - **Movement:** In each iteration, `slow` moves one step (`slow = nums[slow]`), while `fast` moves two steps (`fast = nums[nums[fast]]`).
   - **Meeting Point:** The two pointers will eventually meet inside the cycle. This meeting point confirms the existence of a cycle in the array.

2. **Finding the Duplicate:**
   - **Reset Slow Pointer:** Once a meeting point is found, reset the `slow` pointer to the beginning of the array.
   - **Step Both Pointers:** Now move both pointers one step at a time. The point at which they meet again is the entrance to the cycle, which is the duplicate number.

### Why This Works

- **Cycle Formation:** The duplicate number forces two indices to point to the same next index, creating a cycle in the "linked list" formed by the array.
- **Cycle Entrance:** The cycle entrance corresponds to the duplicate element because it is the only number that is repeated and thus forms the loop.

---

## Code Explanation

```cpp
#include<iostream>
#include<vector>
using namespace std;

int findingRepeat(vector<int> v) {
    int slow = v[0], fast = v[0];

    // Phase 1: Finding the intersection point in the cycle.
    do {
        slow = v[slow];
        fast = v[v[fast]];
    } while (slow != fast);

    // Phase 2: Finding the entrance to the cycle.
    slow = v[0];
    while (slow != fast) {
        slow = v[slow];
        fast = v[fast];
    }
    return slow;
}

int main(int argc, char const *argv[]) {
    vector<int> v = {1, 3, 4, 2, 2};
    int x = findingRepeat(v);
    cout << "Repeated Element is: " << x;
    return 0;
}
```

### Detailed Walkthrough:

- **Initialization:**  
  Both `slow` and `fast` pointers are initialized to the first element of the vector `v[0]`.

- **Cycle Detection (Phase 1):**  
  The `do-while` loop updates the pointers:
  - `slow` moves one step at a time.
  - `fast` moves two steps at a time.
  
  The loop terminates when `slow` equals `fast`, indicating an intersection within the cycle.

- **Finding Cycle Entrance (Phase 2):**  
  The `slow` pointer is reset to the beginning of the vector, and then both pointers move one step at a time. The position where they meet is the duplicate number.

- **Output:**  
  The `main` function demonstrates the solution using a sample vector and prints the duplicate element.

---

## Complexity Analysis

- **Time Complexity:**  
  The algorithm runs in O(n) time. In the worst case, both pointers traverse the cycle at most a couple of times, ensuring linear time relative to the number of elements.

- **Space Complexity:**  
  The solution uses O(1) extra space because the algorithm only employs a few pointers and does not allocate additional data structures that scale with the input size.

---

## Conclusion

This solution effectively finds the duplicate number in an array by converting the problem into a cycle detection scenario and applying Floyd's Tortoise and Hare algorithm. It meets the problem constraints by not modifying the input array and using constant extra space while maintaining a linear time complexity.

Feel free to reach out if you have any questions or need further clarifications regarding the approach or implementation!