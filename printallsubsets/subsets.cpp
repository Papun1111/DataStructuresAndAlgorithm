#include<iostream>
#include<vector>
using namespace std;
void printArr(vector<int>ans){
    for(int i:ans){
        cout<<i;
    }
    cout<<endl;
}
void printallsubsets(vector<int>&arr,vector<int>ans={},int i=0){
if(i==arr.size()){
    printArr(ans);
    return;
}
ans.push_back(arr[i]);
printallsubsets(arr,ans,i+1);
ans.pop_back();
printallsubsets(arr,ans,i+1);
}
int main(int argc, char const *argv[])
{
    vector<int> v={1,2,3,4,5,6};
    printallsubsets(v);
    return 0;
}
