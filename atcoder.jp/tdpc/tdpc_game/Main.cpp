#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  vector<int> a_(A);
  for (int i = 0; i < A; i++) cin >> a_[i];
  vector<int> b_(B);
  for (int i = 0; i < B; i++) cin >> b_[i];
  reverse(a_.begin(), a_.end()), reverse(b_.begin(), b_.end());

  vector<vector<int>> dp(A + 1, vector<int>(B + 1));

  for (int sum = 1; sum <= A + B; sum++) {
    for (int a = 0; a <= sum && a <= A; a++) {
      int b = sum - a;
      if (b > B) continue;
      if ((A + B - sum) % 2 == 0) {
        if (a == 0)
          dp[a][b] = dp[a][b - 1] + b_[b - 1];
        else if (b == 0)
          dp[a][b] = dp[a - 1][b] + a_[a - 1];
        else
          dp[a][b] = max(dp[a][b - 1] + b_[b - 1], dp[a - 1][b] + a_[a - 1]);
      } else {
        if (a == 0)
          dp[a][b] = dp[a][b - 1];
        else if (b == 0)
          dp[a][b] = dp[a - 1][b];
        else
          dp[a][b] = min(dp[a][b - 1], dp[a - 1][b]);
      }
    }
  }

  cout << dp[A][B] << endl;

  return 0;
}
