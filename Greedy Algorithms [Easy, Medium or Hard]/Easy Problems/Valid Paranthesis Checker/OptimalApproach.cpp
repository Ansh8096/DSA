#include<bits/stdc++.h>
using namespace std;
bool checkValidString_OP(string s) {
    int mini = 0, maxi = 0;
    for(int i = 0;i<s.length();i++){
        if(s[i] == '(') {
            mini++;maxi++;
        }
        else if (s[i] == ')'){
            mini--;maxi--;
        }
        else if (s[i] == '*'){
            mini--;
            maxi++;
        }
        if(mini<0) mini = 0;
        if(maxi<0) return false;
    }
    
    return (mini==0);
}
int main(){

    cout<<checkValidString_OP("()");

    return 0;
}
