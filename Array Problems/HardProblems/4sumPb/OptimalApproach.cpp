#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> _4sum_OP(vector<int> &arr, int target)
{
  int n = arr.size();
  vector<vector<int>> ans;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n; i++)
  {
    // avoid the duplicates while moving i:
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    for (int j = i + 1; j < n; j++)
    {
      // avoid the duplicates while moving j:
      if (j > i + 1 && arr[j] == arr[j - 1]) continue;

      // 2 pointers:
      int k = j + 1, l = n - 1;
      while (k < l)
      {
        long long sum = arr[i] + arr[j];
        sum += arr[k];
        sum += arr[l];
        if (sum == target)
        {
          vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
          ans.push_back(temp);
          k++, l--;
          // skip the duplicates:
          while (k < l && arr[k] == arr[k - 1])
            k++;
          while (k < l && arr[l] == arr[l + 1])
            l--;
        }
        if (sum < target)
          k++;
        if (sum > target)
          l--;
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
  int target;
  cout << "Enter the target value: "<<endl;
  cin >> target;
  vector<vector<int>> ans2 = _4sum_OP(arr,target);
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
