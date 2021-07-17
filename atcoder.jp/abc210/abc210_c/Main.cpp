#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> C(N);
  for (int i = 0; i < N; i++) cin >> C[i];

  map<int, int> m;
  for (int i = 0; i < K; i++) {
    m[C[i]]++;
  }

  int ans = (int)m.size();
  for (int i = 0; i < N - K; i++) {
    if (m[C[i]] == 1) {
      m.erase(C[i]);
    } else {
      m[C[i]]--;
    }
    m[C[i + K]]++;
    ans = max(ans, (int)m.size());
  }

  cout << ans << endl;

  return 0;
}
