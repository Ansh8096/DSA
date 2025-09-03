#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[], int n){
  for (int i = 0; i <= n - 1; i++){
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
      swap(arr[j - 1], arr[j]); j--; // (j--) ---> beacuz we don't want to just compare two elements. we want to compare all the previous elements but not less then the index 0 ...
    }
  }
}
int main(){

  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;
  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin >> arr[i];
  insertion_sort(arr, n);
  cout << "displaying the sorted array :" << endl;
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}
