#include <bits/stdc++.h>
using namespace std;
int find_sqrt_BR(int n){
  int ans = 1;
  for (int i = 1; i < n; i++)
  {
    if (i * i <= n)
    {
      ans = i;
    }
    else break;
  }
  return ans;
}
int main(){
  int n1;
  cout<<"Enter the value of n1: "<<endl;
  cin>>n1;

  cout<<find_sqrt_BR(n1);
  return 0;
}
