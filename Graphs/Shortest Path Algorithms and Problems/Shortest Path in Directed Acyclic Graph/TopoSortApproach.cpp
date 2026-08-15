#include <bits/stdc++.h>
using namespace std;
void dfs(int st, vector<int>& vis, vector<vector<pair<int,int>>>& adj, stack<int>& stk){
    vis[st] = 1;
    
    for(auto itt: adj[st]){
        if(!vis[itt.first]){
            dfs(itt.first, vis, adj, stk);
        }
    }

    stk.push(st);
}
vector<int> shortestPathInDagByTopoSort(int V, int E, vector<vector<int>>& edges) {
    
    vector<vector<pair<int,int>>> adj(V);
    
    for(int i=0;i<E;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v,wt});
    }

    // topo sort 
    vector<int> vis(V);
    stack<int> stk;

    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,vis,adj,stk);
        }
    }

    vector<int> dist(V, INT_MAX);
    dist[0] = 0;
    while (!stk.empty()){
        int node = stk.top();
        stk.pop();

        int currDist = dist[node];
        
        // only vist the adjacent nodes if they are reachable from the source node...
        if(currDist != INT_MAX){
            for(auto itt : adj[node]){
                int v = itt.first;
                int wt = itt.second;
                
                if(currDist + wt < dist[v]){
                    dist[v] = currDist + wt;
                }
            }
        }
    }
    
    for(int i=0;i<V;i++){
        if(dist[i] == INT_MAX){
            dist[i] = -1;
        }
    }
    
    return dist;
}
int main() {

    int V = 6;
    int E = 7;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {4, 5, 4},
        {2, 3, 6},
        {5, 3, 1}
    };

    vector<int> dist = shortestPathInDagByTopoSort(V, E, edges);

    cout << "Shortest distances from source 0:\n";

    for (int i = 0; i < V; i++) {
        cout << "0 -> " << i << " = " << dist[i] << "\n";
    }

    return 0;
}
