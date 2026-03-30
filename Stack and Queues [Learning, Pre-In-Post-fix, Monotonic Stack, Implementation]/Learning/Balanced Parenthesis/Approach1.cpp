#include<bits/stdc++.h>
using namespace std;
bool BalanceAndValidParenthesis(string s)
{
    stack<char> stk;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stk.push(s[i]);
        }

        else
        {
            // means there is no opening parenthesis present in stack for closing parenthesis.
            if (stk.size() == 0) return false;

            char poped = stk.top();
            stk.pop();
            if ((s[i] == ')' && poped == '(') or (s[i] == ']' && poped == '[') or (s[i] == '}' && poped == '{'))
            {
                continue;
            }
            else return false;
        }
    }
    return stk.empty();
}
int main(){
    
    cout<< BalanceAndValidParenthesis("(){[}]");

    return 0;
}
