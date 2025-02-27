#include<iostream>
using namespace std;
int gcd(int a,int b){
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }else{
            b=b%a;
        }
        if(b==0)return a;
        return b;
    }
}
int main(int argc, char const *argv[])
{
    int a, b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<gcd(a,b)<<endl;
    return 0;
}
