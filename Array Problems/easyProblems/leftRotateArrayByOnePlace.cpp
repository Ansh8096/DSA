#include <bits/stdc++.h>
using namespace std;
void left_rot_arr_byONE_place(int arr[], int n){
  int temp = arr[0];
  for (int i = 1; i < n; i++){
    arr[i - 1] = arr[i];
  }
  arr[n - 1] = temp;

  // for printing our array..
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
int main(){
  
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;
  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];
  
  left_rot_arr_byONE_place(arr,n);
  return 0;
}
