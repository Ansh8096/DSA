#include <bits/stdc++.h>
using namespace std;
int countPaths(int n, vector<vector<int>> &roads){

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < roads.size(); i++)
    {
        adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
        greater<pair<long long, int>>>pq;

    vector<long long> dis(n, LLONG_MAX);
    vector<int> ways(n, 0);

    pq.push({0, 0});
    dis[0] = 0;
    ways[0] = 1;

    int mod = (int)1e9 + 7;
    while (!pq.empty())
    {
        long long d = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        for (auto itt : adj[node])
        {
            int wt = itt.second;
            int adjNode = itt.first;

            if (wt + d < dis[adjNode])
            {
                dis[adjNode] = wt + d;
                ways[adjNode] = ways[node];
                pq.push({dis[adjNode], adjNode});
            }

            else if (wt + d == dis[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;
}
int main()
{

    int n = 4;

    vector<vector<int>> roads = {
        {0, 1, 1},
        {1, 3, 1},
        {0, 2, 1},
        {2, 3, 1},
        {0, 3, 5}};

    int ans = countPaths(n, roads);

    cout << "Number of shortest paths:- " << ans << endl;

    return 0;
}
