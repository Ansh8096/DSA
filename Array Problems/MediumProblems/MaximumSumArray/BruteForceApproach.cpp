#include <bits/stdc++.h>
using namespace std;
int maximum_subarr_sum(int arr[],int n){
  // BRUTE FORCE APPROACH... O(n^3) near about.
  int maxi = INT_MIN;
  for (int i = 0; i < n; i++)
  {
    for (int j = i; j < n; j++)
    {
      int sum = 0;
      for (int k = i; k <= j; k++)
      {
        sum += arr[k];
        maxi = max(maxi, sum);
      }
    }
  }
  return maxi;
}
int main(){
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;

  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];

  cout<<maximum_subarr_sum(arr,n);
}
