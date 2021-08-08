#include <bits/stdc++.h>
using namespace std;

string S;

void solve() {
  cin >> S;

  int c0 = 0, c1 = 0;
  for (auto c : S) {
    if (c == '0')
      c0++;
    else
      c1++;
  }

  cout << 2 * min(c1, c0) << endl;
}

int main() {
  solve();

  return 0;
}
