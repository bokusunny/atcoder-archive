#include <bits/stdc++.h>
using namespace std;

int main() {
  long double N;
  cin >> N;

  long double ans = 0.0;
  for (long double i = 0; i < N - 1; i++) {
    ans += N / (N - 1.0 - i);
  }

  cout << setprecision(9) << ans << endl;

  return 0;
}
