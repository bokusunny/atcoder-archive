#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;

  vector<long long> A(n);
  for (auto &a : A) cin >> a;
  long long sum = accumulate(A.begin(), A.end(), 0LL);

  if (sum > n) {
    cout << -1 << endl;
  } else {
    cout << n - sum << endl;
  }

  return 0;
}
