#include <bits/stdc++.h>
using namespace std;

int K;
string S;

void solve() {
  cin >> K >> S;
  if ((int)S.size() <= K) {
    cout << S << endl;
  } else {
    cout << S.substr(0, K) + "..." << endl;
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
