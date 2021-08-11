#include <bits/stdc++.h>
using namespace std;

void solve() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid[i][j];
    }
  }

  vector<vector<bool>> seen(H, vector<bool>(W));
  function<void(int, int, long long &, long long &)> dfs = [&](int y, int x, long long &bcnt, long long &wcnt) {
    seen[y][x] = true;
    if (grid[y][x] == '.') {
      wcnt++;
    } else {
      bcnt++;
    }

    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (abs(i) + abs(j) != 1) continue;

        if (y + i == H || y + i == -1 || x + j == W || x + j == -1) continue;
        if (seen[y + i][x + j]) continue;
        if (grid[y][x] == grid[y + i][x + j]) continue;

        dfs(y + i, x + j, bcnt, wcnt);
      }
    }
  };

  long long ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (seen[i][j]) continue;
      long long bcnt = 0, wcnt = 0;
      dfs(i, j, bcnt, wcnt);
      ans += bcnt * wcnt;
    }
  }

  cout << ans << endl;
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
