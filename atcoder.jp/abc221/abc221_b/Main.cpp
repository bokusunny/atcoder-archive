#include <bits/stdc++.h>
using namespace std;

void solve() {
  string S, T;
  cin >> S >> T;
  int N = (int)S.size();

  if (S == T) {
    cout << "Yes" << endl;
    return;
  }

  int idx = -1;
  for (int i = 0; i < N; i++) {
    if (S[i] != T[i]) {
      swap(S[i], S[i + 1]);
      break;
    }
  }

  if (S == T) {
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
