#include <bits/stdc++.h>
using namespace std;
pair<int, int> two_sum(int arr[], int n, int target){
  // BRUTE FORCE APPROACH... T.C-> O (n^2)
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (arr[i] + arr[j] == target)
      {
        cout << "Yes the two sum exists: " << endl;
        return {i, j}; // we gotta use th pair to return our answer like this...
      }
    }
  }
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
