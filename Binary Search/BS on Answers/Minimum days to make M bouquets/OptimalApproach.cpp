#include <bits/stdc++.h>
using namespace std;
int max_el_for_koko(vector<int> &a, int n){
  int maxii = INT_MIN;
  // find the maximum:
  for (int i = 0; i < n; i++)
  {
    maxii = max(maxii, a[i]);
  }
  return maxii;
}
int mini_days(vector<int> &a, int n){
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans = min(ans, a[i]);
  }
  return ans;
}
bool possible_toMake_bouquets(vector<int> &a, int n, int days, int m, int k){
  int cnt = 0, ans = 0;
  // count the number of bouquets:
  for (int i = 0; i < n; i++)
  {
    if (a[i] <= days) cnt++;
    else{
      ans += (cnt / k);
      cnt = 0;
    }
  }
  ans += (cnt / k);
  if (ans >= m) return true;
  else return false;
}
int mini_days_toMake_bouquets_OP(vector<int> &a,int n,int m,int k){
  if (n < m * k) return -1;   // edge case..
  int low = mini_days(a, n);  // this will give the min. element in the arr..
  int high = max_el_for_koko(a, n); // this will give the max. element in the arr..
  while (low <= high){
    int mid = (low + high) / 2;
    if (possible_toMake_bouquets(a, n, mid, m, k) == 1){
      high = mid - 1;
    }
    else{
      low = mid + 1;
    }
  }
  return low;
}
int main(){

  int n;
  cout<<"Enter the value n: "<<endl;
  cin>>n;

  vector<int> a(n);
  cout<<"Enter the values of the array:"<<endl;
  for(int i=0;i<n;i++) cin>>a[i];

  int m;
  cout<<"Enter the no. of boutique you need (m): "<<endl;
  cin>>m;

  int k;
  cout<<"Enter the flowers you need to make boutique (k): "<<endl;
  cin>>k;

  cout<<mini_days_toMake_bouquets_OP(a,n,m,k);

  return 0;
}
