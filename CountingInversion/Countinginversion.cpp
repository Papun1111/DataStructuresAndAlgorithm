#include <vector>
#include <iostream>
using namespace std;

int conquer(vector<int>& arr, int start, int mid, int end) {
    vector<int> temp;
    int i = start, j = mid + 1;
    int count = 0;
    
 
    while (i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
            
            count += (mid - i + 1);
        }
    }
    
 
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }
    
    
    while (j <= end) {
        temp.push_back(arr[j++]);
    }
    

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[start + idx] = temp[idx];
    }
    
    return count;
}

int inversionCount(vector<int>& arr, int start, int end) {
   
    if (start >= end) {
        return 0;
    }
    
    int mid = start + (end - start) / 2;
    int left = inversionCount(arr, start, mid);
    int right = inversionCount(arr, mid + 1, end);
    int cross = conquer(arr, start, mid, end);
    
    return left + right + cross;
}

void print(vector<int>& v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {6,3,5,2,7};
    int inversions = inversionCount(v, 0, v.size() - 1);
    cout << "Number of inversions: " << inversions << endl;
    return 0;
}
