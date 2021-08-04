#include <bits/stdc++.h>
using namespace std;

string S;
int Q;

void solve() {
  cin >> S >> Q;
  bool flipped = false;
  while (Q--) {
    int t;
    cin >> t;
    if (t == 1) {
      flipped = !flipped;
    } else if (t == 2) {
      int f;
      cin >> f;
      f--;
      if (flipped) f = !f;
      char c;
      cin >> c;
      if (f == 0) {
        S = c + S;
      } else {
        S += c;
      }
    }
  }

  if (flipped) reverse(S.begin(), S.end());

  cout << S << endl;
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
