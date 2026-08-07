#include<bits/stdc++.h>
using namespace std;
void dfsTopologicalSort(int st, vector<int> adj[], int vis[], stack<int>& stk){
    vis[st] = 1;
    for(auto itt: adj[st]){
        if(!vis[itt]){
            dfsTopologicalSort(itt, adj,vis,stk);
        }
    }
    
    stk.push(st);
}    
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    int n = edges.size();
    vector<int> adj[V];
    for(int i=0;i<n;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    int vis[V] = {0};
    stack<int> stk;
    
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfsTopologicalSort(i,adj,vis,stk);
        }
    }
    
    vector<int> ans;
    while(!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }
    
    return ans;
}
int main() {

    // Directed Acyclic Graph (DAG)
    //
    //        5 ------> 0
    //        |         ^
    //        |         |
    //        v         |
    //        2 ------> 3 -----> 1
    //        ^
    //        |
    //        4
    //
    // One possible Topological Order:
    // 5 4 2 3 1 0

    int V = 6;

    vector<vector<int>> edges = {
        {5, 0},
        {5, 2},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> topo = topoSort(V, edges);

    cout << "Topological Order:\n";

    for (int node : topo) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}
