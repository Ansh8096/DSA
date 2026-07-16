#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>&vis, vector<int> adj[]){
    vis[node] = 1;
    for(auto itt: adj[node]){
        if(!vis[itt]){
            dfs(itt, vis, adj);
        }
    }
}
int findProvinces(vector<vector<int>>& adjMatrix) {
    int n = adjMatrix.size(); 
    vector<int> adj[n+1];

    // converting the adjacency matrix to adjacency list...
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adjMatrix[i][j]){
                adj[i+1].push_back(j+1);
                adj[j+1].push_back(i+1);
            }
        }
    }
    vector<int> vis(n+1);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,vis,adj);
        }
    }
    return cnt;
}
int main() {

    // Graph:
    //
    //      1 ----- 2
    //
    //      3
    //
    // Number of Provinces = 2

    vector<vector<int>> adjMatrix = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    cout << "Adjacency Matrix:\n";

    for (auto &row : adjMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout << "\nNumber of Provinces = "
        << findProvinces(adjMatrix) << endl;

    return 0;
}
