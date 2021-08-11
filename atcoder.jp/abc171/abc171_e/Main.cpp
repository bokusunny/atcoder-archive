#include <bits/stdc++.h>
using namespace std;

#include <atcoder/string>
using namespace atcoder;

void solve() {
  int N;
  cin >> N;
  int x = 0;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i], x ^= A[i];

  for (auto a : A) {
    cout << (a ^ x) << " ";
  }
  cout << endl;
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
