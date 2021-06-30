#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (auto &a : A) cin >> a;
  vector<int> B(200010);

  long long ans = 0;
  for (int i = 0; i < N; i++) {
    auto a = A[i];
    if (a + i + 1 < (int)B.size()) B[a + i + 1]++;
    if (i + 1 - a >= 0) ans += B[i + 1 - a];
  }

  cout << ans << endl;

  return 0;
}
