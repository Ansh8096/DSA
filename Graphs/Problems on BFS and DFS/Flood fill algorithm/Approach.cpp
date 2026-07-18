#include<bits/stdc++.h>
using namespace std;
void helper_dfs(vector<vector<int>> &a, vector<vector<bool>>& vis, int row, int col, int n, int m, int color, int inColor){
    vis[row][col] = true;
    a[row][col] = color;
    
    vector<int> delRow = {-1,1,0,0};
    vector<int> delCol = {0,0,1,-1};
    for(int i=0;i<=3;i++){
        int nRow = row + delRow[i];
        int nCol = col +  delCol[i];
        if(nCol >= 0 && nCol < m && nRow >= 0 && nRow < n){
            if(!vis[nRow][nCol] && a[nRow][nCol] == inColor){
                helper_dfs(a,vis,nRow,nCol,n,m,color,inColor);
            }
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& a, int sr, int sc, int color) {
    int n = a.size(), m = a[0].size();
    vector<vector<bool>> vis (n, vector<bool>(m, false));
    int inColor = a[sr][sc];
    if(inColor == color) return a;
    helper_dfs(a,vis,sr,sc,n,m,color,inColor);
    return a;
}
int main() {

    // Original Image
    //
    // 1 1 1
    // 1 1 0
    // 1 0 1
    //
    // Start: (1,1)
    // New Color: 2
    //
    // Expected Output:
    //
    // 2 2 2
    // 2 2 0
    // 2 0 1

    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1;
    int sc = 1;
    int color = 2;

    cout << "Original Image:\n";

    for(auto &row : image){
        for(int pixel : row){
            cout << pixel << " ";
        }
        cout << endl;
    }

    vector<vector<int>> ans = floodFill(image, sr, sc, color);

    cout << "\nImage After Flood Fill:-\n";

    for(auto &row : ans){
        for(int pixel : row){
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
