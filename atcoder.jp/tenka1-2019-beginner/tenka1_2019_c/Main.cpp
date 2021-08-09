#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<int> SB(N + 1), SW(N + 1);
  for (int i = 0; i < N; i++) {
    if (S[i] == '#') {
      SB[i + 1]++;
    } else {
      SW[i + 1]++;
    }
    SB[i + 1] += SB[i];
    SW[i + 1] += SW[i];
  }

  const int INF = 1 << 30;
  int ans = INF;
  for (int i = 0; i <= N; i++) {
    auto b = SB[i];
    auto w = SW[N] - SW[i];
    ans = min(ans, b + w);
  }

  cout << ans << endl;
}

int main() {
  solve();

  return 0;
}
