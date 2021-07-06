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
  long long K;
  cin >> K;

  auto D = divisors(K);

  long long ans = 0;
  for (int i = 0; i < (int)D.size(); i++) {
    auto a = D[i];
    for (int j = i; j < (int)D.size(); j++) {
      auto b = D[j];
      if (K / a % b != 0) continue;
      auto c = K / a / b;
      if (c < b) continue;

      if (binary_search(D.begin(), D.end(), c)) ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
