#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int N, M;
const long long INF = 1LL << 62;
vector<long long> H, W;

void solve() {
  cin >> N >> M;
  H.resize(N), W.resize(M);
  for (int i = 0; i < N; i++) cin >> H[i];
  for (int i = 0; i < M; i++) cin >> W[i];
  sort(H.begin(), H.end());

  vector<long long> S1(N), S2(N);
  for (int i = 2; i < N; i += 2) {
    S1[i] = S1[i - 2] + H[i - 1] - H[i - 2];
  }
  for (int i = N - 3; i >= 0; i -= 2) {
    S2[i] = S2[i + 2] + H[i + 2] - H[i + 1];
  }

  long long ans = INF;
  for (auto w : W) {
    auto i = lower_bound(H.begin(), H.end(), w) - H.begin();
    if (i & 1) i ^= 1;
    chmin(ans, S1[i] + S2[i] + abs(w - H[i]));
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
