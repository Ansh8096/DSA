#include<bits/stdc++.h>
using namespace std;
bool dfsCheck(int st, vector<int> adj[], int vis[], int pathVis[]){
    vis[st] = 1;
    pathVis[st] = 1;

    for(auto itt: adj[st]){
        if(!vis[itt]){
            if(dfsCheck(itt,adj,vis,pathVis)) return true;
        }
        else if (pathVis[itt]) return true;
    }
    

    pathVis[st] = 0;
    return false;
}
bool isDirectedGraphCyclic(int V,vector<vector<int>> &edges) {
    vector<int> adj[V];
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    int vis[V] = {0};
    int pathVis[V] = {0};

    for (int i = 0; i < V; i++)
    {   
        if(!vis[i]){
            if (dfsCheck(i,adj,vis,pathVis)) return true;
        }
    }
    
    return false;
}
int main() {

    // Example 1: Graph with a cycle
    //
    // 0 → 1 → 2
    //     ↑   ↓
    //     └── 3
    //
    // Cycle: 1 → 2 → 3 → 1

    int V1 = 4;

    vector<vector<int>> edges1 = {
        {0,1},
        {1,2},
        {2,3},
        {3,1}
    };

    if (isDirectedGraphCyclic(V1, edges1))
        cout << "Graph 1 contains a cycle.\n";
    else
        cout << "Graph 1 does not contain a cycle.\n";


    cout << "\n--------------------------\n\n";


    // Example 2: Directed Acyclic Graph (DAG):
    //
    // 0 → 1 → 3
    //  \
    //   → 2 → 3

    int V2 = 4;

    vector<vector<int>> edges2 = {
        {0,1},
        {0,2},
        {1,3},
        {2,3}
    };

    if (isDirectedGraphCyclic(V2, edges2))
        cout << "Graph 2 contains a cycle.\n";
    else
        cout << "Graph 2 does not contain a cycle.\n";

    return 0;
}
