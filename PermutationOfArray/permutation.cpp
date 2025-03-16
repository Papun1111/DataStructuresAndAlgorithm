#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& arr) {
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

void printAllPermutation(vector<int>& arr, int idx = 0) {
    if (idx == arr.size()) {
        print(arr);
        return;
    }
    for (int i = idx; i < arr.size(); i++) {
        swap(arr[idx], arr[i]);
        printAllPermutation(arr, idx + 1);
        swap(arr[idx], arr[i]);
    }
}

int main() {
    vector<int> v = {1, 2, 3};
    printAllPermutation(v);
    return 0;
}
