#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, X, Y;
  cin >> H >> W >> Y >> X;
  X--, Y--;
  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> grid[i][j];
    }
  }

  int ans = 0;
  for (int i = X; i < W; i++) {
    if (grid[Y][i] == '.')
      ans++;
    else
      break;
  }
  for (int i = Y; i < H; i++) {
    if (grid[i][X] == '.')
      ans++;
    else
      break;
  }
  for (int i = X; i >= 0; i--) {
    if (grid[Y][i] == '.')
      ans++;
    else
      break;
  }
  for (int i = Y; i >= 0; i--) {
    if (grid[i][X] == '.')
      ans++;
    else
      break;
  }
  cout << ans - 3 << endl;

  return 0;
}
