#include <iostream>
#include <string>
using namespace std;

string removeAllOccurances(string s, string part) {
    while (s.find(part) < s.length()) {
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << "Enter part: ";
    string part;
    cin >> part;
    string str = removeAllOccurances(s, part);
    cout << "Resulting string: " << str;
    return 0;
}
