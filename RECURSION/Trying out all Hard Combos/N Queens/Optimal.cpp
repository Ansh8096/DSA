#include <bits/stdc++.h>
using namespace std;

// N-queens optimal solution:-
void solve_OP(int col, vector<string> &board, vector<vector<string>> &ans, int n, vector<int> &leftSide, vector<int> &upperDiagonal, vector<int> &lowerDiagonal)
{
  // Base Case:-->
  if (col == n)
  {
    ans.push_back(board);
    return;
  }

  for (int row = 0; row < n; row++)
  {
    // It is safe to place Queen here...
    if (leftSide[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[(n - 1) + col - row] == 0)
    {
      board[row][col] = 'Q'; // placing Queen...
      // updating the occurence of Queen in the hashArrays...
      leftSide[row] = 1;
      lowerDiagonal[row + col] = 1;
      upperDiagonal[(n - 1) + col - row] = 1;
      solve_OP(col + 1, board, ans, n, leftSide, upperDiagonal, lowerDiagonal);
      // This is necessary steps for backTracking ,it ensures to get all the combinations...
      board[row][col] = '.';
      leftSide[row] = 0;
      lowerDiagonal[row + col] = 0;
      upperDiagonal[(n - 1) + col - row] = 0;
    }
  }
}
vector<vector<string>> solveForN_queens_OP(int n){
  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, '.');

  for (int i = 0; i < n; i++)
  {
    board[i] = s;
  }

  vector<int> leftSide(n, 0), upperDiagonal(((2 * n) - 1), 0), lowerDiagonal(((2 * n) - 1), 0);
  solve_OP(0, board, ans, n, leftSide, upperDiagonal, lowerDiagonal);
  return ans;
}
int main(){
  int n = 5;
  vector<vector<string>> ans = solveForN_queens_OP(n);
  // for printing:-
  for (auto itr : ans)
  {
    for (auto itt : itr)
    {
      cout << itt;
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
