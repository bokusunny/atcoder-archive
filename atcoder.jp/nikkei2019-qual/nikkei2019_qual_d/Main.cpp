#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;
vector<int> topo_sort(const Graph &G) {
  int n = (int)G.size();
  vector<int> ind(n);
  for (int i = 0; i < n; i++) {
    for (auto e : G[i]) {
      ind[e.to]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (ind[i] == 0) {
      q.push(i);
    }
  }

  vector<int> ans;
  while (!q.empty()) {
    int now = q.front();
    ans.push_back(now);
    q.pop();
    for (auto e : G[now]) {
      ind[e.to]--;
      if (ind[e.to] == 0) {
        q.push(e.to);
      }
    }
  }

  assert((int)ans.size() == n);

  return ans;
}

void solve() {
  int N, M;
  cin >> N >> M;
  Graph G(N);
  vector<vector<int>> Parents(N);
  for (int i = 0; i < N + M - 1; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    G[A].push_back({B});
    Parents[B].push_back(A);
  }

  auto V = topo_sort(G);

  const int INF = 1 << 30;
  vector<int> dist(N, -INF), ans(N, -1);
  dist[V.front()] = 0, ans[V.front()] = 0;
  for (int i = 1; i < N; i++) {
    for (auto p : Parents[V[i]]) {
      if (dist[p] + 1 >= dist[V[i]]) {
        dist[V[i]] = dist[p] + 1;
        ans[V[i]] = p + 1;
      }
    }
  }

  for (auto &a : ans) {
    assert(a != -1);
    cout << a << endl;
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
