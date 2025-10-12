#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> _3sum_BR(vector<int> &arr){
  int n = arr.size();
  set<vector<int>> st;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      for (int k = j + 1; k < n; k++){
        if (arr[i] + arr[j] + arr[k] == 0){
          vector<int> temp = {arr[i], arr[j], arr[k]};
          sort(temp.begin(), temp.end());
          st.insert(temp);
        }
      }
    }
  }
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
  vector<vector<int>> ans2 = _3sum_BR(arr);
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
