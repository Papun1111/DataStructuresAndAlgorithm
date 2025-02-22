#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<int>&arr,int n,int m,int maxAllowedPages){
    int stu=1,pages=0;
    for(int i: arr){
        if(i>maxAllowedPages){
            return false;
        }
        if(pages+i<=maxAllowedPages){
            pages=pages+i;
        }else{
        stu++;
        pages=i;
        }
    }
if(stu>m){
    return false;
}else{
    return true;
}
}
int summation(vector<int>&arr){
int sum=0;
for(int i:arr){
    sum+=i;
}
return sum;
}
int allocation(vector<int>&arr,int n,int m){
    if(m>n){
        return -1;
    }
    int st=0;
    int end=summation(arr);
    int ans=0;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(isValid(arr,n,m,mid)){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return ans;
}
int main(){
 vector<int> arr={2,1,3,4};
int n=4,m=2;
cout<<allocation(arr,n,m)<<endl;
    return 0;
}