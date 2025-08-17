#include <bits/stdc++.h>
using namespace std;
/*
 ******
 **  **
 *    *
 *    *
 **  **
 ******
*/
void print19(int n)
{
  int inis = 0;
  for (int i = 0; i < n; i++)
  {

    // stars
    for (int j = 1; j <= n - i; j++)
    {
      cout << "*";
    }

    // spaces
    for (int j = 0; j < inis; j++)
    {
      cout << " ";
    }

    // stars
    for (int l = 1; l <= n - i; l++)
    {
      cout << "*";
    }
    inis += 2;
    cout << endl;
  }

  inis = 2 * n - 2;
  for (int i = 1; i <= n; i++)
  {
    // stars
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }

    // spaces
    for (int j = 0; j < inis; j++)
    {
      cout << " ";
    }

    // stars
    for (int j = 1; j <= i; j++)
    {
      cout << "*";
    }
    inis -= 2;
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
    print19(n);
  }
}
