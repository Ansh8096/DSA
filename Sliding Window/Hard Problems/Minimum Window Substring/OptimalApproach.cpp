#include<bits/stdc++.h>
using namespace std;
string minimumWindowSubstring_OP(string s, string t){
    int l = 0, r = 0, miniLen = INT_MAX, startIdx = -1, cnt = 0, n = s.length(), m = t.length();
    int hash[256] = {0};
    for (int i = 0; i < m; i++){
        hash[t[i]]++;
    }

    while (r<n){
        if(hash[s[r]] > 0) cnt++;
        hash[s[r]]--;

        while(cnt == m){
            if (r - l + 1 < miniLen)
            {
                miniLen = r - l + 1;
                startIdx = l;
            }
            hash[s[l]]++;
            if(hash[s[l]] > 0) cnt--; 
            l++;
        }
        r++;
    }

    return startIdx == -1 ? "" : s.substr(startIdx,miniLen);  
}
int main(){

    cout<<minimumWindowSubstring_OP("ddaaabbca","abc");

    return 0;
}
