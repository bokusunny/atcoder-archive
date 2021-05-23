#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  for (int &a : A) cin >> a;
  reverse(A.begin(), A.end());

  const int INF = pow(10, 9) + 1;
  vector<int> dp(n, INF);

  for (int a : A) {
    int i = (upper_bound(dp.begin(), dp.end(), a) - dp.begin());
    dp[i] = a;
  }

  for (int i = 0; i < n; i++) {
    if (dp[i] != INF) continue;
    cout << i << endl;
    return 0;
  }

  cout << n << endl;

  return 0;
}
