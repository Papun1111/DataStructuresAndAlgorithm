#include<iostream>
#include<string>
using namespace std;

bool isValidPalindrome(string s) {
    int st = 0, end = s.length() - 1;
    while (st < end) {
        if (!isalnum(s[st])) {
            st++;
            continue;
        }
        if (!isalnum(s[end])) {
            end--;
            continue;
        }
        if (tolower(s[st]) != tolower(s[end])) {
            return false;
        }
        st++;
        end--;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    if (!isValidPalindrome(s)) {
        cout << "No, the string is not a valid palindrome.";
    } else {
        cout << "Yes, it is a valid palindrome.";
    }
    return 0;
}
