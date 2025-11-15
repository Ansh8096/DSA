#include <bits/stdc++.h>
using namespace std;
bool place_cows(vector<int> &a, int n, int dist, int cows){
  int cnt_cows = 1, last = a[0];
  for (int i = 1; i < n; i++)
  {
    if (a[i] - last >= dist)
    {
      cnt_cows++;
      last = a[i];
    }
  }
  if (cnt_cows >= cows) return true;
  else return false;
}
int aggressive_cows_OP(vector<int> &a, int n, int cows){
  sort(a.begin(), a.end());
  int low = 1, high = a[n - 1] - a[0];
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (place_cows(a, n, mid, cows) == 1){
      low = mid + 1;
    }
    else high = mid - 1;
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

  int c;
  cout<<"Enter the cows: "<<endl;
  cin>>c;

  cout<<aggressive_cows_OP(a,n,c);
  return 0;
}
