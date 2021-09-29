#include <bits/stdc++.h>
using namespace std;

// nxt[i][c] := i(1-index)番目以降で初めてcが出現するindex(なければN)
vector<vector<int>> calc_next(string &S) {
  int N = (int)S.size();
  vector res(N + 1, vector<int>(26, -1));
  for (int i = N; i >= 1; i--) {
    for (int c = 0; c < 26; c++) {
      if (S[i - 1] - 'a' == c) {
        res[i][c] = i;
      } else if (i != N) {
        res[i][c] = res[i + 1][c];
      }
    }
  }
  return res;
}

void solve() {
  string S;
  cin >> S;
  int N = (int)S.size();
  const int INF = 1 << 30;

  auto Nxt = calc_next(S);
  vector<int> dp(N + 1, INF);  // dp[i] := i文字目以降について「部分文字列とならない」最短の文字列長
  vector<char> To(N + 1, '?');  // To[i] := 次の文字
  dp[N] = 1;
  for (int i = N - 1; i >= 0; i--) {
    // i文字目以降で最初に選ぶ文字で場合分け
    for (int c = 0; c < 26; c++) {
      if (Nxt[i + 1][c] == -1) {
        if (dp[i] > 1) {
          dp[i] = 1;
          To[i] = 'a' + c;
        }
      } else {
        if (dp[i] > dp[Nxt[i + 1][c]] + 1) {
          dp[i] = dp[Nxt[i + 1][c]] + 1;
          To[i] = 'a' + c;
        }
      }
    }
  }

  string ans;
  int now = 0;
  while (now != -1) {
    ans += To[now];
    now = Nxt[now + 1][To[now] - 'a'];
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
