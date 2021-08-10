#include <bits/stdc++.h>
using namespace std;

void solve() {
  vector<int> A(3);
  for (int i = 0; i < 3; i++) cin >> A[i];

  sort(A.begin(), A.end());
  cout << A[0] + A[1] << endl;
}

int main() {
  solve();

  return 0;
}
