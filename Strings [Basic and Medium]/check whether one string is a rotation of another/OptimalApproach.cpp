#include <bits/stdc++.h>
using namespace std;
string rotate_String_OP(string s, string t){
  if (s.size() != t.size()) return "false";    // if the size are not equal then they can't be rotaion of eachother
  string temp = s + s; // temp.string made_by_adding s1 twice,beacuz rotaion will be present in this only
  if (temp.find(t) != -1) return "true"; // if it is not pointing -1 then it is present..
  else return "false"; // it is not present...
}
int main(){
  cout<<rotate_String_OP("abcde","cdeab");
  return 0;                                                                                          
}
