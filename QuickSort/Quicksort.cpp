#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int partition(vector<int>&arr,int st,int end){
int idx=st-1;
int pivot=arr[end];
for(int j=st;j<end;j++){
    if(arr[j]<pivot){
        idx++;
        swap(arr[j],arr[idx]);
    }
}
idx++;
swap(arr[end],arr[idx]);
return idx;
}
void quicksort(vector<int>&arr,int st,int end){
if(st>=end){
    return;
}
int partitonidx=partition(arr,st,end);
quicksort(arr,st,partitonidx-1);
quicksort(arr,partitonidx+1,end);
}
void print(vector<int>&arr){
for(int i:arr){
    cout<<i<<" ";
}
}
int main()
{
    vector<int>v={3,2,1,5,7,6};
    quicksort(v,0,v.size()-1);
    print(v);
    return 0;
}
