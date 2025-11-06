#include <bits/stdc++.h>
using namespace std;
int find_peak_element_OP(vector<int> &a, int n){
  // Edge cases:
  if (n == 1) return 0;
  if (a[0] > a[1]) return 0;
  if (a[n - 1] > a[n - 2]) return n - 1;
  int low = 1, high = n - 2;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    // If arr[mid] is the peak:
    if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
    {
      return mid;
    }
    // If we are in the left:
    else if (a[mid] > a[mid - 1])
    {
      low = mid + 1;
    }
    // If we are in the right:
    // Or, arr[mid] is a common point:
    else
    {
      high = mid - 1;
    }
  }
  // Dummy return statement
  return -1;
}
int main(){
  int n1;
  cout<<"Enter the size of the array: "<<endl;
  cin>>n1;

  vector<int>a(n1);
  cout<<"Enter the value of the array: "<<endl;
  for (int i = 0; i < n1; i++) cin>>a[i]; 

  cout<<find_peak_element_OP(a,n1);
  return 0;
}
