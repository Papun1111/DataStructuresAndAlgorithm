
---

## C++ Program to Find GCD of Two Numbers

### Problem Statement
The goal of this program is to calculate the Greatest Common Divisor (GCD) of two given integers. The GCD of two integers is the largest number that divides both of them without leaving a remainder.

### Intuition
The intuition behind finding the GCD of two numbers is based on the Euclidean algorithm. The Euclidean algorithm is based on the principle that the GCD of two numbers also divides their difference. Hence, we can keep subtracting the smaller number from the larger one and replace the larger number with the difference until one of the numbers becomes zero. The other number, at that point, will be the GCD.

### Approach
The program implements the iterative version of the Euclidean algorithm, which is more efficient than the recursive version for some compilers due to less overhead from recursive calls. Here's how it works:

1. Input two numbers from the user.
2. Use a loop to repeatedly apply the Euclidean step:
   - Replace the larger number by its remainder when divided by the smaller number.
3. Continue this process until one of the numbers becomes zero.
4. The non-zero number at this point is the GCD of the two numbers.

### Time Complexity
The time complexity of the Euclidean algorithm is \( O(\log(\min(a, b))) \), where \( a \) and \( b \) are the two input numbers. This logarithmic complexity makes it very efficient even for large numbers.

### Space Complexity
The space complexity of this program is \( O(1) \) since it uses a constant amount of space regardless of the input size.

### Code
```cpp
#include<iostream>
using namespace std;

// Function to find GCD of two numbers using Euclidean algorithm
int gcd(int a, int b) {
    while (a > 0 && b > 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return b == 0 ? a : b;
}

int main(int argc, char const *argv[]) {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "The GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
    return 0;
}
```

### How to Run
1. Save the above code in a file with a `.cpp` extension, for example, `gcd.cpp`.
2. Compile the program using a C++ compiler like g++: `g++ -o gcd gcd.cpp`.
3. Run the output program: `./gcd`.
4. Follow the on-screen prompts to input two numbers and receive their GCD.

This README explains the essential aspects of the program and provides clear instructions on how to compile and run it, making it accessible for users with varying levels of programming experience.