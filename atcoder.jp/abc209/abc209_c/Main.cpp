#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

int main() {
  int N;
  cin >> N;
  vector<long long> C(N);
  for (int i = 0; i < N; i++) cin >> C[i];
  sort(C.begin(), C.end());
  mint ans = 1;
  for (int i = 0; i < N; i++) {
    ans *= (C[i] - i);
  }

  cout << ans.val() << endl;

  return 0;
}
