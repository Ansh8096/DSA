#include <bits/stdc++.h>
using namespace std;

// M-coloring Solution:-
bool isSafe(int node, int n, int color[], bool graph[101][101], int col)
{
  for (int k = 0; k < n; k++)
  {
    if (k != node && graph[k][node] == 1 && color[k] == col) return false;
  }
  return true;
}
bool colorNodes(int node, int color[], int m, int n, bool graph[101][101])
{
  if (node == n) return true;

  for (int i = 1; i <= m; i++)
  {
    if (isSafe(node, n, color, graph, i))
    {
      color[node] = i;
      if (colorNodes(node + 1, color, m, n, graph)) return true;
      color[node] = 0; // for backTracking...
    }
  }
  return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
  int color[n] = {0};
  if (colorNodes(0, color, m, n, graph) == true) return true;
  return false;
}

int main(){
  int N = 4;
  int m = 2;
  bool graph[101][101];
  memset(graph, false, sizeof graph);

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  cout << graphColoring(graph, m, N);
  return 0;
}
