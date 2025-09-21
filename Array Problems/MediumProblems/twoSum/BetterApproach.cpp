#include <bits/stdc++.h>
using namespace std;
pair<int, int> two_sum(int arr[], int n, int target){
 // BETTER APPROACH... T.C-> O (nlogn) OR O(n).
  map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
      int a = arr[i];
      int more = target - a;
      if (mpp.find(more) != mpp.end()){
        cout << "Yes the two sum exists: " << endl;
        return {mpp[more], i};
      }
      else mpp[a] = i;
    }
  cout << "No two sum exists " << endl;
  return {-1, -1};
}
int main(){
  int n;
  cout << "enter the size of an array: " << endl;
  cin >> n;

  int arr[n];
  cout << "enter the values of an array: " << endl;
  for (int i = 0; i < n; i++) cin>>arr[i];

  int target;
  cout<<"Enter the value of target: "<<endl;
  cin>>target;

  pair<int,int> ans = two_sum(arr,n,target);

  // for printing...
  cout<<"{"<<ans.first<<","<<ans.second<<"}"<<endl;
}
