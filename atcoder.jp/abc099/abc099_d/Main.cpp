#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<vector<int>> D;

void solve() {
  cin >> N >> C;
  D.resize(C, vector<int>(C));
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      cin >> D[i][j];
    }
  }

  vector<vector<int>> Cnt(3, vector<int>(C));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int c;
      cin >> c;
      c--;
      Cnt[(i + j) % 3][c]++;
    }
  }

  const long long INF = 1LL << 62;
  long long ans = INF;
  for (int c0 = 0; c0 < C; c0++) {
    for (int c1 = 0; c1 < C; c1++) {
      for (int c2 = 0; c2 < C; c2++) {
        if (c0 == c1 || c1 == c2 || c0 == c2) continue;

        long long tmp = 0;
        for (int c = 0; c < C; c++) {
          tmp += D[c][c0] * Cnt[0][c];
          tmp += D[c][c1] * Cnt[1][c];
          tmp += D[c][c2] * Cnt[2][c];
        }
        ans = min(ans, tmp);
      }
    }
  }

  cout << ans << endl;
}

int main() {
  solve();

  return 0;
}
