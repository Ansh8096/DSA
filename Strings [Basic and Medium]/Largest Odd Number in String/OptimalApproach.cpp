#include <bits/stdc++.h>
using namespace std;
string largest_Odd_Number_OP(string &s){
  int n = s.length();
  for (int i = n - 1; i >= 0; i--)
  {
    if ((s[i] - '0') % 2 != 0) // it will convert char into int by subtracting '0' from s[i]...
    {
      return s.substr(0, i + 1);
    }
  }
  return "";
}
int main(){
  string str;
  cout<<"Enter the string :"<<endl;
  getline(cin,str); // this will take the entire line as our string.. 

  cout<<largest_Odd_Number_OP(str);
  return 0;                                                                                          
}
