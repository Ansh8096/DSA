// RECURSION METHOD :-------->
#include <bits/stdc++.h>
using namespace std;
void bubble_sort_rec(int arr[], int n){
    if (n<0) return;
    for (int j = 0; j <= n-1; j++)
    {
        if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
    } 
    bubble_sort_rec(arr,n-1); 
}
int main(){
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;
  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin >> arr[i];

  bubble_sort_rec(arr, n);

  cout << "displaying the sorted array :" << endl;
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  
  return 0;
}
