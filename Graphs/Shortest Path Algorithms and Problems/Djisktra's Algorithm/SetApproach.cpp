#include <bits/stdc++.h>
using namespace std;
vector<int> shortestPathByDijkstra_set(int V, vector<vector<int>>& edges, int src) {
    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    set<pair<int, int>> st;

    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    st.insert({0, src});

    while (!st.empty()) {

        auto it = *st.begin();

        int d = it.first;
        int node = it.second;

        st.erase(it);

        for (auto itt : adj[node]) {

            int adjNode = itt.first;
            int edgeWt = itt.second;

            if (d + edgeWt < dist[adjNode]) {

                if (dist[adjNode] != INT_MAX) {
                    st.erase({dist[adjNode], adjNode});
                }

                dist[adjNode] = d + edgeWt;

                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
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

    vector<int> dist = shortestPathByDijkstra_set(V, edges, src);

    cout << "Shortest distances from source " << src << ":\n";

    for (int i = 0; i < V; i++) {
        cout << src << " -> " << i << " = ";

        if (dist[i] == INT_MAX)
            cout << -1;
        else
            cout << dist[i];

        cout << '\n';
    }

    return 0;
}
