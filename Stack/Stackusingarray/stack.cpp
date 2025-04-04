#include<iostream>
using namespace std;
class Stack{
    int top=-1;int st[10];
    public:
        void push(int val){
            if(top==9){
                cout<<"stack overflow"<<endl;
                return;
            }
            st[++top]=val;

        }
        int top(){
            if(top==-1){
                cout<<"stack is empty"<<endl;
                return -1;
            }
            return st[top];
        }
        void pop(){
            if(top==-1){
                cout<<"stack is empty"<<endl;
                return;
            }
            top--;
        }
        int size(){
            return top+1;
        }
        bool empty(){
            return top==-1;
        }
    };
int main(int argc, char const *argv[])
{
    
    return 0;
}
