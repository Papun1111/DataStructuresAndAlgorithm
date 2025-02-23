#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int maxsubsetsum(vector<int>&arr){
    int currSum=0,maxSum=INT_MIN;
    for(int i:arr){
        currSum+=i;
        maxSum=max(maxSum,currSum);
        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
}
int main(){
vector<int>arr={1,2,3,4,5};

int maxSum=maxsubsetsum(arr);
cout<<"Maximum subset sum is "<<maxSum<<endl;
    return 0;
}