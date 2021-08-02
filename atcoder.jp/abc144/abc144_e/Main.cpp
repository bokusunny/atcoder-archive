#include <bits/stdc++.h>
using namespace std;

int N;
long long K;
vector<long long> A, F;

bool is_ok(long long x) {
  long long cnt = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] * F[i] <= x) continue;
    cnt += (A[i] * F[i] - x + F[i] - 1) / F[i];
  }
  return cnt <= K;
}

void solve() {
  cin >> N >> K;
  A.resize(N), F.resize(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < N; i++) cin >> F[i];
  sort(A.begin(), A.end());
  sort(F.begin(), F.end(), greater<long long>());

  long long ng = -1, ok = 1LL << 62;

  while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) / 2;
    if (is_ok(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;
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
