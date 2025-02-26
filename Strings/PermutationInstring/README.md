# Check Inclusion of Permutation

## Problem Statement  
Given two strings, `s1` and `s2`, the task is to check if any permutation of `s1` is present as a substring in `s2`.  
In other words, check if there is any rearrangement of the characters of `s1` that appears as a contiguous substring in `s2`.  

### Example:
```
Input: s1 = "ab", s2 = "eidbaooo"
Output: True  
Explanation: s2 contains one permutation of s1 ("ba").
```
```
Input: s1 = "ab", s2 = "eidboaoo"
Output: False
```

## Approach  
This solution uses the **sliding window** technique along with frequency counting.  

### Detailed Explanation:
1. **Frequency Array:**  
   - An array of size 26 (`freq[]`) is used to store the frequency of each character in `s1`.  
   - Another frequency array (`windFreq[]`) is used to keep track of the character frequencies of the current window in `s2`.  

2. **Initial Frequency Count:**  
   - The frequency of each character in `s1` is calculated and stored in `freq[]`.  
   - A window of the same length as `s1` is initialized in `s2`, and its character frequencies are calculated in `windFreq[]`.  

3. **Sliding Window Technique:**  
   - The window slides one character at a time from left to right in `s2`.  
   - For each slide:
     - The frequency of the character that goes out of the window (leftmost) is decremented.  
     - The frequency of the new character that enters the window (rightmost) is incremented.  
   - After adjusting the frequencies, the two frequency arrays (`freq[]` and `windFreq[]`) are compared.  
   - If they are the same, it means a permutation of `s1` is found in `s2`, and the function returns `true`.  

4. **Edge Cases Considered:**
   - If the length of `s1` is greater than `s2`, the function immediately returns `false`.  
   - If `s1` or `s2` contains non-lowercase letters, the behavior is undefined since the problem assumes lowercase English letters only.  

## Time and Space Complexity  
- **Time Complexity:**  
  - Constructing the frequency array for `s1` takes \( O(n) \) time, where `n` is the length of `s1`.  
  - The sliding window moves across `s2` with constant time operations for each slide, resulting in \( O(m) \) time, where `m` is the length of `s2`.  
  - Overall time complexity: \( O(n + m) \).  

- **Space Complexity:**  
  - Two frequency arrays of fixed size (26 for lowercase English letters) are used.  
  - Thus, space complexity is \( O(1) \), as the space used does not depend on the input size.  

## Code  
```cpp
#include <iostream>
#include <string>
using namespace std;

bool isFreqSame(int freq1[], int freq2[]){
    for(int i = 0; i < 26; i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2){
    int freq[26] = {0};
    for(char i : s1){
        freq[i - 'a']++;
    }

    int windSize = s1.length();
    int windFreq[26] = {0};
    
    for(int i = 0; i < windSize && i < s2.length(); i++){
        windFreq[s2[i] - 'a']++;
    }
    
    for(int i = 0; i <= s2.length() - windSize; i++){
        if(i > 0){
            windFreq[s2[i - 1] - 'a']--; 
            windFreq[s2[i + windSize - 1] - 'a']++; 
        }
        if(isFreqSame(freq, windFreq)){
            return true;
        }
    }
    return false;
}

int main(){
    string s1, s2;
    cout << "Enter string s1 and s2: ";
    getline(cin, s1);
    getline(cin, s2);

    if(checkInclusion(s1, s2)){
        cout << "True: A permutation of s1 is in s2" << endl;
    } else {
        cout << "False: No permutation of s1 is in s2" << endl;
    }

    return 0;
}
```

## How to Run  
1. Copy and paste the code into a file named `checkInclusion.cpp`.  
2. Compile the code using:  
   ```
   g++ checkInclusion.cpp -o checkInclusion
   ```
3. Run the executable:  
   ```
   ./checkInclusion
   ```
4. Input the strings `s1` and `s2` when prompted.  

## Example Run  
```
Enter string s1 and s2: ab
eidbaooo
True: A permutation of s1 is in s2
```

## Conclusion  
This solution efficiently checks for the inclusion of any permutation of `s1` as a substring in `s2` using a sliding window and frequency counting approach with optimal time and space complexity.