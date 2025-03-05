#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> find4Sum(vector<int>& arr, int target) {
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    
    for (int i = 0; i < n - 3; i++) {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;
            int p = j + 1, q = n - 1;
            while (p < q) {
                int sum = arr[i] + arr[j] + arr[p] + arr[q];
                if (sum < target) {
                    p++;
                } else if (sum > target) {
                    q--;
                } else {
                    res.push_back({arr[i], arr[j], arr[p], arr[q]});
                    while (p < q && arr[p] == arr[p + 1])
                        p++;
                    while (p < q && arr[q] == arr[q - 1])
                        q--;
                    p++;
                    q--;
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr = {-2, -1, -1, 1, 1, 2, 2};
    int target = 0;
    vector<vector<int>> quadruplets = find4Sum(arr, target);
    
    for (auto &quad : quadruplets) {
        for (int num : quad)
            cout << num << " ";
        cout << "\n";
    }
    
    return 0;
}
