# Palindrome Validator in C++

## Problem Statement  
Given a string, determine if it is a valid palindrome, considering only alphanumeric characters and ignoring cases. The string can contain spaces, punctuation, and other non-alphanumeric characters, which should be ignored while checking for the palindrome property.

### Example:
```
Input: "A man, a plan, a canal: Panama"
Output: Yes, it is a valid palindrome.

Input: "race a car"
Output: No, the string is not a valid palindrome.
```

## Approach
The code checks if a given string is a valid palindrome by:  
1. Initializing two pointers, one at the start (`st`) and another at the end (`end`) of the string.  
2. Ignoring non-alphanumeric characters by moving the pointers accordingly.  
3. Comparing characters in a case-insensitive manner using `tolower()`.  
4. Returning `false` if a mismatch is found, otherwise continuing to check until the pointers cross.  
5. Returning `true` if the entire string is validated successfully.  

## Code
```cpp
#include<iostream>
#include<string>
using namespace std;

bool isValidPalindrome(string s) {
    int st = 0, end = s.length() - 1;
    while (st < end) {
        if (!isalnum(s[st])) {
            st++;
            continue;
        }
        if (!isalnum(s[end])) {
            end--;
            continue;
        }
        if (tolower(s[st]) != tolower(s[end])) {
            return false;
        }
        st++;
        end--;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    if (!isValidPalindrome(s)) {
        cout << "No, the string is not a valid palindrome.";
    } else {
        cout << "Yes, it is a valid palindrome.";
    }
    return 0;
}
```

## Explanation  
1. **Input Handling:**  
   - The input is taken using `getline(cin, s);` to allow spaces within the string.  
2. **Character Validation:**  
   - `isalnum()` is used to check if a character is alphanumeric.  
   - `tolower()` ensures case insensitivity during comparison.  
3. **Two-pointer Technique:**  
   - `st` starts from the beginning, and `end` starts from the end of the string.  
   - The pointers are moved inward, skipping non-alphanumeric characters.  
   - If characters don't match, the function returns `false`.  
   - If all characters match, the function returns `true`.  

## Constraints  
1. The string can be of length up to \( 10^5 \).  
2. It may contain uppercase and lowercase letters, digits, spaces, and special characters.  
3. An empty string is considered a valid palindrome.  

## Complexity Analysis  
- **Time Complexity:** \( O(N) \), where \( N \) is the length of the string.  
  - Each character is checked at most once, and the two pointers traverse the string linearly.  
- **Space Complexity:** \( O(1) \) additional space, apart from the input string.  
  - Only a few variables (`st`, `end`) are used.  

## Edge Cases Considered  
1. Strings with only special characters (e.g., "!@#$%") — considered valid palindrome.  
2. Empty string — considered valid palindrome.  
3. Case insensitivity (e.g., "AbBa" → valid palindrome).  
4. Numeric palindromes (e.g., "12321" → valid palindrome).  

## Sample Input and Output  
```
Input: "A man, a plan, a canal: Panama"
Output: Yes, it is a valid palindrome.

Input: "No lemon, no melon"
Output: Yes, it is a valid palindrome.

Input: "Hello, World!"
Output: No, the string is not a valid palindrome.
```

## Why Use Two-pointer Technique?  
- Efficiently checks characters from both ends, reducing the number of comparisons.  
- Skips non-alphanumeric characters gracefully.  

## Conclusion  
This solution efficiently validates a string as a palindrome by ignoring non-alphanumeric characters and being case insensitive. The two-pointer approach ensures optimal time complexity, making the solution suitable for long strings.