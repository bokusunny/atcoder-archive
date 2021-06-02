#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, a, b, c;
  cin >> n >> a >> b >> c;

  long long ans = 100000;
  for (int i = 0; i <= 9999; i++) {
    for (int j = 0; i + j <= 9999; j++) {
      long long left = n - i * a - j * b;
      long long tmp = i + j + left / c;
      if (left < 0 || left % c != 0 || tmp > 9999) continue;

      ans = min(ans, tmp);
    }
  }

  cout << ans << endl;

  return 0;
}
