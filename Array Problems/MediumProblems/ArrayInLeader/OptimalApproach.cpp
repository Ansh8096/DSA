#include <bits/stdc++.h>
using namespace std;
vector<int> leaders_inArray_OP(vector<int> &arr,int n){
  vector<int> ans;
  int maxi = INT_MIN;
  for (int i = n - 1; i >= 0; i--){
    if (arr[i] > maxi){
      ans.push_back(arr[i]);
    }
    // Keep track of the maxi....
    maxi = max(maxi, arr[i]);
  }
  return ans;
}
int main(){
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;

  vector<int> arr(n);
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];

  vector<int> ans = leaders_inArray_OP(arr,n);
  
  // for printing the array
  for (auto itt : ans) cout << itt << " ";
}
