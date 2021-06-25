#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<pair<int, int>>> S(N);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    for (int j = 0; j < A; j++) {
      int x, y;
      cin >> x >> y;
      x--;
      S[i].emplace_back(x, y);
    }
  }

  int ans = 0;
  for (int i = 0; i < 1 << N; i++) {
    int cnt = __builtin_popcount(i);
    vector<bool> is_shoujiki(N, false);
    for (int j = 0; j < N; j++) {
      if (i >> j & 1) {
        is_shoujiki[j] = true;
      }
    }

    bool is_ok = true;
    for (int i = 0; i < N; i++) {
      if (!is_shoujiki[i]) continue;

      for (auto [x, y] : S[i]) {
        if ((y == 1 && !is_shoujiki[x]) || (y == 0 && is_shoujiki[x])) {
          is_ok = false;
          break;
        }
      }
      if (!is_ok) break;
    }
    if (!is_ok) continue;
    ans = max(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}
