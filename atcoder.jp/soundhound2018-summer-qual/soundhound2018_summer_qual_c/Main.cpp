#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m, d;
  cin >> n >> m >> d;

  if (d == 0) {
    cout << setprecision(9) << 1.0 / n * (m - 1) << endl;
  } else {
    cout << setprecision(9) << (long double)(2 * n - 2 * d) / n / n * (m - 1) << endl;
  }

  return 0;
}
