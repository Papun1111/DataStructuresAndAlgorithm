#include<iostream>
using namespace std;
class Queue{
    int front=-1,currSize=0,rear=-1;
    int q[10];
    public:
        void push(int val){
            if(currSize==10){
                cout<<"queue overflow"<<endl;
                return;
            }
            if(rear==9){
                rear=-1;
            }
            if(front==-1){
                front=0;
            }

            rear=(rear+1)%10;
            q[rear]=val;
            currSize++;
            if(front==-1){
                front=0;
            }
        }
        void pop(){
            
        }
        int top(){
            if(front==-1){
                cout<<"queue is empty"<<endl;
                return -1;
            }
            return q[front];
        }
};
int main(int argc, char const *argv[])
{
    
    return 0;
}
