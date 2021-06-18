#include <bits/stdc++.h>
using namespace std;

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<long long> A(n);
  for (auto& a : A) cin >> a;

  const long long INF = 1LL << 60;
  vector<vector<long long>> dp(n, vector<long long>(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n + 1; j++) {
      int len = j - i;
      dp.at(i).at(j) = len == 0 ? 0 : (n - len) % 2 == 0 ? -INF : INF;
    }
  }

  for (int len = 1; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      int j = i + len;
      if ((n - len) % 2 == 0) {
        chmax(dp.at(i).at(j), dp.at(i).at(j - 1) + A.at(j - 1));
        if (i != n - 1) chmax(dp.at(i).at(j), dp.at(i + 1).at(j) + A.at(i));
      } else {
        chmin(dp.at(i).at(j), dp.at(i).at(j - 1) - A.at(j - 1));
        if (i != n - 1) chmin(dp.at(i).at(j), dp.at(i + 1).at(j) - A.at(i));
      }
    }
  }

  cout << dp.at(0).at(n) << endl;

  return 0;
}
