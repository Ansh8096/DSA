#include<bits/stdc++.h>
using namespace std;
bool traverseGraphBfs(int start, vector<vector<int>>& adj, vector<int>& color){
    queue<int> q;
    color[start] = 0;
    q.push(start);

    while (!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }
            else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);

    for(int i=0;i<n;i++){
        if(color[i] == -1){
            int res = traverseGraphBfs(i,adj,color);
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

    if (isBipartite(adj))
        cout << "Graph is Bipartite\n";
    else
        cout << "Graph is NOT Bipartite\n";

    return 0;
}
