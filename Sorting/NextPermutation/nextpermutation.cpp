#include<iostream>
#include<vector>
using namespace std;
int pivotIdx(vector<int>&arr)
{
    int piv=-1;
    int n=arr.size();
    for(int i=n-2;i>=0;i++){
        if(arr[i]<arr[i+1]){
            piv=i;
            return piv;
        }
    }
    return -1;
}
void reverseArr(vector<int>&arr){
    int i=0;
    int j=arr.size()-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
void lexicographicalNext(vector<int>&arr){
    int n=arr.size();
    int pivot=pivotIdx(arr);
    if(pivot==-1){
        reverseArr(arr);
        return ;
    }
    for(int i=n-1;i>pivot;i--){
        if(arr[i]>arr[pivot]){
            swap(arr[i],arr[pivot]);
            return;
        }
    }
}
void print(vector<int>&arr){
    for(int i:arr)
    cout<<i<<",";
}
int main(int argc, char const *argv[])
{
    vector<int>arr={1,2,3};
     lexicographicalNext(arr);
     print(arr);
    return 0;
}
