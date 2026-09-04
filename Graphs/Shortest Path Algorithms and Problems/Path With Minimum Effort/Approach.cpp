#include<bits/stdc++.h>
using namespace std;
int minimumEffortPath(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();

    vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
    dis[0][0] = 0;

    priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});

    int delR[4] = {-1, 0, 1, 0};
    int delC[4] = {0, 1, 0, -1};
    while (!pq.empty()){
        
        int currDiff = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;

        pq.pop();

        for(int i=0; i<4; i++){
            int nR = delR[i] + r;
            int nC = delC[i] + c;

            if(nR >= 0 && nR < n && nC >= 0 && nC < m){
                int newDiff = max(abs(heights[r][c] - heights[nR][nC]), currDiff);
                if(newDiff < dis[nR][nC]){
                    dis[nR][nC] = newDiff;
                    pq.push({newDiff, {nR, nC}});
                }
            }
        }
    }
    
    return (dis[n-1][m-1] == INT_MAX) ? -1: dis[n-1][m-1];
}
int main() {

    vector<vector<int>> heights = {
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    int ans = minimumEffortPath(heights);

    cout << "Minimum effort path: " << ans << endl;

    return 0;
}
