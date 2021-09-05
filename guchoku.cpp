#include <bits/stdc++.h>
using namespace std;

void solve() {
  int H, W, M;
  cin >> H >> W >> M;
  vector<int> X(M), Y(M);
  vector<vector<bool>> Grid(H, vector<bool>(W));
  int x_lim = H, y_lim = W;
  for (int i = 0; i < M; i++) {
    cin >> X[i] >> Y[i];
    X[i]--, Y[i]--;
    Grid[X[i]][Y[i]] = 1;
    if (X[i] == 0) y_lim = min(y_lim, Y[i]);
    if (Y[i] == 0) x_lim = min(x_lim, X[i]);
  }

  auto check1 = [&](int x, int y) {
    if (y >= y_lim) return false;
    for (int i = 0; i < x; i++) {
      if (Grid[i][y] == 1) return false;
    }
    return true;
  };
  auto check2 = [&](int x, int y) {
    if (x >= x_lim) return false;
    for (int i = 0; i < y; i++) {
      if (Grid[x][i] == 1) return false;
    }
    return true;
  };

  int cnt = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (Grid[i][j]) continue;
      if (!check1(i, j) && !check2(i, j)) continue;
      cnt++;
    }
  }

  cout << cnt << endl;
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
