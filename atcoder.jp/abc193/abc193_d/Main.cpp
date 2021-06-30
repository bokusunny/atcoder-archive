#include <bits/stdc++.h>
using namespace std;

auto score(vector<int> tehuda) {
  long long res = 0;
  for (int i = 1; i <= 9; i++) {
    long long tmp = i;
    for (int j = 0; j < tehuda[i]; j++) tmp *= 10;
    res += tmp;
  }
  return res;
}

int main() {
  long long K;
  cin >> K;
  string S, T;
  cin >> S >> T;

  vector<long long> deck(10, K);
  deck[0] = 0;
  vector<int> S_tefuda(10), T_tefuda(10);

  for (int i = 0; i < 4; i++) {
    int si = S[i] - '0', ti = T[i] - '0';
    deck[si]--, deck[ti]--;
    S_tefuda[si]++, T_tefuda[ti]++;
  }

  long double ans = 0.0;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      auto ST = S_tefuda, TT = T_tefuda;
      if (i == j) {
        if (deck[i] <= 1) continue;
        ST[i]++, TT[j]++;
        if (score(ST) <= score(TT)) continue;

        long double tmp = deck[i] * (deck[i] - 1);
        ans += tmp / (9LL * K - 8) / (9LL * K - 9);
      } else {
        if (deck[i] == 0 || deck[j] == 0) continue;
        ST[i]++, TT[j]++;
        if (score(ST) <= score(TT)) continue;
        long double tmp = deck[i] * deck[j];
        ans += tmp / (9LL * K - 8) / (9LL * K - 9);
      }
    }
  }

  cout << ans << endl;

  return 0;
}
