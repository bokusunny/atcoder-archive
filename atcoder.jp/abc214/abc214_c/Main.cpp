#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<long long> S(N * 2), T(N * 2);
  for (int i = 0; i < N; i++) {
    long long s;
    cin >> s;
    S[i] = S[N + i] = s;
  }
  vector<int> fastest;
  const long long INF = 1LL << 62;
  long long fas = INF;
  for (int i = 0; i < N; i++) {
    long long t;
    cin >> t;
    T[i] = T[N + i] = t;
    if (t < fas) fastest = {i};
    if (t == fas) fastest.push_back(i);
  }

  vector<long long> ans(2 * N, INF);
  for (auto &i : fastest) ans[i] = T[i];

  for (int i = 1; i < 2 * N; i++) {
    ans[i] = min(T[i], ans[i - 1] + S[i - 1]);
  }

  for (int i = N; i < 2 * N; i++) {
    cout << ans[i] << endl;
  }
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
