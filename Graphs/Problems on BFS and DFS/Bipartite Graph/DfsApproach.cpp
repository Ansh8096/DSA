#include<bits/stdc++.h>
using namespace std;
bool traverseGraphDfs(int st, int color, vector<vector<int>>& adj, vector<int>col){
    col[st] = color;
    for(auto it: adj[st]){
        if(col[it] == -1){
            bool x = traverseGraphDfs(it, !col[st], adj, col);
            if(!x) return false;
        }
        else if (col[it] == col[st]) return false;
    }
    return true;
}
bool isBipartite2(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);

    for(int i=0;i<n;i++){
        if(color[i] == -1){
            int res = traverseGraphDfs(i,0,adj,color);
            if(!res) return res;
        }
    }

    return true;
}
int main() {

    // Graph:
    //
    //      0 ----- 1
    //      |       |
    //      |       |
    //      3 ----- 2
    //
    // Expected Output:
    // Graph is Bipartite

    vector<vector<int>> adj = {
        {1, 3},     // 0
        {0, 2},     // 1
        {1, 3},     // 2
        {0, 2}      // 3
    };

    if (isBipartite2(adj))
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is NOT Bipartite\n";

    return 0;
}
