#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long double> P(N);
  for (auto &p : P) cin >> p;

  vector<double> kitai(N);
  for (int i = 0; i < N; i++) {
    auto p = P[i];
    kitai[i] = ((p + 1.0) * p / 2) / p;
  }

  long double ans = 0.0;
  for (int i = 0; i < K; i++) {
    ans += kitai[i];
  }

  auto tmp = ans;
  for (int i = 0; i < N - K; i++) {
    tmp += kitai[K + i];
    tmp -= kitai[i];
    ans = max(ans, tmp);
  }

  cout << setprecision(9) << ans << endl;

  return 0;
}
