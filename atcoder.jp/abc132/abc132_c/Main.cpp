#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> D;

void solve() {
  cin >> N;
  D.resize(N);
  for (int i = 0; i < N; i++) cin >> D[i];
  sort(D.begin(), D.end());
  auto mi = D[N / 2 - 1];
  auto mx = D[N / 2];
  cout << mx - mi << endl;
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
