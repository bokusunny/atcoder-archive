#include <bits/stdc++.h>
using namespace std;

void solve() {
  int A, B;
  cin >> A >> B;
  if ((A & 1) && (B & 1)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main() {
  solve();

  return 0;
}
