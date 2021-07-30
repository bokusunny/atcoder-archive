#include <bits/stdc++.h>
using namespace std;

int A, B, Q;
const long long INF = 1LL << 62;
vector<long long> S, T, X;
vector<long long> NT, NS;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

void cinout() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> A >> B >> Q;
  S.resize(A), NT.assign(A, INF), T.resize(B), NS.assign(B, INF), X.resize(Q);
  for (int i = 0; i < A; i++) cin >> S[i];
  for (int i = 0; i < B; i++) cin >> T[i];
  sort(S.begin(), S.end());
  sort(T.begin(), T.end());
  for (int i = 0; i < Q; i++) cin >> X[i];
}

void calc_nearest() {
  for (int i = 0; i < A; i++) {
    auto itr = lower_bound(T.begin(), T.end(), S[i]);
    if (itr != T.end()) chmin(NT[i], abs(*itr - S[i]));
    if (itr != T.begin()) chmin(NT[i], abs(*(itr - 1) - S[i]));
  }
  for (int i = 0; i < B; i++) {
    auto itr = lower_bound(S.begin(), S.end(), T[i]);
    if (itr != S.end()) chmin(NS[i], abs(*itr - T[i]));
    if (itr != S.begin()) chmin(NS[i], abs(*(itr - 1) - T[i]));
  }
}

void query(long long x) {
  long long ans = INF;

  auto i = lower_bound(S.begin(), S.end(), x) - S.begin();
  if (i != A) chmin(ans, abs(x - S[i]) + NT[i]);
  if (i != 0) chmin(ans, abs(x - S[i - 1]) + NT[i - 1]);

  auto j = lower_bound(T.begin(), T.end(), x) - T.begin();
  if (j != B) chmin(ans, abs(x - T[j]) + NS[j]);
  if (j != 0) chmin(ans, abs(x - T[j - 1]) + NS[j - 1]);

  cout << ans << endl;
}

void solve() {
  calc_nearest();
  for (int i = 0; i < Q; i++) query(X[i]);
}

int main() {
  cinout();
  solve();

  return 0;
}
