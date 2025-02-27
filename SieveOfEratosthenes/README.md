
# Prime Counting Program  

## Problem Statement  

The program counts the number of prime numbers less than a given integer `n`. A prime number is a natural number greater than `1` that has no positive divisors other than `1` and itself. The function returns the count of such numbers in the range `[2, n)`.  

## Approach and Logic  

The program uses the **Sieve of Eratosthenes** algorithm to efficiently count prime numbers.  

### Steps:  

1. **Initialize a Boolean Vector:**  
   - Create a vector `v` of size `n+1` initialized to `true`, where `v[i]` represents whether `i` is prime.  

2. **Iterate from `2` to `n-1`:**  
   - If `i` is marked as `true`, it is prime.  
   - Increment the count of prime numbers.  
   - Mark all multiples of `i` as `false`, indicating they are not prime.  

3. **Return the Count of Primes.**  

This efficiently eliminates non-prime numbers while iterating through the list, making it significantly faster than checking each number individually.  

## Code  

```cpp
#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    int ans = 0;
    vector<bool> v(n + 1, true);
    for (int i = 2; i < n; i++) {
        if (v[i]) {
            ans++;
            for (int j = i * 2; j < n; j += i) {
                v[j] = false;
            }
        }
    }
    return ans; 
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int count = countPrimes(n);
    cout << count << endl;
    return 0;
}
```

## Time and Space Complexity  

### **Time Complexity:**  
- The Sieve of Eratosthenes runs in **O(n log log n)** time, which is much faster than checking each number individually (**O(n√n)** in naive methods).  
- The inner loop runs approximately `n/2 + n/3 + n/5 + ...`, leading to the **O(n log log n)** complexity.  

### **Space Complexity:**  
- The algorithm uses a boolean vector of size `O(n)`, resulting in **O(n)** space complexity.  

## Example  

**Input:**  
```
Enter the number: 10
```
**Output:**  
```
4
```
(Prime numbers less than 10: **2, 3, 5, 7**)  

## Summary  
- The program efficiently counts prime numbers using the **Sieve of Eratosthenes**.  
- It runs in **O(n log log n)** time and uses **O(n)** space.  
- This approach is well-suited for counting primes in large ranges.  

---

This README provides clarity on the problem, approach, implementation, and efficiency of the solution. 🚀