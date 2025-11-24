#include <bits/stdc++.h>
using namespace std;
double mdn_of_two_sortd_arr_OP(vector<int> &a1, vector<int> &a2){
  int n1 = a1.size();
  int n2 = a2.size();
  // if n1 is bigger swap the arrays:
  if (n2 < n1) return mdn_of_two_sortd_arr_OP(a2, a1);
  int left = (n1 + n2 + 1) / 2; // length of left half
  int n = n1 + n2;              // total length
  // apply binary search:
  int low = 0;
  int high = n1;
  while (low <= high)
  {
    int mid1 = (low + high) >> 1;
    int mid2 = left - mid1;
    // calculate l1, l2, r1 and r2;
    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;
    if (mid1 < n1) r1 = a1[mid1];
    if (mid2 < n2) r2 = a2[mid2];
    if (mid1 - 1 >= 0) l1 = a1[mid1 - 1];
    if (mid2 - 1 >= 0) l2 = a2[mid2 - 1];
    if (l1 <= r2 && l2 <= r1)
    {
      if (n % 2 == 1) // it is odd.....
      {
        return max(l1, l2);
      }
      else // it is even....
      {
        return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
      }
    }

    // eliminate the halves:
    else if (l1 > r2) high = mid1 - 1;
    else low = mid1 + 1;
  }
  // dummy return .........
  return 0.0;
}
int main(){

  int n;
  cout<<"Enter the value n: "<<endl;
  cin>>n;

  vector<int> a(n);
  cout<<"Enter the values of the array:"<<endl;
  for(int i=0;i<n;i++) cin>>a[i];

  int n1;
  cout<<"Enter the value n: "<<endl;
  cin>>n1;

  vector<int> a1(n1);
  cout<<"Enter the values of the array:"<<endl;
  for(int i=0;i<n1;i++) cin>>a1[i];
    
  cout<<mdn_of_two_sortd_arr_OP(a,a1);
  return 0;
}
