#include<bits/stdc++.h>
using namespace std;
void traverseDfs(vector<vector<char>>& a, vector<vector<int>>& vis, int row, int col, vector<pair<int,int>> & vec, int row0, int col0, int delR[], int delC[]){
    int n = a.size();
    int m = a[0].size();
    
    vis[row][col] = 1;
    vec.push_back({row-row0, col-col0});
    
    for(int i=0;i<4;i++){
        int nRow = delR[i] + row;
        int nCol = delC[i] + col;
        
        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && a[nRow][nCol] == 'L'){
            traverseDfs(a,vis,nRow,nCol,vec,row0,col0, delR, delC);
        }
    }
}
int countDistinctIslands(vector<vector<char>>& a) {
    int n = a.size();
    int m = a[0].size();
    
    
    vector<vector<int>> vis(n, vector<int> (m, 0));
    set<vector<pair<int,int>>> st;
    
    int delR[] = {-1,1,0,0};
    int delC[] = {0,0,1,-1};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 'L' && !vis[i][j]){
                vector<pair<int,int>> vec;
                traverseDfs(a,vis,i,j,vec,i,j, delR, delC);
                st.insert(vec);
            }
        }
    }
    
    return st.size();
}
int main() {

    // Grid:
    //
    // L L W W W
    // L L W W W
    // W W W L L
    // W W W L L
    //
    // Distinct Islands = 1

    vector<vector<char>> grid = {
        {'L','L','W','W','W'},
        {'L','L','W','W','W'},
        {'W','W','W','L','L'},
        {'W','W','W','L','L'}
    };

    cout << "Input Grid:\n";
    for (auto &row : grid) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    cout << "\nNumber of Distinct Islands = "
        << countDistinctIslands(grid) << endl;

    return 0;
}
