#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n, m;
  cin >> h >> w >> n >> m;

  vector<vector<int>> vertical_grid(h, vector<int>(w, 0));
  vector<vector<int>> horizontal_grid(h, vector<int>(w, 0));

  vector<pair<int, int>> query(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    query.at(i) = {a, b};
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    vertical_grid.at(a).at(b) = 2;
    horizontal_grid.at(a).at(b) = 2;
  }

  for (auto [a, b] : query) {
    assert(vertical_grid.at(a).at(b) != 2);
    if (vertical_grid.at(a).at(b) == 0) {
      vertical_grid.at(a).at(b) = 1;
      int i = 1;
      while (a + i <= h - 1 && vertical_grid.at(a + i).at(b) != 2) {
        assert(vertical_grid.at(a + i).at(b) == 0);
        vertical_grid.at(a + i).at(b) = 1;
        i++;
      }
      i = -1;
      while (a + i >= 0 && vertical_grid.at(a + i).at(b) != 2) {
        assert(vertical_grid.at(a + i).at(b) == 0);
        vertical_grid.at(a + i).at(b) = 1;
        i--;
      }
    }
    if (horizontal_grid.at(a).at(b) == 0) {
      horizontal_grid.at(a).at(b) = 1;
      int i = 1;
      while (b + i <= w - 1 && horizontal_grid.at(a).at(b + i) != 2) {
        assert(horizontal_grid.at(a).at(b + i) == 0);
        horizontal_grid.at(a).at(b + i) = 1;
        i++;
      }
      i = -1;
      while (b + i >= 0 && horizontal_grid.at(a).at(b + i) != 2) {
        assert(horizontal_grid.at(a).at(b + i) == 0);
        horizontal_grid.at(a).at(b + i) = 1;
        i--;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (horizontal_grid.at(i).at(j) == 1 || vertical_grid.at(i).at(j) == 1) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
