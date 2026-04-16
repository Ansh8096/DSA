#include<bits/stdc++.h>
using namespace std;
int numberOfSubstringsWith3Chars_BR_2(string s) {
    // Slightly optimization , but not for the worst case scenario...
    int cnt = 0; 
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        int hash[3] = {0};
        for (int j = i; j < n; j++){
            hash[s[j] - 'a'] = 1 ;
            if(hash[0] + hash[1] + hash[2] ==  3){
                cnt += n - j;
                break;
            }
        }
    }
    return cnt;
}
int main(){
        
    cout<<numberOfSubstringsWith3Chars_BR_2("bbacba");

    return 0;
}
