#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPathByDijkstra_Pq(int V, vector<vector<int>> &edges, int src) {
    // defining the min heap...
    
    vector<vector<pair<int,int>>> adj(V);
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,src});
    vector<int> distance(V, INT_MAX);
    distance[src] = 0;

    while (!pq.empty()){
        
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto itt: adj[node]){

            if(itt.second + d < distance[itt.first]){
                distance[itt.first] = itt.second+d;
                pq.push({distance[itt.first], itt.first});
            }
        }

    }
    
    return distance;
}
int main() {

    int V = 6;

    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 8},
        {2, 4, 3},
        {3, 4, 2},
        {3, 5, 6},
        {4, 5, 1}
    };

    int src = 0;

    vector<int> distance = shortestPathByDijkstra_Pq(V, edges, src);

    cout << "Shortest distances from source " << src << ":\n";

    for (int i = 0; i < V; i++) {
        cout << src << " -> " << i << " = ";

        if (distance[i] == INT_MAX)
            cout << -1;
        else
            cout << distance[i];

        cout << endl;
    }

    return 0;
}
