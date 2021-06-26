#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000001;
void grid_bfs(vector<vector<int>> &grid, vector<vector<bool>> &seen, pair<int, int> s) {
  int h = (int)grid.size() - 1, w = (int)grid[0].size() - 1;
  queue<pair<int, int>> q;
  q.push(s);
  seen[s.first][s.second] = true;
  vector<pair<int, int>> moving = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  while (!q.empty()) {
    auto [cy, cx] = q.front();
    q.pop();

    for (auto [my, mx] : moving) {
      int dy = cy + my, dx = cx + mx;

      if (dy >= h || dy < 0 || dx >= w || dx < 0 || seen[dy][dx] || grid[dy][dx] > 0) {
        continue;
      }

      seen[dy][dx] = true;
      q.push({dy, dx});
    }
  }
}

int main() {
  int W, H;
  cin >> W >> H;
  int N;
  cin >> N;
  vector<int> Y = {0, H}, X = {0, W};
  vector<tuple<int, int, int, int>> tape(N);
  for (int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    tape[i] = {x1, y1, x2, y2};
    Y.push_back(y1);
    Y.push_back(y2);
    X.push_back(x1);
    X.push_back(x2);
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  X.erase(unique(X.begin(), X.end()), X.end());
  Y.erase(unique(Y.begin(), Y.end()), Y.end());

  int grid_y = (int)Y.size(), grid_x = (int)X.size();
  vector<vector<int>> grid(grid_y, vector<int>(grid_x, 0));
  for (auto [x1, y1, x2, y2] : tape) {
    auto x1i = lower_bound(X.begin(), X.end(), x1) - X.begin();
    auto x2i = lower_bound(X.begin(), X.end(), x2) - X.begin();
    auto y1i = lower_bound(Y.begin(), Y.end(), y1) - Y.begin();
    auto y2i = lower_bound(Y.begin(), Y.end(), y2) - Y.begin();
    grid[y1i][x1i]++, grid[y1i][x2i]--, grid[y2i][x1i]--, grid[y2i][x2i]++;
  }

  for (int i = 0; i < grid_y - 1; i++) {
    for (int j = 0; j < grid_x; j++) {
      grid[i + 1][j] += grid[i][j];
    }
  }
  for (int i = 0; i < grid_y; i++) {
    for (int j = 0; j < grid_x - 1; j++) {
      grid[i][j + 1] += grid[i][j];
    }
  }

  // for (int i = 0; i < (int)grid.size(); i++) {
  //   for (int j = 0; j < (int)grid[0].size(); j++) {
  //     cout << grid[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  vector<vector<bool>> seen(grid_y, vector<bool>(grid_x, false));
  int ans = 0;
  for (int i = 0; i < grid_y - 1; i++) {
    for (int j = 0; j < grid_x - 1; j++) {
      if (grid[i][j] > 0 || seen[i][j]) continue;
      grid_bfs(grid, seen, make_pair(i, j));
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
