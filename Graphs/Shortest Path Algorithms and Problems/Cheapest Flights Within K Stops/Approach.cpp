#include<bits/stdc++.h>
using namespace std;
int findCheapestPriceWithAtmostKStops(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);

    for(int i=0;i<flights.size();i++){
        adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
    }

    vector<int> cost(n, INT_MAX);
    queue<pair<int, pair<int, int>>> q;
    cost[src] = 0;
    q.push({0, {src, 0}});

    while(!q.empty()){
        int stops = q.front().first;
        int node = q.front().second.first;
        int dist = q.front().second.second;
        q.pop();
        for(auto itt: adj[node]){
            int adjNode = itt.first;
            int wt = itt.second;
            if(stops > k ) continue;
            if( dist + wt < cost[adjNode]  && stops <= k){
                cost[adjNode] = dist + wt;
                q.push({stops+1, {adjNode, cost[adjNode]}});
            }
        }
    }

    return (cost[dst] == INT_MAX) ? -1: cost[dst];
}
int main() {

    int n = 4;

    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 2, 500}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    int ans = findCheapestPriceWithAtmostKStops(
        n, flights, src, dst, k
    );

    cout << "Cheapest price: " << ans << endl;

    return 0;
}
