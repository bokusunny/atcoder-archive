#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;

  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  long long ans = 1LL << D;
  for (int i = 1; i < 1 << N; i++) {
    long long OR = 0;
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      if (i >> j & 1) OR |= A[j], cnt++;
    }
    long long pattern = 1;
    for (int j = 0; j < D; j++) {
      if ((OR >> j & 1) == 0) pattern *= 2;
    }
    if (cnt % 2 == 1) {
      ans -= pattern;
    } else {
      ans += pattern;
    }
  }

  cout << ans << endl;

  return 0;
}
