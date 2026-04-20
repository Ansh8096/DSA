#include<bits/stdc++.h>
using namespace std;
string minimumWindowSubsequence_BR(string s,string t){
    int n = s.length(), m = t.length(), startIdx = -1, miniLen = INT_MAX;
    for (int i = 0; i < n; i++){
        int j = i, k = 0;
        while(j<n){
            if(k < m && s[j] == t[k]) k++;
            if(k == m){
                if(j-i+1 < miniLen){
                    miniLen = j-i+1;
                    startIdx = i;
                    break;
                }
            }
            j++;
        }
    }
    return startIdx == -1 ? "" : s.substr(startIdx,miniLen);  
}
int main(){

    cout<<minimumWindowSubsequence_BR("abcdebdde","bde");

    return 0;
}
