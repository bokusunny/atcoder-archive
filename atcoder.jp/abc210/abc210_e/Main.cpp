#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<pair<long long, int>> AC(M);
  for (int i = 0; i < M; i++) {
    cin >> AC[i].second >> AC[i].first;
  }
  sort(AC.begin(), AC.end());

  long long tot = 0;
  for (auto [C, A] : AC) {
    auto new_N = gcd(N, A);  // 新しい連結成分の個数
    tot += (N - new_N) * C;
    N = new_N;
    if (N == 1) break;
  }

  if (N != 1) {
    cout << -1 << endl;
  } else {
    cout << tot << endl;
  }

  return 0;
}
