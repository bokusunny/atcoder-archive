#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  const int INF = 1000000001;
  // dp.at(i).at(j): 位置iを含むそれより後ろにある文字jの最も左のもののindex
  vector<vector<int>> dp(n + 1, vector<int>(26, INF));

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      if (s.at(i) == (int)('a' + j)) {
        dp.at(i).at(j) = i;
      } else {
        dp.at(i).at(j) = dp.at(i + 1).at(j);
      }
    }
  }

  string ans = "";
  int current_pos = 0;
  for (int i = 1; i <= k; i++) {
    int should_right_s_len = k - i;
    for (int j = 0; j < 26; j++) {
      int right_s_len = n - dp.at(current_pos).at(j) - 1;
      if (right_s_len >= should_right_s_len) {
        ans += (char)('a' + j);
        current_pos = dp.at(current_pos).at(j) + 1;
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
