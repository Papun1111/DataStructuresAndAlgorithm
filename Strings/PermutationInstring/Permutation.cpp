#include <iostream>
#include <string>
using namespace std;

bool isFreqSame(int freq1[], int freq2[]){
    for(int i = 0; i < 26; i++){
        if(freq1[i] != freq2[i]){
            return false;
        }
    }
    return true;
}

bool checkInclusion(string s1, string s2){
    int freq[26] = {0};
    for(char i : s1){
        freq[i - 'a']++;
    }

    int windSize = s1.length();
    int windFreq[26] = {0};
    
    for(int i = 0; i < windSize && i < s2.length(); i++){
        windFreq[s2[i] - 'a']++;
    }
    
    for(int i = 0; i <= s2.length() - windSize; i++){
        if(i > 0){
            windFreq[s2[i - 1] - 'a']--; 
            windFreq[s2[i + windSize - 1] - 'a']++; 
        }
        if(isFreqSame(freq, windFreq)){
            return true;
        }
    }
    return false;
}

int main(){
    string s1, s2;
    cout << "Enter string s1 and s2: ";
    getline(cin, s1);
    getline(cin, s2);

    if(checkInclusion(s1, s2)){
        cout << "True: A permutation of s1 is in s2" << endl;
    } else {
        cout << "False: No permutation of s1 is in s2" << endl;
    }

    return 0;
}
