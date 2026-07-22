#include<bits/stdc++.h>
using namespace std;
bool detect_dsf(int curr, int parent, vector<int> adj[],vector<bool>& vis){
    vis[curr] = true;
    for(auto adjNode: adj[curr]){
        if(!vis[adjNode]){
            if(detect_dsf(adjNode,curr,adj,vis)) return true;
        }
        else if (adjNode != parent){
            return true;
        }
    }

    return false;
}
bool isCycle2(int V, vector<vector<int>>& edges) {
    vector<bool> vis(V,false);
    
    // create adjacency list:
    vector<int> adj[V];
    for(int i=0;i<edges.size();i++){
        int v1 = edges[i][0];
        int v2 = edges[i][1];

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }


    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(detect_dsf(i,-1,adj,vis) == true) return true;
        }
    }

    return false;
}
int main() {

    int V = 5;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {3, 4}
    };

    if (isCycle2(V, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
