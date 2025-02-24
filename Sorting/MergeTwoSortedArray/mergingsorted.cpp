#include<iostream>
#include<vector>
using namespace std;
void mergeSorted(vector<int>&arr1,vector<int>&arr2,vector<int>&arr3){
int i=0,j=0,k=0;
int arr1size=arr1.size();
int arr2size=arr2.size();
while (i<arr1size && j<arr2size )
{
    if(arr1[i]<arr2[j]){
        arr3.push_back(arr1[i]);
        i++;
    }else{
        arr3.push_back(arr2[j]);
        j++;
    }
}
while(i<arr1size){
    arr3.push_back(arr1[i]);
    i++;
}
while(j<arr2size){
    arr3.push_back(arr2[j]);
    j++;
}
}
void print(vector<int>&sortarr){
    for(int i:sortarr){
        cout<<i<<",";
    }
}
int main(){
    vector<int>arr1={1,2,3,4};
    vector<int>arr2={9,10,14};
    vector<int>arr3;
    mergeSorted(arr1,arr2,arr3);
print(arr3);
    return 0;
}