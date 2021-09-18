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
  vector Pos(6, vector<int>(6));
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      cin >> Pos[i][j];
    }
  }

  int ans = 0;
  for (int msk = 0; msk < (1 << 16); msk++) {
    UnionFind UF(36);
    for (int y = 0; y < 6; y++) {
      for (int x = 0; x < 6; x++) {
        if (y == 0 || x == 0 || y == 5 || x == 5) {
          int cv = y * 6 + x;
          for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
              if (abs(dy) + abs(dx) != 1) continue;
              int ny = y + dy;
              int nx = x + dx;
              if (ny < 0 || 6 <= ny || nx < 0 || 6 <= nx) continue;
              if (ny == 0 || ny == 5 || nx == 0 || nx == 5) {
                int nv = ny * 6 + nx;
                UF.unite(cv, nv);
              }
            }
          }
        }
      }
    }

    bool ok = true;
    for (int j = 0; j < 16; j++) {
      int y = j / 4 + 1;
      int x = j % 4 + 1;
      if (msk >> j & 1) {
        if (Pos[y][x]) {
          ok = false;
          break;
        }
        int cv = y * 6 + x;
        for (int dy = -1; dy <= 1; dy++) {
          for (int dx = -1; dx <= 1; dx++) {
            if (abs(dy) + abs(dx) != 1) continue;
            int ny = y + dy;
            int nx = x + dx;
            if (1 <= ny && ny <= 4 && 1 <= nx && nx <= 4) {
              int jj = (ny - 1) * 4 + (nx - 1);
              assert(0 <= jj && jj < 16);
              if ((msk >> jj & 1) == 0) continue;
            }
            int nv = ny * 6 + nx;
            UF.unite(cv, nv);
          }
        }
      } else {
        int cv = y * 6 + x;
        for (int dy = -1; dy <= 1; dy++) {
          for (int dx = -1; dx <= 1; dx++) {
            if (abs(dy) + abs(dx) != 1) continue;
            int ny = y + dy;
            int nx = x + dx;
            if (1 <= ny && ny <= 4 && 1 <= nx && nx <= 4) {
              int jj = (ny - 1) * 4 + (nx - 1);
              assert(0 <= jj && jj < 16);
              if ((msk >> jj & 1) == 0) {
                int nv = ny * 6 + nx;
                UF.unite(cv, nv);
              }
            }
          }
        }
      }
    }

    if (!ok) continue;
    if ((int)UF.groups().size() == 2) ans++;
  }

  cout << ans << endl;
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
