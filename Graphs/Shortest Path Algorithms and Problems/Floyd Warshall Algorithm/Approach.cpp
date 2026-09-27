#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>& dist) {

    int n = dist.size();

    for (int via = 0; via < n; via++) {

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (dist[i][via] == 1e8 ||
                    dist[via][j] == 1e8) {
                    continue;
                }

                dist[i][j] = min(
                    dist[i][j],
                    dist[i][via] + dist[via][j]
                );
            }
        }
    }
}

int main() {

    const int INF = 1e8;

    // dist[i][j] = edge weight from i to j
    // INF means there is no direct edge.
    vector<vector<int>> dist = {
        {0,   5,   INF, 10},
        {INF, 0,   3,   INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    cout << "Distance matrix before Floyd-Warshall:\n";

    for (auto& row : dist) {
        for (int x : row) {
            if (x == INF)
                cout << "INF ";
            else
                cout << x << " ";
        }
        cout << '\n';
    }

    floydWarshall(dist);

    cout << "\nDistance matrix after Floyd-Warshall:\n";

    for (auto& row : dist) {
        for (int x : row) {
            if (x == INF)
                cout << "INF ";
            else
                cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}
