#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

int main() {
  int N;
  cin >> N;
  vector<int> C(N);
  for (auto &c : C) cin >> c;

  vector<int> DivisorsCnt(N);
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      if (C[i] % C[j] == 0) cnt++;
    }
    DivisorsCnt[i] = cnt;
  }

  long double ans = 0.0;
  for (auto cnt : DivisorsCnt) {
    if (cnt % 2 == 1)
      ans += 1.0 / 2.0;
    else
      ans += ((long double)cnt + 2.0) / (2.0 * ((long double)cnt + 1.0));
  }

  cout << setprecision(9) << ans << endl;

  return 0;
}
