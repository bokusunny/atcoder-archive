#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> V;
const int INF = 1 << 30;

void solve() {
  cin >> N >> K;
  V.resize(N);
  for (int i = 0; i < N; i++) cin >> V[i];

  int ans = -INF;
  // 取る宝石の数
  for (int v = 1; v <= min(N, K); v++) {
    // 左から取る宝石の数
    for (int l = 0; l <= v; l++) {
      int r = v - l;
      vector<int> J;
      for (int i = 0; i < l; i++) J.push_back(V[i]);
      for (int i = N - 1; i >= N - r; i--) J.push_back(V[i]);

      sort(J.begin(), J.end());
      int sum = 0;
      int left = K - v;
      for (auto j : J) {
        if (left > 0 && j < 0) {
          left--;
          continue;
        } else {
          sum += j;
        }
      }
      ans = max(ans, sum);
    }
  }

  cout << ans << endl;
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
