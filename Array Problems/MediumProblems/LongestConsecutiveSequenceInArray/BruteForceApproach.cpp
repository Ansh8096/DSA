#include <bits/stdc++.h>
using namespace std;
int ls(vector<int> &arr,int num){
    int n=arr.size();
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==num) return true;
    
    }
    return false;
}
int lngst_cons_sequence_BR(vector<int> &arr,int n){
  // BRUTE FORCE APPROACH.....
  int longest=1;
  for (int i = 0; i < n; i++){
    int x = arr[i];
    int cnt = 1;
    while (ls(arr, x + 1) == true){
      x = x + 1;
      cnt += 1;
    }
    longest = max(longest, cnt);
  }
  return longest;
}
int main(){
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;

  vector<int> arr(n);
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];

  cout<<lngst_cons_sequence_BR(arr,n);

}
