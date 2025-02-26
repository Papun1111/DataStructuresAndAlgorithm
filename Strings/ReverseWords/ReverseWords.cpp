#include <iostream>
#include <string>
using namespace std;

string reversestr(string s) {
    string str = "";
    string newstr = "";

    for (char i : s) {
        if (isalpha(i)) {
            str += i;
        }
        if (i == ' ') {
            newstr = str + " " + newstr;
            str = "";
        }
    }
    
    newstr = str + " " + newstr;
    if (!newstr.empty() && newstr.back() == ' ') {
        newstr.pop_back();
    }

    return newstr;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    string st = reversestr(s);
    cout << "Reversed string: " << st << endl;

    return 0;
}
