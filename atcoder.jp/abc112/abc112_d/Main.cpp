#include <bits/stdc++.h>
using namespace std;

vector<int> divisors(int N) {
  vector<int> res;
  for (int i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      if (N / i != i) res.push_back(N / i);
    }
  }
  sort(res.begin(), res.end(), greater<int>());
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;

  auto md = divisors(m);
  for (auto d : md) {
    if (m / d >= n) {
      cout << d << endl;
      return 0;
    }
  }

  return 0;
}
