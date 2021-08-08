#include <bits/stdc++.h>
using namespace std;

int A, B, C;

void solve() {
  cin >> A >> B >> C;
  if (B >= C && C >= A) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}

int main() {
  solve();

  return 0;
}
