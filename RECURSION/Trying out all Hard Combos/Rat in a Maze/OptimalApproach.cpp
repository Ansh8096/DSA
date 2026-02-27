#include <bits/stdc++.h>
using namespace std;

// Rat-Maze optimal solution:-
void routes_OP(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis, vector<int> &di, vector<int> &dj){
  if (i == n - 1 && j == n - 1)
  {
    ans.push_back(move);
    return;
  }

  // checking for all four directions via loop...
  string dir = "DLRU";
  for (int idx = 0; idx < 4; idx++)
  {
    int nextI = i + di[idx];
    int nextJ = j + dj[idx];
    if (nextI >= 0 && nextJ >= 0 && nextI < n && nextJ < n && !vis[nextI][nextJ] && a[nextI][nextJ] == 1)
    {
      vis[i][j] = 1;
      routes_OP(nextI, nextJ, a, n, ans, move + dir[idx], vis, di, dj);
      vis[i][j] = 0;
    }
  }
}
vector<string> findPathsForRatInMaze_OP(vector<vector<int>> &m, int n){
  vector<string> ans;
  vector<vector<int>> vis(n, vector<int>(n, 0)); // it will look like this for n=4:--> {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}
  vector<int> di = {1, 0, 0, -1};
  vector<int> dj = {0, -1, 1, 0};
  if (m[0][0] == 1) routes_OP(0, 0, m, n, ans, "", vis, di, dj);
  return ans;
}
int main(){
  vector<vector<int>> m = {{1,0,0,0} , {1,1,0,1} , {1,1,0,0} , {0,1,1,1} };
  int n = m.size();
  vector<string> ans  = findPathsForRatInMaze_OP(m,n);
  // For Printing:-
  for(auto itr : ans){
      cout<<itr<<" ";
  }

  return 0;
}
