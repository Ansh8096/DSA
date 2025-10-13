#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> _3sum_OP(vector<int> &arr)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;
  for (int i = 0; i < n; i++)
  {
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    int j = i + 1;
    int k = n - 1;
    while (j < k)
    {
      int sum = arr[i] + arr[j] + arr[k];
      if (sum < 0) j++;
      else if (sum > 0) k--;
      else
      {
        vector<int> temp = {arr[i], arr[j], arr[k]};
        ans.push_back(temp);
        j++, k--;
        while (j < k && arr[j] == arr[j - 1]) j++;
        while (j < k && arr[k] == arr[k + 1]) k--;
      }
    }
  }
  return ans;
}
int main(){
  int n;
  cout << "Enter the size of the array: "<<endl;
  cin >> n;
  vector<int> arr(n);
  cout << "Enter the value of the array: "<<endl;
  for (int i = 0; i < n; i++) cin >> arr[i];
  vector<vector<int>> ans2 = _3sum_OP(arr);
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
