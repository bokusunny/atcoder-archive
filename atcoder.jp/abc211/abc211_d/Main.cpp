#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

using Graph = vector<vector<int>>;
void bfs(Graph &graph, int s) {
  int n = (int)graph.size();
  const int INF = 1000000001;
  vector<int> dist(n, INF);
  vector<mint> cnt(n);
  queue<int> q;
  q.push(s);
  dist.at(s) = 0;
  cnt[s] = 1;

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    for (auto nxt : graph.at(cur)) {
      if (dist[nxt] == dist[cur] + 1) cnt[nxt] += cnt[cur];
      if (dist.at(nxt) != INF) continue;

      dist.at(nxt) = dist.at(cur) + 1;
      cnt[nxt] += cnt[cur];
      q.push(nxt);
    }
  }

  cout << cnt[n - 1].val() << endl;
}

int main() {
  int N, M;
  cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  bfs(G, 0);

  return 0;
}
