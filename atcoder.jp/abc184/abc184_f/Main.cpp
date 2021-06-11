#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  vector<long long> A1;
  vector<long long> A2;

  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;

    i % 2 == 1 ? A1.push_back(a) : A2.push_back(a);
  }

  vector<long long> A1_sums;
  vector<long long> A2_sums;
  for (int i = 0; i < 1 << (int)A1.size(); i++) {
    long long tmp = 0;
    for (int j = 0; j < (int)A1.size(); j++) {
      if (i >> j & 1) tmp += A1.at(j);
    }
    if (tmp <= t) A1_sums.push_back(tmp);
  }
  for (int i = 0; i < 1 << (int)A2.size(); i++) {
    long long tmp = 0;
    for (int j = 0; j < (int)A2.size(); j++) {
      if (i >> j & 1) tmp += A2.at(j);
    }
    if (tmp <= t) A2_sums.push_back(t - tmp);
  }
  sort(A2_sums.begin(), A2_sums.end());

  long long ans = -1;
  for (auto s : A1_sums) {
    auto itr = lower_bound(A2_sums.begin(), A2_sums.end(), s);
    if (itr != A2_sums.end()) {
      ans = max(ans, t - ((*itr) - s));
    }
  }

  cout << ans << endl;

  return 0;
}
