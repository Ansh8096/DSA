#include<bits/stdc++.h>
using namespace std;
int numberOfSubstringsWith3Chars_OP(string s) {
    // Slightly optimization , but not for the worst case scenario...
    int cnt = 0; 
    int n = s.length();
    int hash[3] = {-1,-1,-1};
    for (int i = 0; i < n; i++){
        hash[s[i]-'a'] = i;
        // It means , I have encounter the valid window... 
        if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){ // we can also omit this check as well...
            int idx = min(hash[0],hash[1]);
            idx = min (idx,hash[2]);
            cnt += idx+1;
        }
    }
    return cnt;
}
int main(){
        
    cout<<numberOfSubstringsWith3Chars_OP("bbacba");

    return 0;
}
