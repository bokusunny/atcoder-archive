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
  string s;
  cin >> s;

  const int best = 753;

  int ans = 100000;
  rep(i, s.size() - 2) {
    string tmp = s.substr(i, 3);
    int tmp_i = stoi(tmp);
    int diff = abs(best - tmp_i);
    chmin(ans, diff);
  }

  cout << ans << endl;
}
