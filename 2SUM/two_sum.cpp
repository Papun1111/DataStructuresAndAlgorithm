#include<iostream>
#include<vector>
using namespace std;
#include <unordered_map>
vector<int> twosum(vector<int> &nums, int target)
{
    vector<int> result;
  unordered_map <int, int> m;
for(int i=0;i<nums.size();i++)
{
    int first=nums[i];
    int second=target-first;
    if(m.find(second)!=m.end())
    {
        result.push_back(m[second]);
        result.push_back(i);
        return result;
    }
    m[first]=i;

}

   return result;    
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {5,2, 7, 11, 15};
    int target = 9;
    vector<int> result;
    result=twosum(nums, target);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}
