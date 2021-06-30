#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

const int INF = 1000000001;
auto tree_bfs(Graph &graph, int s) {
  int n = (int)graph.size();
  vector<int> dist(n, INF);
  queue<int> q;
  q.push(s);
  dist.at(s) = 0;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto nxt : graph.at(cur)) {
      if (dist.at(nxt) != INF) continue;

      dist.at(nxt) = dist.at(cur) + 1;
      q.push(nxt);
    }
  }

  return dist;
}

int main() {
  int N, M;
  cin >> N >> M;
  Graph G(N + M);
  for (int i = 0; i < M; i++) {
    int K;
    cin >> K;
    for (int j = 0; j < K; j++) {
      int R;
      cin >> R;
      R--;
      G[N + i].push_back(R);
      G[R].push_back(N + i);
    }
  }

  auto dist = tree_bfs(G, 0);
  for (int i = 0; i < N; i++) {
    if (dist[i] == INF) {
      cout << -1 << endl;
    } else {
      cout << dist[i] / 2 << endl;
    }
  }

  return 0;
}
