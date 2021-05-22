#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  long long n;
  cin >> n;

  if (n % 2 || n < 10) {
    cout << 0 << endl;
    return 0;
  }

  n /= 2;
  long long ans = 0;
  long long p5 = 5;
  while (p5 <= n) {
    ans += (n / p5);
    p5 *= 5;
  }

  cout << ans << endl;

  return 0;
}
