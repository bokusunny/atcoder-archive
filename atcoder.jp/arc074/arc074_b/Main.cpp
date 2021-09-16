#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<long long> A(3 * N);
  for (int i = 0; i < 3 * N; i++) cin >> A[i];

  long long tot1 = 0;
  priority_queue<long long, vector<long long>, greater<long long>> pq1;
  for (int i = 0; i < N; i++) {
    tot1 += A[i];
    pq1.push(A[i]);
  }
  vector<long long> dp1(2 * N + 1);
  dp1[N] = tot1;
  for (int i = N; i <= 2 * N - 1; i++) {
    tot1 += A[i];
    pq1.push(A[i]);
    auto mi = pq1.top();
    pq1.pop();
    tot1 -= mi;
    dp1[i + 1] = tot1;
  }

  long long tot2 = 0;
  priority_queue<long long, vector<long long>, less<long long>> pq2;
  for (int i = 3 * N - 1; i >= 2 * N; i--) {
    tot2 += A[i];
    pq2.push(A[i]);
  }

  vector<long long> dp2(2 * N + 1);
  dp2[2 * N] = tot2;
  for (int i = 2 * N - 1; i >= N; i--) {
    tot2 += A[i];
    pq2.push(A[i]);
    auto mx = pq2.top();
    pq2.pop();
    tot2 -= mx;
    dp2[i] = tot2;
  }

  const long long INF = 1LL << 60;
  long long ans = -INF;
  for (int i = N; i <= 2 * N; i++) {
    ans = max(ans, dp1[i] - dp2[i]);
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
