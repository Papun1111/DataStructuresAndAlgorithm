#include<iostream>
using namespace std;
class Node{
    public:
        int val;
        Node*next;
        Node(int val){
            this->val=val;
            this->next=nullptr;
        }
    };
class Stack{
    Node*top;
    public:
        Stack(){
            top=nullptr;
        }
        void push(int val){
            Node*newNode=new Node(val);
            if(top==nullptr){
                top=newNode;
                return;
            }
            newNode->next=top;
            top=newNode;
        }
        int pop(){
            if(top==nullptr){
                cout<<"stack is empty"<<endl;
                return -1;
            }
            int val=top->val;
            Node*temp=top;
            top=top->next;
            delete temp;
            return val;
        }
        int top(){
            if(top==nullptr){
                cout<<"stack is empty"<<endl;
                return -1;
            }
            return top->val;
        }
        int size(){
            Node*temp=top;
            int count=0;
            while(temp!=nullptr){
                count++;
                temp=temp->next;
            }
            return count;
        }
};
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
