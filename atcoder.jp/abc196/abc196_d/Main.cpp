#include <bits/stdc++.h>
using namespace std;

int H, W, A, B;
vector<vector<bool>> used;
int ans = 0;

void dfs(int y, int x, int left_A) {
  if (y == H) {
    if (left_A == 0) ans++;
    return;
  }
  if (x == W) return dfs(y + 1, 0, left_A);
  if (used[y][x]) return dfs(y, x + 1, left_A);

  if (y < H - 1 && left_A > 0) {
    used[y + 1][x] = true;
    dfs(y, x + 1, left_A - 1);
    used[y + 1][x] = false;
  }
  if (x < W - 1 && !used[y][x + 1] && left_A > 0) {
    used[y][x + 1] = true;
    dfs(y, x + 1, left_A - 1);
    used[y][x + 1] = false;
  }
  dfs(y, x + 1, left_A);
}

int main() {
  cin >> H >> W >> A >> B;
  used.resize(H);
  for (auto &v : used) v.resize(W, false);
  dfs(0, 0, A);

  cout << ans << endl;

  return 0;
}
