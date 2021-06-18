#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> A(n);
  for (auto &a : A) cin >> a;
  sort(A.begin(), A.end());

  double x = A.at(n / 2) / 2.0;

  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (x + A.at(i) - min((double)A.at(i), 2 * x)) / (double)n;
  }

  cout << setprecision(9) << ans << endl;

  return 0;
}
