#include <bits/stdc++.h>
using namespace std;
int shortestPathInBinaryMaze(vector<vector<int>> &mat) {
    
    if (mat[0][0] != 0) return -1;
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    int sRow = 0, sCol = 0, dRow = n - 1, dCol = m - 1;

    if (sRow == dRow && sCol == dCol) return 1;
    queue<pair<int, pair<int, int>>> q;
    dist[sRow][sCol] = 1;
    q.push({1, {sRow, sCol}});
    
    while (!q.empty()) {
        int d = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int nRow = i + r;
                int nCol = j + c;
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                    mat[nRow][nCol] == 0 && d + 1 < dist[nRow][nCol]) {
                    if (nRow == dRow && nCol == dCol)
                        return d + 1;
                    dist[nRow][nCol] = d + 1;
                    q.push({dist[nRow][nCol], {nRow, nCol}});
                }
            }
        }
    }

    return -1;
}
int main() {

    vector<vector<int>> mat = {
        {0, 0, 1, 1, 1},
        {1, 0, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 1, 0}
    };

    int ans = shortestPathInBinaryMaze(mat);

    cout << "Shortest path length: " << ans << endl;

    return 0;
}
