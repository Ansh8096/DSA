#include <bits/stdc++.h>
using namespace std;
void problem_2(int i, int n)
{
  // print from 1 to N using recursion...
  if (i < n)
  {
    return;
  }
  problem_2(i - 1, n);
  cout << i << endl;
}
int main()
{
  int n;
  cout << "enter the value" << endl;
  cin >> n;
  problem_2(n, 1);
  return 0;
}
