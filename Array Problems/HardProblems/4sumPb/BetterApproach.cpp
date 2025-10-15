#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> _4sum_BT(vector<int> &arr,int target){
  int n = arr.size();
  set<vector<int>> st;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      set<int> hashset;
      for (int k = j + 1; k < n; k++)
      {
        long long sum = arr[i] + arr[j];
        sum += arr[k];
        // Calculate the 4th element:
        int fourth = target - sum;
        // Find the element in the set:
        if (hashset.find(fourth) != hashset.end())
        {
          vector<int> temp = {arr[i], arr[j], arr[k], fourth};
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
        hashset.insert(arr[k]);
      }
    }
  }
  // store the set in the answer:
  vector<vector<int>> ans(st.begin(), st.end());
  return ans;
}
int main(){
  int n;
  cout << "Enter the size of the array: "<<endl;
  cin >> n;
  vector<int> arr(n);
  cout << "Enter the value of the array: "<<endl;
  for (int i = 0; i < n; i++) cin >> arr[i];
  int target;
  cout << "Enter the target value: "<<endl;
  cin >> target;
  vector<vector<int>> ans2 = _4sum_BT(arr,target);
  for (auto itr : ans2)
  {
    for (auto il : itr)
    {
        cout << il << " ";
    }
    cout << endl;
  }
  return 0;
}
