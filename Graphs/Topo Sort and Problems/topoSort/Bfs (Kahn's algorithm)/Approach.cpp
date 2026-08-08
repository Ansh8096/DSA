#include <bits/stdc++.h>
using namespace std;

void bfsTopologicalSort(
    int V,
    vector<int> adj[],
    vector<int>& indegree,
    vector<int>& ans
) {
    queue<int> q;

    // Push all nodes having indegree 0
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (auto itt : adj[node]) {

            indegree[itt]--;

            if (indegree[itt] == 0) {
                q.push(itt);
            }
        }
    }
}

vector<int> topoSort2(int V, vector<vector<int>>& edges) {

    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        for (int next : adj[node]) {
            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    return ans;
}
int main() {

    // Directed Acyclic Graph (DAG)
    //
    //        5 ------> 0
    //        |
    //        v
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

    vector<int> topo = topoSort2(V, edges);

    cout << "Topological Order:\n";

    for (int node : topo) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}
