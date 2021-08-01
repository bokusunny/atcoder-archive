#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> B;

void solve() {
  cin >> N;
  B.resize(N - 1);
  for (int i = 0; i < N - 1; i++) cin >> B[i];
  int sum = B[0] + B[N - 2];
  for (int i = 1; i < N - 1; i++) {
    sum += min(B[i - 1], B[i]);
  }
  cout << sum << endl;
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
