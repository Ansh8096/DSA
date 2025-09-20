#include <bits/stdc++.h>
using namespace std;
int missing_no(int arr[], int n){
  int XOR1 = 0, XOR2 = 0;
  for (int i = 0; i < n - 1; i++) // 0 --> 3 when n=5;
  {
    XOR2 = XOR2 ^ arr[i];
    XOR1 = XOR1 ^ (i + 1); // 1^2^3^4
  }
  XOR1 = XOR1 ^ n;
  XOR2 = XOR2 ^arr[n-1];
  return XOR1 ^ XOR2;
}
int main(){
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;

  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];

  cout<<missing_no(arr,n);
  return 0;
}
