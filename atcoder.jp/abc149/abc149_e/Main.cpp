#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  long long M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  const int MX = 100100;
  vector<int> Cnt(MX + 1);
  for (auto &a : A) Cnt[a]++;
  for (int i = 0; i < MX; i++) Cnt[i + 1] += Cnt[i];
  vector<long long> Rui(MX + 1);
  for (auto &a : A) Rui[a] += a;
  for (int i = 0; i < MX; i++) Rui[i + 1] += Rui[i];

  auto get_cnt = [&](int minsum) {
    long long res = 0;
    for (auto &x : A) {
      int y = max(minsum - x, 1);
      if (y > MX) continue;
      res += Cnt[MX] - Cnt[y - 1];
    }
    return res;
  };

  int ok = 0, ng = 1 << 30;
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;
    if (get_cnt(mid) >= M) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  auto get_sum = [&](int minsum) {
    long long res = 0;
    for (auto &x : A) {
      int y = max(minsum - x, 1);
      if (y > MX) continue;
      res += Rui[MX] - Rui[y - 1];
      res += 1LL * x * (Cnt[MX] - Cnt[y - 1]);
    }
    return res;
  };

  long long minsum_cnt = M - get_cnt(ok + 1);
  cout << 1LL * ok * minsum_cnt + get_sum(ok + 1) << endl;
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
