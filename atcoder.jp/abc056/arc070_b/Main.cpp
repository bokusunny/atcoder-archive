#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  vector Left(N + 1, vector<int>(K));
  vector Right(N + 1, vector<int>(K));
  Left[0][0] = Right[0][0] = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K; j++) {
      Left[i + 1][j] |= Left[i][j];
      if (j + A[i] < K) Left[i + 1][j + A[i]] |= Left[i][j];
      Right[i + 1][j] |= Right[i][j];
      if (j + A[N - i - 1] < K) Right[i + 1][j + A[N - i - 1]] |= Right[i][j];
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    vector<int> Rui(K + 1);
    for (int k = 0; k < K; k++) Rui[k + 1] = Rui[k] + Right[N - i][k];
    bool ok = true;
    for (int sm = 0; sm < K; sm++) {
      if (!Left[i - 1][sm]) continue;
      if (Rui[K - sm] - Rui[max(0, K - A[i - 1] - sm)] > 0) {
        ok = false;
        break;
      }
    }
    if (ok) ans++;
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
