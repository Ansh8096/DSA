#include <bits/stdc++.h>
using namespace std;
void markRow(vector<vector<int>> &matrix, int i, int n, int m){
  // it find all non-zero elements in the marked row and change them to -1
  for (int j = 0; j < m; j++)
  {
    if (matrix[i][j] != 0)
    {
      matrix[i][j] = -1;
    }
  }
}
void markColumn(vector<vector<int>> &matrix, int j, int n, int m){
  // it find all non-zero elements in the marked column and change them to 1.
  for (int i = 0; i < n; i++){
    if (matrix[i][j] != 0){
      matrix[i][j] = -1;
    }
  }
}
vector<vector<int>> set_matrix_zero_BR(vector<vector<int>> &matrix, int n, int m)
{
  // this is the method to traverse through the 2d array.
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (matrix[i][j] == 0){
        markRow(matrix, i, n, m);    // we marked the row here
        markColumn(matrix, j, n, m); // we marked the column here
      }
    }
  }

  // now we set -1 to 0 to get our answer......
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (matrix[i][j] == -1){
        matrix[i][j] = 0;
      }
    }
  }
  return matrix;
}
int main(){
  vector<vector<int>> matrix = {
  {1,1,1,1}, // matrix[0]
  {1,0,1,1}, // matrix[1]
  {1,1,0,1}, // matrix[2]
  {0,0,1,1}  // matrix[3]
  };
  int n=matrix.size();
  int m = matrix[0].size();  
  vector<vector<int>> ans = set_matrix_zero_BR(matrix,n,m);
  // for printing like 2-d matrix..
  cout <<"the final matrix is :"<<endl;
  for(auto it:ans){
    for(auto il: it){
        cout<<il<<" ";
    }
    cout<<endl;
  }
  
}
