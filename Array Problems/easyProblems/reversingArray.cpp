#include <bits/stdc++.h>
using namespace std;
void reverse_arr_D(int arr[], int start, int end)
{
  while (start <= end)
  {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}
int main(){
  
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;
  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];
  
  reverse_arr_D(arr,0,n-1);
  // for printing our array..
  for (int i = 0; i < n; i++)  cout<<arr[i]<<" ";
  return 0;
}
