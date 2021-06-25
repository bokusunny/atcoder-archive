#include <bits/stdc++.h>
using namespace std;

vector<long long> divisors(long long N) {
  vector<long long> res;
  for (long long i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      if (N / i != i) res.push_back(N / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main() {
  long long N;
  cin >> N;
  auto dv = divisors(N);

  long long ans = 0;
  for (auto a : dv) {
    auto m = N / a - 1;
    if (a >= m) break;
    ans += m;
  }

  cout << ans << endl;

  return 0;
}
