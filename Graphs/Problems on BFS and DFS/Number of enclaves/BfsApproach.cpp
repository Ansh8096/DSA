#include<bits/stdc++.h>
using namespace std;
void traverse_bfs(vector<vector<int>>& a, vector<vector<int>>& vis, queue<pair<int,int>>& q, int delR[], int delC[]){
    int n = a.size();
    int m = a[0].size();
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nRow = delR[i] + r;
            int nCol = delC[i] + c;
            if(nRow >= 0 && nRow < n && nCol >=0 && nCol < m && a[nRow][nCol] == 1 && !vis[nRow][nCol]){
                vis[nRow][nCol] = 1;
                q.push({nRow,nCol});
            }
        }
    }                
}
int numberOfEnclaves_OP(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int,int>>queue;
    for(int j=0;j<m;j++){
        if(a[0][j] == 1 && !vis[0][j]){
            vis[0][j] = 1;
            queue.push({0,j});
        }
        if(a[n-1][j] == 1 && !vis[n-1][j]){
            vis[n-1][j] = 1;
            queue.push({n-1,j});
        }
    }
    for(int i=0;i<n;i++){
        if(a[i][0] == 1 && !vis[i][0]){
            vis[i][0] = 1;
            queue.push({i,0});
        }
        if(a[i][m-1] == 1 && !vis[i][m-1]){
            vis[i][m-1] = 1;
            queue.push({i,m-1});
        }
    }
    int delR[] = {-1,1,0,0};
    int delC[] = {0,0,1,-1};
    traverse_bfs(a,vis,queue,delR,delC);
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 1 && !vis[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {

    // Grid:
    //
    // 0 0 0 0
    // 1 0 1 0
    // 0 1 1 0
    // 0 0 0 0
    //
    // The land cells:
    // (1,2), (2,1), (2,2)
    // are completely surrounded.
    //
    // Expected Answer = 3

    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    cout << "Input Grid:\n";
    for (auto &row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    cout << "\nNumber of Enclaves = "
        << numberOfEnclaves_OP(grid) << endl;

    return 0;
}
