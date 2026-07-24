#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> findNearest_Bfs(vector<vector<int>>& a, int n, int m, vector<vector<bool>>& vis, vector<vector<int>>& dis){
    queue<pair<pair<int,int> , int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 1){
                vis[i][j] = true;
                q.push({{i,j},0});
            }
        }
    }

    int delR[] = {-1,1,0,0};
    int delC[] = {0,0,1,-1};
    while (!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int level = q.front().second;
        q.pop();

        dis[r][c] = level;
        for(int i=0;i<4;i++){
            int nRow = delR[i]+r;
            int nCol = delC[i]+c;
            
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && a[nRow][nCol] != 1){
                vis[nRow][nCol] = true;
                q.push({{nRow,nCol} , level+1});
            }
        }
    }
    
    return dis;
}
vector<vector<int>> nearest(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis (n, vector<bool>(m, false));
    vector<vector<int>> dis (n, vector<int>(m));

    return findNearest_Bfs(grid, n, m, vis, dis);
}
int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 0, 0}
    };

    cout << "Input Grid:\n";
    for (auto &row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    vector<vector<int>> ans = nearest(grid);

    cout << "\nDistance Matrix:\n";
    for (auto &row : ans) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
