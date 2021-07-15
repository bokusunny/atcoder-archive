#include <bits/stdc++.h>
using namespace std;

// dp[a][b][c] := 現在素因数に2がa個、3がb個、5がc個である確率(上限値以上は同一視)
double dp[101][64][64][64];
const long double EPS = 1e-11;

int main() {
  int N;
  cin >> N;
  long long D;
  cin >> D;

  vector<int> d(3), prime = {2, 3, 5};
  for (int i = 0; i < 3; i++) {
    auto p = prime[i];
    while (D % p == 0) {
      d[i]++;
      D /= p;
    }
  }
  if (D != 1) {
    cout << 0 << endl;
    return 0;
  }

  dp[0][0][0][0] = 1.0;
  for (int i = 0; i < N; i++) {
    for (int a = 0; a <= d[0]; a++) {
      for (int b = 0; b <= d[1]; b++) {
        for (int c = 0; c <= d[2]; c++) {
          if (dp[i][a][b][c] < EPS) continue;
          dp[i + 1][a][b][c] += dp[i][a][b][c] / 6.0;
          dp[i + 1][min(a + 1, d[0])][b][c] += dp[i][a][b][c] / 6.0;
          dp[i + 1][a][min(b + 1, d[1])][c] += dp[i][a][b][c] / 6.0;
          dp[i + 1][min(a + 2, d[0])][b][c] += dp[i][a][b][c] / 6.0;
          dp[i + 1][a][b][min(c + 1, d[2])] += dp[i][a][b][c] / 6.0;
          dp[i + 1][min(a + 1, d[0])][min(b + 1, d[1])][c] += dp[i][a][b][c] / 6.0;
        }
      }
    }
  }

  cout << setprecision(15) << dp[N][d[0]][d[1]][d[2]] << endl;

  return 0;
}
