#include <bits/stdc++.h>
using namespace std;
int no_of_gas_st(vector<int> &a, int n, long double dist){
  int cnt = 0;
  for (int i = 1; i < n; i++)
  {
    int no_between = ((a[i] - a[i - 1]) / dist);
    if ((a[i] - a[i - 1]) == (dist * no_between))
    { //  1 == (2 * 0.5)
      no_between--;
    }
    cnt += no_between;
  }
  return cnt;
}
long double minimize_max_dist_gaststation_OP(vector<int> &a, int n, int k){
  long double low = 0;
  long double high = 0;
  // Find the maximum distance:
  for (int i = 0; i < n - 1; i++)
  {
    high = max(high, (long double)(a[i + 1] - a[i]));
  }

  // Apply Binary search:
  long double diff = 1e-6;
  while (high - low > diff)
  {
    long double mid = (low + high) / (2.0);
    int cnt = no_of_gas_st(a, n, mid);
    if (cnt > k) low = mid;
    else {
      high = mid;
    }
  }
  return high;
}
int main(){

  int n;
  cout<<"Enter the value n: "<<endl;
  cin>>n;

  vector<int> a(n);
  cout<<"Enter the values of the array:"<<endl;
  for(int i=0;i<n;i++) cin>>a[i];

  int m;
  cout<<"Enter the value of m: "<<endl;
  cin>>m;
    
  cout<<minimize_max_dist_gaststation_OP(a,n,m);
  return 0;
}
