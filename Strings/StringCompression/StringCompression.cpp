#include<iostream>
#include<string>
#include<vector>
using namespace std;
int compress(vector<char>&chars){
    int n=chars.size();
    int idx=0;
    for(int i=0;i<n;i++){
        char ch=chars[i];
        int count=0;
        while(i<n && chars[i]==ch){
            i++;
            count++;
        }
        chars[idx++]=ch;
        if(count>1){
            for(char c:to_string(count)){
                chars[idx++]=c;
            }
        }
        i--;
    }
    chars.resize(idx);
    return idx;
}
int main(int argc, char const *argv[])
{
    vector<char> v={'a','a','b','a','a','b','c'};
    int compressionLength=compress(v);
    cout<<compressionLength<<endl;
    for(char c:v){
        cout<<c<<" ";
    }
    return 0;
}
