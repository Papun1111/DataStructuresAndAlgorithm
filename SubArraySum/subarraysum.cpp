#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subArrayExist(vector<int>& v, int target) {
    int n = v.size();
    int count = 0;
    vector<int> prefixSum(n, 0);
    prefixSum[0] = v[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + v[i]; 
    }
    unordered_map<int, int> m;
    for (int j = 0; j < n; j++) {
        if (prefixSum[j] == target) {
            count++;
        }
        int val = prefixSum[j] - target;
        if (m.find(val) != m.end()) {
            count += m[val];
        }
        m[prefixSum[j]]++;
    }
    return count;
}

int main() {
    vector<int> v = {9, 4, 20, 3, 10, 5};
    int k;
    cout << "Enter target- ";
    cin >> k;
    int count = subArrayExist(v, k);
    cout << "Number of Subarrays: " << count << endl;
    return 0;
}
