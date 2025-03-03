# Two Sum Problem

This project demonstrates multiple approaches to solve the **Two Sum** problem in C++. The task is to identify two distinct indices in an array such that the corresponding elements sum up to a specified target value.

---

## Problem Statement

Given an array of integers and a target integer, the goal is to return the indices of the two numbers such that their sum equals the target. You can assume that there is exactly one solution for each input, and you may not use the same element twice.

---

## Approach 1: Hash Map (Optimized Approach)

This is the implemented solution in the provided code. It uses an unordered map (hash table) to efficiently find the complement of each element.

### Code Explanation

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find two indices such that their values sum to the target.
vector<int> twosum(vector<int> &nums, int target)
{
    vector<int> result;               // To store the resulting indices.
    unordered_map<int, int> m;        // Map to store numbers and their indices.

    // Iterate over the vector.
    for (int i = 0; i < nums.size(); i++)
    {
        int first = nums[i];          // Current element.
        int second = target - first;  // Complement value required to reach the target.
        
        // Check if the complement is already in the map.
        if (m.find(second) != m.end())
        {
            result.push_back(m[second]); // Index of the complement.
            result.push_back(i);         // Current index.
            return result;               // Return as soon as the pair is found.
        }
        
        // Store the current element and its index in the map.
        m[first] = i;
    }
    
    return result;  // Return result (empty if no pair is found, though problem guarantees a solution).
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {5, 2, 7, 11, 15};  // Example input array.
    int target = 9;                        // Example target sum.
    vector<int> result = twosum(nums, target);
    cout << result[0] << " " << result[1] << endl;  // Output the indices.
    return 0;
}
```

#### How It Works:
- **Initialization:**  
  A vector `result` is prepared to store the answer, and an `unordered_map` `m` is used to keep track of numbers and their indices.

- **Iteration:**  
  For each number in `nums`, its complement (i.e., `target - current number`) is computed. If this complement is already in the map, the solution is found, and the indices are returned.

- **Storage:**  
  If the complement is not found, the current number and its index are stored in the map for future lookups.

### Complexity Analysis
- **Time Complexity:** O(n)  
  Each element is processed once, and hash table lookups are O(1) on average.
- **Space Complexity:** O(n)  
  In the worst-case scenario, all elements are stored in the hash map.

---

## Alternative Approaches

### Approach 2: Brute Force

#### Description
This straightforward method uses two nested loops to check every possible pair in the array to see if they sum up to the target.

#### Code Example

```cpp
vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    // Iterate over all pairs using two loops.
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {  // Check if the sum of the pair equals the target.
                return {i, j};  // Return the indices immediately when a valid pair is found.
            }
        }
    }
    return {};  // Return an empty vector if no solution is found (not expected as per problem statement).
}
```

#### Complexity Analysis
- **Time Complexity:** O(n²)  
  Every pair is checked which results in quadratic time complexity.
- **Space Complexity:** O(1)  
  No extra space is used apart from the result vector.

---

### Approach 3: Sorting with Two-Pointer Technique

#### Description
This approach sorts the array while keeping track of the original indices. Then, it uses two pointers (one starting from the beginning and one from the end) to efficiently search for the pair that sums to the target.

#### Code Example

```cpp
#include <algorithm>  // Required for sort and pair

vector<int> twoSumTwoPointer(vector<int>& nums, int target) {
    // Create a vector of pairs where each pair contains the number and its original index.
    vector<pair<int, int>> nums_with_index;
    for (int i = 0; i < nums.size(); i++) {
        nums_with_index.push_back({nums[i], i});
    }
    
    // Sort the vector based on the numbers.
    sort(nums_with_index.begin(), nums_with_index.end());
    
    // Initialize two pointers.
    int left = 0;
    int right = nums_with_index.size() - 1;
    
    // Search for the pair with the given target sum.
    while (left < right) {
        int sum = nums_with_index[left].first + nums_with_index[right].first;
        
        if (sum == target) {
            // Return the original indices of the found pair.
            return {nums_with_index[left].second, nums_with_index[right].second};
        } else if (sum < target) {
            left++;   // Move left pointer right to increase the sum.
        } else {
            right--;  // Move right pointer left to decrease the sum.
        }
    }
    
    return {};  // Return an empty vector if no valid pair is found (should not happen as per problem constraints).
}
```

#### Complexity Analysis
- **Time Complexity:** O(n log n)  
  Sorting the array dominates the complexity. The two-pointer search itself is O(n).
- **Space Complexity:** O(n)  
  Additional space is used to store the vector of pairs (number and original index).

#### Challenges:
- Sorting changes the order of elements, so it's necessary to track original indices to return the correct answer.

---

## Conclusion

- **Hash Map Approach:**  
  Offers an optimal solution with linear time complexity and is simple to implement.
- **Brute Force Approach:**  
  Is easy to understand but inefficient for large inputs due to its quadratic time complexity.
- **Sorting with Two-Pointer Technique:**  
  Provides a balanced alternative but requires additional steps to preserve original indices.

This README summarizes the problem, explains the provided code in detail, and outlines alternative methods to solve the Two Sum problem. Each approach comes with its trade-offs in terms of time and space complexity, making it useful to choose the right method based on the problem constraints and input size.