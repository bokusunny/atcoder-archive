#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;

  Edge(const int to) : to(to) {}
};
using Graph = vector<vector<Edge>>;

auto topo_sort = [](Graph &graph) {
  int n = (int)graph.size();
  vector<int> ind(n);
  for (int cv = 0; cv < n; cv++) {
    for (auto [nv] : graph[cv]) {
      ind[nv]++;
    }
  }
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int v = 0; v < n; v++) {
    if (ind[v] == 0) pq.push(v);
  }

  vector<int> res;
  while (!pq.empty()) {
    int cv = pq.top();
    pq.pop();
    res.push_back(cv);
    for (auto [nv] : graph[cv]) {
      ind[nv]--;
      if (ind[nv] == 0) pq.push(nv);
    }
  }

  // NOTE: if the size of res is less than n, the graph has a cycle
  return res;
};

void solve() {
  int N, M;
  cin >> N >> M;
  Graph G(N);
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    G[A].emplace_back(B);
  }

  auto res = topo_sort(G);
  if ((int)res.size() < N) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < N; i++) {
      if (i) cout << " ";
      cout << res[i] + 1;
    }
    cout << endl;
  }
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
