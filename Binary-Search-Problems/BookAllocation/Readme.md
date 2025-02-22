Here’s the README that you can copy and paste:

---

# Book Allocation Problem - README

## Problem Description

The problem is based on allocating books to students such that each student gets at least one book and no student is assigned more than a specified number of pages. We are given:

- A set of books, each having a certain number of pages.
- A number of students (`m`) and the total number of books (`n`).
- The goal is to assign books to students such that the maximum number of pages assigned to a student is minimized.

The task is to implement a function that determines the optimal allocation of books, such that the maximum number of pages assigned to any student is as small as possible. The number of students should be less than or equal to the number of books.

### Input:

- `arr[]`: An array where each element represents the number of pages in a book.
- `n`: The total number of books.
- `m`: The total number of students.

### Output:

- The smallest maximum number of pages assigned to a student when the books are optimally allocated.

---

## Approach

The problem is solved using **binary search** in combination with a greedy strategy.

### Key Concepts:

1. **Binary Search**: 
   We use binary search to find the smallest possible maximum pages that a student can be assigned. The possible range of "maximum pages per student" lies between:
   - The maximum number of pages in a single book (`max(arr)`).
   - The sum of all book pages (`sum(arr)`).

2. **Greedy Strategy**:
   We iteratively assign books to students, making sure the total number of pages given to each student does not exceed a certain threshold (`maxAllowedPages`). If adding a book would exceed this threshold, a new student is assigned the book.

### Steps:

1. **Binary Search**:
   - Set `start` as the maximum number of pages in a single book (i.e., `max(arr)`).
   - Set `end` as the total number of pages in all books (i.e., `sum(arr)`).
   - The mid-point (`mid`) in the binary search will be the candidate for the maximum pages any student can be assigned.
   
2. **Checking Validity (Greedy)**:
   - For each candidate `mid`, we use a greedy approach to check if it’s possible to allocate the books to the students such that no student has more than `mid` pages. If the allocation is possible, we adjust the binary search bounds to search for a smaller `maxAllowedPages`.

3. **Stopping Condition**:
   - When the binary search concludes, the optimal `maxAllowedPages` is found.

---

## Code Explanation

```cpp
#include<iostream>
#include<vector>
using namespace std;

// Function to check if it's possible to allocate books with the given maxAllowedPages
bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages) {
    int stu = 1, pages = 0;  // We start with the first student and 0 pages
    for (int i : arr) {
        if (i > maxAllowedPages) {
            return false;  // If a book has more pages than maxAllowedPages, it's not possible
        }
        if (pages + i <= maxAllowedPages) {
            pages += i;  // Add this book to the current student
        } else {
            stu++;  // Assign a new student
            pages = i;  // Assign the current book to the new student
        }
    }
    return stu <= m;  // If the number of students exceeds m, it's not possible
}

// Function to compute the total sum of pages in all books
int summation(vector<int>& arr) {
    int sum = 0;
    for (int i : arr) {
        sum += i;
    }
    return sum;
}

// Function to find the optimal book allocation
int allocation(vector<int>& arr, int n, int m) {
    if (m > n) {
        return -1;  // If the number of students is greater than the number of books, return -1 (impossible)
    }

    // Binary search for the smallest possible "maximum allowed pages"
    int st = *max_element(arr.begin(), arr.end());  // Start from the largest book pages
    int end = summation(arr);  // End at the sum of all book pages
    int ans = 0;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isValid(arr, n, m, mid)) {
            ans = mid;  // Found a possible solution, try to minimize further
            end = mid - 1;  // Search for smaller maxAllowedPages
        } else {
            st = mid + 1;  // Search for larger maxAllowedPages
        }
    }

    return ans;  // Return the optimal maxAllowedPages
}

int main() {
    vector<int> arr = {2, 1, 3, 4};  // Array of book pages
    int n = 4, m = 2;  // 4 books and 2 students
    cout << allocation(arr, n, m) << endl;  // Output the result
    return 0;
}
```

### Explanation of Code:

1. **`isValid` function**:
   - It checks if it's possible to allocate the books to students such that no student has more than `maxAllowedPages`. It tries to allocate books greedily, and if a student exceeds the `maxAllowedPages`, it moves to the next student.

2. **`summation` function**:
   - This function simply calculates the total sum of pages in all books.

3. **`allocation` function**:
   - It implements binary search to minimize the maximum pages a student gets. It starts with `st` as the largest book size (`max(arr)`) and `end` as the total sum of all book pages (`sum(arr)`). For each midpoint, it calls the `isValid` function to check if that allocation is possible, adjusting the search bounds accordingly.

4. **`main` function**:
   - The main function sets up the input (array of books and students) and calls the `allocation` function to get the result, which is then printed.

---

## Example Input and Output:

**Example 1:**

Input:
```cpp
vector<int> arr = {2, 1, 3, 4};
int n = 4, m = 2;
```

Output:
```cpp
5
```

Explanation:
- The optimal allocation is:
  - Student 1 gets books with 2 and 3 pages, totaling 5 pages.
  - Student 2 gets books with 1 and 4 pages, also totaling 5 pages.
  
Thus, the minimum maximum pages assigned to any student is 5.

---

## Time and Space Complexity

- **Time Complexity**:
  - Binary search runs in `O(log(sum))` where `sum` is the total sum of pages in all books.
  - The `isValid` function runs in `O(n)` where `n` is the number of books.
  - Therefore, the overall time complexity is `O(n * log(sum))`.

- **Space Complexity**:
  - The space complexity is `O(1)` since no extra space is used other than a few integer variables.

---

This approach efficiently solves the problem of allocating books to students with the least maximum pages per student using binary search and greedy allocation.

