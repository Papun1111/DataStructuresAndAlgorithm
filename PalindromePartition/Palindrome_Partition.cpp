#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void getAllParts(string s, vector<string>& partition, vector<vector<string>>& ans) {
        if(s.size() == 0) {
            ans.push_back(partition);
            return;
        }
        for(int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);
            if(isPalindrome(part)) {
                partition.push_back(part);
                getAllParts(s.substr(i + 1), partition, ans);
                partition.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllParts(s, partitions, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    string input;
    cout << "Enter a string to partition: ";
    getline(cin, input);
    
    vector<vector<string>> result = sol.partition(input);
    
    cout << "Palindrome partitions are:" << endl;
    for(const auto& partition : result) {
        for(const auto& part : partition) {
            cout << part << " ";
        }
        cout << endl;
    }
    
    return 0;
}
