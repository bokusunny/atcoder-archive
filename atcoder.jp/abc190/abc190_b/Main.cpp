#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s, d;
  cin >> n >> s >> d;

  bool is_ok = false;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    if (x < s && y > d) {
      is_ok = true;
      break;
    }
  }

  if (is_ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
