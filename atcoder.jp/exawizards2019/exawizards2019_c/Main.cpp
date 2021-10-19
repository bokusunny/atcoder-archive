#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, Q;
  cin >> N >> Q;
  string S1;
  cin >> S1;
  auto S2 = S1;
  reverse(S2.begin(), S2.end());
  vector<pair<char, int>> Q1, Q2;
  for (int i = 0; i < Q; i++) {
    char t, d;
    cin >> t >> d;
    if (d == 'L') {
      Q1.emplace_back(t, -1);
      Q2.emplace_back(t, 1);
    } else {
      Q1.emplace_back(t, 1);
      Q2.emplace_back(t, -1);
    }
  }

  auto get_cnt = [](string &S, vector<pair<char, int>> &Q) {
    int N = (int)S.size();

    auto is_ok = [&](int pos) {
      for (auto [c, dir] : Q) {
        if (c == S[pos]) {
          pos += dir;
        }
        if (pos < 0) return true;
        if (pos > N) return false;
      }
      return false;
    };

    int ok = -1, ng = N;
    while (abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      if (is_ok(mid)) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    return ok + 1;
  };

  cout << N - get_cnt(S1, Q1) - get_cnt(S2, Q2) << endl;
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
