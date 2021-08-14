#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  vector<int> RS(N + 1), GS(N + 1), BS(N + 1);
  for (int i = 0; i < N; i++) {
    RS[i + 1] = RS[i] + (S[i] == 'R');
    GS[i + 1] = GS[i] + (S[i] == 'G');
    BS[i + 1] = BS[i] + (S[i] == 'B');
  }

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (S[i] == S[j]) continue;
      if ((S[i] == 'R' && S[j] == 'G') || (S[i] == 'G' && S[j] == 'R')) {
        ans += BS[N] - BS[j + 1];
        if (2 * j - i < N && S[2 * j - i] == 'B') ans--;
      } else if ((S[i] == 'R' && S[j] == 'B') || (S[i] == 'B' && S[j] == 'R')) {
        ans += GS[N] - GS[j + 1];
        if (2 * j - i < N && S[2 * j - i] == 'G') ans--;
      } else if ((S[i] == 'G' && S[j] == 'B') || (S[i] == 'B' && S[j] == 'G')) {
        ans += RS[N] - RS[j + 1];
        if (2 * j - i < N && S[2 * j - i] == 'R') ans--;
      }
    }
  }

  cout << ans << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
