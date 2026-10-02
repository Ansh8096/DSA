#include <bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    int miniCities = INT_MAX;
    int greaterCity = -1;

    for (int i = 0; i < n; i++) {

        vector<int> dis(n, INT_MAX);

        dis[i] = 0;
        pq.push({0, i});

        while (!pq.empty()) {

            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Ignore stale entries
            if (d > dis[node])
                continue;

            for (auto itt : adj[node]) {

                int wt = itt.second;
                int adjNode = itt.first;

                if (d + wt < dis[adjNode]) {
                    dis[adjNode] = d + wt;
                    pq.push({d + wt, adjNode});
                }
            }
        }

        int cnt = 0;

        for (int idx = 0; idx < n; idx++) {
            if (dis[idx] <= distanceThreshold) {
                cnt++;
            }
        }

        if (cnt < miniCities) {
            miniCities = cnt;
            greaterCity = i;
        }
        else if (cnt == miniCities) {
            greaterCity = max(i, greaterCity);
        }
    }

    return greaterCity;
}

int main() {

    int n = 4;

    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };

    int distanceThreshold = 4;

    int ans = findTheCity(n, edges, distanceThreshold);

    cout<<"City with the smallest number of reachable cities: "<< ans << endl;

    return 0;
}
