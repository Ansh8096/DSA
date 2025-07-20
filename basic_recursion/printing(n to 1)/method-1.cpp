#include <bits/stdc++.h>
using namespace std;
void problem3(int i, int n)
{ // print from N to 1 using recursion...
  if (i < 1)
  {
    return;
  }
  cout << i << " ";
  problem3(i - 1, n);
}
int main()
{
  int n;
  cout<<"enter the value"<<endl;
  cin >> n;
  problem3(n,n);
  return 0;
}
