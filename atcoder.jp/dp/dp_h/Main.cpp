#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> grid(H, vector<char>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;
      grid.at(i).at(j) = c;
    }
  }

  vector<vector<mint>> dp(H, vector<mint>(W, 0));
  dp.at(0).at(0) = 1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (grid.at(i).at(j) == '#') continue;
      if (i != H - 1 && grid.at(i + 1).at(j) != '#') dp.at(i + 1).at(j) += dp.at(i).at(j);
      if (j != W - 1 && grid.at(i).at(j + 1) != '#') dp.at(i).at(j + 1) += dp.at(i).at(j);
    }
  }

  cout << dp.at(H - 1).at(W - 1).val() << endl;

  return 0;
}
