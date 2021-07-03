#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> grid(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int a;
      cin >> a;
      grid.at(i).at(j) = a;
    }
  }

  vector<tuple<int, int, int, int>> ans;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W - 1; j++) {
      if (grid[i][j] % 2 == 1) {
        ans.emplace_back(i + 1, j + 1, i + 1, j + 2);
        grid[i][j + 1]++;
      }
    }
  }
  for (int i = 0; i < H - 1; i++) {
    if (grid[i][W - 1] % 2 == 1) {
      ans.emplace_back(i + 1, W, i + 2, W);
      grid[i + 1][W - 1]++;
    }
  }

  cout << (int)ans.size() << endl;
  for (auto [a, b, c, d] : ans) cout << a << " " << b << " " << c << " " << d << endl;

  return 0;
}
