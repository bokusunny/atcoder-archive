#include <bits/stdc++.h>
using namespace std;

int u[510][510], d[510][510];

int main() {
  int R, C, K;
  cin >> R >> C >> K;
  vector<vector<char>> grid(R, vector<char>(C));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < C; i++) {
    int streak = 0;
    for (int j = 0; j < R; j++) {
      u[j][i] = streak;
      if (grid[j][i] == 'o') {
        streak++;
      } else {
        streak = 0;
      }
    }
  }
  for (int i = 0; i < C; i++) {
    int streak = 0;
    for (int j = R - 1; j >= 0; j--) {
      d[j][i] = streak;
      if (grid[j][i] == 'o') {
        streak++;
      } else {
        streak = 0;
      }
    }
  }

  int ans = 0;
  for (int i = K - 1; i <= R - K; i++) {
    for (int j = K - 1; j <= C - K; j++) {
      if (grid[i][j] == 'x') continue;
      bool is_ok = true;
      for (int k = -K + 1; k < K; k++) {
        if (grid[i][j + k] == 'x' || u[i][j + k] < K - abs(k) - 1 || d[i][j + k] < K - abs(k) - 1) {
          is_ok = false;
          break;
        }
      }
      if (is_ok) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
