#include <bits/stdc++.h>
using namespace std;

struct Edge {
  int to;
};
using Graph = vector<vector<Edge>>;

int c_to_num(char c) {
  if ('a' <= c && c <= 'z') {
    return c - 'a';
  } else {
    return c - 'A' + 26;
  }
}

int s_to_num(string s) {
  assert((int)s.size() == 3);
  int res = 0;
  res += c_to_num(s[0]);
  res += 52 * c_to_num(s[1]);
  res += 52 * 52 * c_to_num(s[2]);
  return res;
}

void solve() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) cin >> S[i];

  const int NodeNum = 52 * 52 * 52;
  Graph G(NodeNum);
  vector<int> Deg(NodeNum);
  vector<pair<int, int>> E(N);
  for (int i = 0; i < N; i++) {
    string pre = S[i].substr(0, 3), suf = S[i].substr((int)S[i].size() - 3);
    int pnum = s_to_num(pre), snum = s_to_num(suf);
    E[i] = {pnum, snum};
    G[snum].push_back({pnum});
    Deg[pnum]++;
  }

  vector<int> dp(NodeNum, -1);
  queue<int> q;
  for (int i = 0; i < NodeNum; i++) {
    if (Deg[i] == 0) {
      dp[i] = 0;
      q.push(i);
    }
  }

  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    for (auto [v] : G[u]) {
      if (dp[v] != -1) continue;
      if (dp[u] == 0) {
        dp[v] = 1;
        q.push(v);
      }
      Deg[v]--;
      if (dp[u] == 1 && Deg[v] == 0) {
        dp[v] = 0;
        q.push(v);
      }
    }
  }

  for (auto [pnum, snum] : E) {
    if (dp[snum] == 0) {
      cout << "Takahashi" << endl;
    } else if (dp[snum] == 1) {
      cout << "Aoki" << endl;
    } else {
      cout << "Draw" << endl;
    }
  }
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
