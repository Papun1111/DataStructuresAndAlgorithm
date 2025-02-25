#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    
    vector<int>arr={2,7,11,15};
    int i=0;
    int j=arr.size()-1;
    cout<<"Enter target:";
    int n;
    cin>>n;
    while(i<j){
        int sum=arr[i]+arr[j];
        if(sum==n){
            cout<<"pair is "<<arr[i]<<","<<arr[j]<<endl;
            break;
        }
        else if (sum<n)
        {
            i++;
        }else{
            j--;
        }
        
    }
    return 0;
}
