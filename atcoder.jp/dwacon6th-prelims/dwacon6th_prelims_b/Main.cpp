#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  int N;
  cin >> N;
  vector<long long> X(N);
  for (int i = 0; i < N; i++) cin >> X[i];

  mint ans = 0, sum = 0;
  for (int i = 1; i < N; i++) {
    mint num = 1, deno = i;
    sum += num / deno;
    ans += (X[i] - X[i - 1]) * sum;
  }

  for (int i = 1; i < N; i++) ans *= i;

  cout << ans.val() << endl;

  return 0;
}
