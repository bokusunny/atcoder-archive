#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> A(n);
  for (auto &a : A) cin >> a;

  long long ans = (1 << 30) + 1;
  for (int i = 0; i < (1 << (n - 1)); i++) {
    long long xor_sum = 0, or_sum = A.at(0);
    for (int j = 0; j < (n - 1); j++) {
      if (i >> j & 1) {
        or_sum |= A.at(j + 1);
      } else {
        xor_sum ^= or_sum;
        or_sum = A.at(j + 1);
      }
    }
    xor_sum ^= or_sum;
    if (xor_sum < ans) ans = xor_sum;
  }

  cout << ans << endl;

  return 0;
}
