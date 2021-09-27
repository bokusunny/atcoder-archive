#include <bits/stdc++.h>
using namespace std;

void solve() {
  int K;
  cin >> K;
  string A, B;
  cin >> A >> B;
  cout << stoll(A, nullptr, K) * stoll(B, nullptr, K) << endl;
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
