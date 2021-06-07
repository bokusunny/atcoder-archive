#include <bits/stdc++.h>
using namespace std;

int main() {
  int k, t;
  cin >> k >> t;
  if (t == 1) {
    cout << k - 1 << endl;
    return 0;
  }

  vector<int> A(t);
  for (auto &a : A) cin >> a;
  sort(A.begin(), A.end(), greater<int>());
  int most_frequent = A.at(0);
  int other = k - most_frequent;

  if (most_frequent - other <= 1) {
    cout << 0 << endl;
  } else {
    cout << most_frequent - other - 1 << endl;
  }

  return 0;
}
