#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int H, W;
vector<vector<char>> grid;

void solve() {
  cin >> H >> W;
  grid.resize(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid[i][j];
    }
  }

  deque<pair<int, int>> q;
  const int INF = 1 << 30;
  vector<vector<int>> dist(H, vector<int>(W, INF));
  dist[0][0] = 0;
  q.push_back({0, 0});

  while (!q.empty()) {
    auto [cy, cx] = q.front();
    q.pop_front();

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int ny = cy + i, nx = cx + j;
        if (ny < 0 || ny >= H || nx < 0 || nx >= W || grid[ny][nx] == '#') continue;
        if (abs(i) + abs(j) != 1 || dist[ny][nx] <= dist[cy][cx]) continue;

        dist[ny][nx] = dist[cy][cx];
        q.push_front({ny, nx});
      }
    }

    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        int ny = cy + i, nx = cx + j;
        if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
        if (abs(i) + abs(j) == 0 || abs(i) + abs(j) == 4 || dist[ny][nx] <= dist[cy][cx] + 1) continue;

        dist[ny][nx] = dist[cy][cx] + 1;
        q.push_back({ny, nx});
      }
    }
  }

  cout << dist[H - 1][W - 1] << endl;
}

int main() {
  solve();

  return 0;
}
