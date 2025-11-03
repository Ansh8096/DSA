#include <bits/stdc++.h>
using namespace std;
int how_many_times_arr_has_been_rotatd_dup(vector<int> &a, int n){
  // this one is finding how many times the array has been rotated if the array has duplicate elements...
  int l = 0, h = n - 1;
  int ans = INT_MAX;
  int idx = -1;
  while (l <= h)
  {
    int m = (l + h) / 2;

    // updates the answer..
    if (a[m] < ans)
    {
      ans = a[m];
      idx = m;
    }
    // slightly omptimization...(to avoid duplicates)
    if (a[l] <= a[m] && a[m] <= a[h])
    {
      l++, h--;
    }
    // if left is sorted..
    if (a[l] <= a[m])
    {
      if (a[l] < ans)
      {
        ans = a[l];
        idx = l;
      }
      l = m + 1;
    }
    // if right is sorted..
    if (a[m] <= a[h])
    {
      if (a[m] < ans)
      {
        ans = a[m];
        idx = m;
      }
      h = m - 1;
    }
  }
  return idx;
}
int main(){
  int n1;
  cout<<"Enter the size of the array: "<<endl;
  cin>>n1;

  vector<int>a(n1);
  cout<<"Enter the value of the array: "<<endl;
  for (int i = 0; i < n1; i++) cin>>a[i]; 

  cout<<how_many_times_arr_has_been_rotatd_dup(a,n1);
  return 0;
}
