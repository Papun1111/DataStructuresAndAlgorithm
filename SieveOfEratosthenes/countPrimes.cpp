#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    int ans = 0;
    vector<bool> v(n + 1, true);
    for (int i = 2; i < n; i++) {
        if (v[i]) {
            ans++;
            for (int j = i*2; j < n; j += i) {
                v[j]= false;
            }
        }
    }
    return ans; 
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    int count = countPrimes(n);
    cout << count << endl;
    return 0;
}
