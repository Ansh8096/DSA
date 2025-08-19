#include <bits/stdc++.h>
using namespace std;
/*
555555555
544444445
543333345
543222345
543212345
543222345
543333345
544444445
555555555
*/
void print23(int n)
{
  for (int i = 0; i < 2 * n - 1; i++)
  {
    for (int j = 0; j < 2 * n - 1; j++)
    {
      int top = i;
      int left = j;
      int right = (2 * n - 1) - 1 - j;
      int bottom = (2 * n - 1) - 1 - i;
      cout << (n - min(min(top, bottom), min(left, right)));
    }
    cout << endl;
  }
}
int main(){
  int t;
  cout << "enter how many times you want to print diff. patterns: " << endl;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    print23(n);
  }
}
