#include <bits/stdc++.h>
using namespace std;

// Rat-Maze BruteForce solution:-
void routes(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis){
  if (i == n - 1 && j == n - 1)
  {
    ans.push_back(move);
    return;
  }

  // For downWord direction...
  if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1)
  {
    vis[i][j] = 1;
    routes(i + 1, j, a, n, ans, move + 'D', vis);
    vis[i][j] = 0;
  }

  // For left direction...
  if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1)
  {
    vis[i][j] = 1;
    routes(i, j - 1, a, n, ans, move + 'L', vis);
    vis[i][j] = 0;
  }

  // For right direction...
  if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1)
  {
    vis[i][j] = 1;
    routes(i, j + 1, a, n, ans, move + 'R', vis);
    vis[i][j] = 0;
  }

  // For upWard direction...
  if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1)
  {
    vis[i][j] = 1;
    routes(i - 1, j, a, n, ans, move + 'U', vis);
    vis[i][j] = 0;
  }
}
vector<string> findPathsForRatInMaze(vector<vector<int>> &m, int n){
  vector<string> ans;
  vector<vector<int>> vis(n, vector<int>(n, 0)); // it will look like this for n=4:--> {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}
  if (m[0][0] == 1) routes(0, 0, m, n, ans, "", vis);
  return ans;
}
int main(){
  vector<vector<int>> m = {{1,0,0,0} , {1,1,0,1} , {1,1,0,0} , {0,1,1,1} };
  int n = m.size();
  vector<string> ans  = findPathsForRatInMaze(m,n);
  // For Printing:-
  for(auto itr : ans){
      cout<<itr<<" ";
  }

  return 0;
}
