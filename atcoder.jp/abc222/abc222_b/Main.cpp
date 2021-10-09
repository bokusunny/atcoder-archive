#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N, P;
  cin >> N >> P;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  int cnt = 0;
  for (auto a : A) {
    if (a < P) cnt++;
  }

  cout << cnt << endl;
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
