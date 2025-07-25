#include <bits/stdc++.h>
using namespace std;
bool problem7(int i, string &s)
{ // to check if the given string is palindrome or not using recursion...
  if (i >= s.size() / 2)
  {
    return true;
  }
  if (s[i] != s[s.size() - i - 1])
  {
    return false;
  }
  problem7(i + 1, s);
}
int main()
{
  string str;
  cout<<"enter the string :"<<endl;
  cin >> str;
  cout<<problem7(0,str);

  return 0;
}
