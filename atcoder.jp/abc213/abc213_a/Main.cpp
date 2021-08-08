#include <bits/stdc++.h>
using namespace std;

int A, B;

void solve() {
  cin >> A >> B;
  for (int i = 0; i < 1000; i++) {
    if ((A ^ i) == B) {
      cout << i << endl;
      return;
    }
  }
}

int main() {
  solve();

  return 0;
}
