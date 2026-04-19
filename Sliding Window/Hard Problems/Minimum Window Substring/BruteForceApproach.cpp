#include<bits/stdc++.h>
using namespace std;
string minimumWindowSubstring_BR(string s, string t){
    int n = s.length(), m = t.length(), miniLen = INT_MAX, startingIdx = -1;
    for (int i = 0; i < n; i++){
        int hash[256] = {0};
        for (int k = 0; k < m; k++) hash[t[k]]++;
        int cnt = 0;
        for (int j = i; j < n; j++)
        {
            if (hash[s[j]] > 0)cnt++;
            hash[s[j]]--;
            if (cnt == m)
            {
                if (j - i + 1 < miniLen){
                    miniLen = j - i + 1;
                    startingIdx = i;
                    break;
                }
            }
        }
    }
    return s.substr(startingIdx, miniLen);
}
int main(){

    cout<<minimumWindowSubstring_BR("ddaaabbca","abc");

    return 0;
}
