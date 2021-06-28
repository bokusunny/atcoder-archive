#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, M, K;
  cin >> N >> M >> K;
  vector<long long> A(N), B(M), SA(N + 1), SB(M + 1);
  for (auto &a : A) cin >> a;
  for (auto &b : B) cin >> b;
  for (int i = 0; i < N; i++) SA[i + 1] = SA[i] + A[i];
  for (int i = 0; i < M; i++) SB[i + 1] = SB[i] + B[i];

  auto is_ok = [&](long long x) {
    for (int n = 0; n <= x; n++) {
      auto m = x - n;
      if (m < 0 || M < m || N < n) continue;
      if (SA[n] + SB[m] <= K) return true;
    }
    return false;
  };

  long long ok = -1, ng = N + M + 1;

  while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) / 2;
    if (is_ok(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;

  return 0;
}
