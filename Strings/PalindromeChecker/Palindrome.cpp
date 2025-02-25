#include<iostream>
#include<string>
using namespace std;
int isPalindrome(string str){
string rev="";
int size=str.length();
for(int i=size-1;i>=0;i--){
    rev+=str[i];
}
if(rev==str){
    return 1;
}
return 0;
}
int main(int argc, char const *argv[])
{
    string str;
    cout<<"Enter a string:";
    getline(cin,str);
    if(isPalindrome(str)){
        cout<<"This string is a palindrome";
    }else{
        cout<<"This string is not a palindrome";
    }
    return 0;
}
