#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

using mint = modint1000000007;

void solve() {
  int N;
  cin >> N;
  map<pair<long long, long long>, int> Cnt;
  int zero_zero = 0, zero_no = 0, no_zero = 0;
  for (int i = 0; i < N; i++) {
    long long A, B;
    cin >> A >> B;
    if (A == 0 && B == 0) {
      zero_zero++;
    } else if (A == 0) {
      zero_no++;
    } else if (B == 0) {
      no_zero++;
    } else {
      auto g = gcd(A, B);
      A /= g;
      B /= g;
      if ((A < 0 && B < 0) || (A * B < 0 && A < 0)) {
        A *= -1;
        B *= -1;
      }
      Cnt[{A, B}]++;
    }
  }

  mint two = 2;
  mint ans = 1;
  ans *= two.pow(zero_no) + two.pow(no_zero) - 1;
  set<pair<long long, long long>> seen;
  for (auto [p, cnt] : Cnt) {
    if (seen.count(p)) continue;

    auto rev = make_pair(p.second, -p.first);
    if (rev.first < 0) {
      rev.first *= -1;
      rev.second *= -1;
    }
    if (Cnt.count(rev)) {
      ans *= two.pow(Cnt[p]) + two.pow(Cnt[rev]) - 1;
      seen.insert(rev);
    } else {
      ans *= two.pow(Cnt[p]);
    }
  }
  ans += zero_zero;
  ans--;

  cout << ans.val() << endl;
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
