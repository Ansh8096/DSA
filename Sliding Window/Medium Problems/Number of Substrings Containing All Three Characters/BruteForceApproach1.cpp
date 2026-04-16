#include<bits/stdc++.h>
using namespace std;
int numberOfSubstringsWith3Chars_BR_1(string s) {
    int cnt = 0; 
    for (int i = 0; i < s.length(); i++)
    {
        int hash[3] = {0};
        for (int j = i; j < s.length(); j++){
            hash[s[j] - 'a'] = 1 ;
            if(hash[0] + hash[1] + hash[2] ==  3){
                cnt++;
            }
        }
    }
    return cnt;

}
int main(){
        
    cout<<numberOfSubstringsWith3Chars_BR_1("bbacba");

    return 0;
}
