#include <bits/stdc++.h>
using namespace std;

long double get_diff(long double r1, long double r2) {
  auto tmp = max(r1, r2) - min(r1, r2);
  return abs(M_PI - tmp);
}

int main() {
  int N;
  cin >> N;
  vector<pair<long double, long double>> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i].first >> P[i].second;
  }

  long double min_diff = M_PI;
  for (int i = 0; i < N; i++) {
    auto [cen_x, cen_y] = P[i];
    vector<long double> Rad;
    for (int j = 0; j < N; j++) {
      if (i == j) continue;

      auto [x1, y1] = P[j];
      auto r = atan2(y1 - cen_y, x1 - cen_x);
      Rad.push_back(r);
    }
    sort(Rad.begin(), Rad.end());

    for (auto r : Rad) {
      auto target = r > 0 ? r - M_PI : r + M_PI;
      auto i = lower_bound(Rad.begin(), Rad.end(), target) - Rad.begin();
      if (i == 0 || i == (int)Rad.size()) {
        min_diff = min({min_diff, get_diff(r, Rad[0]), get_diff(r, Rad[(int)Rad.size() - 1])});
      } else {
        min_diff = min({min_diff, get_diff(r, Rad[i]), get_diff(r, Rad[i - 1])});
      }
    }
  }

  auto to_degree = [](const long double r) { return r * 180.0 / M_PI; };
  cout << setprecision(9) << to_degree(M_PI - min_diff) << endl;

  return 0;
}
