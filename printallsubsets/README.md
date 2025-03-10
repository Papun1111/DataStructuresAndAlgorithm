# Subset Generation Using Recursion and Backtracking

This repository contains a C++ program that generates and prints all possible subsets (also known as the power set) of a given array of integers.

---

## Problem Statement

The goal of this program is to generate all subsets of an input array. A subset is any combination of the array's elements, including the empty set and the set containing all elements. For an array of size *n*, there are \(2^n\) possible subsets. This program systematically explores all combinations using recursion and backtracking.

---

## Code Explanation

### `printArr` Function
- **Purpose:**  
  Prints the elements of a subset.
  
- **How it works:**  
  It iterates over the vector `ans` and prints each integer, then ends the line.
  
- **Code snippet:**
  ```cpp
  void printArr(vector<int> ans){
      for(int i : ans){
          cout << i;
      }
      cout << endl;
  }
  ```

### `printallsubsets` Function
- **Purpose:**  
  Recursively generates and prints all subsets of the array.
  
- **Parameters:**
  - `arr`: A reference to the original vector containing the array elements.
  - `ans`: A vector that holds the current subset being constructed (default is an empty vector).
  - `i`: The current index in the array (default is 0).

- **Approach:**
  - **Base Case:**  
    When `i` equals the size of `arr`, it means a subset has been fully constructed. The function prints the subset using `printArr` and returns.
  
  - **Recursive Steps:**  
    1. **Include the Current Element:**  
       The current element (`arr[i]`) is added to `ans`. The function then calls itself with the next index (`i+1`) to continue building the subset.
       
    2. **Exclude the Current Element:**  
       After the recursive call returns, the function removes the last element (backtracks) and makes another recursive call without including the current element. This explores the possibility of the subset without that element.
  
- **Code snippet:**
  ```cpp
  void printallsubsets(vector<int>& arr, vector<int> ans = {}, int i = 0){
      if(i == arr.size()){
          printArr(ans);
          return;
      }
      ans.push_back(arr[i]);
      printallsubsets(arr, ans, i + 1);
      ans.pop_back();
      printallsubsets(arr, ans, i + 1);
  }
  ```

### `main` Function
- **Purpose:**  
  Sets up the initial vector and calls the subset generation function.
  
- **How it works:**  
  It initializes a vector `v` with the integers `{1,2,3,4,5,6}` and then calls `printallsubsets` to generate and print all possible subsets.
  
- **Code snippet:**
  ```cpp
  int main(int argc, char const *argv[]) {
      vector<int> v = {1,2,3,4,5,6};
      printallsubsets(v);
      return 0;
  }
  ```

---

## Approach Taken

- **Recursion:**  
  The solution uses recursion to explore every possible combination of including or excluding each element of the array.

- **Backtracking:**  
  After exploring the branch where an element is included, the algorithm backtracks by removing the element from the current subset (`ans.pop_back()`) and explores the branch where the element is excluded.

- **Subset Generation:**  
  This systematic inclusion/exclusion ensures that all \(2^n\) subsets are generated. In the given example with 6 elements, the program prints all \(2^6 = 64\) subsets.

---

## Complexity Analysis

- **Time Complexity:**  
  - There are \(2^n\) subsets for an array of size \(n\).
  - In the worst case, printing each subset takes \(O(n)\) time.
  - **Overall Time Complexity:** \(O(n \times 2^n)\)

- **Space Complexity:**  
  - The recursion depth can go up to \(n\), and the additional vector `ans` also holds up to \(n\) elements in the worst case.
  - **Overall Space Complexity:** \(O(n)\)

---

## Conclusion

This program provides a clear demonstration of how to use recursion and backtracking to solve the subset generation problem. It efficiently generates all possible subsets of a given array, and its approach is widely applicable in problems involving combinations, such as generating power sets or exploring decision trees.

Feel free to explore and modify the code to better understand the underlying concepts of recursion and backtracking!

