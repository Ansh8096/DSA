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
int cal_total_tym(vector<int> &a, int n, int hourly){
  int totalH = 0;
  // find total hours:
  for (int i = 0; i < n; i++)
  {
    totalH += ceil((double)a[i] / (double)hourly);
  }
  return totalH;
}
int koko_eats_banana_BR(vector<int> &a, int n, int h){
  // Find the maximum number:
  int maxi = max_el_for_koko(a, n);
  // Find the minimum value of k:
  for (int i = 1; i <= maxi; i++)
  {
    int req_tym = cal_total_tym(a, n, i);
    // since we are iterating from 1 we will get the closest answer...
    if (req_tym <= h) return i;
  }
  // dummy return statement....
  return maxi;
}
int main(){
  int n;
  cout<<"Enter the value n: "<<endl;
  cin>>n;

  vector<int> a(n);
  cout<<"Enter the values of the array:"<<endl;
  for(int i=0;i<n;i++) cin>>a[i];

  int h;
  cout<<"Enter the hours: "<<endl;
  cin>>h;

  cout<<koko_eats_banana_BR(a,n,h);
  return 0;
}
