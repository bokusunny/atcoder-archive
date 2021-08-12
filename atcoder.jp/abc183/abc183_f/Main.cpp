#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
 private:
  vector<int> par_table;
  vector<int> size_table;
  vector<map<int, int>> class_cnt;
  int _n;

 public:
  UnionFind(int n, vector<int> C) : par_table(n, 0), size_table(n, 1), class_cnt(n), _n(n) {
    for (int i = 0; i < n; i++) {
      par_table.at(i) = i;
      class_cnt[i][C[i]]++;
    }
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
    for (auto [key, cnt] : class_cnt[ry]) {
      class_cnt[rx][key] += cnt;
    }
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

  int get_cnt(int x, int y) { return class_cnt[find(x)][y]; }
};

void solve() {
  int N, Q;
  cin >> N >> Q;
  vector<int> C(N);
  for (int i = 0; i < N; i++) cin >> C[i];

  UnionFind uf(N, C);
  while (Q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b;
      cin >> a >> b;
      a--, b--;
      uf.unite(a, b);
    } else {
      int x, y;
      cin >> x >> y;
      x--;
      cout << uf.get_cnt(x, y) << endl;
    }
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
