#include <bits/stdc++.h>
using namespace std;
/*
A
AB
ABC
ABCD
ABCDE
*/
void print14(int n)
{
  for (int i = 1; i <= n; i++)
  {
    char alpy = 'A';
    for (int j = 1; j <= i; j++)
    {
      cout << alpy;
      alpy++;
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
    print14(n);
  }
}
