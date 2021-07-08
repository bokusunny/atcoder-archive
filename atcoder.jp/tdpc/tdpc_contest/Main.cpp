#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; i++) cin >> P[i];

  bitset<10001> dp;
  dp[0] = 1;
  for (int i = 0; i < N; i++) {
    dp |= (dp << P[i]);
  }

  cout << dp.count() << endl;

  return 0;
}
