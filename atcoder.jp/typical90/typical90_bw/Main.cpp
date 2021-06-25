#include <bits/stdc++.h>
using namespace std;

template <class T>
vector<pair<T, int>> prime_factorize(T N) {
  vector<pair<T, int>> res;
  for (T i = 2; i * i <= N; i++) {
    if (N % i != 0) continue;
    int ex = 0;
    while (N % i == 0) {
      ex++;
      N /= i;
    }
    res.push_back({i, ex});
  }

  if (N != 1) res.push_back({N, 1});
  return res;
}

int main() {
  long long N;
  cin >> N;

  auto pf = prime_factorize(N);

  long long ex_sum = 0;
  for (auto [val, ex] : pf) {
    ex_sum += ex;
  }

  int i = 0;
  long long n = 1;
  while (true) {
    if (n >= ex_sum) {
      cout << i << endl;
      return 0;
    }
    n *= 2, i++;
  }

  return 0;
}
