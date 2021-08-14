#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, K;
  cin >> N >> K;
  vector<string> Grid(N);
  for (int i = 0; i < N; i++) cin >> Grid[i];

  set<vector<string>> seen;

  auto is_valid = [&](int y, int x) {
    for (int dy = -1; dy <= 1; dy++) {
      for (int dx = -1; dx <= 1; dx++) {
        if (abs(dy) + abs(dx) != 1) continue;
        auto ny = y + dy, nx = x + dx;
        if (ny < 0 || N <= ny || nx < 0 || N <= nx) continue;

        if (Grid[ny][nx] == '@') return true;
      }
    }

    return false;
  };

  function<int(int)> dfs = [&](int cnt) {
    if (seen.count(Grid)) return 0;
    seen.insert(Grid);

    if (cnt == K) return 1;

    int res = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (Grid[i][j] != '.') continue;
        if (!is_valid(i, j)) continue;

        Grid[i][j] = '@';
        res += dfs(cnt + 1);
        Grid[i][j] = '.';
      }
    }

    return res;
  };

  int ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (Grid[i][j] == '#') continue;

      Grid[i][j] = '@';
      ans += dfs(1);
      Grid[i][j] = '.';
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
