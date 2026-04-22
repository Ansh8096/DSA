#include<bits/stdc++.h>
using namespace std;
bool checkValidString_BR(string s,int idx,int cnt) {
    if(cnt<0) return false;
    
    if(idx == s.length()){
        return (cnt == 0);
    }

    if(s[idx] == '(') {
        return checkValidString_BR(s,idx+1,cnt+1);
    }
    else if(s[idx] == ')') {
        return checkValidString_BR(s,idx+1,cnt-1);
    }

    else{
        // for opening, for closening for empty char...
        return (checkValidString_BR(s, idx+1, cnt+1) || checkValidString_BR(s, idx+1, cnt-1) || checkValidString_BR(s, idx+1, cnt));
    }
}
int main(){

    cout<<checkValidString_BR("()",0,0);

    return 0;
}
