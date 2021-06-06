#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
void tree_bfs(Graph &graph, int s, int &ans) {
  int n = (int)graph.size();
  const int INF = 1000000001;
  vector<int> dist(n, INF);
  queue<int> q;
  q.push(s);
  dist.at(s) = 0;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    // Do something

    for (auto nxt : graph.at(cur)) {
      if (dist.at(nxt) != INF) continue;

      ans++;
      dist.at(nxt) = dist.at(cur) + 1;
      q.push(nxt);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> graph(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    graph.at(a).push_back(b);
  }

  int ans = n;
  for (int i = 0; i < n; i++) {
    tree_bfs(graph, i, ans);
  }

  cout << ans << endl;

  return 0;
}
