#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int N;
  cin >> N;
  using T = tuple<int, int, long long>;
  vector<T> B(N);  // s, w, v
  for (int i = 0; i < N; i++) cin >> get<1>(B[i]) >> get<0>(B[i]) >> get<2>(B[i]);
  sort(B.begin(), B.end(), [](const T &v1, const T &v2) { return get<0>(v1) + get<1>(v1) < get<0>(v2) + get<1>(v2); });

  vector<vector<long long>> dp(N + 1, vector<long long>(20001, -1));
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    auto [s, w, v] = B[i];
    for (int j = 0; j <= 20000; j++) {
      if (dp[i][j] == -1) continue;

      chmax(dp[i + 1][j], dp[i][j]);
      if (j <= s) chmax(dp[i + 1][j + w], dp[i][j] + v);
    }
  }

  long long ans = -1;
  for (auto v : dp[N]) chmax(ans, v);

  cout << ans << endl;

  return 0;
}
