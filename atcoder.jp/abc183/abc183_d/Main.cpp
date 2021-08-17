#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, W;
  cin >> N >> W;
  const int mx = 200100;
  vector<long long> X(mx + 1);
  for (int i = 0; i < N; i++) {
    int S, T, P;
    cin >> S >> T >> P;
    X[S] += P;
    X[T] -= P;
  }
  for (int i = 0; i < mx; i++) {
    X[i + 1] += X[i];
    if (X[i] > W) {
      cout << "No" << endl;
      return;
    }
  }

  cout << "Yes" << endl;
}

int main() {
  solve();

  return 0;
}
