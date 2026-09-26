#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, 1e8);
    dist[src] = 0;

    for(int i = 1; i < V; i++ ){
        for(auto itt: edges){
            int u = itt[0];
            int v = itt[1];
            int wt = itt[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }

    for(auto itt: edges){
        int u = itt[0];
        int v = itt[1];
        int wt = itt[2];

        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }

    return dist;
}
int main() {

    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2},
        {4, 0, 2},
        {4, 3, 7}
    };

    int src = 0;

    vector<int> dist = bellmanFord(V, edges, src);

    if (dist.size() == 1 && dist[0] == -1) {
        cout << "Negative weight cycle detected." << endl;
    }
    else {
        cout << "Shortest distances from source " << src << ":\n";

        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e8)
                cout << i << " -> INF" << endl;
            else
                cout << i << " -> " << dist[i] << endl;
        }
    }

    return 0;
}
