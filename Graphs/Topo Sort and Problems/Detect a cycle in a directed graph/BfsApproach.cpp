#include <bits/stdc++.h>
using namespace std;

bool detectCycleBfs(int V, vector<int> adj[], vector<int>& indegree) {

    queue<int> q;

    // Nodes with indegree 0.
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        cnt++;

        for (int itt : adj[node]) {

            indegree[itt]--;

            if (indegree[itt] == 0) {
                q.push(itt);
            }
        }
    }

    // If we couldn't process all vertices,
    // there is a cycle.
    return cnt != V;
}

bool isDirectedGraphCyclic(
    int V,
    vector<vector<int>>& edges
) {

    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    for (auto &edge : edges) {

        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        indegree[v]++;
    }

    // Since detectCycleBfs expects vector<int>[],
    // create the required representation.
    vector<int> adjArray[V];

    for (int i = 0; i < V; i++) {
        adjArray[i] = adj[i];
    }

    return detectCycleBfs(V, adjArray, indegree);
}

int main() {

    // ----------------------------------
    // Example 1: Graph contains a cycle
    //
    // 0 → 1 → 2
    //     ↑   ↓
    //     └── 3
    //
    // Cycle:
    // 1 → 2 → 3 → 1
    // ----------------------------------

    int V1 = 4;

    vector<vector<int>> edges1 = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 1}
    };

    cout << "Graph 1: ";

    if (isDirectedGraphCyclic(V1, edges1))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";


    // ----------------------------------
    // Example 2: DAG
    //
    // 0 → 1 → 3
    //  \       ^
    //   → 2 ───┘
    // ----------------------------------

    int V2 = 4;

    vector<vector<int>> edges2 = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3}
    };

    cout << "Graph 2: ";

    if (isDirectedGraphCyclic(V2, edges2))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";


    return 0;
}
