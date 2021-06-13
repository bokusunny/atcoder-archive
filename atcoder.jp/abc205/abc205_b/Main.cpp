#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto &a : A) cin >> a;
  sort(A.begin(), A.end());
  vector<int> N;
  for (int i = 1; i <= n; i++) N.push_back(i);

  if (A == N) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
