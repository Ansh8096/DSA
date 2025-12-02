#include <bits/stdc++.h>
using namespace std;
string bs(vector<int> &a, int m, int target){
  int low = 0, high = m - 1;
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    if (a[mid] == target) return "true";
    else if (a[mid] > target) high = mid - 1;
    else low = mid + 1;
  }
  return "false";
}
string search_in_2D_arr_BT(vector<vector<int>> &a, int n, int m, int target)
{
  for (int i = 0; i < n; i++)
  {
    if (a[i][0] < target && a[i][m - 1] > target)
    {
      return bs(a[i], m, target);
    }
  }
  return "false";
}
int main(){
  vector<vector<int>> matrix ={
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };

  int n = matrix.size();
  int m = matrix[0].size();

  int tar;
  cout<<"enter the target value: "<<endl;
  cin>>tar;

  cout<<search_in_2D_arr_BT(matrix,n,m,tar);
  return 0;
}
