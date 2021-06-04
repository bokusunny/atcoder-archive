#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  long long m = 1000;
  vector<int> A(n);
  for (auto &a : A) cin >> a;

  long long today = A.at(0);
  for (int i = 1; i < n; i++) {
    if (A.at(i) > A.at(i - 1)) {
      long long cnt = m / A.at(i - 1);
      m += cnt * (A.at(i) - A.at(i - 1));
    }
  }

  cout << m << endl;

  return 0;
}
