#include <bits/stdc++.h>
using namespace std;

int grid_bfs(vector<vector<char>> &grid, pair<int, int> s) {
  int h = (int)grid.size(), w = (int)grid[0].size();
  const int INF = 1000000001;
  vector<vector<int>> dist(h, vector<int>(w, INF));
  queue<pair<int, int>> q;
  q.push(s);
  dist.at(s.first).at(s.second) = 0;
  vector<pair<int, int>> moving = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int res = -1;
  while (!q.empty()) {
    auto [cy, cx] = q.front();
    q.pop();

    for (auto [my, mx] : moving) {
      int dy = cy + my, dx = cx + mx;

      if (dy >= h || dy < 0 || dx >= w || dx < 0 || dist[dy][dx] != INF || grid[dy][dx] == '#') {
        continue;
      }

      dist.at(dy).at(dx) = dist.at(cy).at(cx) + 1;
      res = max(res, dist[dy][dx]);
      q.push({dy, dx});
    }
  }

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
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid[i][j] == '#') continue;
      ans = max(grid_bfs(grid, make_pair(i, j)), ans);
    }
  }

  cout << ans << endl;

  return 0;
}
