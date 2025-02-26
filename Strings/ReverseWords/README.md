
---

### **README - Reverse Words in a String**  

## **Problem Statement**  
This program takes a string input from the user and reverses the order of words while keeping their original spelling intact. The words are considered as sequences of **alphabetic characters** (`A-Z, a-z`), and spaces are preserved as word separators.

### **Example**  
#### **Input:**  
```
Enter a string: Hello World
```
#### **Output:**  
```
Reversed string: World Hello
```

---

## **Code Explanation**  

### **1. Function: `reversestr(string s)`**  
- **Purpose:** This function takes a string as input and returns a new string where the words appear in **reverse order**.  
- **Logic:**  
  - Traverse the input string character by character.  
  - If the character is alphabetic (`isalpha(i)`), it is appended to a temporary `str` variable.  
  - If a space (`' '`) is encountered:  
    - The word stored in `str` is added **at the beginning** of `newstr`, followed by a space.  
    - The `str` is reset to store the next word.  
  - After the loop, the **last word** is added to `newstr` since it is not followed by a space.  
  - If `newstr` ends with an extra space, it is removed using `newstr.pop_back()`.  
  - Finally, `newstr` is returned.  

### **2. Main Function (`main()`)**  
- Reads the input string using `getline(cin, s)`.  
- Calls the `reversestr(s)` function to process the string.  
- Prints the reversed string.  

---

## **Time and Space Complexity**  

### **Time Complexity: O(N)**  
- **Explanation:** The program traverses the string **once** (`O(N)`) and builds the reversed string **at the same time**.  
- **Operations Performed:**  
  - Single pass over the string (`O(N)`).  
  - Concatenation of words (`O(N)`).  
  - Overall, the complexity remains **O(N)**.

### **Space Complexity: O(N)**  
- **Explanation:**  
  - The program uses **two additional strings** (`str` and `newstr`), which store the words and the final output respectively.  
  - In the worst case, `newstr` may contain **all words in reverse order**, meaning it uses **O(N) extra space**.  

---

## **Edge Cases Considered**  
✔ **Multiple spaces between words** → The program correctly handles them.  
✔ **Trailing and leading spaces** → The program removes unnecessary trailing spaces in the output.  
✔ **Single-word input** → The output remains the same as input.  
✔ **Empty string input** → The output is an empty string.  
✔ **Mixed uppercase and lowercase letters** → The program correctly handles them without altering case.  

---

## **Possible Improvements**  
- **Preserve special characters and numbers**: Currently, only alphabetic characters are considered, and special characters/numbers are ignored.  
- **Use a stack-based approach**: This could provide a simpler implementation while maintaining the same `O(N)` time complexity.  
- **Optimised concatenation**: Using `ostringstream` instead of `+` concatenation could improve performance slightly for large inputs.  

---

## **How to Run the Program**  

1. Compile the code using:  
   ```
   g++ -o reverse_string reverse_string.cpp
   ```
2. Run the compiled program:  
   ```
   ./reverse_string
   ```
3. Enter a sentence when prompted.  
4. View the reversed output.  

---

This README provides a clear understanding of how the program works, its efficiency, and potential improvements. 🚀