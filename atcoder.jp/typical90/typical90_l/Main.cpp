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
  int h, w;
  cin >> h >> w;

  vector<vector<bool>> grid(h, vector<bool>(w, false));
  auto tree = UnionFind(h * w);

  auto calc_number = [&](int r, int c) { return w * r + c; };

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int r, c;
      cin >> r >> c;
      r--, c--;

      grid.at(r).at(c) = true;
      vector<pair<int, int>> grid_moving = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
      for (auto [mv_y, mv_x] : grid_moving) {
        int target_y = r + mv_y, target_x = c + mv_x;
        if (target_y < 0 || target_y == h || target_x < 0 || target_x == w) {
          continue;
        }
        if (grid.at(target_y).at(target_x)) {
          tree.unite(calc_number(r, c), calc_number(target_y, target_x));
        }
      }
    } else {
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      r1--, c1--, r2--, c2--;

      if (!grid.at(r1).at(c1) || !grid.at(r2).at(c2)) {
        cout << "No" << endl;
        continue;
      }

      if (tree.same(calc_number(r1, c1), calc_number(r2, c2))) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }

  return 0;
}
