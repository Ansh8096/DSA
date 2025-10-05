#include <bits/stdc++.h>
using namespace std;
int cnt_subarr_sumK(vector<int> &arr, int n, int k){
  unordered_map<int, int> mpp;
  mpp[0] = 1; // for storing zero with cnt=1;
  int presum = 0, cnt = 0;
  for (int i = 0; i < n; i++){
    // add current element to prefix Sum:
    presum += arr[i];
    // Calculate x-k:
    int remove = presum - k;
    // Add the number of subarrays to be removed:
    cnt += mpp[remove]; // mpp[remove] will be cnt of the presum stored in the map....

    // Update the count of prefix sum
    // in the map
    mpp[presum] += 1; // it will store the presum in the map with cnt;
  }
  return cnt;
}
int main(){
  int n;
  cout<<"Enter the size of the array: "<<endl;
  cin>>n;

  int k;
  cout<<"Enter the value of k : "<<endl;
  cin>>k;

  vector<int> arr(n);
  cout<<"Enter the value of the array: "<<endl;
  for (int i = 0; i < n; i++) cin>>arr[i];

  cout<<cnt_subarr_sumK(arr,n,k);
  return 0; 
}
