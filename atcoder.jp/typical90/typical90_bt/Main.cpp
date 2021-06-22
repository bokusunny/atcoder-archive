#include <bits/stdc++.h>
using namespace std;

int grid_dfs(vector<vector<char>> &grid, vector<vector<bool>> &seen, pair<int, int> &s, pair<int, int> cur) {
  auto [cy, cx] = cur;
  int H = (int)grid.size(), W = (int)grid.at(0).size();

  if (cy == s.first && cx == s.second && seen.at(cy).at(cx)) {
    return 0;
  }

  seen.at(cy).at(cx) = true;

  vector<int> dy = {1, 0, -1, 0};
  vector<int> dx = {0, 1, 0, -1};

  int res = -10000;  // 現在値から2回目のsまでの距離
  for (int i = 0; i < 4; i++) {
    int ny = cy + dy.at(i), nx = cx + dx.at(i);
    if (ny == -1 || ny == H || nx == -1 || nx == W || grid.at(ny).at(nx) == '#') continue;
    if (!(ny == s.first && nx == s.second) && seen.at(ny).at(nx)) continue;

    int tmp = grid_dfs(grid, seen, s, {ny, nx});
    res = max(res, tmp + 1);
  }

  seen.at(cy).at(cx) = false;
  return res;
}

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;
      grid.at(i).at(j) = c;
    }
  }

  int ans = -1;
  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      if (grid.at(h).at(w) == '#') continue;
      vector<vector<bool>> seen(H, vector<bool>(W));
      pair<int, int> s = {h, w};

      ans = max(ans, grid_dfs(grid, seen, s, {h, w}));
    }
  }

  if (ans <= 2)
    cout << -1 << endl;
  else
    cout << ans << endl;

  return 0;
}
