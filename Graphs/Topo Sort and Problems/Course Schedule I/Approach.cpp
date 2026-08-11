#include <bits/stdc++.h>
using namespace std;
bool canFinishBfs(
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

    int cnt = 0;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        cnt++;

        for (int next : adj[node]) {

            indegree[next]--;

            if (indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // If we processed every course,
    // there is no cycle.
    return cnt == V;
}
bool courseSchedule1(
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

    return canFinishBfs(
        numCourses,
        adj,
        indegree
    );
}

int main() {

    // Example 1:
    //
    // 0 -> 1
    //
    // Can finish all courses.

    int numCourses1 = 2;

    vector<vector<int>> prerequisites1 = {
        {1, 0}
    };

    cout << "Example 1: ";

    if (courseSchedule1(numCourses1, prerequisites1))
        cout << "true\n";
    else
        cout << "false\n";


    // Example 2:
    //
    // 0 -> 1
    // ↑    |
    // |____|
    //
    // Cycle exists.

    int numCourses2 = 2;

    vector<vector<int>> prerequisites2 = {
        {1, 0},
        {0, 1}
    };

    cout << "Example 2: ";

    if (courseSchedule1(numCourses2, prerequisites2))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
