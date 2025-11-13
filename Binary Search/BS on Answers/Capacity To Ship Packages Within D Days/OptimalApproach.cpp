#include <bits/stdc++.h>
using namespace std;
int total_days(vector<int> &a, int n, int cap)
{
  // First day.
  int day = 1, load = 0;
  for (int i = 0; i < n; i++)
  {
    if (load + a[i] > cap)
    {
      day++;       // move to next day
      load = a[i]; // load the weight.
    }
    // load the weight on the same day.
    else load += a[i];
  }
  return day;
}
int capacity_to_ship_in_days_OP(vector<int> &a, int n, int d)
{
  // maximum element...
  int low = *max_element(a.begin(), a.end());
  // sum 0f a[]...
  int high = accumulate(a.begin(), a.end(), 0);
  while (low <= high)
  {
    long long mid = (low + high) / 2;
    int no_days = total_days(a, n, mid);
    if (no_days <= d)
    {
      high = mid - 1;
    }
    else low = mid + 1;
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

  int d;
  cout<<"Enter the days : "<<endl;
  cin>>d;

  cout<<capacity_to_ship_in_days_OP(a,n,d);

  return 0;
}
