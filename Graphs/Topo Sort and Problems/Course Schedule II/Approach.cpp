#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(
    int V,
    vector<vector<int>>& adj,
    vector<int>& indegree
) {
    queue<int> q;

    // Courses with no prerequisites
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> order;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        order.push_back(node);

        for (int next : adj[node]) {

            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // Cycle exists
    if (order.size() != V)
        return {};

    return order;
}
vector<int> courseSchedule2(
    int numCourses,
    vector<vector<int>>& prerequisites
) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto &edge : prerequisites) {

        int course = edge[0];
        int prerequisite = edge[1];

        // prerequisite -> course
        adj[prerequisite].push_back(course);

        indegree[course]++;
    }

    return bfs(numCourses, adj, indegree);
}

int main() {

    // Example:
    //
    // 0 -> 1
    // 0 -> 2
    // 1 -> 3
    // 2 -> 3
    //
    // One valid answer:
    // 0 1 2 3

    int numCourses = 4;

    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> order =
        courseSchedule2(numCourses, prerequisites);

    cout << "Course Order: ";

    for (int course : order) {
        cout << course << " ";
    }

    cout << endl;

    return 0;
}
