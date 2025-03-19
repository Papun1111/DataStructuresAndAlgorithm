#include <iostream>
#include <vector>
using namespace std;

void helper(vector<int>& arr, vector<int>& accumulator, vector<vector<int>>& ans, int target, int i) {
    if(target == 0) {
        ans.push_back(accumulator);
        return;
    }
    if(i >= arr.size() || target < 0) {
        return;
    }
    accumulator.push_back(arr[i]);
    helper(arr, accumulator, ans, target - arr[i], i + 1);
    helper(arr, accumulator, ans, target - arr[i], i);
    accumulator.pop_back();
    helper(arr, accumulator, ans, target, i + 1);
}

vector<vector<int>> findSumCombination(vector<int>& arr, int target) {
    vector<int> accumulator;
    vector<vector<int>> ans;
    helper(arr, accumulator, ans, target,0);
    return ans;
}

void print(vector<vector<int>>& ans) {
    for(auto i : ans) {
        for(int j : i) {
            cout << j << ",";
        }
        cout << endl;
    }
}

int main() {
    vector<int> arr = {2, 3, 5};
    int target;
    cout << "ENTER TARGET:";
    cin >> target;
    vector<vector<int>> ans = findSumCombination(arr, target);
    print(ans);
    return 0;
}
