#include <bits/stdc++.h>
using namespace std;
int lower_boundd(vector<int> &a, int m, int x)
{
  int low = 0, high = m - 1;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (a[mid] >= x)
    {
      high = mid - 1;
    }
    else low = mid + 1;
  }
  return low;
}
int row_with_max_ones_OP(vector<vector<int>> &a, int n, int m)
{
  int cnt = 0, max_cnt = 0, idx = -1;
  for (int i = 0; i < n; i++)
  {
    int cnt_ones = m - lower_boundd(a[i], m, 1); // it will give us the count of 1's in the particular array....
    if (cnt_ones > max_cnt)
    {
      max_cnt = cnt_ones;
      idx = i;
    }
  }
  return idx;
}
int main(){
  vector<vector<int>> matrix = {{0, 1, 1}, {1, 1, 1}, {0, 0, 0}};
  int n = 3, m = 3;
  cout<<row_with_max_ones_OP(matrix,n,m);
  return 0;
}
