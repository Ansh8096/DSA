#include <bits/stdc++.h>
using namespace std;
vector<int> safeNodes_bfs(
    int V,
    vector<vector<int>>& edges
) {

    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    // Reverse the graph
    for (auto &edge : edges) {

        int u = edge[0];
        int v = edge[1];

        adj[v].push_back(u);
        indegree[u]++;
    }

    queue<int> q;

    // Terminal nodes
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> safeNodes;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        safeNodes.push_back(node);

        for (int next : adj[node]) {

            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
}
int main() {

    int V = 7;

    // Directed graph:
    //
    // 0 → 1
    // 1 → 2
    // 2 → 3
    // 3 → 4
    // 4 → 5
    // 5 → 3   (cycle)
    // 6 → 5
    //
    // Safe node: 0? No, because it eventually reaches the cycle.
    // Safe nodes: none except possibly isolated/terminal nodes.

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 3},
        {6, 5}
    };

    vector<int> safeNodes = safeNodes_bfs(V, edges);

    cout << "Safe Nodes: ";

    for (int node : safeNodes) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}
