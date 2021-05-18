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
  int a, b;
  cin >> a >> b;

  double da = (double)a, db = (double)b;
  cout << int((da + db) / 2 + 0.5) << endl;
}
