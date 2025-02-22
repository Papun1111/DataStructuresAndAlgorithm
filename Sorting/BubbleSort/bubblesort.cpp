#include<iostream>
#include<vector>
using namespace std;

class Bubble {
public:
    void sort(vector<int>& v) {
        int n = v.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (v[j] > v[j + 1]) {
                    swap(v[j], v[j + 1]);
                }
            }
        }
    }
};

int main() {
    vector<int> v = {64, 34, 25, 12, 22, 11, 90};
    
    Bubble bubbleSorter;
    bubbleSorter.sort(v);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    return 0;
}
