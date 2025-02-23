#include<iostream>
#include<vector>
#include <limits.h>
#include<algorithm>
using namespace std;

int maxVal(vector<int>&arr){
    int maxi=0;
    for(int i:arr){
        maxi=max(maxi,i);
    }
    return maxi;
}

bool isPossible(vector<int>&arr,int N,int C,int minALlowedDist){
    int cows=1,lastStallPos=arr[0];
    for(int i=1;i<N;i++){
        if(arr[i]-lastStallPos>=minALlowedDist){
            cows++;
            lastStallPos=arr[i];
        }
        if(cows==C){
            return true;
        }
    }
    return false;
}

int minVal(vector<int>&arr){
    int mini=INT_MAX;
    for(int i:arr){
        mini=min(mini,i);
    }
    return mini;
}

int getDistance(vector<int>&arr,int N,int C){
    sort(arr.begin(),arr.end());
    int st=1, ans=1;
    int end=maxVal(arr)-minVal(arr);
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isPossible(arr,N,C,mid)){
            ans=mid;
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return ans;
}

int main(){
    int N=5,C=3;
    vector<int>arr={1,2,8,4,9};
    cout<<getDistance(arr,N,C)<<endl;
    return 0;
}
