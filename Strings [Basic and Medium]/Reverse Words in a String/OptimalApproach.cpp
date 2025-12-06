#include <bits/stdc++.h>
using namespace std;
string reverse_words_OP(string &s){
  int n = s.length();
  string ans = "";
  reverse(s.begin(), s.end());
  for (int i = 0; i < n; i++)
  {
    string word = "";
    while (s[i] != ' ' && i < n)
    {
      word += s[i];
      i++;
    }
    reverse(word.begin(), word.end());
    if (word.length() > 0)
    {
      ans += " " + word;
    }
  }
  return ans.substr(1);
}
int main(){
  string str;
  cout<<"Enter the string :"<<endl;
  getline(cin,str); // this will take the entire line as our string.. 

  cout<<reverse_words_OP(str);
  return 0;                                                                                          
}
