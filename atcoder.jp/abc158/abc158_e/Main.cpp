#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, P;
  cin >> N >> P;
  string S;
  cin >> S;
  reverse(S.begin(), S.end());

  if (P == 2) {
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      if ((S[i] - '0') % 2 == 0) {
        ans += (N - i);
      }
    }
    cout << ans << endl;
  } else if (P == 5) {
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      if (S[i] - '0' == 0 || S[i] - '0' == 5) {
        ans += (N - i);
      }
    }
    cout << ans << endl;
  } else {
    vector<int> Cnt(P);
    Cnt[0]++;
    int cur = 0;
    int ten = 1;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      cur += ten * (S[i] - '0');
      cur %= P;
      ans += Cnt[cur];
      Cnt[cur]++;
      ten *= 10;
      ten %= P;
    }

    cout << ans << endl;
  }
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
