#include <bits/stdc++.h>
using namespace std;

void solve() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  if (S[N - 1] == 'o') {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
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
