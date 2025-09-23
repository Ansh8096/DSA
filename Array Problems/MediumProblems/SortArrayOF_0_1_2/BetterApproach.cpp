#include <bits/stdc++.h>
using namespace std;
void sort_0_1_2_BT(int arr[],int n){
  // BETTER APPROACH: T.C--> O(2n).
  int cnt0 = 0, cnt1=0, cnt2 = 0;
  for (int  i = 0; i < n; i++){
    if(arr[i] == 0) cnt0++;
    if(arr[i] == 1) cnt1++;
    if(arr[i] == 2) cnt2++;
  }
  for (int i = 0; i < cnt0; i++) arr[i] = 0;
  for (int i = cnt0; i < cnt0+cnt1; i++) arr[i] = 1;
  for (int i = cnt0+cnt1; i < n; i++) arr[i] = 2; 
}
int main(){
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;

  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];

  sort_0_1_2_BT(arr,n);
  for (int i = 0; i < n; i++) cout<<arr[i]<<" ";
}
