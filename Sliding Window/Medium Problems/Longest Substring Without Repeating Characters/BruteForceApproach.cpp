#include<bits/stdc++.h>
using namespace std;
int longestSubstrWithoutRepeatingCharsBR(string s){
    int hash[256] = {0};
    int maxLen = 0;
    for (int  i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            if(hash[s[j]] == 1){
                maxLen = max(maxLen,j-i);
                break;
            }
            
            maxLen = max(maxLen,j-i+1);
            hash[s[j]]++;
        }
    }
    return maxLen;
}
int main(){
    cout<<longestSubstrWithoutRepeatingCharsBR("cadbzabcd");
    return 0;
}
