#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, Z, W;
  cin >> N >> Z >> W;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  if (N == 1) {
    cout << abs(A[N - 1] - W) << endl;
  } else {
    cout << max(abs(A[N - 1] - W), abs(A[N - 2] - A[N - 1])) << endl;
  }
}

int main() {
  solve();

  return 0;
}
