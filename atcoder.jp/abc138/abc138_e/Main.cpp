#include <bits/stdc++.h>
using namespace std;

string S, T;

void solve() {
  cin >> S >> T;
  int t_sz = (int)T.size(), s_sz = (int)S.size();
  int s_cur = -1, t_cur = 0;
  map<char, vector<int>> mp;
  for (int i = 0; i < (int)S.size(); i++) {
    mp[S[i]].push_back(i);
  }
  long long ans = 0;
  while (t_cur != t_sz) {
    auto t = T[t_cur];
    if (!mp.count(t)) {
      cout << -1 << endl;
      return;
    }
    auto itr = upper_bound(mp[t].begin(), mp[t].end(), s_cur);
    if (itr == mp[t].end()) {
      ans += s_sz - 1 - s_cur;
      s_cur = -1;
    } else {
      ans += *itr - s_cur;
      s_cur = *itr;
      t_cur++;
    }
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
