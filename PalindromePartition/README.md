# Palindrome Partitioning

This project implements a solution to the "Palindrome Partitioning" problem in C++. The goal is to partition a given string into all possible substrings such that every substring is a palindrome.

---

## Problem Statement

Given a string, partition it in all possible ways such that every substring in the partition is a palindrome. For example, for the input string `"aab"`, the output should be:
- `["a", "a", "b"]`
- `["aa", "b"]`

---

## Approach

The solution employs a **backtracking** strategy:

1. **Recursive Partitioning:**  
   The function recursively explores all possible partitions of the input string. It progressively divides the string, checking each prefix to determine if it is a palindrome.

2. **Palindrome Check:**  
   A helper function uses a two-pointer approach to determine if a substring is a palindrome. It compares characters from the beginning and end of the substring, moving towards the center.

3. **Backtracking:**  
   When a palindrome is found, it is added to the current partition. The function then recursively processes the remaining part of the string. After the recursive call, the solution "backtracks" by removing the last added substring, allowing the exploration of alternative partitioning paths.

---

## Code Explanation

### 1. `isPalindrome(string s)`
- **Purpose:** Checks if the given string `s` is a palindrome.
- **Method:** Uses two pointers (`i` and `j`) that move towards each other from the beginning and end of the string, respectively.
- **Return:** `true` if `s` is a palindrome, `false` otherwise.

### 2. `getAllParts(string s, vector<string>& partition, vector<vector<string>>& ans)`
- **Purpose:** Recursively partitions the string `s` into palindromic substrings.
- **Parameters:**
  - `s`: The current substring to be partitioned.
  - `partition`: The current list of palindrome substrings.
  - `ans`: The list of all possible palindrome partitions.
- **Method:**  
  - If the string is empty, it means a valid partition has been found, so it adds the current partition to `ans`.
  - Otherwise, it iterates over the string to consider every possible prefix. If the prefix is a palindrome, it is added to `partition`, and the function recursively processes the remainder of the string. After recursion, it removes the last element (backtracks) to explore other partitions.

### 3. `partition(string s)`
- **Purpose:** Initializes the process of partitioning.
- **Method:** Creates an empty result list and calls `getAllParts` with the original string.
- **Return:** A vector containing all possible palindrome partitions of `s`.

### 4. `main()`
- **Purpose:** Handles user input and output.
- **Method:**  
  - Prompts the user to enter a string.
  - Calls the `partition` function of the `Solution` class.
  - Outputs all the palindrome partitions.

---

## Time and Space Complexity

### Time Complexity
- **Worst-case Time Complexity:**  
  The time complexity is exponential in nature. In the worst-case scenario (e.g., when every substring is a palindrome), the number of recursive calls is roughly **O(2^n)**. In addition, checking if a substring is a palindrome takes **O(n)** time.  
  **Overall:** **O(n * 2^n)**.

### Space Complexity
- **Space Complexity:**  
  - The recursion depth can go up to **O(n)** in the worst-case scenario.
  - The space required to store the current partition is also **O(n)**.
  - The overall space required to store all partitions depends on the number of valid partitions, which in the worst-case scenario can be exponential.  
  **Overall:** **O(n)** auxiliary space, with exponential space for storing the results in the worst case.

---

## How to Compile and Run

1. **Compilation:**  
   Use a C++ compiler (e.g., `g++`):
   ```bash
   g++ -std=c++11 -o palindrome_partitioning main.cpp
   ```
2. **Execution:**  
   Run the compiled program:
   ```bash
   ./palindrome_partitioning
   ```
3. **Input:**  
   When prompted, enter a string. The program will output all possible palindrome partitions.

---

