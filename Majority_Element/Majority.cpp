#include<iostream>
#include<vector>
using namespace std;
int majority(vector<int>&arr){
int freq=0,ans=0;
for(int i : arr){
if(freq==0){
    ans=i;
}
if(ans==i){
    freq++;
}else{
    freq--;
}
}
return ans;
}
int main(int argc, char const *argv[])
{
    vector<int>arr={1,2,2,2,1,2,1,2,1,1};
    int major=majority(arr);
    cout<<"Majority Element is :"<<major;
    return 0;
}
