#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  map<long long, long long> Cnt;  // 満足度keyのアトラクションの個数
  for (auto &a : A) Cnt[a]++;

  priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, less<pair<long long, long long>>> pq;
  for (auto [val, cnt] : Cnt) pq.emplace(val, cnt);
  pq.emplace(0, 1);

  auto calc = [&](long long cnt, long long l, long long r) { return cnt * (l + (r + 1)) * (l - r) / 2; };

  long long ans = 0;
  while (pq.size() >= 2 && K > 0) {
    auto [val1, cnt1] = pq.top();
    pq.pop();

    auto [val2, cnt2] = pq.top();
    if (cnt1 * (val1 - val2) <= K) {
      ans += calc(cnt1, val1, val2);
      pq.pop();
      pq.emplace(val2, cnt1 + cnt2);
      K -= cnt1 * (val1 - val2);
    } else {
      long long len = K / cnt1;
      int mo = K % cnt1;
      ans += calc(cnt1, val1, val1 - len);
      K -= cnt1 * len;
      ans += (val1 - len) * mo;
      K -= mo;
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
