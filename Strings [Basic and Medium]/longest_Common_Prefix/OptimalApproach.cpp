#include <bits/stdc++.h>
using namespace std;
string longest_Common_Prefix(vector<string> &str){
  sort(str.begin(), str.end());    // it will sort
  string s1 = str[0];              // first string in vector
  string s2 = str[str.size() - 1]; // last string in vector
  int idx = 0;
  while (idx < min(s1.length(), s2.length())) // comparison between first and last string in the vector...
  {
    if (s1[idx] == s2[idx])
    {
      idx++;
    }
    else break;
  }
  return idx == 0 ? "" : s1.substr(0, idx); // return empty string if idx==0 , else the substring which we want...
}
int main(){

  vector<string> str = {"flow","flower","flight"};
  cout<<longest_Common_Prefix(str);
  return 0;                                                                                          
}
