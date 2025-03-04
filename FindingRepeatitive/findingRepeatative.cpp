#include<iostream>
#include<vector>
using namespace std;
int findingRepeat(vector<int>v){
int slow=v[0],fast=v[0];
do{
slow=v[slow];
fast=v[v[fast]];
}while(slow!=fast);
slow=v[0];
while(slow!=fast){
slow=v[slow];
fast=v[fast];
}
return slow;
}
int main(int argc, char const *argv[])
{
    vector<int>v={1, 3, 4, 2, 2};
    int x=findingRepeat(v);
    cout<<"Repeated Element is :"<<x;
    return 0;
}
