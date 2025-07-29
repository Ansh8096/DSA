#include <bits/stdc++.h>
using namespace std;

// print3:-

/*  1
    1  2     
    1  2  3    
    1  2  3  4  
    1  2  3  4  5     */

void print3(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j <= i + 1; j++)
    {
      cout << j << " ";
    }
    cout << endl;
  }
}
int main()
{
  int t;
  cout << "enter how many times you want to print diff. patterns: ";
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    int n;
    cin >> n;
    print3(n);
  }
}
