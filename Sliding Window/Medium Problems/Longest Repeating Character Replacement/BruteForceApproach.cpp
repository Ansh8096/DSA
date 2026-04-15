#include<bits/stdc++.h>
using namespace std;
int longestRepeatingCharReplacement_BR(string s,int k){
    int maxLen = 0;
    for (int i = 0; i < s.length(); i++){
        int hash[26] = {0}; 
        int maxFreq = 0;
        for (int j = i; j < s.length(); j++){
            hash[s[j] - 'A']++;
            maxFreq = max(maxFreq,hash[s[j] - 'A']);
            int change = (j-i+1) - maxFreq;
            if(change <= k){
                maxLen = max(maxLen,j-i+1);
            }
            else break;
        }
    }
    return maxLen;
}
int main(){
        
    cout<<longestRepeatingCharReplacement_BR("AABABBA",2);

    return 0;
}
