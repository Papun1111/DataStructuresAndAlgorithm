
## Overview

This project implements a simple string compression algorithm in C++. The code takes a vector of characters, compresses it by replacing consecutive repeated characters with the character followed by the count of repetitions (if greater than one), and then outputs the new compressed length along with the updated vector.

## Problem Statement

Given an input vector of characters, compress it such that:
- For each group of consecutive repeating characters, the character is followed by the number of times it appears if the count is greater than one.
- The algorithm should modify the vector in place and return the new length of the compressed vector.

For example, given the input:
```
{'a','a','b','a','a','b','c'}
```
The compressed vector would be:
```
{'a','2','b','a','2','b','c'}
```
and the function would return the new length of the vector.

## Code Explanation

### Function: `compress`

- **Input:** A reference to a vector of characters `chars`.
- **Process:**
  1. **Iteration:** The function iterates over the vector using a for-loop.
  2. **Counting:** For each character, it counts how many times it repeats consecutively.
  3. **Writing to Vector:** 
     - The character is placed at the current index (`idx`).
     - If the count is greater than one, the count is converted to a string and each digit is added to the vector.
  4. **Resizing:** The vector is resized to the new length after processing.
- **Return:** The new length of the vector after compression.

### Main Function

- **Setup:** Initializes a vector of characters `v` with an example input.
- **Compression:** Calls the `compress` function and stores the returned length.
- **Output:**
  - Prints the new length of the compressed vector.
  - Iterates through the vector to print the compressed characters.

## Output Example

For the input:
```
{'a','a','b','a','a','b','c'}
```
The program will output:
```
7
a 2 b a 2 b c 
```
Here, `7` is the new length, and the sequence `a 2 b a 2 b c` represents the compressed vector.

## Time and Space Complexity

- **Time Complexity:** O(n)
  - The algorithm makes a single pass through the vector.
  
- **Space Complexity:** O(1) (in-place)
  - The algorithm uses a constant amount of extra space, modifying the input vector without additional data structures.

## Additional Details

- **Usage:** Compile the code with a C++ compiler (e.g., `g++ code.cpp -o compress`) and run the resulting executable.
- **Assumptions:** The input vector contains only valid characters, and the vector size can be modified.
- **Notes:** The code utilizes the C++ Standard Library (`<vector>`, `<string>`, and `<iostream>`) for ease of manipulation and output.

This README provides a detailed explanation of the code, including the problem statement, a breakdown of the algorithm, expected outputs, and an analysis of the algorithm's complexity. Use it as a reference to understand or extend the code in the future.