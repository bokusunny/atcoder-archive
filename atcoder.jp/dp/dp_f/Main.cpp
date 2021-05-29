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

int main() {
  string s, t;
  cin >> s >> t;

  vector<vector<int>> dp((int)s.size() + 1, vector<int>((int)t.size() + 1, 0));

  for (int i = 0; i < (int)s.size(); i++) {
    for (int j = 0; j < (int)t.size(); j++) {
      if (s[i] == t[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
      chmax(dp[i + 1][j + 1], dp[i + 1][j]);
      chmax(dp[i + 1][j + 1], dp[i][j + 1]);
    }
  }

  string ans = "";
  int i = (int)s.size(), j = (int)t.size();
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else if (dp[i][j] == dp[i][j - 1]) {
      j--;
    } else {
      ans = s[i - 1] + ans;
      i--, j--;
    }
  }

  cout << ans << endl;

  return 0;
}
