#include <bits/stdc++.h>
using namespace std;
void lrgst_elemnt_arr(int arr[], int n)
{
  int largest = arr[0];
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > largest)
    {
      largest = arr[i];
    }
  }
  cout << "Largest element in the array : " << largest << endl;
}
int main(){

  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;
  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin >> arr[i];
  lrgst_elemnt_arr(arr,n);
  return 0;
}
