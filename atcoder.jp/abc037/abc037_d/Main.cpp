#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

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
  vector<vector<long long>> memo(H, vector<long long>(W, -1));

  function<long long(int, int)> f = [&](int h, int w) {
    if (memo.at(h).at(w) != -1) return memo.at(h).at(w);

    mint val = 1;
    int a = grid.at(h).at(w);
    if (h != 0 && grid.at(h - 1).at(w) < a) val += f(h - 1, w);
    if (h != H - 1 && grid.at(h + 1).at(w) < a) val += f(h + 1, w);
    if (w != 0 && grid.at(h).at(w - 1) < a) val += f(h, w - 1);
    if (w != W - 1 && grid.at(h).at(w + 1) < a) val += f(h, w + 1);

    long long res = val.val();
    memo.at(h).at(w) = res;
    return res;
  };

  mint ans = 0;
  for (int h = 0; h < H; h++) {
    for (int w = 0; w < W; w++) {
      ans += f(h, w);
    }
  }

  cout << ans.val() << endl;

  return 0;
}
