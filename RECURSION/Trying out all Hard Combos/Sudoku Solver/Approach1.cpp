#include <bits/stdc++.h>
using namespace std;

// Sudoku Solver Problem:-
bool Uvalid(vector<vector<char>> &board, int row, int col, char ch)
{
  for (int i = 0; i < 9; i++)
  {
    // for checking in the entire row...
    if (board[row][i] == ch) return false;

    // for checking in the entire column...
    if (board[i][col] == ch) return false;

    // for checking in 3X3 sub-matrix...
    if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == ch) return false;
  }
  return true;
}
bool solvingSudoku(vector<vector<char>> &board)
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      if (board[i][j] == '.')
      {
        for (char ch = '1'; ch <= '9'; ch++)
        {
          if (Uvalid(board, i, j, ch) == true)
          {
            board[i][j] = ch;
            if (solvingSudoku(board) == true) return true;
            board[i][j] = '.'; // for BackTracking...
          }
        }
        return false;
      }
    }
  }
  return true;
}

int main(){
  vector<vector<char>> board{
    {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
    {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
    {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
    {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
    {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
    {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
    {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
    {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
    {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

  solvingSudoku(board);
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++) cout << board[i][j] << " ";
    cout << "\n";
  }
  return 0;
}
