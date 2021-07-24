#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> par_table;
  vector<int> size_table;
  int node_num;

  UnionFind(int n) : par_table(n, 0), size_table(n, 1), node_num(n) {
    for (int i = 0; i < n; i++) par_table.at(i) = i;
  }

  int find(int x) {
    if (par_table.at(x) == x) return x;
    return par_table.at(x) = find(par_table.at(x));
  }

  void unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    if (size_table.at(rx) < size_table.at(ry)) swap(rx, ry);
    size_table.at(rx) += size_table.at(ry);
    par_table.at(ry) = rx;
  }

  bool same(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    return rx == ry;
  }

  int size(int x) { return size_table.at(find(x)); }
};

using Graph = vector<vector<int>>;
Graph G;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  UnionFind uf(N);
  G.resize(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
    uf.unite(a, b);
  }

  vector<vector<int>> B(N);
  for (int i = 0; i < K; i++) {
    int c, d;
    cin >> c >> d;
    c--, d--;
    B[c].push_back(d);
    B[d].push_back(c);
  }

  for (int i = 0; i < N; i++) {
    auto ans = uf.size(i) - 1;
    for (auto b : B[i]) {
      if (uf.same(i, b)) ans--;
    }
    ans -= (int)G[i].size();
    if (i) cout << " ";
    cout << ans;
  }
  cout << endl;

  return 0;
}
