#include<bits/stdc++.h>
using namespace std;
void traverse_dfs(vector<vector<char>>& a, vector<vector<int>>& vis, int r, int c, int delR[], int delC[]){
    int n = a.size(), m = a[0].size();
    vis[r][c] = 1;
    for(int i=0;i<4;i++){
        int nRow = r+delR[i];
        int nCol = c+delC[i];
        if(nRow >= 0 && nRow < n && nCol >=0 && nCol < m && a[nRow][nCol] == 'O' && !vis[nRow][nCol])
        {
            traverse_dfs(a,vis,nRow,nCol,delR, delC);
        }
    }
}
void surroundedRegions_OP(vector<vector<char>>& a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> vis(n, vector<int> (m, 0));
    int delR[] = {-1,1,0,0};
    int delC[] = {0,0,1,-1};
    for(int j=0;j<m;j++){
        if(a[0][j] == 'O' && !vis[0][j]){
            traverse_dfs(a,vis,0,j,delR, delC);
        }
        if(a[n-1][j] == 'O' && !vis[n-1][j]){
            traverse_dfs(a,vis,n-1,j,delR, delC);
        }
    }
    for(int i=0;i<n;i++){
        if(a[i][0] == 'O' && !vis[i][0]){
            traverse_dfs(a,vis,i,0,delR, delC);
        }
        if(a[i][m-1] == 'O' && !vis[i][m-1]){
            traverse_dfs(a,vis,i,m-1,delR, delC);
        }
    }
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(a[i][j] == 'O' && !vis[i][j]){
                a[i][j] = 'X';
            }
        }
    }
}
int main() {

    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    cout << "Original Board:\n";
    for (auto &row : board) {
        for (char ch : row)
            cout << ch << " ";
        cout << endl;
    }

    surroundedRegions_OP(board);

    cout << "\nAfter Processing:\n";
    for (auto &row : board) {
        for (char ch : row)
            cout << ch << " ";
        cout << endl;
    }

    return 0;
}
