#include<bits/stdc++.h>
using namespace std;
vector<int> bfsTraverse(int n, vector<int>arr[]){
    vector<int>vis (n);
    queue<int> q;
    
    q.push(0);
    vis[0] = 1;
    vector<int> ans;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto itt: arr[node]){
            if(vis[itt] == 0){
                vis[itt] = 1;
                q.push(itt);
            }
        }
    }
    
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

    vector<int> bfs = bfsTraverse(n, adj);

    cout << "BFS Traversal: ";
    for (int node : bfs) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
