#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<int>> grid(n, vector<int>(n));
  for (auto &row : grid) {
    for (auto &a : row) {
      cin >> a;
    }
  }

  auto is_ok = [&](int x) {
    vector<vector<int>> relative_grid(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int a = grid[i][j];
        if (a >= x) relative_grid[i][j] = 1;
      }
    }

    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        s[i + 1][j + 1] =
            s[i + 1][j] + s[i][j + 1] - s[i][j] + relative_grid[i][j];
      }
    }

    for (int i = 0; i < n - k + 1; i++) {
      for (int j = 0; j < n - k + 1; j++) {
        int over_cnt = s[i + k][j + k] - s[i][j + k] - s[i + k][j] + s[i][j];
        if (over_cnt <= k * k / 2) {
          return false;
        }
      }
    }

    return true;
  };

  int ok = -1, ng = 1000000001;

  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (is_ok(mid))
      ok = mid;
    else
      ng = mid;
  }

  cout << ok << endl;

  return 0;
}
