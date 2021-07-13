#include <bits/stdc++.h>
using namespace std;

set<int> points;

void dfs(int src, vector<int> &dis, vector<int> &low, int timer,
         vector<int> adj[], int parent) {
  low[src] = dis[src] = timer++;
  int children = 0;
  for (int child : adj[src]) {
    if (child == parent) continue;
    if (low[child] == -1) {
      children++;
      dfs(child, dis, low, timer, adj, src);
      low[src] = min(low[src], low[child]);
      if (low[child] >= dis[src] && parent != -1) {
        points.insert(src);
      }
    } else {
      low[src] = min(low[src], dis[child]);
    }
  }
  if (children > 1 && parent == -1) {
    points.insert(src);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj[n];
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> dis(n, -1), low(n, -1);
  int timer = 0;
  for (int i = 0; i < n; i++) {
    if (low[i] == -1) {
      dfs(i, dis, low, timer, adj, -1);
    }
  }
  for (int x : points) {
    cout << x << " ";
  }
}
