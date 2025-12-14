#include <bits/stdc++.h>
using namespace std;
int string_to_integer_OP(string s){
  if (s.length() == 0) return 0; // edge case if string is empty
  int i = 0;
  while (i < s.size() && s[i] == ' '){
    i++;
  }
  s = s.substr(i); // trim down the string...
  int sign = +1;   // to store the sign...
  int max = INT_MAX;
  int min = INT_MIN;
  i = 0; // new index after trimming down the string...
  if (s[i] == '-') sign = -1; // to store the negative sign ....
  i = (s[i] == '+' || s[i] == '-') ? 1 : 0;
  long long ans = 0;
  while (i < s.length()){
    if (s[i] == ' ' || !isdigit(s[i])) break; // break if the s[i] is a non digit string...
    ans = (ans * 10) + (s[i] - '0'); // generating the ans this will also not consider if zero is in starting or after the sign...
    if (sign == -1 && -1 * ans < min) return min;
    if (sign == 1 && ans > max) return max;
    i++;
  }
  return (int)(sign * ans);
}
int main(){
  cout<<string_to_integer_OP("212");
  return 0;                                                                                          
}
