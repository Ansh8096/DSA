#include <bits/stdc++.h>
using namespace std;
void max_consecutive_ones(int arr[], int n){
  int maxi = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 1)
    {
      cnt++;
      maxi = max(maxi, cnt);
    }
    else
    {
      cnt = 0;
    }
  }
  cout << "the max. no. of consecutive ones in the array " << maxi << endl;
}
int main(){
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;

  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];
  
  max_consecutive_ones(arr,n);
  return 0;
}
