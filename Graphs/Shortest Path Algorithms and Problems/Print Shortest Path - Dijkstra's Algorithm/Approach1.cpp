#include <bits/stdc++.h>
using namespace std;
vector<int> nodesOfShortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
    vector<vector<pair<int,int>>> adj(V+1);
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    vector<int> dis(V+1, INT_MAX);
    vector<int> parent(V+1);
    for(int i=1;i<=V;i++) parent[i] = i;

    set<pair<int,int>> st;
    st.insert({0,src});
    dis[src] = 0;

    while (!st.empty()){
        auto first = *(st.begin());
        int d = first.first;
        int node = first.second;
        st.erase(st.begin());

        for(auto itt: adj[node]){
            int wt = itt.second;
            int adjNode = itt.first;

            if(d+wt < dis[adjNode]){
                
                if (dis[adjNode] != INT_MAX) {
                    st.erase({dis[adjNode], adjNode});
                }
    
                dis[adjNode] = d+wt;
                parent[adjNode] = node;
                st.insert({dis[adjNode], adjNode});
            }
        }
    }
    
    if(dis[dest] == INT_MAX) return {-1};
    
    int node = dest;
    vector<int> ans;
    while(parent[node] != node){
        ans.push_back(node);
        node = parent[node];
    }
    
    ans.push_back(src);
    
    reverse(ans.begin(), ans.end());
    return ans;
    
}
int main() {

    int V = 6;

    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {5, 4, 2},
        {4, 6, 1},
        {5, 6, 5}
    };

    int src = 1;
    int dest = 6;

    vector<int> path = nodesOfShortestPath(V, edges, src, dest);

    if (path.size() == 1 && path[0] == -1) {
        cout << "No path exists." << endl;
    }
    else {
        cout << "Shortest path: ";

        for (int i = 0; i < path.size(); i++) {
            cout << path[i];

            if (i != path.size() - 1)
                cout << " -> ";
        }

        cout << endl;
    }

    return 0;
}
