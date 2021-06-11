#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> s(n + 1);
  s.at(0) = 0;
  vector<int> A(n);
  for (auto &a : A) cin >> a;
  for (int i = 0; i < n; i++) {
    s.at(i + 1) = s.at(i) + A.at(i);
  }

  for (int i = 3; i < n + 1; i++) {
    auto sum = s.at(i) - s.at(i - 3);
    if (sum < k) {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
