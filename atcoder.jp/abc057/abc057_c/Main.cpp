#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

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
  long long n;
  cin >> n;

  auto F = [](long long a, long long b) {
    string sa = to_string(a), sb = to_string(b);
    return max((int)sa.size(), (int)sb.size());
  };

  vector<long long> divs = divisors(n);
  int ans = 11;
  for (long long a : divs) {
    long long b = n / a;
    int f = F(a, b);
    if (f < ans) ans = f;
  }

  cout << ans << endl;

  return 0;
}
