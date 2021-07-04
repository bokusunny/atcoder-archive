#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long long X;
  cin >> N >> X;

  vector<long long> A1, A2;
  for (int i = 0; i < N; i++) {
    long long w;
    cin >> w;
    if (i % 2 == 0)
      A1.push_back(w);
    else
      A2.push_back(w);
  }

  vector<long long> S1, S2;
  for (int i = 0; i < (1 << (int)A1.size()); i++) {
    long long sum = 0;
    for (int j = 0; j < (int)A1.size(); j++) {
      if ((i >> j) & 1) sum += A1[j];
    }
    S1.push_back(sum);
  }
  for (int i = 0; i < (1 << (int)A2.size()); i++) {
    long long sum = 0;
    for (int j = 0; j < (int)A2.size(); j++) {
      if ((i >> j) & 1) sum += A2[j];
    }
    S2.push_back(sum);
  }

  sort(S2.begin(), S2.end());

  long long ans = 0;
  for (auto s : S1) {
    auto target = X - s;
    ans += upper_bound(S2.begin(), S2.end(), target) - lower_bound(S2.begin(), S2.end(), target);
  }

  cout << ans << endl;

  return 0;
}
