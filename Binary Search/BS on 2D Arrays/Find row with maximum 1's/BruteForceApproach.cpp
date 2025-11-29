#include <bits/stdc++.h>
using namespace std;
int row_with_max_ones_BR(vector<vector<int>> &a, int n, int m)
{
  int cnt = 0, max_cnt = -1, idx = -1;
  for (int i = 0; i < n; i++)
  {
    int cnt_row = 0;
    for (int j = 0; j < m; j++)
    {
      cnt_row += a[i][j]; // it will tell us that which row has maximum ones....
      if (cnt_row > max_cnt)
      {
        max_cnt = cnt_row;
        idx = i;
      }
    }
  }
  return idx;
}
int main(){
   vector<vector<int>> matrix = {{0, 1, 1}, {1, 1, 1}, {0, 0, 0}};
    int n = 3, m = 3;
  cout<<row_with_max_ones_BR(matrix,n,m);
  return 0;
}
