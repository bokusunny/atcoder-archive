#include <bits/stdc++.h>
using namespace std;

auto grid_bfs(vector<vector<char>> &grid) {
  int h = (int)grid.size(), w = (int)grid.at(0).size();
  const int INF = 1000000001;
  vector<vector<int>> dist(h, vector<int>(w, INF));
  queue<pair<int, int>> q;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == '#') {
        dist[i][j] = 0;
        q.push({i, j});
      }
    }
  }
  vector<pair<int, int>> moving = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int ans = 0;
  while (!q.empty()) {
    auto [cur_y, cur_x] = q.front();
    q.pop();

    for (auto [mv_y, mv_x] : moving) {
      int target_y = cur_y + mv_y, target_x = cur_x + mv_x;

      if (target_y >= h || target_y < 0 || target_x >= w || target_x < 0) {
        continue;
      }

      if (dist.at(target_y).at(target_x) != INF) continue;

      dist.at(target_y).at(target_x) = dist.at(cur_y).at(cur_x) + 1;
      ans = max(ans, dist[target_y][target_x]);
      q.push(make_pair(target_y, target_x));
    }
  }

  return ans;
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

  auto ans = grid_bfs(grid);
  cout << ans << endl;

  return 0;
}
