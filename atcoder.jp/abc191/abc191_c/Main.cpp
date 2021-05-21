#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  for (auto &row : grid)
    for (auto &cell : row) cin >> cell;

  int ans = 0;
  for (int i = 1; i < h; i++) {
    for (int j = 1; j < w; j++) {
      int black_num = 0;
      if (grid[i - 1][j - 1] == '#') black_num++;
      if (grid[i][j - 1] == '#') black_num++;
      if (grid[i - 1][j] == '#') black_num++;
      if (grid[i][j] == '#') black_num++;
      if (black_num % 2) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
