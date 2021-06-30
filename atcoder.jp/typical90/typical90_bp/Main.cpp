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
  int N, Q;
  cin >> N >> Q;

  vector<tuple<int, int, int, long long>> q(Q);
  vector<long long> relational(N, -1);
  vector<tuple<int, int, long long>> tmp;
  for (int i = 0; i < Q; i++) {
    int T, X, Y;
    cin >> T >> X >> Y;
    X--, Y--;
    long long V;
    cin >> V;
    q[i] = {T, X, Y, V};
    if (T == 1) continue;
    tmp.push_back({X, Y, V});
  }
  sort(tmp.begin(), tmp.end());
  for (auto [X, Y, V] : tmp) {
    if (relational[X] == -1) relational[X] = 0;
    relational[Y] = V - relational[X];
  }

  auto tree = UnionFind(N);

  for (auto [T, X, Y, V] : q) {
    if (T == 0) {
      tree.unite(X, Y);
    } else {
      if (!tree.same(X, Y)) {
        cout << "Ambiguous" << endl;
        continue;
      } else {
        if ((Y - X) % 2 == 0) {
          cout << relational[Y] + V - relational[X] << endl;
        } else {
          cout << relational[Y] - (V - relational[X]) << endl;
        }
      }
    }
  }

  return 0;
}
