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

int main() {
  int n, m;
  cin >> n >> m;

  auto tree = UnionFind(n);

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    tree.unite(a, b);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int size = tree.size(i);
    if (size > ans) ans = size;
  }

  cout << ans << endl;

  return 0;
}
