#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
 private:
  vector<int> par_table;
  vector<int> size_table;
  int _n;

 public:
  UnionFind(int n) : par_table(n, 0), size_table(n, 1), _n(n) {
    for (int i = 0; i < n; i++) par_table.at(i) = i;
  }

  int find(int x) {
    assert(0 <= x && x < _n);

    if (par_table.at(x) == x) return x;
    return par_table.at(x) = find(par_table.at(x));
  }

  void unite(int x, int y) {
    assert(0 <= x && x < _n);
    assert(0 <= y && y < _n);

    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return;
    if (size_table.at(rx) < size_table.at(ry)) swap(rx, ry);
    size_table.at(rx) += size_table.at(ry);
    par_table.at(ry) = rx;
  }

  bool same(int x, int y) {
    assert(0 <= x && x < _n);
    assert(0 <= y && y < _n);

    int rx = find(x);
    int ry = find(y);
    return rx == ry;
  }

  int size(int x) {
    assert(0 <= x && x < _n);

    return size_table.at(find(x));
  }

  vector<vector<int>> groups() {
    vector<vector<int>> res(_n);
    for (int i = 0; i < _n; i++) res[find(i)].push_back(i);

    auto itr = remove_if(res.begin(), res.end(), [](vector<int> v) { return v.empty(); });
    res.erase(itr, res.end());

    return res;
  }
};

void solve() {
  int N, M;
  cin >> N >> M;
  UnionFind uf(N + 1);

  vector<tuple<long long, int, int>> E(M);
  for (int i = 0; i < M; i++) {
    cin >> get<0>(E[i]) >> get<1>(E[i]) >> get<2>(E[i]);
  }
  sort(E.begin(), E.end());
  long long ans = 0;
  for (auto [C, L, R] : E) {
    if (uf.same(L - 1, R)) continue;
    ans += C;
    uf.unite(L - 1, R);
  }

  if (uf.size(0) != N + 1) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
}

int main() {
  solve();

  return 0;
}
