#include<vector>
#include<iostream>
using namespace std;
void conquer(vector<int>&arr,int start,int mid,int end){
vector<int>temp;
int i=start,j=mid+1;
while (i<=mid && j<=end)
{
    if(arr[i]<arr[j]){
        temp.push_back(arr[i++]);
    }else{
        temp.push_back(arr[j++]);
    }
}
while(i<=mid){
    temp.push_back(arr[i++]);
}
while(j<=end){
    temp.push_back(arr[j++]);
}
for(int idx=0;idx<temp.size();idx++){
    arr[start+idx]=temp[idx];
}
}
void mergeSort(vector<int>&arr,int start,int end){
   if(start >= end) {
    return;
}
    int mid=start+(end-start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    conquer(arr,start,mid,end);
}
void print(vector<int>&v){
    for(int i:v){
        cout<<i<<" ";
    }
}
int main()
{
    vector<int>v={1,3,2,6,4,7,6,9,8};
    mergeSort(v,0,v.size()-1);
    print(v);
    return 0;
}
