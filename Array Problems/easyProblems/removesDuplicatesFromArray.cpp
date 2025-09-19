#include <bits/stdc++.h>
using namespace std;
void remov_dup_frm_arr(int arr[], int n){
  int i = 0;
  for (int j = 0; j < n; j++)
  {
    if (arr[j] != arr[i])
    {
      arr[i + 1] = arr[j];
      i++;
    }
  }
  cout << "length of the new array : " << i + 1 << endl; // it will return the length of the new array...
  cout << "new array is: ";
  // for printing the new array...
  for (int k = 0; k < i + 1; k++) cout << arr[k] << " ";
}
int main(){
  
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;
  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];
  
  remov_dup_frm_arr(arr,n);
  return 0;
}
