#include <bits/stdc++.h>
using namespace std;
vector<int> rearrange_arr_alt_pos_neg_OP(int arr[],int n){
  vector<int> ans(n);
  int posindex = 0, negindex = 1;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] < 0){
      ans[negindex] = arr[i];
      negindex += 2;
    }
    else{
      ans[posindex] = arr[i];
      posindex += 2;
    }
  }
  return ans;
}
int main(){
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;

  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];

  vector<int> ans = rearrange_arr_alt_pos_neg_OP(arr,n);
  
  // for printing the array
  for (auto itt : ans) cout << itt << " ";
}
