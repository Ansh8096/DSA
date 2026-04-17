#include<bits/stdc++.h>
using namespace std;
int longestSubstringWithAtmostKchars_BR(string a,int k){
    int maxLen = 0;
    for (int i = 0; i < a.length(); i++)
    {
        map<char,int>mpp;
        for (int j = i; j < a.length(); j++){
            mpp[a[j]]++;
            if(mpp.size() <= k){
                maxLen = max(maxLen,j-i+1);
            }
            else break;
        }
    }
    return maxLen;
}
int main(){

    cout<<longestSubstringWithAtmostKchars_BR("tvtgv",4);

    return 0;
}
