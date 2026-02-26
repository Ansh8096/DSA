#include <bits/stdc++.h>
using namespace std;

// N-queens BruteForce solution:-
bool isSafe(int col, int row, vector<string> &board, int n)
{
  // since we haven't put queen on the right side yet,so we left with only three directions to check only...

  // storing the org values...
  int dupRow = row;
  int dupCol = col;

  // upward left diagonal direction...
  while (row >= 0 && col >= 0)
  {
    if (board[row][col] == 'Q')
      return false;
    row--;
    col--;
  }

  col = dupCol;
  row = dupRow;
  // left direction...
  while (col >= 0)
  {
    if (board[row][col] == 'Q')
      return false;
    col--;
  }

  col = dupCol;
  row = dupRow;
  // downward left diagonal direction...
  while (row < n && col >= 0)
  {
    if (board[row][col] == 'Q')
      return false;
    row++;
    col--;
  }

  return true;
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
{
  // base case:-->
  if (col == n)
  {
    ans.push_back(board);
    return;
  }

  // checking where we can place the queen in the col...
  for (int row = 0; row < n; row++)
  {
    if (isSafe(col, row, board, n) == true)
    {
      board[row][col] = 'Q';
      solve(col + 1, board, ans, n);
      board[row][col] = '.'; // for backTracking , ensures we get all our combinations...
    }
  }
}
vector<vector<string>> solveForN_queens(int n)
{
  vector<vector<string>> ans;
  vector<string> board(n);
  string s(n, '.');

  for (int i = 0; i < n; i++)
  {
    board[i] = s;
  }

  solve(0, board, ans, n);
  return ans;
}
int main(){
  int n = 5;
  vector<vector<string>> ans = solveForN_queens(n);
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
