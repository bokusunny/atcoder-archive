#include <bits/stdc++.h>
using namespace std;
#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  long long n, k;
  cin >> n >> k;

  mint ans = 0;
  for (long long i = k; i <= n + 1; i++) {
    long long min = i * (i - 1) / 2;
    long long max = i * (2 * n - i + 1) / 2;
    ans += (max - min + 1);
  }

  cout << ans.val() << endl;

  return 0;
}
