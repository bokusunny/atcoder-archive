#include <bits/stdc++.h>
using namespace std;

int main() {
  double t, l, x, y;
  cin >> t >> l >> x >> y;
  int q;
  cin >> q;

  auto to_degree = [](const double r) { return r * 180.0 / M_PI; };
  auto solve = [&](double r) {
    complex<double> cen = {0, l / 2.0}, o = {0, 0};
    auto target = cen + (o - cen) * polar(1.0, r);
    auto ey = target.real(), ez = target.imag();
    auto ans = atan2(ez, sqrt(pow(y - ey, 2) + pow(x, 2)));
    cout << setprecision(9) << to_degree(ans) << endl;
  };

  auto to_rad = [](const double d) { return d * M_PI / 180.0; };
  for (int i = 0; i < q; i++) {
    double e;
    cin >> e;

    solve(to_rad(-360.0 * e / t));
  }

  return 0;
}
