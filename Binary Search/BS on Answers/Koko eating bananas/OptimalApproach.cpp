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
int koko_eats_banana_OP(vector<int> &a, int n, int h){
  int low = 1, high = max_el_for_koko(a, n);
  while (low <= high){
    int mid = (low + high) / 2;
    int total_hrs = cal_total_tym(a, n, mid);
    if (total_hrs <= h)
    {
      high = mid - 1;
    }
    else
    {
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

  int h;
  cout<<"Enter the hours: "<<endl;
  cin>>h;

  cout<<koko_eats_banana_OP(a,n,h);
  return 0;
}
