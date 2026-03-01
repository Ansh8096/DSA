#include <bits/stdc++.h>
using namespace std;

void expressionAddOperators_OP(string s, int target, int i, string temp, long eval, int lastVal, vector<string> &ans){
  if (i == s.length())
  {
    if (eval == target)
    {
      ans.push_back(temp);
    }
    return;
  }
  string currStr;                      // it will store the current chars and subsets of the string...
  long num = 0;                        // it will store the current chars and subsets of the string as the lastVal used in our expression...
  for (int j = i; j < s.length(); j++) // loop to get the recursive calls for chars as well as for setsin string...
  {
    if (j > i && s[i] == '0') return; // when s[i]='0',so we need to skip it because our subset can't have zero...
    currStr += s[j];               // it will have single chars and as well as subsets in string ...
    num = num * 10 + (s[j] - '0'); // it will have single chars and as well as our subsets as lastVal...

    if (i == 0)
    {
      expressionAddOperators_OP(s, target, j + 1, temp + currStr, num, num, ans); // initially lastVal and eval will be num...
    }
    else
    {
      // for addition...
      expressionAddOperators_OP(s, target, j + 1, temp + "+" + currStr, eval + num, num, ans); // initially lastVal and eval will be num...

      // for subtraction...
      expressionAddOperators_OP(s, target, j + 1, temp + "-" + currStr, eval - num, -num, ans); // lastVal should be in '-ve'...

      // for multiplication...
      expressionAddOperators_OP(s, target, j + 1, temp + "*" + currStr, eval - lastVal + (lastVal * num), lastVal * num, ans); // lastVal should be in 'num*lastVal'...
    }
  }
}

int main(){
  string s = "232";
  int target = 8;
  vector<string> ans;
  expressionAddOperators_OP(s, target, 0, "", 0, 0, ans);
  for (auto str : ans)
  {
    cout << str << " ";
  }
  return 0;
}
