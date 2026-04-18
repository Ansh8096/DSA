#include<bits/stdc++.h>
using namespace std;
int longestSubstringWithAtmostKchars_OP1(string a,int k){
    int maxLen = 0;
    map<char,int>mpp;
    int l=0,r=0,n=a.length(); 
    while (r<n)
    {
        mpp[a[r]]++;
        while(mpp.size()>k){
            mpp[a[l]]--;
            if(mpp[a[l]]==0){
                mpp.erase(a[l]);
            }
            l++;
        }
        maxLen = max(maxLen,r-l+1);
        r++;
    }
    
    return maxLen;
}
int main(){

    cout<<longestSubstringWithAtmostKchars_OP1("tvtgv",4);

    return 0;
}
