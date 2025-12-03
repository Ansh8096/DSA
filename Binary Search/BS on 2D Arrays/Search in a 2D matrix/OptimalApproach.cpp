#include <bits/stdc++.h>
using namespace std;
string search_in_2D_arr_OP(vector<vector<int>> &a, int n, int m, int tar)
{  
  int low = 0, high = (n * m) - 1;
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    int row = mid / m;
    int col = mid % m;
    if (a[row][col] == tar) return "true";
    else if (a[row][col] < tar) low = mid + 1;
    else high = mid - 1;
  }
  return "false";
}
int main(){
  vector<vector<int>> matrix ={
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
  };

  int n = matrix.size(); // rowSize...
  int m = matrix[0].size(); // columnSize...

  int tar;
  cout<<"enter the target value: "<<endl;
  cin>>tar;

  cout<<search_in_2D_arr_OP(matrix,n,m,tar);
  return 0;
}
