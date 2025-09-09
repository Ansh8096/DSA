#include <bits/stdc++.h>
using namespace std;
void Sec_smallst_elemnt_arr(int arr[], int n){
  int smallest = arr[0];
  int Ssmallest = INT_MAX;
  for (int i = 0; i < n; i++){
    if (arr[i] < smallest){
      Ssmallest = smallest;
      smallest = arr[i];
    }
    else if (arr[i] != smallest && arr[i] < Ssmallest){
      Ssmallest = arr[i];
    }
  }
  cout << "Second smallest element in the array : " << Ssmallest << endl;
}
int main(){

  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;
  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin >> arr[i];
  Sec_smallst_elemnt_arr(arr,n);
  return 0;
}
