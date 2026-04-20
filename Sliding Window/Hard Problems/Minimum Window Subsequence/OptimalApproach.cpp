#include<bits/stdc++.h>
using namespace std;
string minimumWindowSubsequence_OP(string s,string t){
int n = s.size(), m = t.size();
    int minLen = INT_MAX, startIdx = -1;
    int i = 0;

    while (i < n) {
        int j = 0;

        // Forward: try matching t inside s
        while (i < n && j < m) {
            if (s[i] == t[j]) j++;
            i++;
        }
        if (j < m) break;     // t not found → no more windows possible

        // Backward: shrink window
        int end = i - 1;      // window ends here
        j = m - 1;
        while (j >= 0) {
            if (s[i - 1] == t[j]) j--;
            i--;
        }

        int start = i;        // smallest start for this window
        int len = end - start + 1;

        if (len < minLen) {
            minLen = len;
            startIdx = start;
        }

        i = start + 1;        // move i to search next possible window
    }

    return (startIdx == -1) ? "" : s.substr(startIdx, minLen);
}
int main(){

    cout<<minimumWindowSubsequence_OP("abcdebdde","bde");

    return 0;
}
