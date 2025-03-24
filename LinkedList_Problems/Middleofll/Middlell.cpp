#include <iostream>
using namespace std;
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
    void middle(){
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<slow->val;
    }
    void pop_back(){
        if(head==nullptr){
            cout<<"empty list cannot pop further";
            return;
        }
        if(head->next==nullptr){
            head=nullptr;
            return;
        }
        Node*temp=head;
        Node*secondLast=head;
        while (temp->next!=nullptr)
        {
            secondLast=temp;
            temp=temp->next;
        }
        secondLast->next=nullptr;
    }
    void pop_front(){
        if(head==nullptr){
            cout<<"empty list cannot pop further";
            return;
        }
        if(head->next==nullptr){
            head=nullptr;
            return;
        }
        Node*temp=head;
        head=head->next;
        delete temp;
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
    l.middle();
    return 0;
}
