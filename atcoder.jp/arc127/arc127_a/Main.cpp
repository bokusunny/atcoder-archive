#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long N;
  cin >> N;
  auto S = to_string(N);
  int keta = (int)S.size();

  long long ans = 0;
  for (int cnt1 = 1; cnt1 <= keta; cnt1++) {
    string lowerStmp(cnt1, '1');
    for (int cnt0 = 0; cnt0 + cnt1 <= keta; cnt0++) {
      string lowerS = lowerStmp;
      for (int j = 0; j < cnt0; j++) lowerS += '0';
      string upperS = lowerS;
      upperS[cnt1 - 1] = '2';
      long long lower = stoll(lowerS);
      long long upper = stoll(upperS);
      upper = min(upper, N + 1);
      if (upper < lower) continue;
      ans += upper - lower;
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
