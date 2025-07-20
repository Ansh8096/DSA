#include <bits/stdc++.h>
using namespace std;
void problem4(int i, int sum)
{ // sum of thr first N numbers..
  // 1. Parameterized way :-
  if (i < 1)
  {
    cout << sum;
    return;
  }
  problem4(i - 1, sum + i);
}
int main()
{
  int n;
  cout<<"enter the value"<<endl;
  cin >> n;
  problem4(n,0);
  return 0;
}
