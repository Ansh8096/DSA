#include<bits/stdc++.h>
using namespace std;
int longestRepeatingCharReplacement_OP1(string s,int k){
    int l = 0 , r = 0 , maxLen = 0 , maxFreq = 0;
    int hash[26] = {0};
    map<int,int> mpp;
    while (r<s.length()){
        hash[s[r]-'A']++;
        maxFreq = max(maxFreq,hash[s[r]-'A']);
        
        while((r-l+1) - maxFreq > k){
            hash[s[l]-'A']--;
            // Scanning for maxFeq everytime in the hashArray...
            maxFreq = 0;
            for(int i=0;i<26;i++) maxFreq = max(maxFreq,hash[i]);
            l++;
        }

        if((r-l+1) - maxFreq <= k) maxLen = max(maxLen,r-l+1);
        r++;

    }
    return maxLen;
}
int main(){
        
    cout<<longestRepeatingCharReplacement_OP1("AABABBA",2);

    return 0;
}
