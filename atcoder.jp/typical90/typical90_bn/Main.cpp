#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> V;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    V.push_back({l, r});
  }

  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    auto [l1, r1] = V.at(i);
    for (int j = i + 1; j < n; j++) {
      auto [l2, r2] = V.at(j);
      for (int a1 = l1; a1 <= r1; a1++) {
        for (int a2 = l2; a2 <= r2 && a1 > a2; a2++) {
          ans += 1.0 / ((r1 - l1 + 1) * (r2 - l2 + 1));
        }
      }
    }
  }

  cout << setprecision(9) << ans << endl;

  return 0;
}
