#include<bits/stdc++.h>
using namespace std;
int longestSubstrWithoutRepeatingCharsOP(string s){
    int hash[256];
    fill(hash, hash + 256, -1);
    int maxLen = 0 , l = 0 , r = 0;
    while (r<s.length()){
       if(hash[s[r]] != -1){
            if(hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
       }
       maxLen = max(maxLen,r-l+1);
       hash[s[r]] = r;
       r++;
    }
    return maxLen;
}
int main(){
    cout<<longestSubstrWithoutRepeatingCharsOP("cadbzabcd");
    return 0;
}
