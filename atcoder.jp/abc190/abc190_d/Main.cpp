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

void solve() {
  long long N;
  cin >> N;

  auto D = divisors(N * 2);
  int cnt = 0;
  for (auto d : D) {
    if ((N * 2 / d - d + 1) & 1) continue;
    cnt++;
  }

  cout << cnt << endl;
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
