#include<bits/stdc++.h>
using namespace std;
int priorityChk(char ch){
    if(ch == '^') return 3;
    if(ch == '*' || ch == '/') return 2; 
    if(ch == '+' || ch == '-') return 1; 
    else return -1;
}
string infixToPostFix(string s){
    int i = 0;
    string ans = "";
    stack<char> stk;
    // o(n)...
    while(i<s.length()){
        // If the scanned character is an operand , then add it to output string...
        if(s[i] >= 'A' && s[i] <= 'Z' or
           s[i] >= 'a' && s[i] <= 'z' or
           s[i] >= '0' && s[i] <= '9' )
        {
            ans += s[i];
        }

        else if (s[i] == '(') stk.push(s[i]);
        else if (s[i] == ')'){
            // removing operators between the brackets...
            while(!stk.empty() && stk.top() != '('){ // O(n) not always...
                ans += stk.top();
                stk.pop();
            }
            stk.pop(); // for removing '(' from the stack...
        }

        else {

            // removing all the higher priority operators from the stack...
            while(!stk.empty() && priorityChk(s[i]) <= priorityChk(stk.top())){ //  O(n) not always...
                ans += stk.top();
                stk.pop();
            }
            stk.push(s[i]); // now 's[i]' has greater priority then stk.top()...
        }
        i++;
    }

    // if the stack is not empty...
    while(!stk.empty()) { // O(n)... 
        ans += stk.top();
        stk.pop();
    }
    return ans;
}
int main(){

    cout<<infixToPostFix("a+b*(c^d-e)");

    return 0;
}
