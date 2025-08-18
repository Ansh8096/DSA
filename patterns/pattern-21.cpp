#include <bits/stdc++.h>
using namespace std;
/*
*      *
**    **
***  ***
********
***  ***
**    **
*      *
*/
void print20(int n)
{
  int space = 2 * n - 2;
  for (int i = 1; i <= 2 * n - 1; i++)
  {
    int stars = i;
    if (i > n)
      stars = 2 * n - i;

    // stars
    for (int i = 1; i <= stars; i++)
    {
      cout << "*";
    }

    // spaces
    for (int j = 1; j <= space; j++)
    {
      cout << " ";
    }

    // stars
    for (int i = 1; i <= stars; i++)
    {
      cout << "*";
    }
    cout << endl;
    if (i < n)
      space -= 2;
    else
      space += 2;
  }
}
int main(){
  int t;
  cout << "enter how many times you want to print diff. patterns: " << endl;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    print20(n);
  }
}
