#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

int N, T;
vector<pair<int, long long>> AB;

void solve() {
  cin >> N >> T;
  AB.resize(N);
  for (int i = 0; i < N; i++) cin >> AB[i].first >> AB[i].second;
  sort(AB.begin(), AB.end());
  vector<vector<long long>> dp(N + 1, vector<long long>(T + 1));
  for (int i = 0; i < N; i++) {
    auto [A, B] = AB[i];
    for (int j = 0; j < T; j++) {
      chmax(dp[i + 1][j], dp[i][j]);
      chmax(dp[i + 1][min(T, j + A)], dp[i][j] + B);
    }
    chmax(dp[i + 1][T], dp[i][T]);
  }

  cout << dp[N][T] << endl;
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
