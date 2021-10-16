#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-8;

void solve() {
  int N, M;
  double S;
  cin >> N >> M >> S;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<long long> Rui(N + 1);
  for (int i = 0; i < N; i++) Rui[i + 1] = Rui[i] + A[i];

  double ans = 0.0;
  for (int i = 0; i < N; i++) {
    double score = 0.0;
    long long rui = Rui[N] - Rui[i];
    double xi = min((double)M, S / (N - i));
    score += xi * rui;
    double left = S - xi * (N - i);
    for (int j = 0; j < i; j++) {
      double yi = min((double)M, left / (i - j));
      ans = max(ans, score + yi * (Rui[i] - Rui[j]));
    }
    ans = max(ans, score);
  }

  cout << setprecision(15) << ans << endl;
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
