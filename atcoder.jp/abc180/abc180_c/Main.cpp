#include <bits/stdc++.h>
using namespace std;

template <class T>
vector<T> divisors(T N) {
  vector<T> res;
  for (T i = 1; i * i <= N; ++i) {
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

  for (auto d : dv) cout << d << endl;

  return 0;
}
