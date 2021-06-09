#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
void tree_bfs(Graph &graph, int s) {
  int n = (int)graph.size();
  const int INF = 1000000001;
  vector<int> dist(n, INF);
  vector<int> ans(n, -1);
  queue<int> q;
  q.push(s);
  dist.at(s) = 0;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto nxt : graph.at(cur)) {
      if (dist.at(nxt) != INF) continue;

      dist.at(nxt) = dist.at(cur) + 1;
      ans.at(nxt) = cur + 1;
      q.push(nxt);
    }
  }

  for (int i = 1; i < n; i++) {
    if (ans.at(i) == -1) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
  for (int i = 1; i < n; i++) {
    cout << ans.at(i) << endl;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  Graph graph(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }

  tree_bfs(graph, 0);

  return 0;
}
