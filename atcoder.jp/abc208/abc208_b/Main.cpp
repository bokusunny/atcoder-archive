#include <bits/stdc++.h>
using namespace std;

int main() {
  long long P;
  cin >> P;

  vector<long long> C(11);
  C[1] = 1LL;
  for (long long i = 2; i <= 10; i++) {
    C[i] = C[i - 1] * i;
  }

  int ans = 0;
  for (int i = 10; i >= 1; i--) {
    ans += (P / C[i]);
    P %= C[i];
  }

  cout << ans << endl;

  return 0;
}
