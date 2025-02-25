# Remove All Occurrences of a Substring in C++

## Problem Statement  
Given a string `s` and a substring `part`, the task is to remove all occurrences of `part` from `s`. The removal should be done iteratively until no more occurrences of `part` are found in `s`. The remaining string should then be printed as the result.  

### Example:  
```
Input: 
  s = "abcbcabc"
  part = "bc"
Output: 
  "aa"
```

In the example, all occurrences of `"bc"` are removed from the string `"abcbcabc"`, leaving `"aa"` as the result.

---

## Code Explanation  
This C++ program achieves the desired output using a custom function named `removeAllOccurances()`, which removes all instances of the substring `part` from the string `s`.

### Code:
```cpp
#include <iostream>
#include <string>
using namespace std;

string removeAllOccurances(string s, string part) {
    while (s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << "Enter part: ";
    string part;
    cin >> part;
    string str = removeAllOccurances(s, part);
    cout << "Resulting string: " << str;
    return 0;
}
```

---

## Approach Taken  
1. **Input Handling**:  
   - The program first takes the input string `s` using `getline()` to allow spaces within the string.  
   - It then takes the substring `part` using `cin`.  

2. **Removal of Substring**:  
   - A `while` loop is used to check if `part` exists in `s` using `s.find(part)`.  
   - If found, `erase()` is used to remove the occurrence of `part` from `s`.  
   - The loop continues until no more occurrences of `part` are found.  

3. **Output**:  
   - The modified string is returned and displayed as the result.

---

## Functions and Methods Used  
1. **getline(cin, s)**:  
   - Used to take input of the full string including spaces.

2. **s.find(part)**:  
   - Finds the first occurrence of `part` in `s`.  
   - Returns the starting index if found, or `string::npos` if not found.  

3. **s.erase(pos, len)**:  
   - Removes a substring starting at index `pos` with a length of `len`.  
   - In this program, `pos` is the index where `part` is found, and `len` is the length of `part`.  

4. **return s;**:  
   - Returns the modified string after all occurrences are removed.

---

## Time Complexity  
- **O(N * M)**, where:  
  - `N` is the length of the string `s`.  
  - `M` is the length of the substring `part`.  
  - In the worst case, `find()` and `erase()` may be called multiple times, leading to the complexity.  

## Space Complexity  
- **O(1)** (excluding input storage), since no additional space proportional to the input size is used.  
- The modifications are done in-place on the string `s`.

---

## Example Run  
```
Enter a string: abcbcabc
Enter part: bc
Resulting string: aa
```

### Explanation:  
- The first occurrence of `"bc"` is found at index 1, and the string becomes `"aabc"`.  
- The next occurrence is at index 2, resulting in `"aa"`.  
- No more `"bc"` substrings are found, and the loop terminates.

---

## Edge Cases Considered  
1. If `part` is not found in `s`, the original string is returned.  
2. If `part` is an empty string, the input string `s` is returned unchanged.  
3. If `s` is empty, the output is also an empty string.  

---

## Conclusion  
This solution efficiently removes all occurrences of the given substring `part` from the string `s` using a straightforward approach with `find()` and `erase()` methods in C++. It handles edge cases and provides an optimized in-place modification of the string.  

Feel free to modify the input and test with different examples to see the program's versatility!