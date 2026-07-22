#include<bits/stdc++.h>
using namespace std;
bool detect_bsf(int src, vector<int> adj[],vector<bool>& vis){
    queue<pair<int,int>>q;
    q.push({src,-1});
    vis[src] = true;

    while (!q.empty()){
        int curr = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjNode : adj[curr]){
            if(!vis[adjNode]){
                vis[adjNode] = true;
                q.push({adjNode,curr});
            }
            else if (parent != adjNode){
                return true;
            }
        }
    }
    return false;
}
bool isCycle1(int V, vector<vector<int>>& edges) {
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
            if(detect_bsf(i,adj,vis) == true) return true;
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

    if (isCycle1(V, edges))
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0;
}
