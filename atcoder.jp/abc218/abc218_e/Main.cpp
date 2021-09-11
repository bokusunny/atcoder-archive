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
  using T = tuple<long long, int, int>;
  vector<T> E(M);
  long long total = 0;
  for (int i = 0; i < M; i++) {
    cin >> get<1>(E[i]) >> get<2>(E[i]) >> get<0>(E[i]);
    total += get<0>(E[i]);
  }
  sort(E.begin(), E.end());

  UnionFind uf(N);
  for (int i = 0; i < M; i++) {
    auto [cost, a, b] = E[i];
    if (!uf.same(a - 1, b - 1)) {
      uf.unite(a - 1, b - 1);
      total -= cost;
    } else {
      if (cost < 0) total -= cost;
    }
  }

  cout << total << endl;
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
