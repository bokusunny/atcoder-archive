#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

template <typename T> inline bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T> inline bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
// --------------------------------------------------------
int main() {
  string s;
  cin >> s;
  reverse(all(s));

  long long w_cnt = 0;
  long long ans = 0;
  for (auto c : s) {
    c == 'W' ? w_cnt++ : ans += w_cnt;
  }

  cout << ans << endl;
}
