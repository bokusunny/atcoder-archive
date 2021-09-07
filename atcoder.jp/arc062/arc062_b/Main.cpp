#include <bits/stdc++.h>
using namespace std;

void solve() {
  string S;
  cin >> S;
  int N = (int)S.size();

  int score = 0;
  for (int i = 0; i < N; i++) {
    if (i & 1) {
      if (S[i] == 'g') score++;
    } else {
      if (S[i] == 'p') score--;
    }
  }

  cout << score << endl;
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
