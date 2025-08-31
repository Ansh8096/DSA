#include <bits/stdc++.h>
using namespace std;
void selection_sort(int arr[], int n){
  for (int i = 0; i <= n - 2; i++)
  {
    int min = i;
    for (int j = i; j <= n - 1; j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }
    swap(arr[i], arr[min]);
    // int temp =arr[min];
    // arr[min]=arr[i];
    // arr[i]=temp;
  }
}
int main(){
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;
  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin >> arr[i];

  selection_sort(arr, n);

  cout << "displaying the sorted array :" << endl;
  for (int i = 0; i < n; i++) cout << arr[i] << " ";
  
  return 0;
}
