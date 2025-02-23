#include<iostream>
#include<vector>
using namespace std;
void sorting(vector<int>&arr){
int n=arr.size();
int low=0,mid=0,high=n-1;
while(mid<=high){
    if(arr[mid]==0){
        swap(arr[low],arr[mid]);
        low++;
        mid++;
    }
    else if (arr[mid]==1)
    {
        mid++;
    }else{
        swap(arr[high],arr[mid]);
        high--;
    }
    
}
}
void print(vector<int>&arr){
    for(int i:arr){
        cout<<i<<" ";
    }
}
int main(int argc, char const *argv[])
{
    vector<int>arr={0,1,2,1,2,0,0,0,2,1,0,0,1};
    sorting(arr);
    print(arr);
    return 0;
}
