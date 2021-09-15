#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, K;
  cin >> N >> K;
  vector<pair<int, int>> S(N);
  for (int i = 0; i < N; i++) cin >> S[i].first >> S[i].second;
  auto comp = [](const pair<int, int> &a, const pair<int, int> &b) { return a.second > b.second; };
  sort(S.begin(), S.end(), comp);

  priority_queue<int, vector<int>, greater<int>> pq;
  set<int> Kind;
  long long ans = 0, prev = 0;
  for (int i = 0; i < N; i++) {
    auto [t, d] = S[i];
    if (i >= K) {
      if (!Kind.count(t) && (int)Kind.size() < K) {
        auto mi = pq.top();
        pq.pop();
        long long tmp = prev;
        tmp -= mi;
        tmp -= 1LL * (int)Kind.size() * (int)Kind.size();
        Kind.insert(t);
        tmp += d;
        tmp += 1LL * (int)Kind.size() * (int)Kind.size();
        prev = tmp;
        ans = max(ans, tmp);
      }
    } else {
      ans -= 1LL * (int)Kind.size() * (int)Kind.size();
      if (Kind.count(t)) pq.push(d);
      Kind.insert(t);
      ans += d;
      ans += 1LL * (int)Kind.size() * (int)Kind.size();
      prev = ans;
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
