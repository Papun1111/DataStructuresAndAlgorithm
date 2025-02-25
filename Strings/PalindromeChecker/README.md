# Palindrome Checker in C++

## Problem Statement  
Given a string, determine if it is a palindrome by reversing the string and comparing it to the original. A palindrome is a string that reads the same forwards and backwards.

### Example:
```
Input: "madam"
Output: This string is a palindrome.

Input: "hello"
Output: This string is not a palindrome.
```

## Approach  
1. Reverse the given string and store it in a new string `rev`.  
2. Compare the reversed string with the original string.  
3. If they are the same, the string is a palindrome; otherwise, it is not.  

## Code  
```cpp
#include<iostream>
#include<string>
using namespace std;

int isPalindrome(string str) {
    string rev = "";
    int size = str.length();
    for(int i = size - 1; i >= 0; i--) {
        rev += str[i];
    }
    if(rev == str) {
        return 1;
    }
    return 0;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    if(isPalindrome(str)) {
        cout << "This string is a palindrome";
    } else {
        cout << "This string is not a palindrome";
    }
    return 0;
}
```

## Explanation  
1. **Input Handling:**  
   - `getline(cin, str);` is used to capture the complete input string, including spaces.  
2. **Reversing the String:**  
   - The `for` loop starts from the end of the string and appends each character to the `rev` string.  
3. **Palindrome Check:**  
   - If the reversed string is equal to the original string, the function returns `1` (true).  
   - Otherwise, it returns `0` (false).  

## Constraints  
1. The string can be of length up to \( 10^5 \).  
2. The string may contain uppercase and lowercase letters, digits, spaces, and special characters.  
3. Palindrome check is case-sensitive. For example, "Madam" is not considered a palindrome.  

## Complexity Analysis  
- **Time Complexity:** \( O(N) \), where \( N \) is the length of the string.  
  - Reversing the string takes \( O(N) \) time.  
  - Comparing the original and reversed string takes \( O(N) \) time.  
- **Space Complexity:** \( O(N) \) for the reversed string.  

## Edge Cases Considered  
1. An empty string is considered a palindrome.  
2. Case sensitivity is preserved (e.g., "Abba" is not a palindrome, but "abba" is).  
3. Strings with spaces and special characters are compared as-is.  

## Sample Input and Output  
```
Input: "madam"
Output: This string is a palindrome.

Input: "racecar"
Output: This string is a palindrome.

Input: "hello"
Output: This string is not a palindrome.

Input: "A man a plan a canal Panama"
Output: This string is not a palindrome (case-sensitive and includes spaces).
```

## Limitations  
- This implementation is case-sensitive. To make it case-insensitive, `tolower()` can be applied to both the original and reversed strings.  
- It does not ignore non-alphanumeric characters. For a more flexible check, filtering out special characters and spaces would be necessary.  

## Comparison with Two-pointer Approach  
- This solution uses additional space for the reversed string, leading to a space complexity of \( O(N) \).  
- The two-pointer approach is more space-efficient as it checks characters in-place without storing the reversed string.  

## Conclusion  
This palindrome checker is straightforward and uses a reversal-based approach to validate a palindrome. It is efficient in terms of time complexity but uses additional space to store the reversed string.