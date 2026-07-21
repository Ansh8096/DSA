#include<bits/stdc++.h>
using namespace std;
int orangesRotting_OP(vector<vector<int>>& a) {
    queue<pair<pair<int,int>, int>> q;
    int n = a.size(), m = a[0].size();
    vector<vector<int>> vis(n, vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 2){
                q.push({{i,j} , 0});
                vis[i][j] = 2;
            }
        }
    }

    vector<int> delR = {-1,1,0,0};
    vector<int> delC = {0,0,1,-1};
    int maxii = 0;
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        maxii = max(cnt,maxii);
        for(int i=0;i<4;i++){
            int nRow = delR[i] + r;
            int nCol = delC[i] + c;
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && a[nRow][nCol] == 1 && vis[nRow][nCol] != 2){
                vis[nRow][nCol] = 2;
                q.push({{nRow, nCol} , cnt + 1});
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 1 && vis[i][j] != 2){
                return -1;
            }
        }
    }

    return maxii;
}
int main() {
  
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    cout << "Original Grid:\n";

    for (auto &row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    cout << "\nMinimum Time = "
        << orangesRotting_OP(grid) << endl;

    return 0;
}
