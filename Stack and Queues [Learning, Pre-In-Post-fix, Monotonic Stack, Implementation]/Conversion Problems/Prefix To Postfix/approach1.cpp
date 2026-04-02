#include<bits/stdc++.h>
using namespace std;
string prefixToPostfix(string s){
    stack<string> stk;
    int i = s.length()-1;
    while (i >= 0){
        if(s[i] >= 'A' && s[i] <= 'Z' or
           s[i] >= 'a' && s[i] <= 'z' or
           s[i] >= '0' && s[i] <= '9' ){
            stk.push(string(1, s[i]));
        }

        else{
            string top1 = stk.top();
            stk.pop();
            string top2 = stk.top();
            stk.pop();
            // This string generation takes t.c of (o(n1) + o(n2)) in some languages...
                // where: n1 = length of first string , n2 = length of second string    
            string reqString = top1 + top2 + s[i]; 

            stk.push(reqString); 
        }
        i--;
    }
    return stk.top();
}
int main(){

    cout<<prefixToPostfix("/-AB*+DEF");

    return 0;
}
