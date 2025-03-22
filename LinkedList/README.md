# Linked List Implementation in C++

This project demonstrates a simple implementation of a singly linked list in C++ along with basic operations such as adding nodes at the front and back, removing nodes from the front and back, and printing the list. This README explains every function, class, and segment of code, and also discusses the advantages and disadvantages of using a linked list.

---

## Overview

The code consists of two primary classes:

- **Node Class:** Represents a single element (node) in the linked list.
- **List Class:** Manages the linked list by maintaining pointers to the head and tail nodes and providing methods to manipulate the list.

The `main()` function shows how to use these classes by performing several operations on a list instance.

---

## Detailed Explanation

### 1. Node Class

```cpp
class Node {
public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};
```

- **Attributes:**
  - `int val`: Stores the integer value of the node.
  - `Node *next`: A pointer that points to the next node in the list. It is initialized to `nullptr`.

- **Constructor:**
  - Initializes the node with the given value and sets the `next` pointer to `nullptr`.

---

### 2. List Class

```cpp
class List {
public:
    Node *head;
    Node *tail;
    List() {
        head = nullptr;
        tail = nullptr;
    }
```

- **Attributes:**
  - `Node *head`: Points to the first node in the list.
  - `Node *tail`: Points to the last node in the list.

- **Constructor:**
  - Initializes an empty list by setting both `head` and `tail` to `nullptr`.

---

### Member Functions of the List Class

#### `push_front(int val)`

```cpp
void push_front(int val) {
    Node *newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}
```

- **Purpose:** Inserts a new node at the beginning of the list.
- **How it works:**
  - A new node is created with the given value.
  - If the list is empty (`head` is `nullptr`), both `head` and `tail` are set to this new node.
  - Otherwise, the new node’s `next` pointer is set to the current `head`, and then `head` is updated to the new node.

#### `push_back(int val)`

```cpp
void push_back(int val) {
    Node *newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    tail = newNode;
}
```

- **Purpose:** Appends a new node at the end of the list.
- **How it works:**
  - A new node is created with the given value.
  - If the list is empty, both `head` and `tail` are set to the new node.
  - Otherwise, the list is traversed until the last node is found (where `next` is `nullptr`), and the new node is linked to the end. The `tail` is then updated.

#### `print()`

```cpp
void print() {
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << std::endl;
        temp = temp->next;
    }
}
```

- **Purpose:** Outputs the values of all nodes in the list.
- **How it works:**
  - Starts at the `head` and traverses the list.
  - Prints the value of each node until the end of the list is reached.

#### `pop_back()`

```cpp
void pop_back(){
    if(head == nullptr){
        cout << "empty list cannot pop further";
        return;
    }
    if(head->next == nullptr){
        head = nullptr;
        return;
    }
    Node *temp = head;
    Node *secondLast = head;
    while (temp->next != nullptr)
    {
        secondLast = temp;
        temp = temp->next;
    }
    secondLast->next = nullptr;
}
```

- **Purpose:** Removes the last node from the list.
- **How it works:**
  - Checks if the list is empty and prints an error if so.
  - If there is only one node, sets `head` to `nullptr`.
  - Otherwise, traverses the list to locate the second-to-last node and updates its `next` pointer to `nullptr`, effectively removing the last node.

#### `pop_front()`

```cpp
void pop_front(){
    if(head == nullptr){
        cout << "empty list cannot pop further";
        return;
    }
    if(head->next == nullptr){
        head = nullptr;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}
```

- **Purpose:** Removes the first node from the list.
- **How it works:**
  - Checks if the list is empty and prints an error if so.
  - If there is only one node, sets `head` to `nullptr`.
  - Otherwise, stores the current `head` in a temporary variable, updates `head` to the next node, and deletes the removed node to free memory.

---

### 3. Main Function

```cpp
int main() {
    List l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_back(4);
    l.push_back(5);
    l.pop_front();
    l.pop_back();
    l.print();
    return 0;
}
```

- **Purpose:** Demonstrates how the `List` class and its member functions are used.
- **Process:**
  1. A `List` instance `l` is created.
  2. Nodes with values `3`, `2`, and `1` are added to the front, resulting in the list: **1 → 2 → 3**.
  3. Nodes with values `4` and `5` are added to the back, updating the list to: **1 → 2 → 3 → 4 → 5**.
  4. The first node is removed using `pop_front()`, leaving: **2 → 3 → 4 → 5**.
  5. The last node is removed using `pop_back()`, leaving: **2 → 3 → 4**.
  6. Finally, the `print()` function outputs the remaining list elements.

---

## Advantages and Disadvantages of Linked Lists

### Advantages

- **Dynamic Size:**  
  Linked lists are dynamic, meaning they can easily grow or shrink during runtime without needing a pre-allocated block of memory.

- **Efficient Insertions/Deletions:**  
  Particularly at the beginning of the list, operations like `push_front()` and `pop_front()` are very efficient (constant time, O(1)), as they only involve updating pointers.

- **Memory Utilization:**  
  Memory is allocated as needed for each node, reducing wasted space compared to static data structures like arrays.

### Disadvantages

- **Memory Overhead:**  
  Each node requires additional memory for storing pointers, which can add up if many nodes are present.

- **No Random Access:**  
  Linked lists do not allow direct access to elements by index. Accessing a specific element requires traversing the list, which can be time-consuming (O(n) time complexity).

- **Extra Pointer Management:**  
  The use of pointers requires careful management to avoid issues such as memory leaks or pointer errors.

- **Cache Inefficiency:**  
  Due to non-contiguous memory allocation, linked lists are generally less cache-friendly compared to arrays, which can impact performance in certain scenarios.

---

## Conclusion

This simple C++ project provides a foundational implementation of a singly linked list, demonstrating key operations such as insertion, deletion, and traversal. While linked lists offer dynamic memory allocation and efficient insertions/deletions, they come with trade-offs like increased memory overhead and lack of direct element access. Understanding these trade-offs is crucial when deciding whether a linked list is the right data structure for a particular application.

