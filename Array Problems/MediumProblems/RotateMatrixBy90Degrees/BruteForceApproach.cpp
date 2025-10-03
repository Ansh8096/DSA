#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> rotate_by90_matrix_BR(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  vector<vector<int>> ans(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      ans[j][n - 1 - i] = matrix[i][j];
    }
  }
  return ans;
}
int main(){
  vector<vector<int>> matrix = {
    {1,2,3,4,5,6},        // matrix[0]
    {20,21,22,23,24,7},   // matrix[1]
    {19,32,33,34,25,8},   // matrix[2] 
    {18,31,36,35,26,9},   // matrix[3]
    {17,30,29,28,27,10},  // matrix[4]
    {16,15,14,13,12,11}   // matrix[5]
  };
  int n=matrix.size();
  int m = matrix[0].size();  
  vector<vector<int>> ans=rotate_by90_matrix_BR(matrix);
  cout<<"rotated matrix is : "<<endl;
  for (int i = 0; i < matrix.size(); i++){
      for (int j = 0; j < matrix[0].size(); j++){
          cout<<ans[i][j]<<" ";
      }
      cout<<endl;
  }
  return 0; 
}
