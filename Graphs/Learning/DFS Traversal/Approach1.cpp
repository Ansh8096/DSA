#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>&vis, vector<int> adj[], vector<int>& ans){
    vis[node] = 1;
    ans.push_back(node);
    for(auto itt: adj[node]){
        if(!vis[itt]){
            dfs(itt, vis, adj, ans);
        }
    }
}
vector<int> dfsTraverse(int n, vector<int>adj[]){
    vector<int> ans;
    vector<int> vis(n);

    dfs(0, vis, adj, ans);
    return ans;
}
int main() {

    int n = 5;

    // Adjacency List
    vector<int> adj[n];

    // Undirected Graph
    //
    //      0
    //     / \
    //    1   2
    //    |   |
    //    3---4
    //

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[0].push_back(2);
    adj[2].push_back(0);

    adj[1].push_back(3);
    adj[3].push_back(1);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    vector<int> bfs = dfsTraverse(n, adj);

    cout << "DFS Traversal: ";
    for (int node : bfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
