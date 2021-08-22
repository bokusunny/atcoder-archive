#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;

  vector<pair<int, int>> P(N);
  for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
  sort(P.begin(), P.end());

  auto is_ok = [&](long long d) {
    queue<pair<int, int>> q;
    int mi = 1000000000, mx = 0;
    for (auto [cx, cy] : P) {
      while (!q.empty()) {
        auto [px, py] = q.front();
        if (cx - d < px) break;
        mi = min(mi, py);
        mx = max(mx, py);
        q.pop();
      }
      if (mi <= cy - d || cy + d <= mx) return true;
      q.emplace(cx, cy);
    }
    return false;
  };

  long long ok = -1, ng = 1LL << 30;
  while (abs(ok - ng) > 1) {
    long long mid = (ok + ng) / 2;
    if (is_ok(mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;
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
