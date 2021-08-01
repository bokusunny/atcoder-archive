#include <bits/stdc++.h>
using namespace std;

int N, K;

void solve() {
  cin >> N >> K;

  if (K > (N - 1) * (N - 2) / 2) {
    cout << -1 << endl;
    return;
  }

  cout << N - 1 + (N - 1) * (N - 2) / 2 - K << endl;
  for (int i = 2; i <= N; i++) {
    cout << 1 << " " << i << endl;
  }
  int left = (N - 1) * (N - 2) / 2 - K;
  for (int i = 2; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      if (left <= 0) break;
      cout << i << " " << j << endl;
      left--;
    }
  }
}

void setcin() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  setcin();
  solve();

  return 0;
}
