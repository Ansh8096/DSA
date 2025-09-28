#include <bits/stdc++.h>
using namespace std;
vector<int> next_permutation_op(vector<int> &arr, int n){
  int ind = -1;
  // this is for finding the break point.... T.C->O(n)
  for (int i = n - 2; i >= 0; i--)
  {
    if (arr[i] < arr[i + 1])
    {
      ind = i;
      break;
    }
  }
  // this is when we the giver arr is the last permutation so we just need to reverse it..
  if (ind == -1)
  {
    reverse(arr.begin(), arr.end());
    return arr;
  }

  // now we are finding the just greater element then arr[ind] T.C->O(n)
  for (int i = n - 1; i >= ind; i--)
  {
    if (arr[i] > arr[ind])
    {
      swap(arr[i], arr[ind]);
      break;
    }
  }

  // now we are reversing the left elements.. T.C->O(n)
  reverse(arr.begin() + ind + 1, arr.end());
  return arr;
}
int main(){
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;

  vector<int> arr(n);
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];

  vector<int> ans = next_permutation_op(arr,n);
  
  // for printing the array
  for (auto itt : ans) cout << itt << " ";
}
