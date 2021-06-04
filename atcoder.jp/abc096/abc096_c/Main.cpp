#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> grid(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      char c;
      cin >> c;
      grid.at(i).at(j) = c == '#' ? 1 : 0;
    }
  }

  vector<pair<int, int>> moving = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid.at(i).at(j) == 0) continue;
      bool is_ok = false;
      for (auto [mv_y, mv_x] : moving) {
        int target_y = i + mv_y, target_x = j + mv_x;
        if (target_y == h || target_y == -1 || target_x == w ||
            target_x == -1) {
          continue;
        }

        if (grid.at(target_y).at(target_x) == 1) {
          is_ok = true;
          break;
        }
      }
      if (!is_ok) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;

  return 0;
}
