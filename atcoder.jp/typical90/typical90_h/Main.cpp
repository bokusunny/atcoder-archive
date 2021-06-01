#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> sv;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (c == 'a') {
      sv.emplace_back(0);
    } else if (c == 't') {
      sv.emplace_back(1);
    } else if (c == 'c') {
      sv.emplace_back(2);
    } else if (c == 'o') {
      sv.emplace_back(3);
    } else if (c == 'd') {
      sv.emplace_back(4);
    } else if (c == 'e') {
      sv.emplace_back(5);
    } else if (c == 'r') {
      sv.emplace_back(6);
    } else {
      sv.emplace_back(-1);
    }
  }
  const long long mod = 1000000007;

  vector<vector<long long>> dp(n + 1, vector<long long>(7, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 7; j++) {
      dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
    }
    int val = sv[i];
    if (val == -1) continue;

    if (val == 0) {
      dp[i + 1][val] = (dp[i + 1][val] + 1) % mod;
    } else {
      dp[i + 1][val] = (dp[i + 1][val] + dp[i][val - 1]) % mod;
    }
  }

  cout << dp[n][6] << endl;

  return 0;
}