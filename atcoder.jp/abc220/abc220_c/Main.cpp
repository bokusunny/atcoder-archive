#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  long long X;
  cin >> X;
  auto sum = accumulate(A.begin(), A.end(), 0LL);
  long long ans = 0;
  ans += 1LL * N * (X / sum);
  X %= sum;
  for (int i = 0; i < N; i++) {
    if (X < 0) break;
    X -= A[i];
    ans++;
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
