#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  double n;
  cin >> n;
  double x, y;
  complex<double> a, b;
  cin >> x >> y;
  a = {x, y};
  cin >> x >> y;
  b = {x, y};

  auto cen = (a + b) / 2.0;
  auto ans = cen + (a - cen) * polar(1.0, M_PI * 2.0 / n);

  cout << ans.real() << " " << ans.imag() << endl;

  return 0;
}
