
### **README: Sorting an Array of 0s, 1s, and 2s**  

---

## **Overview:**  
This code efficiently sorts an array containing only `0s`, `1s`, and `2s` using the **Dutch National Flag Algorithm**. The sorted order is `0s`, followed by `1s`, and then `2s`.  

---

## **Algorithm Used:**  
### **Dutch National Flag Algorithm**  
- Developed by **Edsger Dijkstra**, this algorithm efficiently sorts an array of three distinct elements.  
- It uses a **three-pointer approach**:  
  - `low` for the **boundary of 0s**  
  - `mid` for the **current element** being processed  
  - `high` for the **boundary of 2s**  

---

## **Approach:**  
1. **Initialize Pointers:**  
   - `low` = `0`: Tracks the position for `0s`.  
   - `mid` = `0`: Current element being processed.  
   - `high` = `n-1`: Tracks the position for `2s`.  

2. **Traversal & Sorting:**  
   - **While** `mid <= high`:  
     - **If** `arr[mid]` is `0`:  
       - Swap `arr[low]` and `arr[mid]`.  
       - Increment `low` and `mid`.  
     - **If** `arr[mid]` is `1`:  
       - Increment `mid`.  
     - **If** `arr[mid]` is `2`:  
       - Swap `arr[mid]` and `arr[high]`.  
       - Decrement `high`.  
       - **Do not increment `mid`**, as the swapped element at `mid` needs to be checked.  

3. **End Condition:**  
   - The loop ends when `mid > high`.  
   - The array is then sorted in the order of `0s`, `1s`, and `2s`.  

---

## **Code Explanation:**  
```cpp
#include <iostream>
#include <vector>
using namespace std;

void sorting(vector<int>& arr) {
    int n = arr.size();
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } 
        else if (arr[mid] == 1) {
            mid++;
        } 
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}
```

- **`sorting()` Function:**  
  - Accepts a vector reference `arr` containing `0s`, `1s`, and `2s`.  
  - Initializes `low`, `mid`, and `high` pointers.  
  - Uses a `while` loop to iterate through the array.  
  - Performs swaps and updates pointers according to the value at `arr[mid]`.  

---

```cpp
void print(vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}
```
- **`print()` Function:**  
  - Displays the elements of the vector.  

---

```cpp
int main() {
    vector<int> arr = {0, 1, 2, 1, 2, 0, 0, 0, 2, 1, 0, 0, 1};
    sorting(arr);
    print(arr);
    return 0;
}
```
- **`main()` Function:**  
  - Initializes a vector `arr` with `0s`, `1s`, and `2s` in random order.  
  - Calls the `sorting()` function to sort the array.  
  - Calls the `print()` function to display the sorted array.  

---

## **Example:**  

### **Input:**  
```cpp
vector<int> arr = {0, 1, 2, 1, 2, 0, 0, 0, 2, 1, 0, 0, 1};
```

### **Output:**  
```
0 0 0 0 0 0 1 1 1 1 2 2 2 
```

### **Explanation:**  
- The array is sorted in the order of `0s`, followed by `1s`, and then `2s`.  

---

## **Time Complexity:**  
- **O(n)** because the array is traversed at most once.  
- Each element is checked and moved at most once, resulting in **linear time complexity**.  

---

## **Space Complexity:**  
- **O(1)** because no additional space is used apart from a few integer variables.  

---

## **Why use Dutch National Flag Algorithm?**  
- It efficiently solves the problem in **one pass** without using extra space.  
- It avoids the need for counting and rearranging the elements separately.  

---

## **Edge Cases Considered:**  
1. Array with all `0s`, all `1s`, or all `2s`.  
2. Array with a single element.  
3. Array with no elements (empty vector).  
4. Array with a random mix of `0s`, `1s`, and `2s`.  

---

## **Conclusion:**  
This code provides an optimal solution to the problem of sorting an array of `0s`, `1s`, and `2s` using the **Dutch National Flag Algorithm**. Its **O(n)** time complexity and **O(1)** space complexity make it highly efficient for competitive programming and real-world scenarios.  

---

Feel free to ask for further explanations or modifications! 😊