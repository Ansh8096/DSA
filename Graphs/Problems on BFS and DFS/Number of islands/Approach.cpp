#include<bits/stdc++.h>
using namespace std;
void bfs(int row, int col, int n, int m, vector<vector<char>>& grid, vector<vector<bool>> &vis){
    queue<pair<int,int>> q;
    q.push({row,col});
    vis[row][col] = true;
    vector<int> delRows = {-1, 0, 1, 0}; 
    vector<int> delCols = {0, 1, 0, -1}; 
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i <= 3; i++){
            int nRow = delRows[i] + row;
            int nCol = delCols[i] + col;
            if(nRow < n && nRow >=0 && nCol < m && nCol >= 0){
                if(grid[nRow][nCol] == '1' && !vis[nRow][nCol]){
                    vis[nRow][nCol] = true;
                    q.push({nRow, nCol});
                }
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int cnt =0;
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '1' && !vis[i][j]){
                cnt++;
                bfs(i,j,n,m,grid,vis);
            }
        }
    }
    return cnt;
}
int main() {

    // Grid:
    //
    // 1 1 0 0 0
    // 1 1 0 0 0
    // 0 0 1 0 0
    // 0 0 0 1 1
    //
    // Since your BFS considers all 8 directions,
    // the answer will be 3.

    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Grid:\n";

    for (auto &row : grid) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    cout << "\nNumber of Islands = " << numIslands(grid) << endl;

    return 0;
}
