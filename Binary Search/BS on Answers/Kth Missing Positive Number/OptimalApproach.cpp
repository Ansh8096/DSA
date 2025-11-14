#include <bits/stdc++.h>
using namespace std;
int Kth_missing_no_sortd_ARR_OP(vector<int> &a, int n, int k){
  int low = 0, high = n - 1;
  while (low <= high){
    int mid = (low + high) / 2;
    int missing = a[mid] - (mid + 1);
    if (missing < k) low = mid + 1;
    else high = mid - 1;
  }
  return high + k + 1;
}
int main(){

  int n;
  cout<<"Enter the value n: "<<endl;
  cin>>n;

  vector<int> a(n);
  cout<<"Enter the values of the array:"<<endl;
  for(int i=0;i<n;i++) cin>>a[i];

  int k;
  cout<<"Enter the value of Kth missing no.: "<<endl;
  cin>>k;
  cout<<Kth_missing_no_sortd_ARR_OP(a,n,k);

  return 0;
}
