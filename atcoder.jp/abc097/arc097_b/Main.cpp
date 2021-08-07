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
    for (int i = 0; i < _n; i++) {
      res[find(i)].push_back(i);
    }

    auto itr = remove_if(res.begin(), res.end(), [](vector<int> v) { return v.empty(); });
    res.erase(itr, res.end());

    return res;
  }
};

int N, M;
vector<int> P;

void solve() {
  cin >> N >> M;
  P.resize(N);
  for (int i = 0; i < N; i++) cin >> P[i], P[i]--;
  UnionFind uf(N);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    uf.unite(x, y);
  }

  auto groups = uf.groups();
  int ans = 0;
  for (auto g : groups) {
    set<int> st(g.begin(), g.end());
    for (auto i : g) {
      if (st.count(P[i])) ans++;
    }
  }
  cout << ans << endl;
}

int main() {
  solve();

  return 0;
}
