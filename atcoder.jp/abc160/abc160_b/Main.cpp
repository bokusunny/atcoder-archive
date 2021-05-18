#include <bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()

template <typename T> inline bool chmin(T &a, const T &b) {
  bool compare = a > b;
  if (a > b)
    a = b;
  return compare;
}
template <typename T> inline bool chmax(T &a, const T &b) {
  bool compare = a < b;
  if (a < b)
    a = b;
  return compare;
}
// --------------------------------------------------------
int main() {
  int x;
  cin >> x;
  long long ans = 0;
  ans += (1000 * (x / 500));
  x %= 500;
  ans += (5 * (x / 5));
  cout << ans << endl;
}
