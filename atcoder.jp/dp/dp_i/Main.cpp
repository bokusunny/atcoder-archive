#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int max = n / 2;
  vector<double> P(n);
  for (auto &p : P) cin >> p;

  vector<vector<double>> dp(n + 1, vector<double>(max + 1, 0.0));
  dp.at(0).at(0) = 1.0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= max; j++) {
      dp.at(i + 1).at(j) += dp.at(i).at(j) * (1.0 - P.at(i));
      if (j != max) dp.at(i + 1).at(j + 1) += dp.at(i).at(j) * P.at(i);
    }
  }

  double ans = 1.0;
  for (auto p : dp.at(n)) ans -= p;

  cout << setprecision(9) << ans << endl;

  return 0;
}
