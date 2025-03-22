#include <iostream>

class Node {
public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class List {
public:
    Node *head;
    Node *tail;
    List() {
        head = nullptr;
        tail = nullptr;
    }

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
    
    void print() {
        Node *temp = head;
        while (temp != nullptr) {
            std::cout << temp->val << std::endl;
            temp = temp->next;
        }
    }
};

int main() {
    List l;
    l.push_front(3);
    l.push_front(2);
    l.push_front(1);
    l.push_back(4);
    l.push_back(5);
    l.print();
    return 0;
}
