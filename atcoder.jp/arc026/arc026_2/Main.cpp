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
  long long n;
  cin >> n;

  auto divs = divisors(n);
  long long sum = 0;
  for (long long d : divs) sum += d;
  sum -= n;

  string ans;
  if (sum == n) {
    ans = "Perfect";
  } else if (sum < n) {
    ans = "Deficient";
  } else {
    ans = "Abundant";
  }

  cout << ans << endl;

  return 0;
}
