#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<bool> Bonus(N + 1);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    if (Bonus[i]) {
      if (A[i] & 1) {
        ans += (A[i] + 1) / 2;
      } else if (A[i] != 0) {
        ans += A[i] / 2;
        Bonus[i + 1] = true;
      }
    } else {
      if (A[i] & 1) {
        ans += A[i] / 2;
        Bonus[i + 1] = true;
      } else {
        ans += A[i] / 2;
      }
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
