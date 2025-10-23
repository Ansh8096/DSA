#include <bits/stdc++.h>
using namespace std;
int max_subarr_product_BR(vector<int> &a, int n)
{
  // BRUTE FORCE APPROACH..........
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int product = 1;
      for (int k = i; k <= j; k++)
      {
        product = product * a[k];
      }

      maxi = max(maxi, product);
    }
  }
  return maxi;
}
int main(){
  int n1;
  cout<<"Enter the size of the array: "<<endl;
  cin>>n1;
  vector<int>a(n1);
  cout<<"Enter the value of the array: "<<endl;
  for (int i = 0; i < n1; i++) cin>>a[i];  
  
  cout<<max_subarr_product_BR(a,n1);

  return 0;
}
