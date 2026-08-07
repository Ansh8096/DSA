#include<bits/stdc++.h>
using namespace std;
bool dfsCheck(int st, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check){
    vis[st] = 1;
    pathVis[st] = 1;
    for(auto itt: graph[st]){
        if(!vis[itt]){
            if(dfsCheck(itt,graph,vis,pathVis,check)) return true;
        }
        else if (pathVis[itt]) return true;
    }
    check[st] = 1;
    pathVis[st] = 0;
    return false;
}
vector<int> SafeNodes_dfs(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> vis(n,0);
    vector<int> pathVis(n,0);
    vector<int> check(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfsCheck(i,graph,vis,pathVis,check);
        }
    }
    vector<int> safeNodes;
    for(int i=0;i<n;i++){
        if(check[i]){
            safeNodes.push_back(i);
        }
    } 
    return safeNodes;
}
int main() {

    // Graph:
    //
    // 0 → 1 → 2 → 5
    //     ↓   ↑
    //     3 → 0
    //     |
    //     ↓
    //     4 → 5
    //
    // Safe Nodes = {2,4,5,6}

    vector<vector<int>> graph = {
        {1,2},    // 0
        {2,3},    // 1
        {5},      // 2
        {0},      // 3
        {5},      // 4
        {},       // 5
        {}        // 6
    };

    vector<int> safeNodes = SafeNodes_dfs(graph);

    cout << "Safe Nodes: ";

    for (int node : safeNodes) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}
