# Missing and Repeated Number Finder

This C++ program identifies the missing and repeated numbers in a 2D matrix that is supposed to contain consecutive integers from 1 to _n_ (where _n_ is the total number of elements in the matrix). However, one number is missing and one number appears twice (repeated).

## Problem Statement

Given a 2D matrix of size _m x n_ with numbers from 1 to _m*n_, the matrix is expected to have unique numbers in that range. In this scenario:
- One number is missing.
- One number is repeated.

For example, in the matrix:
```
1 2 3
4 5 6
7 9 9
```
the expected sequence is `1, 2, 3, 4, 5, 6, 7, 8, 9`. Here, `8` is missing and `9` is repeated.

## Code Overview

The program is divided into two main parts:

1. **`finding` Function**  
   This function takes the 2D matrix as input and performs the following operations:
   - Iterates through every element in the matrix, accumulating the total sum of all elements.
   - Uses an `unordered_set` to detect if an element has already been seen (i.e., to detect the repeated number).
   - Computes the expected sum of the sequence from 1 to _n_ using the formula:
     \[
     \text{Expected Sum} = \frac{n \times (n + 1)}{2}
     \]
   - Derives the missing number by using the relation:
     \[
     \text{totalSum} = \text{Expected Sum} - \text{missingNumber} + \text{repeatedNumber}
     \]
     which can be rearranged to:
     \[
     \text{missingNumber} = \text{Expected Sum} - (\text{totalSum} - \text{repeatedNumber})
     \]
   - Returns a vector containing the missing number (first element) and the repeated number (second element).

2. **`main` Function**  
   This function:
   - Defines a test matrix.
   - Calls the `finding` function to retrieve the missing and repeated numbers.
   - Prints the results.

## Approach and Mathematical Intuition

### Approach
- **Iteration and Sum Calculation:**  
  The program iterates through the matrix, summing all elements and using an `unordered_set` to identify the repeated number.
  
- **Expected Sum Calculation:**  
  The expected sum for numbers from 1 to _n_ (where _n_ is the total number of elements) is calculated using:
  \[
  \text{Expected Sum} = \frac{n \times (n + 1)}{2}
  \]
  
- **Finding the Missing Number:**  
  Since the actual sum is:
  \[
  \text{totalSum} = \text{Expected Sum} - \text{missingNumber} + \text{repeatedNumber},
  \]
  the missing number is computed by rearranging the equation:
  \[
  \text{missingNumber} = \text{Expected Sum} - (\text{totalSum} - \text{repeatedNumber})
  \]

### Mathematical Intuition
- **Sum Formula:**  
  The formula \(\frac{n(n+1)}{2}\) provides the sum of the first _n_ natural numbers.
  
- **Error Adjustment:**  
  With one number missing and one repeated, the total sum is adjusted by subtracting the missing number and adding the repeated one. This difference helps in accurately retrieving the missing number.

## Space and Time Complexity

- **Time Complexity:**  
  The code processes each element in the matrix once, resulting in a time complexity of:
  \[
  O(n)
  \]
  where _n_ is the total number of elements.

- **Space Complexity:**  
  An `unordered_set` is used to store elements, and in the worst-case scenario, it stores all _n_ elements. Hence, the space complexity is:
  \[
  O(n)
  \]
  Additionally, the result vector uses constant space.

## Conclusion

This program effectively identifies the missing and repeated numbers in a matrix by leveraging basic arithmetic operations and an `unordered_set` for duplicate detection. With a time complexity of \( O(n) \) and space complexity of \( O(n) \), the solution is both efficient and straightforward, making it suitable for matrices of moderate sizes.