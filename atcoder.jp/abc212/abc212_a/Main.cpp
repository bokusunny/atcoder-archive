#include <bits/stdc++.h>
using namespace std;

int A, B;

void solve() {
  cin >> A >> B;
  if (0 < A && B == 0) {
    cout << "Gold" << endl;
  } else if (A == 0 && 0 < B) {
    cout << "Silver" << endl;
  } else {
    cout << "Alloy" << endl;
  }
}

void cinout() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  cinout();
  solve();

  return 0;
}
