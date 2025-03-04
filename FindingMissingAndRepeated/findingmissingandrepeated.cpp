#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> finding(const vector<vector<int>>& v) {
    vector<int> ans;
    unordered_set<int> s;
    int totalSum = 0;
    int repeated = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            totalSum += v[i][j];
            if (s.find(v[i][j]) == s.end()) {
                s.insert(v[i][j]);
            } else {
                repeated = v[i][j];
            }
        }
    }
    int n = v.size() * v[0].size();
    int expectedSum = (n * (n + 1)) / 2;
    int missingNumber = expectedSum - (totalSum - repeated);
    ans.push_back(missingNumber);
    ans.push_back(repeated);
    return ans;
}

int main() {
    vector<vector<int>> v = { {1, 2, 3}, {4, 5, 6}, {7, 9, 9} };
    vector<int> missingAndRepeated = finding(v);
    cout << "Missing number is " << missingAndRepeated[0] << endl;
    cout << "Repeated number is " << missingAndRepeated[1] << endl;
    return 0;
}
