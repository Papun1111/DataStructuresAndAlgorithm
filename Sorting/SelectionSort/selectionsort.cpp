#include<iostream>
#include<vector>
using namespace std;

class SelectionSort {
public:
    void sort(vector<int>& v) {
        int n = v.size();
        
        for (int i = 0; i < n - 1; i++) {
            int idx = i;
            for (int j = i + 1; j < n; j++) {
                if (v[j] < v[idx]) {
                    idx = j;
                }
            }
            swap(v[i], v[idx]);
        }
    }
};

int main() {
    vector<int> v = {64, 34, 25, 12, 22, 11, 90};
    
    SelectionSort sorter;
    sorter.sort(v);
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}
