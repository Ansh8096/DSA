#include <bits/stdc++.h>
using namespace std;
int find_mid_N(int mid, int n, int m)
{
  // return 1, if == m:
  // return 0, if < m:
  // return 2, if > m:
  long long ans = 1;
  for (int i = 1; i <= n; i++){
    ans *= mid;
    if (ans > m) return 2;
  }

  if (ans == m) return 1;
  else return 0;
}
int find_Nth_root_of_integer_OP(int n, int m)
{
  // Use Binary search on the answer space:
  int low = 1, high = m;
  while (low <= high)
  {
    long long mid = (low + high) / 2;
    long long mid_n = find_mid_N(mid, n, m);
    if (mid_n == 1) return mid; // answer is found...
    else if (mid_n == 0) low = mid + 1; // eliminate left half...
    else high = mid - 1; // eliminate right half...
  }
  return -1;
}
int main(){
  int n;
  cout<<"Enter the value of n: "<<endl;
  cin>>n;

  int m;
  cout<<"Enter the value of m: "<<endl;
  cin>>m;

  cout<<find_Nth_root_of_integer_OP(n,m);
  return 0;
}
