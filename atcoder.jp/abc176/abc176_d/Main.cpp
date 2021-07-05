#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  pair<int, int> C, D;
  cin >> C.first >> C.second >> D.first >> D.second;
  C.first--, C.second--, D.first--, D.second--;
  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid[i][j];
    }
  }

  deque<pair<int, int>> d;
  const int INF = 1000000001;
  vector<vector<int>> dist(H, vector<int>(W, INF));
  dist[C.first][C.second] = 0;
  d.push_back(C);

  while (!d.empty()) {
    auto [cy, cx] = d.front();
    d.pop_front();

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int ny = cy + i, nx = cx + j;
        if (ny < 0 || ny >= H || nx < 0 || nx >= W || grid[ny][nx] == '#') continue;
        if (abs(i) + abs(j) != 1 || dist[ny][nx] <= dist[cy][cx]) continue;

        dist[ny][nx] = dist[cy][cx];
        d.push_front({ny, nx});
      }
    }

    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        int ny = cy + i, nx = cx + j;
        if (ny < 0 || ny >= H || nx < 0 || nx >= W || grid[ny][nx] == '#') continue;
        if (abs(i) + abs(j) <= 1 || dist[ny][nx] <= dist[cy][cx] + 1) continue;

        dist[ny][nx] = dist[cy][cx] + 1;
        d.push_back({ny, nx});
      }
    }
  }

  if (dist[D.first][D.second] != INF) {
    cout << dist[D.first][D.second] << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
