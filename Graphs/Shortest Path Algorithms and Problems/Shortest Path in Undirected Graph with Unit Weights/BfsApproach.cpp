#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPathInUnweightedGraph(int V, int E, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);

    for(int i=0;i<E;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(V, INT_MAX);
    
    queue<pair<int,int>> q;
    dist[0] = 0;
    q.push({0,0});

    while (!q.empty()){
        int node = q.front().first;
        int currDist = q.front().second;
        q.pop();

        for(auto itt: adj[node]){
            if(currDist+1 < dist[itt]){
                dist[itt] = currDist+1;
                q.push({itt,currDist+1});
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
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3},
        {3, 4},
        {4, 5},
        {2, 5}
    };

    vector<int> dist = shortestPathInUnweightedGraph(V, E, edges);

    cout << "Shortest distances from node 0:\n";

    for (int i = 0; i < V; i++) {
        cout << "0 -> " << i << " = " << dist[i] << "\n";
    }

    return 0;
}
