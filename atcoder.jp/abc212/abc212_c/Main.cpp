#include <bits/stdc++.h>
using namespace std;

int N, M;
const long long INF = 1LL << 62;
vector<long long> A, B = {-INF};

void solve() {
  cin >> N >> M;
  A.resize(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) {
    long long b;
    cin >> b;
    B.push_back(b);
  }
  B.push_back(INF);

  sort(B.begin(), B.end());
  long long ans = INF;
  for (auto a : A) {
    auto itr = lower_bound(B.begin(), B.end(), a);
    ans = min(ans, abs(*itr - a));
    ans = min(ans, abs(*(itr - 1) - a));
  }
  cout << ans << endl;
}

void cinout() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  cinout();
  solve();

  return 0;
}
