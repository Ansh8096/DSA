#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> rotate_by90_matrix_OP(vector<vector<int>> &matrix)
{
  int n = matrix.size();
  // for transposing..
  for (int i = 0; i <= n - 2; i++){
    for (int j = i + 1; j <= n - 1; j++){
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  // for reversing rows..
  for (int i = 0; i < n; i++){
    reverse(matrix[i].begin(), matrix[i].end());
  }
  return matrix;
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
  vector<vector<int>> ans=rotate_by90_matrix_OP(matrix);
  cout<<"rotated matrix is : "<<endl;
  for (int i = 0; i < matrix.size(); i++){
      for (int j = 0; j < matrix[0].size(); j++){
          cout<<ans[i][j]<<" ";
      }
      cout<<endl;
  }
  return 0; 
}
