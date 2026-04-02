#include<bits/stdc++.h>
using namespace std;
string postfixToPrefix(string s){
    stack<string> stk;
    int i = 0;
    while (i < s.length()){
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
            // Where: n1 = length of first string, n2 = length of second string...    
            string reqString = s[i] + top2 + top1; 

            stk.push(reqString); 
        }
        i++;
    }
    return stk.top();
}
int main(){

    cout<<postfixToPrefix("AB-DE+F*/");

    return 0;
}
