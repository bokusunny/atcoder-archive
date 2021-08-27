#include <bits/stdc++.h>
using namespace std;

void solve() {
  int H, W;
  cin >> H >> W;
  vector<string> Grid(H);
  for (int i = 0; i < H; i++) {
    cin >> Grid[i];
    Grid[i].push_back('#');
  }
  string s(W + 1, '#');
  Grid.push_back(s);

  vector Grid2(H + 1, vector<int>(W + 1, -1));
  queue<pair<int, int>> q;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (Grid[i][j] == '#') continue;
      if (Grid[i + 1][j] == '#' && Grid[i][j + 1] == '#' && Grid[i + 1][j + 1] == '#') {
        Grid2[i][j] = 0;
        q.emplace(i, j);
      }
    }
  }
  for (int i = 0; i <= H; i++) {
    for (int j = 0; j <= W; j++) {
      if (Grid[i][j] == '#') Grid2[i][j] = 1;
    }
  }

  vector<int> Dy({-1, -1, 0});
  vector<int> Dx({0, -1, -1});

  while (!q.empty()) {
    auto [cy, cx] = q.front();
    q.pop();
    if (Grid2[cy][cx] == 0) {
      for (auto dy : Dy) {
        for (auto dx : Dx) {
          int ny = cy + dy, nx = cx + dx;
          if (ny < 0 || nx < 0) continue;
          if (Grid2[ny][nx] != -1) continue;
          if (Grid[ny][nx] == '#') continue;

          Grid2[ny][nx] = 1;
          q.emplace(ny, nx);
        }
      }
    } else {
      if (cy > 0 && Grid2[cy][cx + 1] == 1 && Grid2[cy - 1][cx + 1] == 1) {
        if (Grid2[cy - 1][cx] == -1) {
          Grid2[cy - 1][cx] = 0;
          q.emplace(cy - 1, cx);
        }
      }
      if (cx > 0 && Grid2[cy + 1][cx] == 1 && Grid2[cy + 1][cx - 1] == 1) {
        if (Grid2[cy][cx - 1] == -1) {
          Grid2[cy][cx - 1] = 0;
          q.emplace(cy, cx - 1);
        }
      }
      if (cy > 0 && cx > 0 && Grid2[cy - 1][cx] == 1 && Grid2[cy][cx - 1] == 1) {
        if (Grid2[cy - 1][cx - 1] == -1) {
          Grid2[cy - 1][cx - 1] = 0;
          q.emplace(cy - 1, cx - 1);
        }
      }
    }
  }

  if (Grid2[0][0] == 0) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
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
